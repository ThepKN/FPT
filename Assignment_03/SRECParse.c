#include "SRECParse.h"
#define HEX_INVALID 0xFF
static SrecData_t SrecData={
.Line=0
};
static FILE*fileptr=NULL;
static uint8_t AddressNum=0;
static uint8_t DataBytes = 0;
static uint8_t Line=0;


static uint8_t ChartoHex(uint8_t character);
static SrecStatus StrtoHex(uint8_t * pStr, uint8_t len, uint32_t * pResult);
static SrecStatus Check_CheckSum(void);


//function to open file
SrecStatus SREC_OpenFile(const char*Filename)
{
	SrecStatus status=FILE_OK;
	fileptr=fopen(Filename,"r");
	if(NULL==fileptr)
	{
		status = FILE_NOT_EXIST;
	}
	return status;
}


//function to close file
void SREC_CloseFile(void)
{
	if(NULL!=SrecData.pData)
	{
		free(SrecData.pData);
	}
	fclose(fileptr);
}


//The function reads each line
SrecStatus SREC_ReadLine(SrecData_t* Ptr)
{
	char Buffer[9];
	uint8_t idx;
		// Stype - S1
	SrecStatus status = FILE_OK;
	SrecData.Line++;
	if(NULL!=fileptr)
{
	
	fgets(Buffer, 3, fileptr);
	//Read 'S'
	if (Buffer[0] == 'S' && Buffer[1] == '0')
	{
		status= FILE_HEADER;
		while(fgetc(fileptr) != '\n' && feof(fileptr) == 0);
	}
	else if (Buffer[0] == 'S' && Buffer[1] >= '1' && Buffer[1] <= '6' && Buffer[1] != '4')
	{
		//Read Type -> 1 / 2 / 3
		SrecData.SType = ChartoHex(Buffer[1]);
		//	=> number of address bytes / Data bytes
		AddressNum = (SrecData.SType + 1) * 2;
		
		//Read ByteCount => decimal	"13"
		fgets(Buffer, 3, fileptr);
		status = StrtoHex(Buffer, 2, &SrecData.ByteCount);
		
		if ( FILE_OK == status )
		{
			// Read Address => decimal
			fgets(Buffer, AddressNum+1, fileptr);
			status = StrtoHex(Buffer, AddressNum, &SrecData.Address);
			
			if ( FILE_OK == status )
			{
				// Read Data => decimal
				DataBytes = SrecData.ByteCount - 1 - AddressNum/2;
				if(NULL==SrecData.pData)
				{
					free(SrecData.pData);
				};
				SrecData.pData = (uint8_t*)malloc(DataBytes);
				SrecData.DataBytes=DataBytes; 
				for (idx = 0; idx < DataBytes; idx++)
				{
					fgets(Buffer, 3, fileptr);		// "49"
					status = StrtoHex(Buffer, 2, &SrecData.pData[idx]);
					if ( FILE_ERR_FORMAT == status )
					{
						while(fgetc(fileptr) != '\n' && feof(fileptr) == 0);
						break;
					}
				}
				
				if ( FILE_OK == status )
				{
					// Read Checksum byte => decimal
					fgets(Buffer, 3, fileptr);
					status = StrtoHex(Buffer, 2, &SrecData.CheckSum);
					
					if ( FILE_OK == status )
					{
						// => Calculate & check Checksum
						status = Check_CheckSum();
						//Check end of line / file => \n or EOF
						if ( FILE_OK == status )
						{
							if ( fgetc(fileptr) != '\n' && feof(fileptr) == 0 )
							{
								status = FILE_ERR_BYTECOUNT;
								// => Read continue to \n or eof
								while(fgetc(fileptr) != '\n' && feof(fileptr) == 0);
							}
						}else {while(fgetc(fileptr) != '\n' && feof(fileptr) == 0);}
					}else{while(fgetc(fileptr) != '\n' && feof(fileptr) == 0);};
				}
			}
		}
	}
	else if (Buffer[0] == 'S'&& Buffer[1] <= '9' && Buffer[1] >= '7')
	{
		status=FILE_END;
	}
	else 
	{
		status = FILE_ERR_FORMAT;
		while(fgetc(fileptr) != '\n' && feof(fileptr) == 0);
	};
	
}else {SrecStatus status = FILE_NOT_EXIST;}


SrecData.status=status;
*Ptr=SrecData;
	return status;
}



uint8_t ChartoHex(uint8_t character)
{
	uint8_t result;
	if(character<='9'&&character>='0')
	{
		result=character-'0';	
	}
	else if (character<='F'&&character>='A')
	{
		result=character-'A'+ 0xA;
	}
	else
	{
		result=HEX_INVALID;
	}
	return result;
}




SrecStatus StrtoHex(uint8_t * pStr, uint8_t len, uint32_t * pResult)
{
	uint8_t index;
	SrecStatus status = FILE_OK;
	*pResult = 0;
	uint8_t tempHex;
	
	for (index = 0; index < len; index++)
	{
		tempHex = ChartoHex(pStr[index]);
		if ( HEX_INVALID == tempHex )
		{
			status = FILE_ERR_FORMAT;
			break;
		}
		*pResult += tempHex * pow(16, len - 1 - index);
	}
	
	return status;
}




// Function to Calculate & check Checksum
SrecStatus Check_CheckSum(void)
{
	uint8_t idx;
	SrecStatus status = FILE_OK;
	uint8_t sum = 0;
	uint8_t * ptr = (uint8_t*)&SrecData.Address;
	
	sum += SrecData.ByteCount;		// 19 = 0x13
	// sum += 0x7AF0 => sum += 0x7A + 0xF0
	
	for (idx = 0; idx < AddressNum/2; idx++)
	{
		sum += ptr[idx];
	}
	
	for (idx = 0; idx < DataBytes; idx++)
	{
		sum += SrecData.pData[idx];
	}
	
	sum += SrecData.CheckSum;
	
	if (0xFFU != (sum & 0xFFU))
	{
		status = FILE_ERR_CHECKSUM;
	}
	
	return status;
}


