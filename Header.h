#pragma once
#include <iostream>
#include <string>
using namespace std;

class Find											                // ����������� ����
{
public:
	virtual void coutPerson() = 0;                                 	// ����� ��� ��������� ������ ���
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

class Staff :protected Find	        						     	// �������� ���� �� Find �� People
{
protected:
	People A;
	People B;
	People C;
	int Ashift;									                 	// ���� �������
	int Bshift; 									             	// ���� �������
	int Cshift; 									             	// ���� �������
public:
	Staff(string name1, string name2, string name3, int Ashift, int Bshift, int Cshift); 	// ����������� � �����������
	Staff(const Staff& other);                                      // ����������� ���������
	void FindDay(string Doctor, int data);						    // ���� �������� ����� ��������� � ������� ����								
	bool CheckDay(int day);                                         //�������� ��� �������� ���� ��� ������� � ������� �����
	int FindShift(int New, int month, int Doctor);				    // ���� ���� ��������� �����
	string FindPerson(int choice);							        //���� ��������� �����
	void coutPerson() override;								        // ��������������, ���� �����
	void ChangeTimetable(int Doctor, int time, int data);           // ����� �������
	bool FindDoctor(string name);                                   //���� ����� � ���
};

class Client : public Find								            // �������� ���� �� Find
{
protected:
	string name;									             	// ������� �� ��� �����������
	int number;									                	// ����� �����������
	string** Cards;										            // ���� ��� ��������
public:
	Client();											            // ����������� �� �������������
	Client(string name, int number);								// ����������� � �����������
	void SetClient(string name, int number);				    	// ������� �������, ���� �� ������ ��������
	string GetClientName();						        			// ���� ������� ����
	int GetClientNum();									            // ���� ������ ��������
	void NewClient(int New, string doctor, int data, int month, int time);	// ���� ������ �������� � ���� �����
	void coutPerson() override;						                // ��������������, ���� ������ ��������
	bool FindClient(string name);                                   //���� �������� �����
	void Diagnosis(string name);                                    //��� �������
};

