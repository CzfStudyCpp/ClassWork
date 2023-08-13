#include<iostream>
#include<Windows.h>
#include<fstream>
#include<iomanip>
using namespace std;

inline int add(int a, int b)
{
	cout << "三个整形数加法" << endl;
	return a + b ;
}

//int add(int a, int b)
//{
//	cout << "两个整型数加法" << endl;
//	return a + b;
//}

void printArr(int arr[3][4])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j< 4; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void fab(int n)
{
	if (n>5)
	{
		return;
	}
	cout << "进入第" << n << "层" << endl;
	fab(n + 1);
	cout << "退出第" << n << "层" << endl;
		
}
float add(float a, float b)
{
	cout << "两个浮点型数加法" << endl;
	return a + b;
}


int main(void)
{
	int rows  ;
	int cols  ;
	int n;
	cin >> n;
	rows = cols = n;
	int** array = new int* [rows]; // 创建指向一维数组的指针

	for (int i = 0; i < rows; i++) {
		array[i] = new int[cols]; // 创建每一行的一维数组
		for (int j = 0; j <= i; j++) {
			if (i == 0 || i == 1)
			{
				array[i][j] = 1;
			}
			else if (i > 1 && (j == 0 || j == i))
			{
				array[i][j] = 1;
			}
			else
			{
				array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
			}
		}
	}
	for (int i = 0; i < rows; i++)
	{
		
			cout <<setw((rows-i-1)*2) <<array[i][0];
		
		for (int k = 1; k <= i; k++)
		{
			cout <<setw(4)<< array[i][k] ;
		}
		cout << endl;
	}

	std::system("pause");
	for (int i = 0; i < rows; i++)
	{
		delete[]array[i];
	}
	delete[]array;
	return 0;
	
	
	
}
