#include "Address_List.h"


/*������д��*/
void Address_List::Save_As_Bin(const string fileName)
{
	ofstream ostrm(fileName, ios::binary | ios::out | ios::app);
	if (!ostrm.is_open())
	{
		cerr << fileName << "Error:Open Fail!" << endl;
		ostrm.close();
		return;
	}
	for (int i = 0; i < Persons.size(); ++i)
		ostrm.write(reinterpret_cast<char*>(&Persons[i]), sizeof(Persons[i]));
	ostrm.close();
}

/*�����ƶ�ȡ*/
void Address_List::Read_As_Bin(const string fileName)
{
	ifstream istrm(fileName, ios::binary | ios::in | ios::beg);
	if (!istrm.is_open())
	{
		cerr << fileName << "Error:Open Fail!" << endl;
		istrm.close();
		return;
	}
	int i = 0;
	while (!istrm.eof())
	{
		Persons.emplace_back();
		istrm.read(reinterpret_cast<char*>(&Persons.back()), sizeof(Persons.back()));
		++i;
	}
	istrm.close();
}

/*��ϵ��д���ı��ļ�*/
void Address_List::Save_As_Txt(const string fileName)
{
	ofstream  ostrm;
	ostrm.open(fileName, ios::out | ios::trunc);
	if (!ostrm.is_open())
	{
		cerr << fileName << "Error:Open Fail!" << endl;
		ostrm.close();
		return;
	}
	for (int i = 0; i < Persons.size(); ++i)
		ostrm << Persons[i] << endl;
	ostrm.close();
}

/*�ı��ļ�������ϵ����Ϣ*/
void Address_List::Read_As_Txt(const string fileName)
{
	ifstream istrm;
	istrm.open(fileName, ios::in | ios::beg);
	if (!istrm.is_open())
	{
		cerr << fileName << "Error:Open Fail!" << endl;
		istrm.close();
		return;
	}
	while (!istrm.eof())
	{
		Persons.emplace_back();
		string tmp;
		for (int i = 1; i < Contact::item_type + 1; ++i)
		{
			istrm >> tmp;
			Persons.back().Modificate(tmp, i);
		}
	}
	istrm.close();
	return;
}

/*��ѯ��ϵ��*/
int Address_List::Inquiry(const string& pattern, int search_mode)const
{
	if (search_mode == 1)
	{
		for (int i = 0; i < Persons.size(); ++i)
		{
			if (pattern == Persons[i].getName())
				return i;
		}
		return -1;
	}
	else//if(search_mode == 2)
	{
		for (int i = 0; i < Persons.size(); ++i)
		{
			if (pattern == Persons[i].getPhone_Number())
				return i;
		}
		return -1;
	}
}

/*�����ϵ��*/
void Address_List::AppendRecord(int opt_size)
{
	for (int i = 0; i < opt_size; ++i)
	{
		Persons.emplace_back();
		Persons.back().Input();
	}
}

/*������ϵ��*/
void Address_List::EmplaceRecord(int index, Contact contact_argv)
{
	Persons.emplace(Persons.begin() + index, contact_argv);
}

/*ɾ����ϵ��*/
void Address_List::DeleteRecord(int index, int opt_size)
{
	if (index == -1)
			Persons.pop_back();
	else // if(index >= 0)
	{
		vector<Contact>::iterator ptr = Persons.begin()+ index;
			Persons.erase(ptr, ptr + opt_size);
	}
}
/*�޸���ϵ��*/
void Address_List::ModRecord(const string subti,int index, int opt_mode)
{
	Persons[index].Modificate(subti, opt_mode);
}

/*�����ϵ��*/
void Address_List::ClearRecord()
{
	Persons.clear();
	if (!Persons.empty())
	{
		cerr << "Eeception:Address_List not empty yet!" << endl;
		abort();
	}
}

/*��ʾ��ϵ��*/
void Address_List::Display(int index, int opt_size)const
{
	if (index == -1)
		for (int i = 0; i < Persons.size(); ++i)
		{
			Persons[i].Print(); cout << endl;
		}
	else
		for (int i = index; i < Persons.size() && i < index + opt_size; ++i)
		{
			Persons[i].Print();
			cout << endl;
		}
}