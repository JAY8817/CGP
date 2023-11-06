#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int x, y;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C://turboc3//bgi");

   setcolor(getmaxcolor());
   x = getmaxx();
   y = getmaxy();

   /* draw a mountain */
   setfillstyle(SOLID_FILL, 6);
   line(0, y / 2, x, y / 2);
   line(0, y / 2, x / 8, 0);
   line(x / 8, 0, x / 4, y / 2);
   floodfill(x / 8, (y / 2) - 10, getmaxcolor());
   line(x / 4, y / 2, (3 * x) / 8, 0);
   line((3 * x) / 8, 0, x / 2, y / 2);
   floodfill((3 * x) / 8, (y / 2) - 10, getmaxcolor());
   line(x / 2, y / 2, (5 * x) / 8, 0);
   line((5 * x) / 8, 0, (3 * x) / 4, y / 2);
   floodfill((5 * x) / 8, (y / 2) - 10, getmaxcolor());
   line((3 * x) / 4, y / 2, (7 * x) / 8, 0);
   line((7 * x) / 8, 0, x, y / 2);
   floodfill((7 * x) / 8, (y / 2) - 10, getmaxcolor());
   /* draw a sun */
   setfillstyle(SOLID_FILL, 14);
   circle(x / 2, 40, 30);
   floodfill(x / 2, 40, getmaxcolor());

   /* fill colour in sky */
   setfillstyle(SOLID_FILL, 9);
   floodfill(5, 5, getmaxcolor());
   floodfill(x / 4, 5, getmaxcolor());
   floodfill(x / 2, 5, getmaxcolor());
   floodfill((3 * x) / 4, 10, getmaxcolor());
   floodfill(x - 5, 5, getmaxcolor());

   /* draw a river */
   setfillstyle(SOLID_FILL, 3);
   line(x / 2, y / 2, (3 * x) / 4, y);
   line((3 * x) / 4, y / 2, x, y);
   floodfill((x / 2) + 10, (y / 2) + 10, getmaxcolor());

   /* fill colour in grass */
   setfillstyle(SOLID_FILL, 10);
   floodfill(5, y - 5, getmaxcolor());
   floodfill(((3 * x) / 4) + 5, (y / 2) + 5, getmaxcolor());

   /* clean up */
   getch();
   closegraph();
   return 0;
}
