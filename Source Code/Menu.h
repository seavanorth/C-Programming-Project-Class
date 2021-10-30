#pragma once

#include "Address_List.h"
#include <cstdlib>
using namespace std;

void Menu_Text_Print();
/*搜索模式选择*/
void Choose_Search_Mode(Address_List& list1);

/*二次确认*/
bool Re_Confirm();

/*删除选择*/
void Delete_Mode(Address_List& list1);

/*修改联系人信息*/
void Modificate_Mode(Address_List& list1);

/*联系人列表判空*/
bool Check_Empty(Address_List& list1);

/*添加模式选择*/
void Append_Mode(Address_List& list1);
/*主菜单*/
void MainMenu(Address_List& list1);