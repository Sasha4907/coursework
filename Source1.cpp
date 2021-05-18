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
	cout << "Розклад лiкаря на цей мiсяць:" << endl;
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
				if (Days[i][j] == 0) cout << setw(3) << "зайнято|";
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
		doctor = "Лор";
	}
	if (choice == 2)
	{
		doctor = "Стоматолог";
	}
	if (choice == 3)
	{
		doctor = "Хірург";
	}
	if (choice == 4)
	{
		doctor = "Дерматолог";
	}
	if (choice == 5)
	{
		doctor = "Дієтолог";
	}
	if (choice == 6)
	{
		doctor = "Кардіолог";
	}
	if (choice == 7)
	{
		doctor = "Нерволог";
	}
	if (choice == 8)
	{
		doctor = "Ортопед";
	}
	if (choice == 9)
	{
		doctor = "Педіатр";
	}
	if (choice == 10)
	{
		doctor = "Психіатр";
	}
	if (choice == 11)
	{
		doctor = "Терапевт";
	}
	if (choice == 12)
	{
		doctor = "Окуліст";
	}
	return doctor;
}

void Client::NewClient(int New, string doctor, int choice, int data, int month, int time)
{
	int quantity = 20;
	string** Card = this->Cards;
	Card[New][0] = GetClientName();
	Card[New][1] = "Номер телефону: 380" + to_string(GetClientNum());
	Card[New][2] = "Лікар: " + doctor;
	if (month < 10)
		Card[New][3] = "Дата прийому: " + to_string(data) + ".0" + to_string(month);
	else
		Card[New][3] = "Дата прийому: " + to_string(data) + "." + to_string(month);
	Card[New][4] = "Час прийому: " + to_string(time) + ":00";
	Card[New][5] = "Діагноз: " + Diagnosis(choice);
	this->Cards = Card;
}

void Client::coutPerson()
{
	string name;
	cout << endl << "Ваше прізвище та ім'я: ";
	cin.ignore();
	getline(cin, name);
	string** Card = this->Cards;
	cout << "====================================================================" << endl;
	for (int i = 0; i < 20; i++)
	{
		if (Card[i][0] == name)
		{
			cout << endl << "Клієнт: " << Card[i][0] << endl;
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
	if (doctor == "Лор")
	{
		if (N == 1)
			diagnosis = "Хронічний тонзиліт";
		if (N == 2)
			diagnosis = "Хронічний синусит";
		if (N == 3)
			diagnosis = "Деформація зовнішнього носа";
	}
	if (doctor == "Стоматолог")
	{
		if (N == 1)
			diagnosis = "Анатомічна форма зуба";
		if (N == 2)
			diagnosis = "Біомеханіка нижньої щелепи";
		if (N == 3)
			diagnosis = "Вкладка-пломба";
	}
	if (doctor == "Хірург")
	{
		if (N == 1)
			diagnosis = "Грижі передньої черевної стінки";
		if (N == 2)
			diagnosis = "Ахалазія стравоходу і кардії";
		if (N == 3)
			diagnosis = "Виразкова хвороба шлунка та дванадцятипалої кишки";
	}
	if (doctor == "Дерматолог")
	{
		if (N == 1)
			diagnosis = "Вугрі і контагіозний молюск";
		if (N == 2)
			diagnosis = "Дерматит і екзема";
		if (N == 3)
			diagnosis = "Мікоз і короста";
	}
	if (doctor == "Дієтолог")
	{
		if (N == 1)
			diagnosis = "Алергія та порушення апетиту";
		if (N == 2)
			diagnosis = "Гіповітаміноз";
		if (N == 3)
			diagnosis = "Захворювання шлунково-кишкового тракту";
	}
	if (doctor == "Кардіолог")
	{
		if (N == 1)
			diagnosis = "Ішемічна хвороба серця";
		if (N == 2)
			diagnosis = "Артеріальна гіпертензія";
		if (N == 3)
			diagnosis = "Порушення серцевого ритму";
	}
	if (doctor == "Нерволог")
	{
		if (N == 1)
			diagnosis = "Артроз суглобів";
		if (N == 2)
			diagnosis = "Запалення головного мозку";
		if (N == 3)
			diagnosis = "Хвороба Паркінсона";
	}
	if (doctor == "Ортопед")
	{
		if (N == 1)
			diagnosis = "Діабетична артопатія";
		if (N == 2)
			diagnosis = "Остеохондроз";
		if (N == 3)
			diagnosis = "Клишоногість та викривлення стоп";
	}
	if (doctor == "Педіатр")
	{
		if (N == 1)
			diagnosis = "Пневмонія";
		if (N == 2)
			diagnosis = "Кишкова інфекція";
		if (N == 3)
			diagnosis = "Бронхіальна астма";
	}
	if (doctor == "Психіатр")
	{
		if (N == 1)
			diagnosis = "Симптоматичні і органічні психічні розлади";
		if (N == 2)
			diagnosis = "Розумова відсталість";
		if (N == 3)
			diagnosis = "Розлади психічного розвитку";
	}
	if (doctor == "Терапевт")
	{
		if (N == 1)
			diagnosis = "Двобічне запалення легенів";
		if (N == 2)
			diagnosis = "COVID-19";
		if (N == 3)
			diagnosis = "Гостра респіраторна-вірусна інфекція";
	}
	if (doctor == "Окуліст")
	{
		if (N == 1)
			diagnosis = "Короткозорість";
		if (N == 2)
			diagnosis = "Катаракта";
		if (N == 3)
			diagnosis = "Косоокість";
	}
	return diagnosis;
}
