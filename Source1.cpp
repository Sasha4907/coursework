#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include "Header1.h"
using namespace std;

People::People()
{
	this->name = "Name";
	int** Days = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		Days[i] = new int[31];
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			Days[i][j] = 0;
		}
	}
	this->Timetable = Days;
}

People::People(string name)
{
	this->name = name;
}

string People::GetName()
{
	return name;
}

void People::SetName(string name)
{
	this->name = name;
}

void People::NewTimetable(int month, int shift)
{
	int day = 31;
	int** Days = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		Days[i] = new int[day];
	}
	for (int j = 0; j < day; j++)
	{
		Days[0][j] = j + 1;
	}

	for (int j = 0; j < day; j++)
	{
		int first = 8, second = 14;
		for (int i = 1; i < 5; i++)
		{

			if (shift == 1)
			{
				Days[i][j] = first;
				first++;
			}
			else
			{
				Days[i][j] = second;
				second++;
			}
		}
	}

	day = Weekdays(Days, month);
	this->day = day;
	this->Timetable = Days;
}

int** People::GetTimetable()
{
	return Timetable;
}

void People::SetTimetable(int** Days)
{
	this->Timetable = Days;
}

int People::GetDay()
{
	return day;
}

int People::Weekdays(int** Days, int month)
{
	int day = 0;
	int M1[7]{ 1,3,7,10,17,24,31 };
	int M2[7]{ 7,14,21,28,29,30,31 };
	int M3[5]{ 7,8,14,21,28 };
	int M4[5]{ 4,11,18,25,31 };
	int M5[6]{ 1,2,9,16,23,30 };
	int M6[6]{ 6,13,20,27,28,31 };
	int M7[5]{ 4,11,18,25 };
	int M8[6]{ 1,8,15,22,24,29 };
	int M9[5]{ 5,12,19,26,31 };
	int M10[6]{ 3,10,14,17,24,31 };
	int M11[5]{ 7,14,21,28,31 };
	int M12[5]{ 5,12,19,25,26 };
	if (month == 1)
	{
		day = Delete(Days, M1, 7);
	}
	if (month == 2)
	{
		day = Delete(Days, M2, 7);
	}
	if (month == 3)
	{
		day = Delete(Days, M3, 5);
	}
	if (month == 4)
	{
		day = Delete(Days, M4, 5);
	}
	if (month == 5)
	{
		day = Delete(Days, M5, 6);
	}
	if (month == 6)
	{
		day = Delete(Days, M6, 6);
	}
	if (month == 7)
	{
		day = Delete(Days, M7, 5);
	}
	if (month == 8)
	{
		day = Delete(Days, M8, 6);
	}
	if (month == 9)
	{
		day = Delete(Days, M9, 5);
	}
	if (month == 10)
	{
		day = Delete(Days, M10, 6);
	}
	if (month == 11)
	{
		day = Delete(Days, M11, 5);
	}
	if (month == 12)
	{
		day = Delete(Days, M12, 5);
	}
	return day;
}

int People::Delete(int** Days, int* Mi, int k)
{
	int* temp = new int[31];
	for (int i = 0; i < 31; i++)
	{
		temp[i] = Days[0][i];
	}
	int day = 31 - k;
	for (int i = 0, l = 0; i < 31, l < 31 - k; i++, l++)
	{
		for (int j = 0; j < k; j++)
		{
			if (temp[i] == Mi[j])
			{
				Days[0][l] = temp[i + 1];
				i++;
				break;
			}
			else
			{
				Days[0][l] = temp[i];
			}
		}
	}
	return day;
}

Doctor::Doctor(string name1, string name2, string name3, int Ashift, int Bshift, int Cshift)
{
	A.SetName(name1);
	B.SetName(name2);
	C.SetName(name3);
	this->Ashift = Ashift;
	this->Bshift = Bshift;
	this->Cshift = Cshift;
}

Client::Client(string name, int number)
{
	this->name = name;
	this->number = number;
}

int Doctor::FindShift(int New, int month, int Doctor)
{
	int shift;
	if (Doctor == 1)
	{
		shift = this->Ashift;
	}
	if (Doctor == 2)
	{
		shift = this->Bshift;
	}
	if (Doctor == 3)
	{
		shift = this->Cshift;
	}
	if (New == 0)
	{
		A.NewTimetable(month, this->Ashift);
		B.NewTimetable(month, this->Bshift);
		C.NewTimetable(month, this->Cshift);
	}
	return shift;
}

