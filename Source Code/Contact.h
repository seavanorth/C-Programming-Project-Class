#pragma once
/*
联系人类头文件
包含联系人类的定义和功能实现
*/
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

/*联系人类*/
class Contact
{
protected:

	string Name;         //姓名
	string Age;          //年龄
	string Gender;       //性别
	string Phone_Number; //电话号码
	string Email;        //电子邮箱
	string Comment;      //备注

	/*Additional*/
	//string Nickname;  //昵称
	//string Birthday; //生日
	//string Location; //地址
	//string 
	//string Website;  //网站
public:
	static int item_type;
	Contact();
	void Input();
	void Print()const;
	void Modificate(const string, int index); // 修改

	string getName()const { return Name; };
	string getPhone_Number()const { return Phone_Number; }
	
	friend ostream& operator<<(ostream& os, Contact& contact_Argu);//流提取重载

};
