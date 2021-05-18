#pragma once
#include <iostream>
#include <string>
using namespace std;

class Find											                // ����������� ����
{
public:
	virtual void coutPerson() = 0;                                 	// ����� ��� ��������� ������ ���
	virtual string FindPerson(int choice) = 0;						// ����� ��� ������ ���� �������
};


class People
{
protected:
	string name;									             	// ������� �� ���
	int** Timetable;									            // ������� �����
	int day;											            // ������� ������� ���
	int Weekdays(int** Days, int month);							// ������ ��� ��� ������ ��
	int Delete(int** Days, int* Mi, int k);							// ����� ������ ��
public:
	People();									                 	// ����������� �� �������������
	People(string name);							         		// ����������� � �����������
	string GetName();								            	// ���� ������� �� ����
	int GetDay();										            // ���� ������� ������� ���
	void SetName(string name);								        // ������� ������� �� ����
	void NewTimetable(int month, int shift);						// �������� ����� ������� ��� (1�31) �� �������
	void SetTimetable(int** Days);							     	// ������� ��������
	int** GetTimetable();									        // ���� ��������
};

class Doctor :protected People, Find								// �������� ���� �� Find �� People
{
protected:
	People A;
	People B;
	People C;
	int Ashift;									                 	// ���� �������
	int Bshift; 									             	// ���� �������
	int Cshift; 									             	// ���� �������
public:
	Doctor(string name1, string name2, string name3, int Ashift, int Bshift, int Cshift); 	// ����������� � �����������
	Doctor(const Doctor& other);
	void FindDay(int Doctor, int data);						     	// ���� �������� ����� ��������� � ������� ����								// ����������� ���������
	bool CheckDay(int day);                                         //�������� ��� �������� ���� ��� ������� � ������� �����
	int FindShift(int New, int month, int Doctor);				    // ���� ���� ��������� �����
	string FindPerson(int choice) override;							// ��������������, ���� ��������� �����
	void coutPerson() override;								        // ��������������, ���� �����
	void ChangeTimetable(int Doctor, int time, int data);           // ����� �������
};

class Client : protected Find								     	// �������� ���� �� Find
{
private:
	string name;									             	// ������� �� ��� �����������
	int number;									                	// ����� �����������
	string** Cards;										            // ���� ��� ��������
	string Diagnosis(int chDoctor);								    // ���� �������
public:
	Client();											            // ����������� �� �������������
	Client(string name, int number);								// ����������� � �����������
	void SetClient(string name, int number);				    	// ������� �������, ���� �� ������ ��������
	string GetClientName();						        			// ���� ������� ����
	int GetClientNum();									            // ���� ������ ��������
	string FindPerson(int choice) override;							// ��������������, ���� ������������ ����� ��� ������ ������
	void NewClient(int New, string doctor, int chDoctor, int data, int month, int time);	// ���� ������ �������� � ���� �����
	void coutPerson() override;								        // ��������������, ���� ������ ��������
};

