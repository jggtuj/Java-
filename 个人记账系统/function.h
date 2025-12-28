#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma once
#define num_acc 5          //支持的最大账户数量
#define num_data 50        //支持的最大记录条数数量
#define length 100         //支持的最大备注长度

void registe();
void enroll();
void second_menu(int what_acc);
void manage_accounts(int what_acc);
int devide(int j,char name_registe[20], char code_registe[20]);
void add_income(int what_acc);
void add_pay(int what_acc);
void look_all(int what_acc);
void revise_choose(int what_acc);
void revise_income(int what_acc, int import);
void revise_pay(int what_acc, int import);
void detel(int what_acc);
void detel_income(int what_acc, int import);
void detel_pay(int what_acc, int import);
void statistics_menu(int what_acc);
void statistics(int what_acc);
void remainder(int what_acc);
void print_pay(int what_acc,int i);
void print_type_by_sign(int code);

typedef struct  //收入信息
{
	int money;
	char date[30];
	char remarks[length];
}Income;

typedef struct  //支出信息
{
	int money;
	char date[30];
	char remarks[length];
	int type;
}Pay;

typedef struct              //存储收入和支出信息的结构体 的数组 的结构体
{
	Income income[num_data];
	Pay pay[num_data];
}Data;

typedef struct              //存储名称和密码的结构体
{
	char name[30];
	char code[30];
}Acc_stru;

int* account_num_p;               //记录账号数量的计数器指针
Acc_stru* All_acc_name_code_p;    //结构体数组的指针

int income_data[num_acc] = { 0 }; //记录信息数量的计数器 的数组
int pay_data[num_acc] = { 0 };

Data* All_data_p;                 //收入和支出信息结构体 的数组 的指针

void main_menu()           //主菜单
{
	printf("=== 主菜单 ===\n");
	printf("1. 用户登录\n");
	printf("2. 用户注册\n");
	printf("3. 退出程序\n");
	
	int a = 0;
A:
	printf("请选择操作:");
	scanf_s("%d", &a);
	while (getchar() != '\n');//
	if (a != 1 && a != 2 && a != 3)
	{
		printf("请输入有效数字\n");
		goto A;
	}
	if (a == 1)          
	{
		if (*account_num_p != 0)
		{
			registe();
		}
		else
		{
			printf("请先注册账号!\n");
			goto A;
		}
	}
	else if (a == 2)
	{
		enroll();
	}
	else if (a == 3)
	{
		exit(0);
	}
}

void registe()           //登录
{
	printf("\n");
	printf("=== 用户登录 ===\n");
	printf("请输入用户名和密码\n");

	char name_registe[20] = { 0 };            //存储用户的输入值
	char code_registe[20] = { 0 };

	B:
	printf("用户名:");
	scanf_s("%19[^\n]",name_registe, 20);
	while (getchar() != '\n');

	printf("密码:");
	scanf_s("%19[^\n]",code_registe, 20);
	while (getchar() != '\n');

	int mistake = 1;
	for (int j = 0; j < *account_num_p; j++)
	{
		if (devide(j, name_registe,code_registe))       //用devide函数比对所有注册账号的名称与密码
		{                                               //成功则登录并返回what_acc(标志是第几个账号)
			printf("登录成功!欢迎%s\n", name_registe);
			mistake = 0;
			int what_acc = j;
			second_menu(what_acc);
		}
	}
	if (mistake)
	{
		printf("账号名或密码错误,请重新输入\n");
		goto B;
	}
}

void enroll()
{
	printf("\n");
	Acc_stru acc_name_code;
	printf("=== 用户注册 ===\n");
	printf("请输入用户名和密码\n");

	printf("用户名:");
	scanf_s("%19[^\n]", acc_name_code.name,20);
	while (getchar() != '\n');

	printf("密码:");
	scanf_s("%19[^\n]", acc_name_code.code,20);  //
	while (getchar() != '\n');

	All_acc_name_code_p[*account_num_p] = acc_name_code;//通过指针将名称和密码存储到结构体数组的结构体上
	
	income_data[*account_num_p] = 0;             //初始化信息计数器
	pay_data[*account_num_p] = 0;

	(*account_num_p)++;
	printf("账号注册成功!\n");
	printf("\n");
	main_menu();
}

