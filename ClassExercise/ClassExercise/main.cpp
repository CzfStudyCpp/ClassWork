#include<graphics.h>
#include<iostream>
#include<conio.h>
#include"hacker.h"

using namespace std;

//��������ڴ�С����
#define WIDTH 80
#define HEIGHT 35
//�˵���ʾ�ַ�������
const int all = 5;

void inputPwd(char pwd[], size_t size)
{
	char c;
	unsigned int i = 0;
	while (i<size-1)
	{
		c = _getch();
		if (c == '\r')
		{
			pwd[i] = '\0';
			break;
		}
		else if (i == size - 1)
		{
			pwd[i] = '\0';
		}
		else
		{
			pwd[i] = c;
			i++;
			cout << '*';
		}
	}
}
void login(void)
{
	string userName;
	char pwd[17];
	while (1)
	{
		system("cls");
		cout << "�������˺�:";
		cin >> userName;
		cout << "����������:";
		inputPwd(pwd,sizeof(pwd));
		if (userName == "54hk" && !strcmp(pwd,"123456"))
		{
			break;
		}
		else
		{
			//system("pause");
			cout << "�û������������"<<endl ;
			system("pause");
		}
	}
}

void printMid(string msg)
{
	for (int i = 0; i < (WIDTH - sizeof(msg)) / 2; i++)
	{
		cout << " ";
	}
	cout << msg <<endl;
}
void displayMenu(void)
{
	system("cls");
	/*cout << "��ѡ��һ��ѡ��֮һ��" ;
	cout << "1.��վ404����" << endl;
	cout << "2.��վ�۸Ĺ���" << endl;
	cout << "3.��վ������¼" << endl;
	cout << "4.��վ�����޸�" << endl;
	cout << "5.�˳�" << endl;*/
	string menu[all] = {
		 "1.��վ404����",
		 "2.��վ�۸Ĺ���",
		"3.��վ������¼",
		"4.��վ�����޸�",
		"5.�˳�"
	};
	size_t stringLong = 0;
	unsigned int stringMax = 0;
	for (int i = 0; i < all; i++)
	{
		stringLong = sizeof(menu[i]);
		if (stringLong > stringMax)
		{
			stringMax = stringLong;
		}
	}
	printMid("--�ڿ͹���ϵͳ--");
	unsigned int leftSpace = (WIDTH - stringMax)/2;
	
	
	for (int i = 0; i < all; i++)
	{
		for (int j = 0; j < leftSpace; j++)
		{
			cout << ' ';
		}
		cout << menu[i]<< endl;
	}
	printMid("�������Ž���ѡ��:");
}

int menuSelect(void)
{
	int n = 0;
	while (1)
	{
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout << "��Ч���룬����������:" << endl;
			system("pause");
		}
		else
		{
			break;
		}
	}
	return n;
}

//��վ404
void attack404(void)
{
	char id[64] ;
	
	//�������ؽ��
	char response[4096];

	system("cls");
	printMid("--��վ404����--");
	cout << "������Ҫ��������վID:";
	scanf_s("%s", id, 64);
	cout << "���ڽ���404����......" ;
	hk_404(id, response);
	//�ѹ������ת����GBK����--936
	string retStr = UTF8ToGBK(response);
	cout << retStr<<endl;
	cout << "404�������" << endl;
	system("pause");
}

//��վ�۸�
void webTemper(void)
{
	system("cls");
	char id[64];
	//�������ؽ��
	char response[MAXSIZE];
	string attackText;
	printMid("--��վ�۸Ĺ���--");
	cout << "������ID��";
	unsigned int idt = sizeof(id);
	scanf_s("%s", id,idt);

	cout << "����Ҫ�۸ĵ�����:";
	unsigned int idtt = sizeof(attackText);
	cin >> attackText;
	cout << "���ڽ��д۸Ĺ���......";
	GBKToUTF8(attackText);
	
	hk_tamper(id,(char*)attackText.c_str(), response);
	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
	cout << "��վ�۸Ĺ������" << endl;
	system("pause");
}

//��վ������¼
void attackRecord(void)
{
	system("cls");
	char id[64];

	//�������ؽ��
	char response[4096];

	system("cls");
	printMid("--��վ������¼--");
	cout << "����Ҫ�鿴����վID:";
	scanf_s("%s", id, 64);
	cout << "���ڲ鿴������¼......"<<endl;
	hk_record(id, response);
	//�ѹ������ת����GBK����--936
	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
	
	cout << "�鿴��վ������¼���......" << endl;
	system("pause");
}

//��վ�����޸�
void webRepair(void)
{
	system("cls");
	char id[64];

	//�������ؽ��
	char response[4096];

	system("cls");
	printMid("--��վ�����޸�--");
	cout << "����Ҫ�޸�����վID:";
	scanf_s("%s", id, 64);
	cout << "���ڽ�����վ�޸�......";
	hk_restore(id, response);
	//�ѹ������ת����GBK����--936
	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
	 cout << "��վ�޸����" << endl;
	
	system("pause");
}

//�����ն˴�С
void init(void)
{
	
	char cmd[128];
	sprintf_s(cmd, "mode con cols=%d lines=%d", WIDTH, HEIGHT);
	system(cmd);
}
int main(void)
{
	init();
	login();
	while (1)
	{
		displayMenu();
		int numbering = menuSelect();
		switch (numbering)
		{
		case 1:
			attack404();
			break;
		case 2:
			webTemper();
			break;
		case 3:
			attackRecord();
			break;
		case 4:
			webRepair();
			break;
		case 5:
			return 0;
		default:
			cout << "��Ч���룬�����������" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}