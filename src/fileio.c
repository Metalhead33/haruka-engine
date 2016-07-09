#ifdef __cplusplus
extern "C" {
#endif
#include "fileio.h"
#include <stdio.h>
char* ReadBin(char* filename)
{
	FILE* fp=0;size_t filesize=0,cur=0;char* buf=0;char c;
	if(!(fp = fopen(filename,"rb")))
	{
		printf("\nInvalid file! Either %s does not exist, or something went seriously wrong.\n",filename);
		return 0;
	}
	fseek(fp, 0L, SEEK_END);
	filesize = ftell(fp);
	if(!(buf = (char*)malloc(filesize)))
	{
		printf("\nCouldn't allocate memory to suck in the file %s. Perhpas there is not enough free memory available?\n",filename);
		return 0;
	}
	for(cur=0; (c=fgetc(fp)) != EOF;++cur) buf[cur] = c;
	fclose(fp);
	return buf;
}
char* WriteBin(char* filename,char* buf,size_t filesize)
{
	FILE* fp=0;size_t cur;
	if(!(fp = fopen(filename,"wb")))
	{
		printf("\nError! Couldn't open %s for writing.\n",filename);
		return 0;
	}
	for(cur = 0;cur < filesize;++cur) fputc(buf[cur],fp);
	fclose(fp);
	return buf;
}
#ifdef __cplusplus
}
#endif
