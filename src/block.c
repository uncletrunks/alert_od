
#include "../include/general.h"

void BLOCKdraw(SINT8 col, SINT8 px, SINT8 py, SINT8 sx, SINT8 sy);

void BLOCKdraw(SINT8 col, SINT8 px, SINT8 py, SINT8 sx, SINT8 sy)
{
	px -= sx / 2;
	py -= sy / 2;
	pceLCDPaint(col, px, py, sx, sy);
	sx -= 1;
	sy -= 1;
	pceLCDPoint(0, px +  0, py +  0);
	pceLCDPoint(0, px + sx, py +  0);
	pceLCDPoint(0, px +  0, py + sy);
	pceLCDPoint(0, px + sx, py + sy);
}
