#include "Contact.h"
/*项目数目*/
int Contact::item_type = 6;

/*构造初始化*/
Contact::Contact()
{
	Name = "空";
	Age = "空";
	Gender = "空";
	Phone_Number = "空";
	Email = "空";
	Comment = "空";
}

/*流提取重载*/
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

/*输入函数*/
void Contact::Input()
{
	cin >> Name
		>> Age
		>> Gender
		>> Phone_Number
		>> Email
		>> Comment;
}

/*显示函数*/
void Contact::Print()const
{
	cout << Name << " "
		<< Age << " "
		<< Gender << " "
		<< Phone_Number << " "
		<< Email << " "
		<< Comment << endl;
}

/*修改函数*/
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