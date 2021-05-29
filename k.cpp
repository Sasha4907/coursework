#include <iostream>
#include <math.h>
#include <Windows.h>
#include <limits>
#include "Header.h"
#include "Source1.cpp"

using namespace std;

int main()
{
    int New = 0, New1 = 0, New2 = 0, New3 = 0, New4 = 0, New5 = 0, New6 = 0, New7 = 0, New8 = 0, New9 = 0, New10 = 0, New11 = 0, New12 = 0;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice, chSpecialist, chDoctor, shift, data, month, day, time;
    string doctor = "name", nameDoctor;
    cout << "���� ���������� ��-02 || ������� ������" << endl;
    Staff Lore("������ �����", "������� ����", "��������� �����", 2, 1, 1);
    Staff Dentist("����������� ����", "����� ������", "��������� �����", 1, 2, 1);
    Staff Surgeon("�������� ������", "�������� ������", "������� �����", 2, 2, 1);
    Staff Dermatologist("��������� �����", "����� ���������", "���������� ������", 1, 1, 2);
    Staff Nutritionist("��������� ������", "���������� ���������", "�������� ������", 2, 1, 2);
    Staff Cardiologist("����� ����", "��������� ������", "���������� ������", 2, 2, 1);
    Staff Neurologist("��������� ��������", "���� ������", "������� �����", 1, 1, 2);
    Staff Orthopedist("������� �������", "���������� ����", "�������� ������", 2, 1, 1);
    Staff Pediatrician("������� �������", "˳��� ³�����", "�������� ������", 1, 2, 1);
    Staff Psychiatrist("���������� ³����", "ϳ������ ����", "�������� �����", 2, 1, 2);
    Staff Therapist("����� ĳ���", "��������� �������", "�������� ���������", 2, 2, 1);
    Staff Ophthalmologist("��������� �����", "��������� �������", "���� ���������", 1, 1, 2);
    string name;
    int number, n, password;
    bool p = true, k = true;
    Client A;
    while (true)
    {
        p = true;
        k = true;
        cout << endl << "====================================================================" << endl;
        cout << "0 ���i�" << endl;
        cout << "1 ˳���" << endl;
        cout << "2 �������" << endl;
        cout << "====================================================================" << endl;
        cout << "���� �����, ������� ��� ������: ";
        cin >> choice;
        if (choice > 2)
        {
            cout << "�������! ������� �� ���!" << endl;
            continue;
        }
        switch (choice)
        {
        case 0:
        {
            cout << endl;
            system("pause");
            return 0;
            break;
        }
        case 1:
        {
            bool find = true;
            do
            {
                cout << endl << "������ ������: ";
                cin >> password;
            } while (password != 4907);
            do
            {
                cout << endl << "���� ������� �� ��'�: ";
                cin.ignore();
                getline(cin, name);
                find = Lore.FindDoctor(name);
                if (find == false)
                    find = Dentist.FindDoctor(name);
                if (find == false)
                    find = Surgeon.FindDoctor(name);
                if (find == false)
                    find = Dermatologist.FindDoctor(name);
                if (find == false)
                    find = Nutritionist.FindDoctor(name);
                if (find == false)
                    find = Cardiologist.FindDoctor(name);
                if (find == false)
                    find = Neurologist.FindDoctor(name);
                if (find == false)
                    find = Orthopedist.FindDoctor(name);
                if (find == false)
                    find = Pediatrician.FindDoctor(name);
                if (find == false)
                    find = Psychiatrist.FindDoctor(name);
                if (find == false)
                    find = Therapist.FindDoctor(name);
                if (find == false)
                    find = Ophthalmologist.FindDoctor(name);
            } while (find == false);
            while (k == true)
            {
                cout << endl << "====================================================================" << endl;
                cout << "0 ���i�" << endl;
                cout << "1 ����������� �������" << endl;
                cout << "2 ��������� ������" << endl;
                cout << "====================================================================" << endl;
                cout << "�����i�� �i�: ";
                cin >> choice;
                if (choice > 2)
                {
                    cout << "�������! ������� �� ���!" << endl;
                    continue;
                }
                switch (choice)
                {
                case 0:
                {
                    k = false;
                    break;
                }
                case 1:
                {
                    do
                    {
                        cout << endl << "���� �����, ������ ������ ����: ����: ";
                        cin >> data;
                        cout << "                                 ̳����: ";
                        cin >> month;
                    } while (data > 31 || month > 12);
                    if (find == Lore.FindDoctor(name))
                        Lore.FindDay(name, data);
                    if (find == Dentist.FindDoctor(name))
                        Dentist.FindDay(name, data);
                    if (find == Surgeon.FindDoctor(name))
                        Surgeon.FindDay(name, data);
                    if (find == Dermatologist.FindDoctor(name))
                        Dermatologist.FindDay(name, data);
                    if (find == Nutritionist.FindDoctor(name))
                        Nutritionist.FindDay(name, data);
                    if (find == Cardiologist.FindDoctor(name))
                        Cardiologist.FindDay(name, data);
                    if (find == Neurologist.FindDoctor(name))
                        Neurologist.FindDay(name, data);
                    if (find == Orthopedist.FindDoctor(name))
                        Orthopedist.FindDay(name, data);
                    if (find == Pediatrician.FindDoctor(name))
                        Pediatrician.FindDay(name, data);
                    if (find == Psychiatrist.FindDoctor(name))
                        Psychiatrist.FindDay(name, data);
                    if (find == Therapist.FindDoctor(name))
                        Therapist.FindDay(name, data);
                    if (find == Ophthalmologist.FindDoctor(name))
                        Ophthalmologist.FindDay(name, data);
                    find = A.FindClient(name);
                    if (find = false)
                        cout << "������� �� ��!" << endl;
                }
                break;
                case 2:
                {
                    A.Diagnosis(name);
                }
                break;
                }
            }
        }
        break;
        case 2:
        {
            while (p == true)
            {
                cout << endl << "====================================================================" << endl;
                cout << "0 ���i�" << endl;
                cout << "1 �������������� �� ������ �� �i����" << endl;
                cout << "2 ����������� ������" << endl;
                cout << "====================================================================" << endl;
                cout << "�����i�� �i�: ";
                cin >> choice;
                if (choice > 2)
                {
                    cout << "�������! ������� �� ���!" << endl;
                    continue;
                }
                switch (choice)
                {
                case 0:
                {
                    p = false;
                    break;
                }
                case 1:
                {
                    cout << endl << "���� ������� �� ��'�: ";
                    cin.ignore();
                    getline(cin, name);
                    do
                    {
                        cout << "��� ����� ��������: 380";
                        cin >> number;
                        A.SetClient(name, number);
                        for (n = 0; number > 10; n++)
                        {
                            number /= 10;

                        }
                    } while (n < 8);
                    cout << endl << "����� ��:" << endl;
                    cout << "   1. ���" << endl;
                    cout << "   2. ����������" << endl;
                    cout << "   3. �i����" << endl;
                    cout << "   4. ����������" << endl;
                    cout << "   5. ĳ������" << endl;
                    cout << "   6. ��������" << endl;
                    cout << "   7.��������" << endl;
                    cout << "   8. �������" << endl;
                    cout << "   9. ������" << endl;
                    cout << "   10. ��������" << endl;
                    cout << "   11. ��������" << endl;
                    cout << "   12. ������" << endl;
                    do
                    {
                        cout << "����i�� ����i��i���: ";
                        cin >> chSpecialist;
                    } while (chSpecialist > 12 || chSpecialist == 0);
                    cout << endl;
                    if (chSpecialist == 1)
                    {
                        Lore.coutPerson();
                        do
                        {
                            cout << "������� �i����: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Lore.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "���� �����, ������ ������ ����: ����: ";
                            cin >> data;
                            cout << "                                 ̳����: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Lore.FindShift(New1, month, chDoctor);
                        Lore.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "������� ����: ";
                            cin >> day;
                            check = Lore.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "������� ���: ";
                            cin >> time;
                            if (shift == 1)
                            {
                                min = 7;
                                max = 12;
                            }
                            if (shift == 2)
                            {
                                min = 13;
                                max = 18;
                            }
                        } while (time <= min || time >= max);
                        Lore.ChangeTimetable(chDoctor, time, day);
                        New1++;
                    }
                    if (chSpecialist == 2)
                    {
                        Dentist.coutPerson();
                        do
                        {
                            cout << "������� �i����: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Dentist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "���� �����, ������ ������ ����: ����: ";
                            cin >> data;
                            cout << "                                 ̳����: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Dentist.FindShift(New2, month, chDoctor);
                        Dentist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "������� ����: ";
                            cin >> day;
                            check = Dentist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "������� ���: ";
                            cin >> time;
                            if (shift == 1)
                            {
                                min = 7;
                                max = 12;
                            }
                            if (shift == 2)
                            {
                                min = 13;
                                max = 18;
                            }
                        } while (time <= min || time >= max);
                        Dentist.ChangeTimetable(chDoctor, time, day);
                        New2++;
                    }
                    if (chSpecialist == 3)
                    {
                        Surgeon.coutPerson();
                        do
                        {
                            cout << "������� �i����: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Surgeon.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "���� �����, ������ ������ ����: ����: ";
                            cin >> data;
                            cout << "                                 ̳����: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Surgeon.FindShift(New3, month, chDoctor);
                        Surgeon.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "������� ����: ";
                            cin >> day;
                            check = Surgeon.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "������� ���: ";
                            cin >> time;
                            if (shift == 1)
                            {
                                min = 7;
                                max = 12;
                            }
                            if (shift == 2)
                            {
                                min = 13;
                                max = 18;
                            }
                        } while (time <= min || time >= max);
                        Surgeon.ChangeTimetable(chDoctor, time, day);
                        New3++;
                    }
                    if (chSpecialist == 4)
                    {
                        Dermatologist.coutPerson();
                        do
                        {
                            cout << "������� �i����: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Dermatologist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "���� �����, ������ ������ ����: ����: ";
                            cin >> data;
                            cout << "                                 ̳����: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Dermatologist.FindShift(New4, month, chDoctor);
                        Dermatologist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "������� ����: ";
                            cin >> day;
                            check = Dermatologist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "������� ���: ";
                            cin >> time;
                            if (shift == 1)
                            {
                                min = 7;
                                max = 12;
                            }
                            if (shift == 2)
                            {
                                min = 13;
                                max = 18;
                            }
                        } while (time <= min || time >= max);
                        Dermatologist.ChangeTimetable(chDoctor, time, day);
                        New4++;
                    }
                    if (chSpecialist == 5)
                    {
                        Nutritionist.coutPerson();
                        do
                        {
                            cout << "������� �i����: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Nutritionist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "���� �����, ������ ������ ����: ����: ";
                            cin >> data;
                            cout << "                                 ̳����: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Nutritionist.FindShift(New5, month, chDoctor);
                        Nutritionist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "������� ����: ";
                            cin >> day;
                            check = Nutritionist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "������� ���: ";
                            cin >> time;
                            if (shift == 1)
                            {
                                min = 7;
                                max = 12;
                            }
                            if (shift == 2)
                            {
                                min = 13;
                                max = 18;
                            }
                        } while (time <= min || time >= max);
                        Nutritionist.ChangeTimetable(chDoctor, time, day);
                        New5++;
                    }
                    if (chSpecialist == 6)
                    {
                        Cardiologist.coutPerson();
                        do
                        {
                            cout << "������� �i����: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Cardiologist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "���� �����, ������ ������ ����: ����: ";
                            cin >> data;
                            cout << "                                 ̳����: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Cardiologist.FindShift(New6, month, chDoctor);
                        Cardiologist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "������� ����: ";
                            cin >> day;
                            check = Cardiologist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "������� ���: ";
                            cin >> time;
                            if (shift == 1)
                            {
                                min = 7;
                                max = 12;
                            }
                            if (shift == 2)
                            {
                                min = 13;
                                max = 18;
                            }
                        } while (time <= min || time >= max);
                        Cardiologist.ChangeTimetable(chDoctor, time, day);
                        New6++;
                    }
                    if (chSpecialist == 7)
                    {
                        Neurologist.coutPerson();
                        do
                        {
                            cout << "������� �i����: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Neurologist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "���� �����, ������ ������ ����: ����: ";
                            cin >> data;
                            cout << "                                 ̳����: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Neurologist.FindShift(New7, month, chDoctor);
                        Neurologist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "������� ����: ";
                            cin >> day;
                            check = Neurologist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "������� ���: ";
                            cin >> time;
                            if (shift == 1)
                            {
                                min = 7;
                                max = 12;
                            }
                            if (shift == 2)
                            {
                                min = 13;
                                max = 18;
                            }
                        } while (time <= min || time >= max);
                        Neurologist.ChangeTimetable(chDoctor, time, day);
                        New7++;
                    }
                    if (chSpecialist == 8)
                    {
                        Orthopedist.coutPerson();
                        do
                        {
                            cout << "������� �i����: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Orthopedist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "���� �����, ������ ������ ����: ����: ";
                            cin >> data;
                            cout << "                                 ̳����: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Orthopedist.FindShift(New8, month, chDoctor);
                        Orthopedist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "������� ����: ";
                            cin >> day;
                            check = Orthopedist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "������� ���: ";
                            cin >> time;
                            if (shift == 1)
                            {
                                min = 7;
                                max = 12;
                            }
                            if (shift == 2)
                            {
                                min = 13;
                                max = 18;
                            }
                        } while (time <= min || time >= max);
                        Orthopedist.ChangeTimetable(chDoctor, time, day);
                        New8++;
                    }
                    if (chSpecialist == 9)
                    {
                        Pediatrician.coutPerson();
                        do
                        {
                            cout << "������� �i����: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Pediatrician.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "���� �����, ������ ������ ����: ����: ";
                            cin >> data;
                            cout << "                                 ̳����: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Pediatrician.FindShift(New9, month, chDoctor);
                        Pediatrician.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "������� ����: ";
                            cin >> day;
                            check = Pediatrician.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "������� ���: ";
                            cin >> time;
                            if (shift == 1)
                            {
                                min = 7;
                                max = 12;
                            }
                            if (shift == 2)
                            {
                                min = 13;
                                max = 18;
                            }
                        } while (time <= min || time >= max);
                        Pediatrician.ChangeTimetable(chDoctor, time, day);
                        New9++;
                    }
                    if (chSpecialist == 10)
                    {
                        Psychiatrist.coutPerson();
                        do
                        {
                            cout << "������� �i����: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Psychiatrist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "���� �����, ������ ������ ����: ����: ";
                            cin >> data;
                            cout << "                                 ̳����: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Psychiatrist.FindShift(New10, month, chDoctor);
                        Psychiatrist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "������� ����: ";
                            cin >> day;
                            check = Psychiatrist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "������� ���: ";
                            cin >> time;
                            if (shift == 1)
                            {
                                min = 7;
                                max = 12;
                            }
                            if (shift == 2)
                            {
                                min = 13;
                                max = 18;
                            }
                        } while (time <= min || time >= max);
                        Psychiatrist.ChangeTimetable(chDoctor, time, day);
                        New10++;
                    }
                    if (chSpecialist == 11)
                    {
                        Therapist.coutPerson();
                        do
                        {
                            cout << "������� �i����: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Therapist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "���� �����, ������ ������ ����: ����: ";
                            cin >> data;
                            cout << "                                 ̳����: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Therapist.FindShift(New11, month, chDoctor);
                        Therapist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "������� ����: ";
                            cin >> day;
                            check = Therapist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "������� ���: ";
                            cin >> time;
                            if (shift == 1)
                            {
                                min = 7;
                                max = 12;
                            }
                            if (shift == 2)
                            {
                                min = 13;
                                max = 18;
                            }
                        } while (time <= min || time >= max);
                        Therapist.ChangeTimetable(chDoctor, time, day);
                        New11++;
                    }
                    if (chSpecialist == 12)
                    {
                        Ophthalmologist.coutPerson();
                        do
                        {
                            cout << "������� �i����: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Ophthalmologist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "���� �����, ������ ������ ����: ����: ";
                            cin >> data;
                            cout << "                                 ̳����: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Ophthalmologist.FindShift(New12, month, chDoctor);
                        Ophthalmologist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "������� ����: ";
                            cin >> day;
                            check = Ophthalmologist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "������� ���: ";
                            cin >> time;
                            if (shift == 1)
                            {
                                min = 7;
                                max = 12;
                            }
                            if (shift == 2)
                            {
                                min = 13;
                                max = 18;
                            }
                        } while (time <= min || time >= max);
                        Ophthalmologist.ChangeTimetable(chDoctor, time, day);
                        New12++;
                    }
                    A.NewClient(New, doctor, day, month, time);
                    cout << endl << "�� ������� ��: " << doctor;
                    if (month < 10)
                        cout << endl << "���� �������: " << day << ".0" << month;
                    else
                        cout << endl << "���� �������: " << day << "." << month;
                    cout << endl << "��� �������: " << time << ":00";
                    cout << endl << "�������� ��� �� �������: 380" << A.GetClientNum();
                    cout << endl << endl;
                    New++;
                }
                break;
                case 2:
                {
                    A.coutPerson();
                }
                break;
                }
            }
        }
        break;
        }
    }
    system("pause");
    return 0;
}