void Doctor::FindDay(int Doctor, int data)
{
	int day = 31;
	int** Days = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		Days[i] = new int[day];
	}
	if (Doctor == 1)
	{
		Days = A.GetTimetable();
		day = A.GetDay();
	}
	if (Doctor == 2)
	{
		Days = B.GetTimetable();
		day = B.GetDay();
	}
	if (Doctor == 3)
	{
		Days = C.GetTimetable();
		day = C.GetDay();
	}
	cout << "������� �i���� �� ��� �i����:" << endl;
	for (int i = 0; i < day; i++)
	{
		if (Days[0][i] >= data)
			cout << setw(3) << Days[0][i] << "    |";
	}
	cout << endl;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < day; j++)
		{
			if (Days[0][j] >= data)
			{
				if (Days[i][j] == 0) cout << setw(3) << "�������|";
				else cout << setw(3) << Days[i][j] << ":00 |";
			}
		}
		cout << endl;
	}
	cout << endl;
}

bool Doctor::CheckDay(int data)
{
	int check = false;
	int** Days = A.GetTimetable();
	int day = A.GetDay();
	for (int i = 0; i < day; i++)
	{
		if (Days[0][i] == data)
			check = true;
	}
	return check;
}

void Doctor::coutPerson()
{
	cout << "1. " << A.GetName() << endl;
	cout << "2. " << B.GetName() << endl;
	cout << "3. " << C.GetName() << endl;
}

string Doctor::FindPerson(int choice)
{
	string name;
	if (choice == 1)
	{
		name = A.GetName();
	}
	if (choice == 2)
	{
		name = B.GetName();
	}
	if (choice == 3)
	{
		name = C.GetName();
	}
	return name;
}

void Doctor::ChangeTimetable(int Doctor, int time, int data)
{
	int day = 31;
	int** Days = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		Days[i] = new int[day];
	}
	if (Doctor == 1)
	{
		Days = A.GetTimetable();
		day = A.GetDay();
		for (int i = 1; i < 5; i++)
		{
			for (int j = 0; j < day; j++)
			{
				if (Days[0][j] == data)
				{
					if (time == Days[i][j])
						Days[i][j] = 0;
				}
			}
		}
		A.SetTimetable(Days);
	}
	if (Doctor == 2)
	{
		Days = B.GetTimetable();
		day = B.GetDay();
		for (int i = 1; i < 5; i++)
		{
			for (int j = 0; j < day; j++)
			{
				if (Days[0][j] == data)
				{
					if (time == Days[i][j])
						Days[i][j] = 0;
				}
			}
		}
		B.SetTimetable(Days);
	}
	if (Doctor == 3)
	{
		Days = C.GetTimetable();
		day = C.GetDay();
		for (int i = 1; i < 5; i++)
		{
			for (int j = 0; j < day; j++)
			{
				if (Days[0][j] == data)
				{
					if (time == Days[i][j])
						Days[i][j] = 0;
				}
			}
		}
		C.SetTimetable(Days);
	}
}

Client::Client()
{
	this->name = "Name";
	this->number = 0;
	int quantity = 20;
	string** Card = new string * [quantity];
	for (int i = 0; i < quantity; i++)
	{
		Card[i] = new string[6];
	}
	this->Cards = Card;
}

void Client::SetClient(string name, int number)
{
	this->name = name;
	this->number = number;
}

string Client::GetClientName()
{
	return name;
}

int Client::GetClientNum()
{
	return number;
}

string Client::FindPerson(int choice)
{
	string doctor;
	if (choice == 1)
	{
		doctor = "���";
	}
	if (choice == 2)
	{
		doctor = "����������";
	}
	if (choice == 3)
	{
		doctor = "ճ����";
	}
	if (choice == 4)
	{
		doctor = "����������";
	}
	if (choice == 5)
	{
		doctor = "ĳ������";
	}
	if (choice == 6)
	{
		doctor = "��������";
	}
	if (choice == 7)
	{
		doctor = "��������";
	}
	if (choice == 8)
	{
		doctor = "�������";
	}
	if (choice == 9)
	{
		doctor = "������";
	}
	if (choice == 10)
	{
		doctor = "��������";
	}
	if (choice == 11)
	{
		doctor = "��������";
	}
	if (choice == 12)
	{
		doctor = "������";
	}
	return doctor;
}

