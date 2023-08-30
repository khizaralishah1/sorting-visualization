#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
using namespace std;

int partition(int *arr, int start, int end);
void swaps(int &a, int &b);
void quickSort(int *arr, int start, int end);
int n = 300;
int height = 300;
HDC hdc = GetDC(GetConsoleWindow());

int main() {
	srand(time(NULL));
	int arr[n];
	
	cout<<"\nBefore\n";
	for(int i=0; i<n; i++)
	{
		arr[i] = rand() % height;
		cout<<arr[i]<<" ";
	}
	cout<<endl;	
	cout<<"After\n";
	quickSort(arr, 0, n-1);
	
	for(int i=0; i<n; i++) 
	{
		cout<<arr[i]<<" ";
	}
	
	return 0;
}

void quickSort(int *arr, int start, int end) 
{
	for(int q=0; q<=n-1; q++)
		for(int y=0; y<arr[q]; y++)
			SetPixel(hdc, q, 450-y, RGB(255, 255, 255));
	//getch();
	system("cls");
	if(start < end) 
	{
		int pIndex = partition(arr, start, end);
		quickSort(arr, start, pIndex-1);
		quickSort(arr, pIndex+1, end);
	}
	
}
int partition(int *arr, int start, int end) {
	int pivot = arr[end];
	int pIndex = start;
	for(int i=start; i<=end-1; i++) {
		if(arr[i] <= pivot) {
			swaps(arr[i], arr[pIndex]);
			pIndex++;
		}
	}
	
	swaps(arr[pIndex], arr[end]);
	return pIndex;
}

void swaps(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}


