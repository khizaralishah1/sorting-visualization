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
	
	int size = 500;
	
	int a[size];
	for(int j=0; j<size; j++)
	{
		a[j] = rand()%450;
	}
	
	
		for(int k=0; k<size; k++)
			for(int j=0; j<a[k]; j++)
				SetPixel(hdc, k, 450-j, RGB(255, 255, 255));
		
		
	
	
	
	for(int i=0; i<size; i++)
	{
		int smallestLoc = i;
		for(int j=i+1; j<size; j++)
		{
			if(a[j] < a[smallestLoc])
			{
				smallestLoc = j;
			}
		}	
		for(int p=0; p<a[smallestLoc]; p++)
		{
			SetPixel(hdc, smallestLoc, 450-p, RGB(0, 0, 0));
		}
		for(int l=0;l<a[i]; l++)
		{
			SetPixel(hdc, i, 450-l, RGB(0, 0, 0));
		}
		
		int temp = a[smallestLoc];
		a[smallestLoc] = a[i];
		a[i] = temp;
		
		for(int p=0; p<a[i]; p++)
		{
			SetPixel(hdc, i, 450-p, RGB(255, 255, 255));
		}
		for(int p=0; p<a[smallestLoc]; p++)
		{
			SetPixel(hdc, smallestLoc, 450-p, RGB(255, 255, 255));
		}
		//getch();
	}
	getch();
	return 0;
}

