#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <math.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int x, y, th = 0, th1 = 0, th2 = 90, th3 = 150;
   int r = 100;
   float rd, rd1;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C://turboc3//bgi");

   x = getmaxx() / 2;
   y = getmaxy() / 2;
   setcolor(getmaxcolor());

   while (!kbhit())
   {
      cleardevice();
      /* draw the circle */
      setfillstyle(SOLID_FILL, 9);
      circle(x, y, r + 30);
      floodfill(x, y, getmaxcolor());
      setfillstyle(SOLID_FILL, 7);
      circle(x, y, r);
      floodfill(x, y, getmaxcolor());
      circle(x, y, 3);

      /*************************************************
            Numbers in clock
      ************************************************/
      rd1 = th1 * 3.14 / 180;
      outtextxy(x + (r + 10) * cos(rd1), y + (r + 10) * sin(rd1), "3");
      rd1 = (th1 + 30) * 3.14 / 180;
      outtextxy(x + (r + 10) * cos(rd1), y + (r + 10) * sin(rd1), "4");
      rd1 = (th1 + 60) * 3.14 / 180;
      outtextxy(x + (r + 10) * cos(rd1), y + (r + 10) * sin(rd1), "5");
      rd1 = (th1 + 90) * 3.14 / 180;
      outtextxy(x + (r + 10) * cos(rd1), y + (r + 10) * sin(rd1), "6");
      rd1 = (th1 + 120) * 3.14 / 180;
      outtextxy(x + (r + 10) * cos(rd1), y + (r + 10) * sin(rd1), "7");
      rd1 = (th1 + 150) * 3.14 / 180;
      outtextxy(x + (r + 10) * cos(rd1), y + (r + 10) * sin(rd1), "8");
      rd1 = (th1 + 180) * 3.14 / 180;
      outtextxy((x - 5) + (r + 10) * cos(rd1), y + (r + 10) * sin(rd1), "9");
      rd1 = (th1 + 210) * 3.14 / 180;
      outtextxy((x - 10) + (r + 10) * cos(rd1), y + (r + 10) * sin(rd1), "10");
      rd1 = (th1 + 240) * 3.14 / 180;
      outtextxy((x - 10) + (r + 10) * cos(rd1), y + (r + 10) * sin(rd1), "11");
      rd1 = (th1 + 270) * 3.14 / 180;
      outtextxy((x - 15) + (r + 10) * cos(rd1), y + (r + 10) * sin(rd1), "12");
      rd1 = (th1 + 300) * 3.14 / 180;
      outtextxy(x + (r + 10) * cos(rd1), y + (r + 10) * sin(rd1), "1");
      rd1 = (th1 + 330) * 3.14 / 180;
      outtextxy(x + (r + 10) * cos(rd1), y + (r + 10) * sin(rd1), "2");

      /* Second Kanto*/
      setcolor(BLUE);
      rd = th2 * 3.14 / 180;
      line(x, y, x + (r - 25) * cos(rd), y + (r - 25) * sin(rd));
      /* Minute Kanto */
      setcolor(BLACK);
      rd = th * 3.14 / 180;
      line(x, y, x + (r - 10) * cos(rd), y + (r - 10) * sin(rd));
      /* Hour Kanto */
      setcolor(RED);
      rd = th3 * 3.14 / 180;
      line(x, y, x + (r - 40) * cos(rd), y + (r - 40) * sin(rd));
      th = th + 1;
      setcolor(getmaxcolor());
      outtextxy(270, 390, "Ishwar Trada");
      outtextxy(270, 410, "IU2141220162");

      delay(100);
   }
   /* clean up */
   getch();
   closegraph();
   return 0;
}
