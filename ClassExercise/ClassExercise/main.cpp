#include<graphics.h>
#include<iostream>
#include<conio.h>
#include"hacker.h"

using namespace std;

//命令符窗口大小参数
#define WIDTH 80
#define HEIGHT 35
//菜单显示字符串数量
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
		cout << "请输入账号:";
		cin >> userName;
		cout << "请输入密码:";
		inputPwd(pwd,sizeof(pwd));
		if (userName == "54hk" && !strcmp(pwd,"123456"))
		{
			break;
		}
		else
		{
			//system("pause");
			cout << "用户名或密码错误"<<endl ;
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
	/*cout << "请选择一下选项之一：" ;
	cout << "1.网站404攻击" << endl;
	cout << "2.网站篡改攻击" << endl;
	cout << "3.网站攻击记录" << endl;
	cout << "4.网站攻击修复" << endl;
	cout << "5.退出" << endl;*/
	string menu[all] = {
		 "1.网站404攻击",
		 "2.网站篡改攻击",
		"3.网站攻击记录",
		"4.网站攻击修复",
		"5.退出"
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
	printMid("--黑客攻击系统--");
	unsigned int leftSpace = (WIDTH - stringMax)/2;
	
	
	for (int i = 0; i < all; i++)
	{
		for (int j = 0; j < leftSpace; j++)
		{
			cout << ' ';
		}
		cout << menu[i]<< endl;
	}
	printMid("请输入编号进行选择:");
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
			cout << "无效输入，请重新输入:" << endl;
			system("pause");
		}
		else
		{
			break;
		}
	}
	return n;
}

//网站404
void attack404(void)
{
	char id[64] ;
	
	//攻击返回结果
	char response[4096];

	system("cls");
	printMid("--网站404攻击--");
	cout << "请输入要攻击的网站ID:";
	scanf_s("%s", id, 64);
	cout << "正在进行404攻击......" ;
	hk_404(id, response);
	//把攻击结果转换成GBK编码--936
	string retStr = UTF8ToGBK(response);
	cout << retStr<<endl;
	cout << "404攻击完成" << endl;
	system("pause");
}

//网站篡改
void webTemper(void)
{
	system("cls");
	char id[64];
	//攻击返回结果
	char response[MAXSIZE];
	string attackText;
	printMid("--网站篡改攻击--");
	cout << "请输入ID：";
	unsigned int idt = sizeof(id);
	scanf_s("%s", id,idt);

	cout << "输入要篡改的内容:";
	unsigned int idtt = sizeof(attackText);
	cin >> attackText;
	cout << "正在进行篡改攻击......";
	GBKToUTF8(attackText);
	
	hk_tamper(id,(char*)attackText.c_str(), response);
	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
	cout << "网站篡改攻击完成" << endl;
	system("pause");
}

//网站攻击记录
void attackRecord(void)
{
	system("cls");
	char id[64];

	//攻击返回结果
	char response[4096];

	system("cls");
	printMid("--网站攻击记录--");
	cout << "输入要查看的网站ID:";
	scanf_s("%s", id, 64);
	cout << "正在查看攻击记录......"<<endl;
	hk_record(id, response);
	//把攻击结果转换成GBK编码--936
	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
	
	cout << "查看网站攻击记录完成......" << endl;
	system("pause");
}

//网站攻击修复
void webRepair(void)
{
	system("cls");
	char id[64];

	//攻击返回结果
	char response[4096];

	system("cls");
	printMid("--网站攻击修复--");
	cout << "输入要修复的网站ID:";
	scanf_s("%s", id, 64);
	cout << "正在进行网站修复......";
	hk_restore(id, response);
	//把攻击结果转换成GBK编码--936
	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
	 cout << "网站修复完成" << endl;
	
	system("pause");
}

//控制终端大小
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
			cout << "无效输入，请重新输出：" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}