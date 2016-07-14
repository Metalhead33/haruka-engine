#ifndef FILEIO_H
#define FILEIO_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stdlib.h>
char* ReadBin(char* filename);
char* WriteBin(char* filename,char* buf,size_t filesize);
#ifdef __cplusplus
}
#endif

#endif // FILEIO_H
