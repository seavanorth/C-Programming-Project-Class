#include "Contact.h"
/*��Ŀ��Ŀ*/
int Contact::item_type = 6;

/*�����ʼ��*/
Contact::Contact()
{
	Name = "��";
	Age = "��";
	Gender = "��";
	Phone_Number = "��";
	Email = "��";
	Comment = "��";
}

/*����ȡ����*/
ostream& operator<<(ostream& os, Contact& contact_Argu)
{
	os << contact_Argu.Name << " "
		<< contact_Argu.Age << " "
		<< contact_Argu.Gender << " "
		<< contact_Argu.Phone_Number << " "
		<< contact_Argu.Email << " "
		<< contact_Argu.Comment;
	return os;
}

/*���뺯��*/
void Contact::Input()
{
	cin >> Name
		>> Age
		>> Gender
		>> Phone_Number
		>> Email
		>> Comment;
}

/*��ʾ����*/
void Contact::Print()const
{
	cout << Name << " "
		<< Age << " "
		<< Gender << " "
		<< Phone_Number << " "
		<< Email << " "
		<< Comment << endl;
}

/*�޸ĺ���*/
void Contact::Modificate(const string argu, int mod_mode)
{
	switch (mod_mode)
	{
	case 1:  Name = argu; break;
	case 2:	 Age = argu; break;
	case 3:	 Gender = argu; break;
	case 4:	 Phone_Number = argu; break;
	case 5:	 Email = argu; break;
	case 6:	 Comment = argu; break;
	default:break;
	}
}