#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int x, a, y, i = 0, th = 0;
   int r = 70;
   float rad1, rad2, rad3, rad4;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C://TURBOC3//bgi");
   x = 100;
   y = getmaxy() / 2;
   setcolor(getmaxcolor());

   /* draw the circle */
   while (!kbhit())
   {
      cleardevice();

      circle(x, y, r + 20);
      setfillstyle(SOLID_FILL, 9);
      floodfill(x, y, getmaxcolor());
      circle(x, y, r);
      setfillstyle(SOLID_FILL, 10);
      floodfill(x, y, getmaxcolor());

      rad1 = (th * 3.14) / 180;
      rad2 = ((th + 45) * 3.14) / 180;
      rad3 = ((th + 90) * 3.14) / 180;
      rad4 = ((th + 135) * 3.14) / 180;
      line(x, y, x + r * sin(rad1), y + r * cos(rad1));
      line(x, y, x - r * sin(rad1), y - r * cos(rad1));
      line(x, y, x + r * sin(rad2), y + r * cos(rad2));
      line(x, y, x - r * sin(rad2), y - r * cos(rad2));
      line(x, y, x + r * sin(rad3), y + r * cos(rad3));
      line(x, y, x - r * sin(rad3), y - r * cos(rad3));
      line(x, y, x + r * sin(rad4), y + r * cos(rad4));
      line(x, y, x - r * sin(rad4), y - r * cos(rad4));

      i++;
      x = x + i;
      th = th - 15;

      outtextxy(300, 380, "Ishwar  Trada");
      outtextxy(300, 400, "IU2141220162");
      delay(500);
   }
   /* clean up */
   getch();
   closegraph();
   return 0;
}
