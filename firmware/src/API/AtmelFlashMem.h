
#ifndef __AtmelFlash_H
#define __AtmelFlash_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "DataFlash_Comm.h"
#include <string.h>

#define MaxNoOfPage 8191 //total 8192 pages 0 to 8191
#define Bytes528InPage 528u
#define Bytes512InPage 512u

//Returns True if DataFlash is busy
bool FlashBusy();
//fAddr - Addres to Write to
//mAddr - pointer to Data to write
//Count - no of bytes to be written (Max 250)
//Returns true if successful 
//False if failed like mismatch in written data or SPI failure
bool WriteDataFlash (long fAddr, uint8_t *mAddr, int Count);
//FlashAddr - Addres to Read from
//mAddr - pointer to Data to receive
//Count - no of bytes to read (there is no limit)
//Returns true if successful 
//False if failed 
bool ReadDataFlash (long FlashAddr, uint8_t *mAddr, int Count);

//Returns No of Bytes in a Page of DataFlash 528 or 512
unsigned int GetFlashPageSize();
//Returns value indicating 2M 4M or 8M
unsigned int GetFlashMemCapacity();

//*************************************************************************
//**** Following functions are used for Internal Routines Not for the User
//Internal used for comparing the Written data
bool Flash_Page_Buffer_Match();
//Used to Adjust the Flash address depending Upon No of Bytes in a Page of Flash Mem
long GetFlashAddress (long fAddr);
//to Write the Input Data in the same Page of the Flash
//if the Data is to be written is crossing Border If so then Two separate Writes are performed
bool WriteDataFlashWithinPage(long FlashAddr, uint8_t *mAddr, int Count);
//Used to re-write the Pages for data integrity After AutoPageCnt reaches to a certain value
//to be taken care by before switching off the unit
void AutoPageReWrite();

#ifdef	__cplusplus
}
#endif

#endif