void second_menu(int what_acc)		//二级菜单
{
	printf("\n");
	printf("=== 用户菜单 ===\n");
	printf("1. 记账管理\n");
	printf("2. 统计查询\n");
	printf("3. 返回上级\n");
	printf("请选择操作:");
	int a;
	A:
	scanf_s("%d", &a);
	while (getchar() != '\n');//
	if (a != 1 && a != 2 && a != 3)
	{
		printf("请输入有效数字\n");
		goto A;
	}
	if (a == 1)
	{
		manage_accounts(what_acc);
	}
	else if (a == 2)
	{
		statistics_menu(what_acc);
	}
	else if (a == 3)
	{
		printf("\n");
		main_menu();
	}
}

void manage_accounts(int what_acc)     //三级菜单
{
	printf("\n");
	printf("=== 记账管理 ===\n");
	printf("1. 添加收入\n");
	printf("2. 添加支出\n");
	printf("3. 查看所有记录\n");
	printf("4. 修改记录\n");
	printf("5. 删除记录\n");
	printf("6. 返回上级\n");
	printf("请选择操作:");
	int a;
	A:
	scanf_s("%d", &a);
	while (getchar() != '\n');
	if (a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6)
	{
		printf("请输入有效数字\n");
		goto A;
	}
	if (a == 1)
	{
		add_income(what_acc);
	}
	else if (a == 2)
	{
		add_pay(what_acc);
	}
	else if (a == 3)
	{
		look_all(what_acc);
	}
	else if (a == 4)
	{
		revise_choose(what_acc);
	}
	else if (a == 5)
	{ 
		detel(what_acc);
	}
	else if (a == 6)
	{
		second_menu(what_acc);
	}
}

int devide(int j, char name_registe[20], char code_registe[20])
{
	int a = 1;               //用来比对密码和名称的函数
	int b = 1;
	for (int i = 0; i < 20; i++)
	{
		if(All_acc_name_code_p[j].name[i] != name_registe[i])      //比对名称
		{ 
			a = 0;
			break;
		}
		if (All_acc_name_code_p[j].name[i] == name_registe[i] && name_registe[i] =='\0')
		{
			break;
		}
	}                   
	for (int i = 0; i < 20; i++)
	{
		if (All_acc_name_code_p[j].code[i] != code_registe[i])		 //比对密码
		{
			b = 0;
			break;
		}
		if (All_acc_name_code_p[j].code[i] == code_registe[i] && code_registe[i] == '\0')
		{
			break;
		}
	}
	return a * b;            //只有名称和密码同时正确才可输出True
}

void add_income(int what_acc)
{
	Income income;
	printf("请输入收入的金额:");
	scanf_s("%d", &income.money);

	printf("请输入日期:");
	scanf_s("%s",&income.date,100);

	printf("请输入备注:");
	scanf_s("%s", &income.remarks,100);

	All_data_p[what_acc].income[income_data[what_acc]] = income;
	income_data[what_acc]++;             //通过指针赋值
	printf("收入添加成功!\n");
	manage_accounts(what_acc);
}

void add_pay(int what_acc)
{
	Pay pay;

	int import = 0;
	while (import <= 0 || import > 6)
	{
		printf("1.娱乐 2.购物 3.餐饮 4.服务 5.教育 6.其他\n");
		printf("请选择支出的类型:");
		scanf_s("%d", &import);
		if (import <= 0 || import > 6)      //通过存储数字来间接存储类型
		{
			printf("没有这个类型!\n");
			while (getchar() != '\n');
		}
		pay.type = import;
	}

	printf("请输入支出的金额:");
	scanf_s("%d", &pay.money);

	printf("请输入日期:");
	scanf_s("%s", &pay.date, 100);

	printf("请输入备注:");
	scanf_s("%s", &pay.remarks, 100);

	All_data_p[what_acc].pay[pay_data[what_acc]] = pay;//通过指针赋值
	pay_data[what_acc]++;
	printf("支出添加成功!\n");
	manage_accounts(what_acc);
}

