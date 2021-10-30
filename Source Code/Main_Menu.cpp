#include "Menu.h"

/*�˵��ı����*/
void Menu_Text_Print()
{
	cout << "-----------------ͨѶ¼---------------" << endl
		<< "--------------1.�����ϵ��------------" << endl
		<< "--------------2.ɾ����ϵ��------------" << endl
		<< "--------------3.��ʾ��ϵ���б�--------" << endl
		<< "--------------4.������ϵ��------------" << endl
		<< "--------------5.�޸���ϵ����Ϣ--------" << endl
		<< "--------------6.�����ϵ��------------" << endl
		<< "--------------7.��ȡ�ļ�--------------" << endl
		<< "--------------8.�����ļ�--------------" << endl
		<< "--------------0.�˳�------------------" << endl
		<< "--------------------------------------" << endl
		<< "������ѡ��:";
}

/*����ģʽѡ��*/
void Choose_Search_Mode(Address_List& list1)
{
	char choice4;
	while (true)
	{
		cout << "��ѡ���ѯ����:" << endl
			<< "1.����" << endl
			<< "2.�绰" << endl
			<< "0.����" << endl
			<< "������:";
		//cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		choice4 = cin.get();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		if (choice4 == '0')
		{
			cout << "��������..." << endl; break; return;
		}
		else if (choice4 == '1' || choice4 == '2')
		{
			cout << "�������ѯ����:";
			string pattern;
			cin >> pattern;
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			int pos = list1.Inquiry(pattern, int(choice4 - '0'));
			if (pos == -1)
				cout << "���޴���!" << endl;
			else
			{
				cout << "Name  Age  Gender   Phone_Number   Email   Comment" << endl;
				list1.Display(pos, 1);
			}
		}
		else
			cerr << "��������,������" << endl;
		system("pause"); system("cls");
	}
	return;
}

/*����ȷ��*/
bool Re_Confirm()
{
	cout << "ȷ��Ҫ���иò�����?" << endl
		<< "Y.ȷ��(�������������)" << endl;
	char choice5;
	//cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
	choice5 = cin.get();
	cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
	if (choice5 == 'Y')
		return true;
	else
		return false;
}

/*ɾ��ѡ��*/
void Delete_Mode(Address_List& list1)
{
	cout << "������Ҫɾ������ϵ������:";
	string pattern;
	cin >> pattern;
	int pos = list1.Inquiry(pattern, 1);
	if (pos == -1)
		cerr << "���޴���!" << endl;
	else
	{
		list1.DeleteRecord(pos, 1);
		cout << "ɾ���ɹ�!" << endl;
	}
	return;
}

/*�޸���ϵ����Ϣ*/
void Modificate_Mode(Address_List& list1)
{
	cout << "������Ҫ�޸ĵ���ϵ������:";
	string pattern;
	cin >> pattern;
	int pos = list1.Inquiry(pattern, 1);
	if (pos == -1)
	{
		cerr << "���޴���!" << endl;
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
			<< "0.����" << endl
			<< "������Ҫ�޸ĵ���:" << endl;
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		choice5 = cin.get();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		string substi;
		switch (choice5)
		{
		case '0': cout << "��������..." << endl; return; break;
		case '1':   cout << "Name:";         cin >> substi; list1.ModRecord(substi, pos, 1); cout << "�޸ĳɹ�!" << endl; break;
		case '2': cout << "Age:";          cin >> substi; list1.ModRecord(substi, pos, 2); cout << "�޸ĳɹ�!" << endl; break;
		case '3': cout << "Gender:";       cin >> substi; list1.ModRecord(substi, pos, 3); cout << "�޸ĳɹ�!" << endl; break;
		case '4': cout << "Phone_Number:"; cin >> substi; list1.ModRecord(substi, pos, 4); cout << "�޸ĳɹ�!" << endl; break;
		case '5': cout << "Email:";        cin >> substi; list1.ModRecord(substi, pos, 5); cout << "�޸ĳɹ�!" << endl; break;
		case '6': cout << "Comment:";      cin >> substi; list1.ModRecord(substi, pos, 6); cout << "�޸ĳɹ�!" << endl; break;
		default:cerr << "��������,����������!" << endl; system("pause"); system("cls"); break;
		}
	}
}

