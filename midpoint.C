#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

int main(void)
{
	/* request auto detection */
	int gdriver = DETECT, gmode;
	int x = 0, y = 0, r = 60, xc = 300, yc = 200;
	float p;

	/* initialize graphics, local variables*/
	initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");

	x = 0;
	y = r;
	p = (5 / 4) - r;

	while (x <= y)
	{
		if (p < 0)
		{
			x = x + 1;
			p = p + (2 * x) + 1;
		}
		else
		{
			x = x + 1;
			y = y - 1;
			p = p + 2 * (x - y) + 1;
		}
		putpixel(x + xc, y + yc, 1);
		putpixel(y + xc, x + yc, 1);
		putpixel(xc - x, yc - y, 2);
		putpixel(xc - y, yc - x, 2);
		putpixel(xc + x, yc - y, 3);
		putpixel(xc + y, yc - x, 3);
		putpixel(xc - x, yc + y, 4);
		putpixel(xc - y, yc + x, 4);
		delay(10);
	}
	outtextxy(255, 300, "Ishwar Trada");
	outtextxy(255, 310, "IU2141220162");

	getch();
	closegraph();
	return 0;
}