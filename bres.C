#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
// generalized bresenham algoeithm
int main(void)
{
    /* request auto detection */
    int gd = DETECT, gm;
    int x1 = 100, y1 = 100, x2 = 500, y2 = 300, x, y, dy, dx, swap = 0, s1, s2, temp = 0, e, i = 0;
    /* initialize graphics and local variables */
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if (x2 > x1)
        s1 = 1;
    if (x2 == x1)
        s1 = 0;
    if (x2 < x1)
        s1 = -1;
    if (y2 > y1)
        s2 = 1;
    if (y2 == y1)
        s2 = 0;
    if (y2 < y1)
        s2 = -1;
    if (dy > dx) // m>1
    {
        temp = dx;
        dx = dy;
        dy = temp;
        swap = 1;
    }
    else // m<1
        swap = 0;
    e = (2 * dy) - dx; // p0-initial decision parameter
    x = x1;
    y = y1;
    putpixel(x, y, 15);
    for (i = 0; i <= dx; i++)
    {
        putpixel(x, y, 15);
        while (e >= 0)
        {
            if (swap == 1)
                x = x + s1;
            else
                y = y + s2;
            e = e - (2 * dx);
        }
        if (swap == 1)
            y = y + s2;
        else
            x = x + s1;
        e = e + (2 * dy);
        // delay(100);
    }
    outtextxy(300, 400, "Enrollment No: IU2141220162");
    outtextxy(300, 430, "Name: Ishwar");
    getch();
    closegraph();
    return 0;
}