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
    cout << "Педь Олександра ІС-02 || Курсова робота" << endl;
    Staff Lore("Зайцев Сергій", "Антонюк Анна", "Симоненко Андрій", 2, 1, 1);
    Staff Dentist("Кондратенко Ігор", "Гусак Максим", "Антоненко Мирон", 1, 2, 1);
    Staff Surgeon("Лебедева Марина", "Панченко Дмитро", "Кучярев Сергій", 2, 2, 1);
    Staff Dermatologist("Макаренко Антон", "Стоян Володимир", "Головацько Галина", 1, 1, 2);
    Staff Nutritionist("Гринченко Валерія", "Незабудько Олександр", "Чепурний Микита", 2, 1, 2);
    Staff Cardiologist("Лебідь Анна", "Коваленко Василій", "Криворучко Степан", 2, 2, 1);
    Staff Neurologist("Загородня Анастасія", "Ткач Арсеній", "Миронов Андрій", 1, 1, 2);
    Staff Orthopedist("Соломов Григорій", "Орлянський Даніїл", "Горбачев Кирилл", 2, 1, 1);
    Staff Pediatrician("Крутько Світлана", "Літух Вікторія", "Ткаченко Дмитро", 1, 2, 1);
    Staff Psychiatrist("Солохненко Віктор", "Пінченко Анна", "Шарапата Ганна", 2, 1, 2);
    Staff Therapist("Луцик Діана", "Приходько Світлана", "Похилько Олександр", 2, 2, 1);
    Staff Ophthalmologist("Гомбалева Поліна", "Авраменко Григорій", "Стус Святослав", 1, 1, 2);
    string name;
    int number, n, password;
    bool p = true, k = true;
    Client A;
    while (true)
    {
        p = true;
        k = true;
        cout << endl << "====================================================================" << endl;
        cout << "0 Вихiд" << endl;
        cout << "1 Лікар" << endl;
        cout << "2 Пацієнт" << endl;
        cout << "====================================================================" << endl;
        cout << "Будь ласка, виберіть свій варіант: ";
        cin >> choice;
        if (choice > 2)
        {
            cout << "Помилка! Виберіть ще раз!" << endl;
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
                cout << endl << "Введіть пароль: ";
                cin >> password;
            } while (password != 4907);
            do
            {
                cout << endl << "Ваше прізвище та ім'я: ";
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
                cout << "0 Вихiд" << endl;
                cout << "1 Переглянути розклад" << endl;
                cout << "2 Поставити діагноз" << endl;
                cout << "====================================================================" << endl;
                cout << "Виберiть дiю: ";
                cin >> choice;
                if (choice > 2)
                {
                    cout << "Помилка! Виберіть ще раз!" << endl;
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
                        cout << endl << "Будь ласка, вкажіть бажану дату: День: ";
                        cin >> data;
                        cout << "                                 Місяць: ";
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
                        cout << "Прийомів не має!" << endl;
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
                cout << "0 Вихiд" << endl;
                cout << "1 Зареєструватись на прийом до лiкаря" << endl;
                cout << "2 Переглянути анкету" << endl;
                cout << "====================================================================" << endl;
                cout << "Виберiть дiю: ";
                cin >> choice;
                if (choice > 2)
                {
                    cout << "Помилка! Виберіть ще раз!" << endl;
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
                    cout << endl << "Ваше прізвище та ім'я: ";
                    cin.ignore();
                    getline(cin, name);
                    do
                    {
                        cout << "Ваш номер телефону: 380";
                        cin >> number;
                        A.SetClient(name, number);
                        for (n = 0; number > 10; n++)
                        {
                            number /= 10;

                        }
                    } while (n < 8);
                    cout << endl << "Запис до:" << endl;
                    cout << "   1. Лор" << endl;
                    cout << "   2. Стоматолог" << endl;
                    cout << "   3. Хiрург" << endl;
                    cout << "   4. Дерматолог" << endl;
                    cout << "   5. Дієтолог" << endl;
                    cout << "   6. Кардіолог" << endl;
                    cout << "   7.Невролог" << endl;
                    cout << "   8. Ортопед" << endl;
                    cout << "   9. Педіатр" << endl;
                    cout << "   10. Психіатр" << endl;
                    cout << "   11. Терапевт" << endl;
                    cout << "   12. Окуліст" << endl;
                    do
                    {
                        cout << "Оберiть спецiалiста: ";
                        cin >> chSpecialist;
                    } while (chSpecialist > 12 || chSpecialist == 0);
                    cout << endl;
                    if (chSpecialist == 1)
                    {
                        Lore.coutPerson();
                        do
                        {
                            cout << "Виберіть лiкаря: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Lore.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "Будь ласка, вкажіть бажану дату: День: ";
                            cin >> data;
                            cout << "                                 Місяць: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Lore.FindShift(New1, month, chDoctor);
                        Lore.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "Виберіть день: ";
                            cin >> day;
                            check = Lore.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "Виберіть час: ";
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
                            cout << "Виберіть лiкаря: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Dentist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "Будь ласка, вкажіть бажану дату: День: ";
                            cin >> data;
                            cout << "                                 Місяць: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Dentist.FindShift(New2, month, chDoctor);
                        Dentist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "Виберіть день: ";
                            cin >> day;
                            check = Dentist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "Виберіть час: ";
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
                            cout << "Виберіть лiкаря: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Surgeon.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "Будь ласка, вкажіть бажану дату: День: ";
                            cin >> data;
                            cout << "                                 Місяць: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Surgeon.FindShift(New3, month, chDoctor);
                        Surgeon.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "Виберіть день: ";
                            cin >> day;
                            check = Surgeon.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "Виберіть час: ";
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
                            cout << "Виберіть лiкаря: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Dermatologist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "Будь ласка, вкажіть бажану дату: День: ";
                            cin >> data;
                            cout << "                                 Місяць: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Dermatologist.FindShift(New4, month, chDoctor);
                        Dermatologist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "Виберіть день: ";
                            cin >> day;
                            check = Dermatologist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "Виберіть час: ";
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
                            cout << "Виберіть лiкаря: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Nutritionist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "Будь ласка, вкажіть бажану дату: День: ";
                            cin >> data;
                            cout << "                                 Місяць: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Nutritionist.FindShift(New5, month, chDoctor);
                        Nutritionist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "Виберіть день: ";
                            cin >> day;
                            check = Nutritionist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "Виберіть час: ";
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
                            cout << "Виберіть лiкаря: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Cardiologist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "Будь ласка, вкажіть бажану дату: День: ";
                            cin >> data;
                            cout << "                                 Місяць: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Cardiologist.FindShift(New6, month, chDoctor);
                        Cardiologist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "Виберіть день: ";
                            cin >> day;
                            check = Cardiologist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "Виберіть час: ";
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
                            cout << "Виберіть лiкаря: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Neurologist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "Будь ласка, вкажіть бажану дату: День: ";
                            cin >> data;
                            cout << "                                 Місяць: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Neurologist.FindShift(New7, month, chDoctor);
                        Neurologist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "Виберіть день: ";
                            cin >> day;
                            check = Neurologist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "Виберіть час: ";
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
                            cout << "Виберіть лiкаря: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Orthopedist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "Будь ласка, вкажіть бажану дату: День: ";
                            cin >> data;
                            cout << "                                 Місяць: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Orthopedist.FindShift(New8, month, chDoctor);
                        Orthopedist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "Виберіть день: ";
                            cin >> day;
                            check = Orthopedist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "Виберіть час: ";
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
                            cout << "Виберіть лiкаря: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Pediatrician.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "Будь ласка, вкажіть бажану дату: День: ";
                            cin >> data;
                            cout << "                                 Місяць: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Pediatrician.FindShift(New9, month, chDoctor);
                        Pediatrician.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "Виберіть день: ";
                            cin >> day;
                            check = Pediatrician.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "Виберіть час: ";
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
                            cout << "Виберіть лiкаря: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Psychiatrist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "Будь ласка, вкажіть бажану дату: День: ";
                            cin >> data;
                            cout << "                                 Місяць: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Psychiatrist.FindShift(New10, month, chDoctor);
                        Psychiatrist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "Виберіть день: ";
                            cin >> day;
                            check = Psychiatrist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "Виберіть час: ";
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
                            cout << "Виберіть лiкаря: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Therapist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "Будь ласка, вкажіть бажану дату: День: ";
                            cin >> data;
                            cout << "                                 Місяць: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Therapist.FindShift(New11, month, chDoctor);
                        Therapist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "Виберіть день: ";
                            cin >> day;
                            check = Therapist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "Виберіть час: ";
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
                            cout << "Виберіть лiкаря: ";
                            cin >> chDoctor;
                        } while (chDoctor > 3 || chDoctor == 0);
                        doctor = Ophthalmologist.FindPerson(chDoctor);
                        do
                        {
                            cout << endl << "Будь ласка, вкажіть бажану дату: День: ";
                            cin >> data;
                            cout << "                                 Місяць: ";
                            cin >> month;
                        } while (data > 31 || month > 12);
                        shift = Ophthalmologist.FindShift(New12, month, chDoctor);
                        Ophthalmologist.FindDay(doctor, data);
                        bool check;
                        do
                        {
                            cout << endl << "Виберіть день: ";
                            cin >> day;
                            check = Ophthalmologist.CheckDay(day);

                        } while (day < data || check == false);
                        int min = 0, max = 0;
                        do
                        {
                            cout << endl << "Виберіть час: ";
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
                    cout << endl << "Ви записані до: " << doctor;
                    if (month < 10)
                        cout << endl << "Дата прийому: " << day << ".0" << month;
                    else
                        cout << endl << "Дата прийому: " << day << "." << month;
                    cout << endl << "Час прийому: " << time << ":00";
                    cout << endl << "Очікуйте смс за номером: 380" << A.GetClientNum();
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
