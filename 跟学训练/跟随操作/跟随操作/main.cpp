#include<iostream>
#include<Windows.h>
#include<fstream>
#include<iomanip>
using namespace std;

inline int add(int a, int b)
{
	cout << "�����������ӷ�" << endl;
	return a + b ;
}

//int add(int a, int b)
//{
//	cout << "�����������ӷ�" << endl;
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
	cout << "�����" << n << "��" << endl;
	fab(n + 1);
	cout << "�˳���" << n << "��" << endl;
		
}
float add(float a, float b)
{
	cout << "�������������ӷ�" << endl;
	return a + b;
}


int main(void)
{
	int rows  ;
	int cols  ;
	int n;
	cin >> n;
	rows = cols = n;
	int** array = new int* [rows]; // ����ָ��һά�����ָ��

	for (int i = 0; i < rows; i++) {
		array[i] = new int[cols]; // ����ÿһ�е�һά����
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