/*��ϵ���б��п�*/
bool Check_Empty(Address_List& list1)
{
	if (list1.isEmpty())
	{
		cerr << "Tip:��ϵ���б�Ϊ��!" << endl;
		return true;
	}
	else
		return false;
}

/*���ģʽѡ��*/
void Append_Mode(Address_List& list1)
{
	char choice1;
	while (true)
	{
		cout << "1.��ӵ�����ϵ�� 2.��Ӷ����ϵ�� 0.����" << endl
			<< "���������ģʽ:";
		choice1 = cin.get();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		switch (choice1)
		{
		case '0':
			cout << "��������..." << endl; return;
			break;
		case '1':
			cout << "Name  Age  Gender   Phone_Number   Email   Comment" << endl;
			list1.AppendRecord(1);
			cout << "��ӳɹ�!" << endl;
			system("pause"); system("cls");
			break;
		case '2':
			cout << "��������Ӹ���:";
			int size; cin >> size;
			cout << "Name  Age  Gender   Phone_Number   Email   Comment" << endl;
			list1.AppendRecord(size);
			cout << "��ӳɹ�!" << endl;
			system("pause"); system("cls");
			break;
		default:
			cerr << "��������,��������..." << endl;
			system("pause"); system("cls"); break;
		}
	}
}
/*���˵�*/
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
		case '0'://�˳�
			if (Re_Confirm())
				exit(0);
			else
				system("pause"); system("cls");
			break;
		case '1'://�����ϵ��
			system("cls");
			Append_Mode(list1);
			system("pause"); system("cls");
			break;
		case '2'://ɾ����ϵ��
			if (Check_Empty(list1))
			{
				system("pause"); system("cls");
				break;
			}
			if (Re_Confirm())
				Delete_Mode(list1);
			system("pause"); system("cls");
			break;
		case '3'://��ʾ��ϵ��
			if (Check_Empty(list1))
			{
				system("pause"); system("cls");
				break;
			}
			cout << "Name   Age   Gender   Phone_Number    Email     Comment" << endl;
			list1.Display();
			system("pause"); system("cls");
			break;
		case '4'://������ϵ��
			if (Check_Empty(list1))
			{
				system("pause"); system("cls");
				break;
			}
			//system("cls");
			Choose_Search_Mode(list1);
			system("pause"); system("cls");
			break;
		case '5': //�޸���ϵ��
			if (Check_Empty(list1))
			{
				system("pause"); system("cls");
				break;
			}
			system("cls");
			Modificate_Mode(list1);
			system("pause"); system("cls");
			break;
		case '6': //�����ϵ��
			if (Check_Empty(list1))
			{
				system("pause"); system("cls");
				break;
			}
			if (Re_Confirm())
				list1.ClearRecord();
			cout << "��ճɹ�!" << endl;
			system("pause"); system("cls");
			break;
		case '7'://��ȡ�ļ�
			if (!list1.isEmpty())
			{
				cerr << "�б�����������!" << endl;
				system("pause"); system("cls");
				break;
			}
			list1.Read_As_Txt();
			cout << "��ȡ�ɹ�!" << endl;
			system("pause"); system("cls");
			break;
		case '8'://�����ļ�
			if (Check_Empty(list1))
			{
				cout << "Warning:��ϵ���б�Ϊ��,��ʱ���潫����ļ�����!" << endl;
				if (Re_Confirm())
					list1.Save_As_Txt();
				else
					break;
			}
			cout << "����ɹ�!" << endl;
			system("pause"); system("cls");
			break;
		default:
			cerr << "��������,������!" << endl;
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