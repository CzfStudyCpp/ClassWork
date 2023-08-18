#include<iostream>
#include<string.h>
using namespace std;
void reverse(unsigned char* arr)
{
	unsigned int count = strlen((char*)arr);
	cout << count << endl;
	unsigned char temp[100];

	unsigned char* p1 = arr;
	unsigned char* p2 = temp + count ;
	*p2-- = 0;
	unsigned int counter = count / 2;
	while (*p1)
	{
		if (*p1 < 0x80)
		{
			*p2-- = *p1++;
		}
		else
		{
			*(p2 - 1) = *p1++;
			*p2 = *p1++;
			p2 -= 2;
		}
	}
	for (int i = 0; i < count; i++)
		arr[i] = temp[i];
	
}
int main()
{
	unsigned char arr[] = { "话a发啊f的给g看e" };

	//cout << arr << endl;
	reverse(arr);
	cout << arr;
}