void look_all(int what_acc)//打印统计表
{ 
	if (income_data[what_acc] == 0 && pay_data[what_acc] == 0)
	{
		printf("还没有任何记录信息\n");
		manage_accounts(what_acc);
	}
	printf("类型  金额  日期     备注\n");
	for (int i = 0; i < income_data[what_acc]; i++)
	{
		printf("收入 +%d ", All_data_p[what_acc].income[i].money);
		printf("%s ", All_data_p[what_acc].income[i].date);
		printf("%s\n", All_data_p[what_acc].income[i].remarks);
	}
	for (int j = 0; j < pay_data[what_acc]; j++)
	{
		print_pay(what_acc, j);					//传入数值来打印支出的类型
		printf("-%d ", All_data_p[what_acc].pay[j].money);
		printf("%s ", All_data_p[what_acc].pay[j].date);
		printf("%s\n", All_data_p[what_acc].pay[j].remarks);
	}
	char import = '0';
	while (import != '1')
	{
		printf("输入1返回:");
		scanf_s("%c", &import,1);
		while (getchar() != '\n');
		if (import == '1')
		{
			manage_accounts(what_acc);
		}
	}
}

void revise_choose(int what_acc)//让用户选择修改收入还是支出并再次打印统计表
{
	if (income_data[what_acc] == 0 && pay_data[what_acc] == 0)
	{
		printf("还没有任何记录信息可以修改\n");
		manage_accounts(what_acc);
	}
	int import;
	A:
	printf("1.收入 2.支出\n");
	printf("请选择要修改收入还是支出:");
	scanf_s("%d", &import);
	if (import == 1)
	{
		if (income_data[what_acc] == 0)
		{
			printf("还没有任何收入记录可以修改\n");
			goto A;
		}
		printf("  类型  金额  日期     备注\n");
		for (int i = 0; i < income_data[what_acc]; i++)//
		{
			printf("%d.收入 +%d ", i + 1, All_data_p[what_acc].income[i].money);
			printf("%s ", All_data_p[what_acc].income[i].date);
			printf("%s\n", All_data_p[what_acc].income[i].remarks);
		}
		printf("请选择要修改的编号:");
		int import1;
		scanf_s("%d", &import1);
		import1--;
		revise_income(what_acc, import1);
	}
	if (import == 2)
	{
		if (pay_data[what_acc] == 0)
		{
			printf("还没有任何支出记录可以修改\n");
			goto A;
		}
		printf("  类型  金额  日期     备注\n");
		for (int j = 0; j < pay_data[what_acc]; j++)
		{
			printf("%d.", j + 1);
			print_pay(what_acc,j);			//传入数值来打印支出的类型
			printf("-%d ", All_data_p[what_acc].pay[j].money);
			printf("%s ", All_data_p[what_acc].pay[j].date);
			printf("%s\n", All_data_p[what_acc].pay[j].remarks);
		} 
		printf("请选择要修改的编号:");
		int import2;
		scanf_s("%d", &import2);
		import2--;
		revise_pay(what_acc, import2);
	}
}

void revise_income(int what_acc,int import)//修改收入
{ 
	Income income;
	printf("请输入修改的金额:");
	scanf_s("%d", &income.money);

	printf("请输入修改的日期:");
	scanf_s("%s", &income.date, 100);

	printf("请输入修改的备注:");
	scanf_s("%s", &income.remarks, 100);

	All_data_p[what_acc].income[import] = income;
	printf("收入修改成功!\n");
	manage_accounts(what_acc);
}

void revise_pay(int what_acc, int import)//修改支出
{
	Pay pay;

	int a;
	printf("1.娱乐 2.购物 3.餐饮 4.服务 5.教育 6.其他\n");
	printf("请选择修改的类型:");
	scanf_s("%d", &a);
	if (a <= 0 || a > 6)
	{
		printf("没有这个类型!");
	}
	pay.type = a;

	printf("请输入修改的金额:");
	scanf_s("%d", &pay.money);

	printf("请输入修改的日期:");
	scanf_s("%s", &pay.date, 100);

	printf("请输入修改的备注:");
	scanf_s("%s", &pay.remarks, 100);

	All_data_p[what_acc].pay[import] = pay;
	printf("支出修改成功!\n");
	manage_accounts(what_acc);
}

