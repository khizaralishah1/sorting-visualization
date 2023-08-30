#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <cstdlib>
#include <time.h>
using namespace std;

int main() 
{
	srand(time(NULL));
	HDC hdc = GetDC(GetConsoleWindow());
	
	int size = 200;
	int height = 475;
	int xC = 5;
	
	int a[size];
	for(int j=0; j<size; j++)
	{
		a[j] = rand()%height;
		for(int x=0; x<a[j]; x++)
			SetPixel(hdc, j+xC, height-x, RGB(255, 255, 255));
	}
	
	int newa[size];
	
	int y=5;
	for(int i=xC; i<size+xC; i++)
	{
		SetPixel(hdc, i, y, RGB(255, 0, 0));
		HDC dc = GetDC(NULL);
		COLORREF cl = RGB(255, 255, 255);
		COLORREF color = GetPixel(dc, i, y);
		if(color == cl)
		{
			cout << "a";
			getch();
		}
		ReleaseDC(NULL, dc);
	}
	
	
	
	
	getch();
	return 0;
}
