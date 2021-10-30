#pragma once
#include "Contact.h"
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;


/*ͨѶ¼��*/
class Address_List
{
private:
	vector<Contact> Persons;
	//int Size;  // ͨѶ¼����
public:
	Address_List() {}
	//״̬�ж�
	bool isEmpty()const { return (Persons.empty()== true); }

	//���ݲ���
	void AppendRecord(int opt_size = 1);    //��� 1-1��
	void EmplaceRecord(int index, Contact contact_argv); // (����λ�ã���������)

	void DeleteRecord(int index = -1, int opt_size = 1); //ɾ�� -1-β�� 1-1��
	void ModRecord(const string, int index, int opt_mode);//(�������±꣬����������ĸ�����)
	int Inquiry(const string& pattern, int search_mode = 1)const; // ��ѯ 1-���� 2-�绰��

	void Display(int index = -1,int opt_size = 1)const; //��ʾ -1-ȫ�� 1-1��
	void ClearRecord();//���
	//�ļ�����
	void Save_As_Txt(const string fileName = "AddressList_Save1.txt");//д���ļ�
	void Read_As_Txt(const string fileName = "AddressList_Save1.txt");//��ȡ�ļ�

	void Save_As_Bin(const string fileName = "AddressList_Save1.dat");
	void Read_As_Bin(const string fileName = "AddressList_Save1.dat");
};

