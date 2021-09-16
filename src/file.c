
#include "../include/general.h"

int FILEread(UINT8 *fname, char **rbuf, BOOL flag);
int FILEsave(UINT8 *fname, char *sbuf, int size);

int FILEread(UINT8 *fname, char **rbuf, BOOL flag)
{
	Uint32 size;
	Uint32 flen;
	FILE *fp;
	Uint32 i;
	Uint32 *tmp;

	fp = fopen((const char *)fname, "rb");
	if(fp){
		printf("fopen success %s\n", fname);
		fseek(fp, 0L, SEEK_END);
		flen = ftell(fp);
		fseek(fp, 0L, SEEK_SET);
		ftell(fp);
		if(flag){
			if(!(*rbuf)){
				*rbuf = (char *)malloc(flen);
				if(*rbuf == NULL){
					fclose(fp);
					return	-1;
				}
			}
		}
		size = fread(*rbuf, sizeof(char), flen, fp);
		fclose(fp);
		tmp = (Uint32 *)*rbuf;
		for(i = 0; i < (size / 4); i++){
			*tmp = SDL_SwapLE32(*tmp);
			tmp++;
		}
	}else{
		printf("fopen fales %s\n", fname);
		return	-1;
	}
	printf("read size %d\n", size);

	return	size;
}

int FILEsave(UINT8 *fname, char *sbuf, int size)
{
	FILE *fp;
	int	i;
	Uint32 *tmp;

	fp = fopen((const char *)fname, "wb");
	if(fp){
		tmp = (Uint32 *)sbuf;
		for(i = 0; i < (size / 4); i++){
			*tmp = SDL_SwapLE32(*tmp);
			tmp++;
		}
		fwrite(sbuf, sizeof(char), size, fp);
		fclose(fp);
	}else{
		return	-1;
	}

	return	0;
}
