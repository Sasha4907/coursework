
#include <iostream>
#include <math.h>
#include <Windows.h>
#include <limits>
#include "Header1.h"
#include "Source1.cpp"
#ifdef max
#undef max
#endif
using namespace std;

int main()
{
    int New = 0, New1 = 0, New2 = 0, New3 = 0, New4 = 0, New5 = 0, New6 = 0, New7 = 0, New8 = 0, New9 = 0, New10 = 0, New11 = 0, New12 = 0;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice, chSpecialist, chDoctor, shift, data, month, day, time;
    string doctor = "name", nameDoctor;
    cout << "Педь Олександра ІС-02 || Курсова робота" << endl;
    Doctor Lore("Зайцев Сергій", "Антонюк Анна", "Симоненко Андрій", 2, 1, 1);
    Doctor Dentist("Кондратенко Ігор", "Гусак Максим", "Антоненко Мирон", 1, 2, 1);
    Doctor Surgeon("Лебедева Марина", "Панченко Дмитро", "Кучярев Сергій", 2, 2, 1);
    Doctor Dermatologist("Макаренко Антон", "Стоян Володимир", "Головацько Галина", 1, 1, 2);
    Doctor Nutritionist("Гринченко Валерія", "Незабудько Олександр", "Чепурний Микита", 2, 1, 2);
    Doctor Cardiologist("Лебідь Анна", "Коваленко Василій", "Криворучко Степан", 2, 2, 1);
    Doctor Neurologist("Загородня Анастасія", "Ткач Арсеній", "Миронов Андрій", 1, 1, 2);
    Doctor Orthopedist("Соломов Григорій", "Орлянський Даніїл", "Горбачев Кирилл", 2, 1, 1);
    Doctor Pediatrician("Крутько Світлана", "Літух Вікторія", "Ткаченко Дмитро", 1, 2, 1);
    Doctor Psychiatrist("Солохненко Віктор", "Пінченко Анна", "Шарапата Ганна", 2, 1, 2);
    Doctor Therapist("Луцик Діана", "Приходько Світлана", "Похилько Олександр", 2, 2, 1);
    Doctor Ophthalmologist("Гомбалева Поліна", "Авраменко Григорій", "Стус Святослав", 1, 1, 2);
    string name;
    int number, n;
    Client A;
    while (true)
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
            cout << endl;
            system("pause");
            return 0;
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
                Lore.FindDay(chDoctor, data);
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
                Dentist.FindDay(chDoctor, data);
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
                Surgeon.FindDay(chDoctor, data);
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
                Dermatologist.FindDay(chDoctor, data);
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
                Nutritionist.FindDay(chDoctor, data);
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
                Cardiologist.FindDay(chDoctor, data);
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
                Neurologist.FindDay(chDoctor, data);
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
                Orthopedist.FindDay(chDoctor, data);
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
                Pediatrician.FindDay(chDoctor, data);
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
                Psychiatrist.FindDay(chDoctor, data);
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
                Therapist.FindDay(chDoctor, data);
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
                Ophthalmologist.FindDay(chDoctor, data);
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
            A.NewClient(New, doctor, chSpecialist, day, month, time);
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
    system("pause");
    return 0;
}
