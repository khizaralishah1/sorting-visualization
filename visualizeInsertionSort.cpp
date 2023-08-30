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
	
	int size = 950;
	int height = 50;
	
	int a[size];
	for(int j=0; j<size; j++)
	{
		a[j] = rand()%height;
	}
	
	for(int k=0; k<size; k++)
		for(int j=0; j<a[k]; j++)
			SetPixel(hdc, k, height-j, RGB(255, 255, 255));
			
	for(int i=1; i<size; i++)
	{
		static int r = 0;
		int j=i-1;
		int e = i;
		int var = a[i];
		int replace[size] = {0};
		int note = 0;
		for(; j>=0; j--)
		{
			if(a[j] > var)
			{
				for(int k=0; k<a[j]; k++)
					SetPixel(hdc, j, height-k, RGB(0, 0, 0));
				replace[note] = j;
				note++;
				a[j+1] = a[j];
				e = j;	
			}
			else
			{
				break;
			}
		}
		a[e] = var;
	
		for(int x=0; x<note; x++)
		{
				for(int j=0; j<a[replace[x]]; j++)
					SetPixel(hdc, replace[x], height-j, RGB(r%255, r%255, r%255));
		}
		r+=10;	
	}
	
	
	getch();
	return 0;
}

