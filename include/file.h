#ifndef	_FILE_
#define	_FILE_

extern int FILEread(UINT8 *fname, char **rbuf, BOOL flag);
extern int FILEsave(UINT8 *fname, char *sbuf, int size);

#endif /* _FILE_ */
