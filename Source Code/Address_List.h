#pragma once
#include "Contact.h"
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;


/*通讯录类*/
class Address_List
{
private:
	vector<Contact> Persons;
	//int Size;  // 通讯录人数
public:
	Address_List() {}
	//状态判断
	bool isEmpty()const { return (Persons.empty()== true); }

	//数据操作
	void AppendRecord(int opt_size = 1);    //添加 1-1个
	void EmplaceRecord(int index, Contact contact_argv); // (插入位置，传入数据)

	void DeleteRecord(int index = -1, int opt_size = 1); //删除 -1-尾部 1-1个
	void ModRecord(const string, int index, int opt_mode);//(操作数下标，操作对象的哪个数据)
	int Inquiry(const string& pattern, int search_mode = 1)const; // 查询 1-姓名 2-电话号

	void Display(int index = -1,int opt_size = 1)const; //显示 -1-全部 1-1个
	void ClearRecord();//清空
	//文件操作
	void Save_As_Txt(const string fileName = "AddressList_Save1.txt");//写入文件
	void Read_As_Txt(const string fileName = "AddressList_Save1.txt");//读取文件

	void Save_As_Bin(const string fileName = "AddressList_Save1.dat");
	void Read_As_Bin(const string fileName = "AddressList_Save1.dat");
};

