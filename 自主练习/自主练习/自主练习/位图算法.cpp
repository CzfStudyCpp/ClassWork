#include<iostream>
using namespace std;

void init(char* data, unsigned int len)
{
	cout << "���ڳ�ʼ����......";
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
	//��չ�ڴ�
	char* data = (char*)malloc(len);
	//ȫ��������
	memset(data, 0, len);
	//��ʼ��
	init(data, len);
	while (1)
	{
		cout << "����һ������ ��";
		int value;
		cin >> value;
		if (value == -1)
			break;
		if (check(data, len, value) == true)
		{
			cout << value << "����40�ڸ�����" << endl;
		}
		else {
			cout << value << "������40�ڸ�����" << endl;
		}

	}
}