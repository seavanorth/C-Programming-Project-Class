#pragma once
/*
��ϵ����ͷ�ļ�
������ϵ����Ķ���͹���ʵ��
*/
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

/*��ϵ����*/
class Contact
{
protected:

	string Name;         //����
	string Age;          //����
	string Gender;       //�Ա�
	string Phone_Number; //�绰����
	string Email;        //��������
	string Comment;      //��ע

	/*Additional*/
	//string Nickname;  //�ǳ�
	//string Birthday; //����
	//string Location; //��ַ
	//string 
	//string Website;  //��վ
public:
	static int item_type;
	Contact();
	void Input();
	void Print()const;
	void Modificate(const string, int index); // �޸�

	string getName()const { return Name; };
	string getPhone_Number()const { return Phone_Number; }
	
	friend ostream& operator<<(ostream& os, Contact& contact_Argu);//����ȡ����

};
