#include "Menu.h"

/*菜单文本输出*/
void Menu_Text_Print()
{
	cout << "-----------------通讯录---------------" << endl
		<< "--------------1.添加联系人------------" << endl
		<< "--------------2.删除联系人------------" << endl
		<< "--------------3.显示联系人列表--------" << endl
		<< "--------------4.查找联系人------------" << endl
		<< "--------------5.修改联系人信息--------" << endl
		<< "--------------6.清空联系人------------" << endl
		<< "--------------7.读取文件--------------" << endl
		<< "--------------8.保存文件--------------" << endl
		<< "--------------0.退出------------------" << endl
		<< "--------------------------------------" << endl
		<< "请输入选择:";
}

/*搜索模式选择*/
void Choose_Search_Mode(Address_List& list1)
{
	char choice4;
	while (true)
	{
		cout << "请选择查询根据:" << endl
			<< "1.姓名" << endl
			<< "2.电话" << endl
			<< "0.返回" << endl
			<< "请输入:";
		//cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		choice4 = cin.get();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		if (choice4 == '0')
		{
			cout << "即将返回..." << endl; break; return;
		}
		else if (choice4 == '1' || choice4 == '2')
		{
			cout << "请输入查询根据:";
			string pattern;
			cin >> pattern;
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			int pos = list1.Inquiry(pattern, int(choice4 - '0'));
			if (pos == -1)
				cout << "查无此人!" << endl;
			else
			{
				cout << "Name  Age  Gender   Phone_Number   Email   Comment" << endl;
				list1.Display(pos, 1);
			}
		}
		else
			cerr << "输入有误,请重试" << endl;
		system("pause"); system("cls");
	}
	return;
}

/*二次确认*/
bool Re_Confirm()
{
	cout << "确定要进行该操作吗?" << endl
		<< "Y.确认(其他任意键返回)" << endl;
	char choice5;
	//cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
	choice5 = cin.get();
	cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
	if (choice5 == 'Y')
		return true;
	else
		return false;
}

/*删除选择*/
void Delete_Mode(Address_List& list1)
{
	cout << "请输入要删除的联系人姓名:";
	string pattern;
	cin >> pattern;
	int pos = list1.Inquiry(pattern, 1);
	if (pos == -1)
		cerr << "查无此人!" << endl;
	else
	{
		list1.DeleteRecord(pos, 1);
		cout << "删除成功!" << endl;
	}
	return;
}

/*修改联系人信息*/
void Modificate_Mode(Address_List& list1)
{
	cout << "请输入要修改的联系人姓名:";
	string pattern;
	cin >> pattern;
	int pos = list1.Inquiry(pattern, 1);
	if (pos == -1)
	{
		cerr << "查无此人!" << endl;
		return;
	}
	char choice5;
	while (true)
	{
		cout << "1.Name" << endl
			<< "2.Age" << endl
			<< "3.Gender" << endl
			<< "4.Phone_Number" << endl
			<< "5.Email" << endl
			<< "6.Comment" << endl
			<< "0.返回" << endl
			<< "请输入要修改的项:" << endl;
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		choice5 = cin.get();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		string substi;
		switch (choice5)
		{
		case '0': cout << "即将返回..." << endl; return; break;
		case '1':   cout << "Name:";         cin >> substi; list1.ModRecord(substi, pos, 1); cout << "修改成功!" << endl; break;
		case '2': cout << "Age:";          cin >> substi; list1.ModRecord(substi, pos, 2); cout << "修改成功!" << endl; break;
		case '3': cout << "Gender:";       cin >> substi; list1.ModRecord(substi, pos, 3); cout << "修改成功!" << endl; break;
		case '4': cout << "Phone_Number:"; cin >> substi; list1.ModRecord(substi, pos, 4); cout << "修改成功!" << endl; break;
		case '5': cout << "Email:";        cin >> substi; list1.ModRecord(substi, pos, 5); cout << "修改成功!" << endl; break;
		case '6': cout << "Comment:";      cin >> substi; list1.ModRecord(substi, pos, 6); cout << "修改成功!" << endl; break;
		default:cerr << "输入有误,请重新输入!" << endl; system("pause"); system("cls"); break;
		}
	}
}

