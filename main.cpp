#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

struct point
{
float x;
float y;
};


const float PI = 3.14159265359;

float input_value(const char * invitation);
float radian_from_degress(float degrees);
int sign(float number);
void zero_square(float edge, float angle, point * square);
void move_square(const point destination, point * square);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Программа определяет координаты вершин квадрата по:\n"
    " - координатам центра квадрата\n"
    " - длине ребра квадрата\n"
    " - углу поворота в градусах относительно горизонта\n";

    point square_center;
    float square_edge;
    float square_angle;
    point square[4];

    cout << endl;

    square_center.x = input_value("Введите координату X центра квадрата: ");
    square_center.y = input_value("Введите координату Y центра квадрата: ");
    square_edge = input_value("Введите длину ребра квадрата: ");
    square_angle = input_value("Введите Угол поворота квадрата в градусах: ");

    square_angle = radian_from_degress(square_angle);
    zero_square(square_edge, square_angle, square);
    move_square(square_center, square);

    char letter[5] = { 'A', 'B', 'C', 'D' };
    cout << endl;
    cout << "Координаты вершин заданного квадрата: \n";
    for(int i = 0; i < 4; i++)
    {
        cout.precision(2);
        cout << letter[i] << "(x,y) : (" << fixed << square[i].x
        << "," << fixed << square[i].y << ")\n";
    }

    cout << "Для выхода нажмите <Enter>.. ";
    fflush(stdin);
    while (cin.get() != '\n');
    return 0;
}

int sign(float number)
{
    int reply =0;
    if(number > 0)
        reply = 1;
    else if (number < 0)
        reply = - 1;
    return reply;
}

float input_value(const char * invitation)
{
    float reply;
    cout << invitation;
    while (!(cin >> reply))
    {
        cin.clear();
        while (cin.get()!= '\n');
        cout << "Ввод некоректен, введите число:";
    }
    return reply;
}

void zero_square(float edge, float angle, point * square)
{
    const float spa[4] = { PI/4, -PI/4, -3*PI/4, 3*PI/4 };
    float half_edge = edge/2;

    for(int i = 0; i < 4; i++)
    {
        square[i].x = sign(cos(spa[i]))*half_edge;
        square[i].y = sign(sin(spa[i]))*half_edge;

    }

    float pd = sqrt(square[0].x * square[0].x + square[0].y * square[0].y);
    for(int i = 0; i < 4; i++)
    {
        square[i].x = cos (spa[i]+angle)*pd;
        square[i].y = sin (spa[i]+angle)*pd;
    }
}

void move_square(const point destination, point * square)
{
    for(int i = 0; i < 4; i++)
    {
        square[i].x += destination.x;
        square[i].y += destination.y;
    }
}

float radian_from_degress(float degress)
{
    return degress * PI/180;
}
