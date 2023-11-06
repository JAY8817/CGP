#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    int gd = DETECT, gm, i;
    float x, y, dx, dy, steps;
    int x0, x1, y0, y1;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    setbkcolor(BLACK);

    printf("Enter x0 : ");
    scanf("%d", &x0);
    printf("Enter y0 : ");
    scanf("%d", &y0);
    printf("Enter x1 : ");
    scanf("%d", &x1);
    printf("Enter y1 : ");
    scanf("%d", &y1);

    dx = (float)(x1 - x0);
    dy = (float)(y1 - y0);
    if (dx >= dy)
    {
        steps = dx;
    }
    else
    {
        steps = dy;
    }
    dx = dx / steps;
    dy = dy / steps;
    x = x0;
    y = y0;
    i = 1;
    while (i <= steps)
    {
        putpixel(x, y, WHITE);
        x += dx;
        y += dy;
        i = i + 1;
    }
    outtextxy(250, 380, "Ishwar Trada");
    outtextxy(250, 400, "IU2141220162");
    getch();
    closegraph();
    return 0;
}