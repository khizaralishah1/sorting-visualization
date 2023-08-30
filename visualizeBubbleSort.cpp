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
	int height = 300;
	
	int a[size];
	for(int j=0; j<size; j++)
	{
		a[j] = rand()%height;
	}
	
	
		for(int k=0; k<size; k++)
			for(int j=0; j<a[k]; j++)
				SetPixel(hdc, k, height-j, RGB(255, 255, 255));
		
	//bubble sort alg
	for(int i=0; i<size; i++)
	{
		for(int j=1; j<size-i; j++)
		{
			if(a[j-1] > a[j])
			{
				//black out of j-1 and j
//				for(int x=0; x<a[j-1]; x++)
//				{	
//					SetPixel(hdc, j-1, height-x, RGB(0, 0, 0));
//				}
//				for(int x=0; x<a[j]; x++)
//					SetPixel(hdc, j, height-x, RGB(0, 0, 0));
//				
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				//show new j-1 and j
//				for(int x=0; x<a[j-1]; x++)
//				{
//					SetPixel(hdc, j-1, height-x, RGB(255, 0, 0));
//				}
//				for(int x=0; x<a[j]; x++)
//				{
//					SetPixel(hdc, j, height-x, RGB(255, 0, 0));
//				}
				//getch();
			}
		}
		if(i%10 == 0)
		{
			system("cls");
			for(int k=0; k<size; k++)
			for(int j=0; j<a[k]; j++)
				SetPixel(hdc, k, height-j, RGB(255, 255, 255));
		}
		
		//getch();
	}
		
	
	
	
	getch();
	return 0;
}

