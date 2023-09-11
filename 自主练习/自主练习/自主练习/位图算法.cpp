#include<iostream>
using namespace std;

void init(char* data, unsigned int len)
{
	cout << "正在初始化中......";
	unsigned int n = len * 8;
	for (unsigned int i = 0; i < n; i++)
	{
		if (i % 3 == 0)
		{
			char* p = data + i / 8;
			*p = *p | (1 << (i % 8));
		}
	}
}

bool check(char* data, int len, int value)
{
	char* p = data + value / 8;
	bool ret = *p & (1 << (value % 8));
	return ret;
}
int main()
{
	unsigned int n = 4000000000;
	unsigned int len = n / 8 + 1;
	//拓展内存
	char* data = (char*)malloc(len);
	//全部归清零
	memset(data, 0, len);
	//初始化
	init(data, len);
	while (1)
	{
		cout << "输入一个整数 ：";
		int value;
		cin >> value;
		if (value == -1)
			break;
		if (check(data, len, value) == true)
		{
			cout << value << "在这40亿个数中" << endl;
		}
		else {
			cout << value << "不在这40亿个数中" << endl;
		}

	}
}