#pragma once

#include "Address_List.h"
#include <cstdlib>
using namespace std;

void Menu_Text_Print();
/*����ģʽѡ��*/
void Choose_Search_Mode(Address_List& list1);

/*����ȷ��*/
bool Re_Confirm();

/*ɾ��ѡ��*/
void Delete_Mode(Address_List& list1);

/*�޸���ϵ����Ϣ*/
void Modificate_Mode(Address_List& list1);

/*��ϵ���б��п�*/
bool Check_Empty(Address_List& list1);

/*���ģʽѡ��*/
void Append_Mode(Address_List& list1);
/*���˵�*/
void MainMenu(Address_List& list1);