void Client::NewClient(int New, string doctor, int choice, int data, int month, int time)
{
	int quantity = 20;
	string** Card = this->Cards;
	Card[New][0] = GetClientName();
	Card[New][1] = "����� ��������: 380" + to_string(GetClientNum());
	Card[New][2] = "˳���: " + doctor;
	if (month < 10)
		Card[New][3] = "���� �������: " + to_string(data) + ".0" + to_string(month);
	else
		Card[New][3] = "���� �������: " + to_string(data) + "." + to_string(month);
	Card[New][4] = "��� �������: " + to_string(time) + ":00";
	Card[New][5] = "ĳ�����: " + Diagnosis(choice);
	this->Cards = Card;
}

void Client::coutPerson()
{
	string name;
	cout << endl << "���� ������� �� ��'�: ";
	cin.ignore();
	getline(cin, name);
	string** Card = this->Cards;
	cout << "====================================================================" << endl;
	for (int i = 0; i < 20; i++)
	{
		if (Card[i][0] == name)
		{
			cout << endl << "�볺��: " << Card[i][0] << endl;
			for (int j = 1; j <= 6; j++)
			{
				cout << Card[i][j] << endl;
			}
		}
	}
	cout << "====================================================================" << endl;
}

string Client::Diagnosis(int choice)
{
	srand(time(NULL));
	string doctor = FindPerson(choice);
	string diagnosis;
	int N = rand() % (3 - 1 + 1) + 1;
	if (doctor == "���")
	{
		if (N == 1)
			diagnosis = "�������� �������";
		if (N == 2)
			diagnosis = "�������� �������";
		if (N == 3)
			diagnosis = "���������� ���������� ����";
	}
	if (doctor == "����������")
	{
		if (N == 1)
			diagnosis = "��������� ����� ����";
		if (N == 2)
			diagnosis = "���������� ������ ������";
		if (N == 3)
			diagnosis = "�������-������";
	}
	if (doctor == "ճ����")
	{
		if (N == 1)
			diagnosis = "���� �������� ������� �����";
		if (N == 2)
			diagnosis = "������� ���������� � ���䳿";
		if (N == 3)
			diagnosis = "��������� ������� ������ �� �������������� �����";
	}
	if (doctor == "����������")
	{
		if (N == 1)
			diagnosis = "���� � ����������� ������";
		if (N == 2)
			diagnosis = "�������� � ������";
		if (N == 3)
			diagnosis = "̳��� � �������";
	}
	if (doctor == "ĳ������")
	{
		if (N == 1)
			diagnosis = "������ �� ��������� �������";
		if (N == 2)
			diagnosis = "ó���������";
		if (N == 3)
			diagnosis = "������������ ��������-��������� ������";
	}
	if (doctor == "��������")
	{
		if (N == 1)
			diagnosis = "������� ������� �����";
		if (N == 2)
			diagnosis = "���������� ���������";
		if (N == 3)
			diagnosis = "��������� ��������� �����";
	}
	if (doctor == "��������")
	{
		if (N == 1)
			diagnosis = "������ �������";
		if (N == 2)
			diagnosis = "��������� ��������� �����";
		if (N == 3)
			diagnosis = "������� ���������";
	}
	if (doctor == "�������")
	{
		if (N == 1)
			diagnosis = "ĳ�������� ��������";
		if (N == 2)
			diagnosis = "������������";
		if (N == 3)
			diagnosis = "����������� �� ����������� ����";
	}
	if (doctor == "������")
	{
		if (N == 1)
			diagnosis = "��������";
		if (N == 2)
			diagnosis = "������� ��������";
		if (N == 3)
			diagnosis = "����������� �����";
	}
	if (doctor == "��������")
	{
		if (N == 1)
			diagnosis = "������������ � ������� ������� �������";
		if (N == 2)
			diagnosis = "�������� ���������";
		if (N == 3)
			diagnosis = "������� ���������� ��������";
	}
	if (doctor == "��������")
	{
		if (N == 1)
			diagnosis = "������� ��������� ������";
		if (N == 2)
			diagnosis = "COVID-19";
		if (N == 3)
			diagnosis = "������ �����������-������ ��������";
	}
	if (doctor == "������")
	{
		if (N == 1)
			diagnosis = "�������������";
		if (N == 2)
			diagnosis = "���������";
		if (N == 3)
			diagnosis = "���������";
	}
	return diagnosis;
}