void detel(int what_acc)//让用户选择删除收入还是支出并再次打印统计表
{
	if (income_data[what_acc] == 0 && pay_data[what_acc] == 0)
	{
		printf("还没有任何记录信息可改删除\n");
		manage_accounts(what_acc);
	}
	int import;
A:
	printf("1.收入 2.支出\n");
	printf("请选择要删除收入还是支出:");
	scanf_s("%d", &import);
	if (import == 1)
	{
		if (income_data[what_acc] == 0)
		{
			printf("还没有任何收入记录可以删除\n");
			goto A;
		}
		printf("  类型  金额  日期     备注\n");
		for (int i = 0; i < income_data[what_acc]; i++)//
		{
			printf("%d.收入 +%d ", i + 1, All_data_p[what_acc].income[i].money);
			printf("%s ", All_data_p[what_acc].income[i].date);
			printf("%s\n", All_data_p[what_acc].income[i].remarks);
		}
		printf("请选择要删除的编号:");
		int import1;
		scanf_s("%d", &import1);
		import1--;
		detel_income(what_acc,import1);
	}
	if (import == 2)
	{
		if (pay_data[what_acc] == 0)
		{
			printf("还没有任何支出记录可以删除\n");
			goto A;
		}
		printf("  类型  金额  日期     备注\n");
		for (int j = 0; j < pay_data[what_acc]; j++)
		{
			printf("%d.", j + 1);
			print_pay(what_acc, j);
			printf("-%d ", All_data_p[what_acc].pay[j].money);
			printf("%s ", All_data_p[what_acc].pay[j].date);
			printf("%s\n", All_data_p[what_acc].pay[j].remarks);
		}
		printf("请选择要删除的编号:");
		int import2;
		scanf_s("%d", &import2);
		import2--;
		detel_pay(what_acc, import2);
	}
}

void detel_income(int what_acc, int import)//删除输入
{
	for (int i = import; i < income_data[what_acc]; i++)
	{
		All_data_p[what_acc].income[i] = All_data_p[what_acc].income[i + 1];
	}
	All_data_p[what_acc].income[income_data[what_acc]].money = 0;
	memset(All_data_p[what_acc].income[income_data[what_acc]].date,0,sizeof(All_data_p[what_acc].income[income_data[what_acc]].date));
	memset(All_data_p[what_acc].income[income_data[what_acc]].remarks, 0, sizeof(All_data_p[what_acc].income[income_data[what_acc]].remarks));
	//将收入的信息前移一格去删除选定的信息

	income_data[what_acc]--;       //更改计数器  
	printf("记录删除成功!\n");
	manage_accounts(what_acc);
}

void detel_pay(int what_acc, int import)//删除支出
{
	for (int i = import; i < pay_data[what_acc]; i++)
	{
		All_data_p[what_acc].pay[i] = All_data_p[what_acc].pay[i + 1];
	}
	All_data_p[what_acc].pay[pay_data[what_acc]].money = 0;
	All_data_p[what_acc].pay[pay_data[what_acc]].type = 0;
	memset(All_data_p[what_acc].pay[pay_data[what_acc]].date, 0, sizeof(All_data_p[what_acc].pay[pay_data[what_acc]].date));
	memset(All_data_p[what_acc].pay[pay_data[what_acc]].remarks, 0, sizeof(All_data_p[what_acc].pay[pay_data[what_acc]].remarks));
	//将支出的信息前移一格去删除选定的信息

	pay_data[what_acc]--;     //更改计数器
	printf("记录删除成功!\n");
	manage_accounts(what_acc);
}

void statistics_menu(int what_acc)//三级菜单
{
	printf("\n");
	printf("=== 统计查询 ===\n");
	printf("1. 查看余额\n");
	printf("2. 查看消费类型及次数\n");
	printf("3. 返回上级\n");
	printf("请选择操作:");
	int a;
A:
	scanf_s("%d", &a);
	while (getchar() != '\n');//
	if (a != 1 && a != 2 && a != 3)
	{
		printf("请输入有效数字\n");
		goto A;
	}
	if (a == 1)
	{
		remainder(what_acc);
	}
	else if (a == 2)
	{
		statistics(what_acc);
	}
	else if (a == 3)
	{
		second_menu(what_acc);
	}
}

