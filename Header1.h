#pragma once
#include <iostream>
#include <string>
using namespace std;

class Find											                // абстрактний клас
{
public:
	virtual void coutPerson() = 0;                                 	// метод для виведення списку осіб
	virtual string FindPerson(int choice) = 0;						// метод для вибору однієї персони
};


class People
{
protected:
	string name;									             	// прізвище та ім’я
	int** Timetable;									            // розклад лікаря
	int day;											            // кількість робочих днів
	int Weekdays(int** Days, int month);							// зберігає дані про вихідні дні
	int Delete(int** Days, int* Mi, int k);							// віднімає вихідні дні
public:
	People();									                 	// конструктор за замовчуванням
	People(string name);							         		// конструктор з параметрами
	string GetName();								            	// вивід прізвища та імені
	int GetDay();										            // вивід кількості робочих днів
	void SetName(string name);								        // задання прізвища та імені
	void NewTimetable(int month, int shift);						// заповнює масив робочих днів (1…31) та розклад
	void SetTimetable(int** Days);							     	// задання розкладу
	int** GetTimetable();									        // вивід розкладу
};

class Doctor :protected People, Find								// похідний клас від Find та People
{
protected:
	People A;
	People B;
	People C;
	int Ashift;									                 	// часи прийому
	int Bshift; 									             	// часи прийому
	int Cshift; 									             	// часи прийому
public:
	Doctor(string name1, string name2, string name3, int Ashift, int Bshift, int Cshift); 	// конструктор з параметрами
	Doctor(const Doctor& other);
	void FindDay(int Doctor, int data);						     	// вивід розкладу лікаря починаючи з поточної дати								// конструктор копіювання
	bool CheckDay(int day);                                         //перевіряє щоб вибраний день був робочим у графіку лікаря
	int FindShift(int New, int month, int Doctor);				    // шукає зміну вибраного лікаря
	string FindPerson(int choice) override;							// перевизначений, шукає вибраного лікаря
	void coutPerson() override;								        // перевизначений, вивід лікарів
	void ChangeTimetable(int Doctor, int time, int data);           // змінює розклад
};

class Client : protected Find								     	// похідний клас від Find
{
private:
	string name;									             	// прізвище та ім’я користувача
	int number;									                	// номер користувача
	string** Cards;										            // база всіх пацієнтів
	string Diagnosis(int chDoctor);								    // база діагнозів
public:
	Client();											            // конструктор за замовчуванням
	Client(string name, int number);								// конструктор з параметрами
	void SetClient(string name, int number);				    	// задання прізвища, імені та номеру телефону
	string GetClientName();						        			// вивід прізвища імені
	int GetClientNum();									            // вивід номеру телефону
	string FindPerson(int choice) override;							// перевизначений, шукає спеціальність лікаря щоб задати діагноз
	void NewClient(int New, string doctor, int chDoctor, int data, int month, int time);	// додає нового пацієнта в базу даних
	void coutPerson() override;								        // перевизначений, вивід картки пацієнта
};

