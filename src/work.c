
#include "../include/general.h"
#include "../include/work.h"

void WORKinit(void);

SINT32 work[WRK_MAX];

void WORKinit(void)
{
	int i;

	for(i = 0; i < WRK_MAX; i++){
		work[i] = 0;
	}
}