/*联系人列表判空*/
bool Check_Empty(Address_List& list1)
{
	if (list1.isEmpty())
	{
		cerr << "Tip:联系人列表为空!" << endl;
		return true;
	}
	else
		return false;
}

/*添加模式选择*/
void Append_Mode(Address_List& list1)
{
	char choice1;
	while (true)
	{
		cout << "1.添加单个联系人 2.添加多个联系人 0.返回" << endl
			<< "请输入添加模式:";
		choice1 = cin.get();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		switch (choice1)
		{
		case '0':
			cout << "即将返回..." << endl; return;
			break;
		case '1':
			cout << "Name  Age  Gender   Phone_Number   Email   Comment" << endl;
			list1.AppendRecord(1);
			cout << "添加成功!" << endl;
			system("pause"); system("cls");
			break;
		case '2':
			cout << "请输入添加个数:";
			int size; cin >> size;
			cout << "Name  Age  Gender   Phone_Number   Email   Comment" << endl;
			list1.AppendRecord(size);
			cout << "添加成功!" << endl;
			system("pause"); system("cls");
			break;
		default:
			cerr << "输入有误,即将返回..." << endl;
			system("pause"); system("cls"); break;
		}
	}
}
/*主菜单*/
void MainMenu(Address_List& list1)
{
	char choice;
	while (true)
	{
		Menu_Text_Print();
		choice = cin.get();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		switch (choice)
		{
		case '0'://退出
			if (Re_Confirm())
				exit(0);
			else
				system("pause"); system("cls");
			break;
		case '1'://添加联系人
			system("cls");
			Append_Mode(list1);
			system("pause"); system("cls");
			break;
		case '2'://删除联系人
			if (Check_Empty(list1))
			{
				system("pause"); system("cls");
				break;
			}
			if (Re_Confirm())
				Delete_Mode(list1);
			system("pause"); system("cls");
			break;
		case '3'://显示联系人
			if (Check_Empty(list1))
			{
				system("pause"); system("cls");
				break;
			}
			cout << "Name   Age   Gender   Phone_Number    Email     Comment" << endl;
			list1.Display();
			system("pause"); system("cls");
			break;
		case '4'://查找联系人
			if (Check_Empty(list1))
			{
				system("pause"); system("cls");
				break;
			}
			//system("cls");
			Choose_Search_Mode(list1);
			system("pause"); system("cls");
			break;
		case '5': //修改联系人
			if (Check_Empty(list1))
			{
				system("pause"); system("cls");
				break;
			}
			system("cls");
			Modificate_Mode(list1);
			system("pause"); system("cls");
			break;
		case '6': //清空联系人
			if (Check_Empty(list1))
			{
				system("pause"); system("cls");
				break;
			}
			if (Re_Confirm())
				list1.ClearRecord();
			cout << "清空成功!" << endl;
			system("pause"); system("cls");
			break;
		case '7'://读取文件
			if (!list1.isEmpty())
			{
				cerr << "列表中已有数据!" << endl;
				system("pause"); system("cls");
				break;
			}
			list1.Read_As_Txt();
			cout << "读取成功!" << endl;
			system("pause"); system("cls");
			break;
		case '8'://保存文件
			if (Check_Empty(list1))
			{
				cout << "Warning:联系人列表为空,此时保存将清空文件内容!" << endl;
				if (Re_Confirm())
					list1.Save_As_Txt();
				else
					break;
			}
			cout << "保存成功!" << endl;
			system("pause"); system("cls");
			break;
		default:
			cerr << "输入有误,请重试!" << endl;
			system("pause"); system("cls");
			break;
		}
	}
}

int main()
{
	Address_List list1;
	list1.Read_As_Txt();
	MainMenu(list1);
	return 0;
}