void statistics(int what_acc)
{
	printf("\n");
	printf("消费类型 次数 金额\n");
	
	typedef struct  //6个类型分别对应 1.娱乐 2.购物 3.餐饮 4.服务 5.教育 6.其他
	{
		int sign;       //存储类型标识
		int number;     //存储次数
		int sum;        //存储总金额
	}Type;         

	Type type[6] = { 0 };

	for (int k = 0; k < 6; k++)
	{
		type[k].sign = k + 1;
	}
	
	for (int i = 0; i < pay_data[what_acc]; i++)//历遍信息并计算各个类型的次数
	{
		if (All_data_p[what_acc].pay[i].type == 1)
		{
			type[0].number++;
			type[0].sum += All_data_p[what_acc].pay[i].money;
		}
		if (All_data_p[what_acc].pay[i].type == 2)
		{
			type[1].number++;
			type[1].sum += All_data_p[what_acc].pay[i].money;
		}
		if (All_data_p[what_acc].pay[i].type == 3)
		{
			type[2].number++;
			type[2].sum += All_data_p[what_acc].pay[i].money;
		}
		if (All_data_p[what_acc].pay[i].type == 4)
		{
			type[3].number++;
			type[3].sum += All_data_p[what_acc].pay[i].money;
		}
		if (All_data_p[what_acc].pay[i].type == 5)
		{
			type[4].number++;
			type[4].sum += All_data_p[what_acc].pay[i].money;
		}
		if (All_data_p[what_acc].pay[i].type == 6)
		{
			type[5].number++;
			type[5].sum += All_data_p[what_acc].pay[i].money;
		}
	}
	for (int j = 0; j < 5; j++)        //排序:次数多的类型排前面
	{
		for (int k = 0; k < 5; k++)
		{
			if (type[k].number < type[k + 1].number)
			{
				Type temp = type[k];
				type[k] = type[k + 1];
				type[k + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 6; i++)  //打印
	{
		printf(" ");
		print_type_by_sign(type[i].sign);    //输入类型的标识来打印类型
		printf(" %d  ", type[i].number);
		printf(" -%d\n", type[i].sum);
	}
	char import = '0';
	while (import != '1')
	{
		printf("输入1返回:");
		scanf_s("%c", &import, 1);
		while (getchar() != '\n');
		if (import == '1')
		{
			statistics_menu(what_acc);
		}
	}
}

void remainder(int what_acc)
{
	int sum = 0;
	int income = 0;
	int pay = 0;
	int i = 0;
	while (i < income_data[what_acc])		//计算收入额
	{
		income += All_data_p[what_acc].income[i].money;
		i++;
	}
	i = 0;

	while (i < pay_data[what_acc])		//计算支出额
	{
		pay += All_data_p[what_acc].pay[i].money;
		i++;
	}
	sum = income - pay;			//计算总余额
	printf("\n");
	printf("本月的收入,支出及总余额为:\n");
	printf("收入: +%d\n", income);
	printf("支出: -%d\n", pay);
	printf("总余额 %d\n", sum);
	if (sum < 0)
	{
		printf("本月的收入小于支出,");
		printf("请确认是否数据输入错误");
		printf("或有收入的数据未输入.\n");
	}
	char import = '0';
	while (import != '1')
	{
		printf("输入1返回:");
		scanf_s("%c", &import, 1);
		while (getchar() != '\n');
		if (import == '1')
		{
			statistics_menu(what_acc);
		}
	}
}

void print_pay(int what_acc,int i)	//历遍信息来打印支出类型
{
		int a = All_data_p[what_acc].pay[i].type;
		char type[7];
		if (a == 1)strcpy_s(type, sizeof(type), "娱乐");
		else if (a == 2)strcpy_s(type, sizeof(type), "购物");
		else if (a == 3)strcpy_s(type, sizeof(type), "餐饮");
		else if (a == 4)strcpy_s(type, sizeof(type), "服务");
		else if (a == 5)strcpy_s(type, sizeof(type), "教育");
		else if (a == 6)strcpy_s(type, sizeof(type), "其他");
		printf("%s ",type);
}

void print_type_by_sign(int sign)	//通过标识来打印支出类型
{
	char type[7];
	if (sign == 1) strcpy_s(type, sizeof(type), "娱乐");
	else if (sign == 2) strcpy_s(type, sizeof(type), "购物");
	else if (sign == 3) strcpy_s(type, sizeof(type), "餐饮");
	else if (sign == 4) strcpy_s(type, sizeof(type), "服务");
	else if (sign == 5) strcpy_s(type, sizeof(type), "教育");
	else if (sign == 6) strcpy_s(type, sizeof(type), "其他");
	else strcpy_s(type, sizeof(type), "未知");
	printf(" %s   ", type);
}