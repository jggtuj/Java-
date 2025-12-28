#include "function.h" 

int main(void)
{
	int account_num = 0;
	account_num_p = &account_num;               //指针赋值

	Acc_stru* All_acc_name_code = (Acc_stru*)malloc(num_acc * sizeof(Acc_stru));
	if (!All_acc_name_code) { perror("malloc"); return 1; }       //存储名称和密码的结构体 的数组
	memset(All_acc_name_code, 0, num_acc * sizeof(Acc_stru));

	All_acc_name_code_p = All_acc_name_code;          //指针赋值

	Data* All_data = (Data*)malloc(num_acc * sizeof(Data));		//存储收入和支出信息的结构体 的数组
	if (!All_data) { perror("malloc"); free(All_acc_name_code); return 1; }
	memset(All_data, 0, num_acc * sizeof(Data));

	All_data_p = All_data;							//指针赋值

	main_menu();

	free(All_acc_name_code);
	free(All_data);

	return 0;
}