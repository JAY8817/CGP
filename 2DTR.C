#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>
typedef struct
{
    int x;
    int y;
} Point;
void drawSquare(Point vertices[4])
{   int i;
    for (i = 0; i < 4; i++)
    {
	line(vertices[i].x, vertices[i].y, vertices[(i + 1) % 4].x, vertices[(i + 1) % 4].y);
    }
}
void translate(Point vertices[4], int dx, int dy)
{    int i;
    for (i = 0; i < 4; i++)
    {
	vertices[i].x += dx;
	vertices[i].y += dy;
    }
}
void scale(Point vertices[4], float sx, float sy)
{    int i;
    for (i = 0; i < 4; i++)
    {
	vertices[i].x = (int)(vertices[i].x * sx);
	vertices[i].y = (int)(vertices[i].y * sy);
    }
}
void rotate(Point vertices[4], float angle)
{
    float radians = angle * M_PI / 180.0;
    int cx = (vertices[0].x + vertices[2].x) / 2; // Center of the square
    int cy = (vertices[0].y + vertices[2].y) / 2;
    int i;
    for (i = 0; i < 4; i++)
    {
	int x = vertices[i].x - cx;
	int y = vertices[i].y - cy;
	vertices[i].x = cx + (int)(x * cos(radians) - y * sin(radians));
	vertices[i].y = cy + (int)(x * sin(radians) + y * cos(radians));
    }
}
int main()
{
    int gd = DETECT, gm;
    int choice;
    Point vertices[] = {
	{100, 100},
	{200, 100},
	{200, 200},
	{100, 200}};

    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    drawSquare(vertices);

    printf("Select transformation:\n");
    printf("1. Translation\n");
    printf("2. Scaling\n");
    printf("3. Rotation\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        int dx, dy;
        printf("Enter translation values (dx dy): ");
        scanf("%d %d", &dx, &dy);
        translate(vertices, dx, dy);
        break;
    }
    case 2:
    {
        float sx, sy;
        printf("Enter scaling factors (sx sy): ");
        scanf("%f %f", &sx, &sy);
        scale(vertices, sx, sy);
        break;
    }
    case 3:
    {
        float angle;
        printf("Enter rotation angle (degrees): ");
        scanf("%f", &angle);
        rotate(vertices, angle);
        break;
    }
    default:
        printf("Invalid choice\n");
        closegraph();
        return 1;
    }
    drawSquare(vertices);
    outtextxy(400, 380, "IU2141220162");
    outtextxy(400, 400, "Ishwar Trada");
    getch();
    closegraph();
    return 0;
}