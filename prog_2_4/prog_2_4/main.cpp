#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const char* sign_zodiac[12] = { "Oven", "Telez", "Bliznezi", "Rak",
    "Lev", "Deva", "Vesy", "Scorpion",
    "Strelez", "Kozerog", "Vodoley", "Ryby" };

struct TZnak {
    char name[50]; // фамилия, имя
    char zodiac[20]; // знак зодиака
    int bday[3];
    operator int() const { return (*bday); }
    void operator()(char* str, char* str2, int mybday[3])
    {
        strcpy_s(name, str);
        strcpy_s(zodiac, str2);
        *bday = mybday[3];
    }
};
TZnak operator+(const TZnak& znak1, const TZnak& znak2)
{
    TZnak znak3 = znak1;

    strcat_s(znak3.name, znak3.name);
    strcat_s(znak3.zodiac, znak3.zodiac);
    znak3.bday[0] = znak3.bday[0] + znak2.bday[0];
    znak3.bday[1] = znak3.bday[1] + znak2.bday[1];
    znak3.bday[2] = znak3.bday[2] + znak2.bday[2];
    return znak3;
}
TZnak operator++(TZnak& znak)
{
    char name[10] = "IVANOV";
    char zodiac[10] = "OVEN";
    strcat_s(znak.name, name);
    strcat_s(znak.zodiac, zodiac);
    ++znak.bday[0];
    ++znak.bday[1];
    ++znak.bday[2];
    return znak;
}
bool operator>(const TZnak& Znak1, const TZnak& Znak2)
{
    int getIntZodiak(char* str);
    const int n = 3;
    TZnak book[n];
    for (int ctr1 = 0; ctr1 < 12; ctr1++) {
        for (int ctr2 = ctr1 + 1; ctr2 < 12; ctr2++) {
            if (getIntZodiak(book[ctr1].zodiac) > getIntZodiak(book[ctr2].zodiac)) // если порядок не правильный, то
            // поменять местами записи
            {
                char temp_name[50]; // временная переменная для перестановки строк: имя
                // и знак зодиака

                // перестановка имён
                strcpy_s(temp_name, book[ctr1].name);
                strcpy_s(book[ctr1].name, book[ctr2].name);
                strcpy_s(book[ctr2].name, temp_name);

                // перестановка знака зодиака
                strcpy_s(temp_name, book[ctr1].zodiac);
                strcpy_s(book[ctr1].zodiac, book[ctr2].zodiac);
                strcpy_s(book[ctr2].zodiac, temp_name);

                int temp_data[3] = {
                    book[ctr1].bday[0], book[ctr1].bday[1], book[ctr1].bday[2]
                }; // временный массив, для обмена д.р.

                book[ctr1].bday[0] = book[ctr2].bday[0];
                book[ctr1].bday[1] = book[ctr2].bday[1];
                book[ctr1].bday[2] = book[ctr2].bday[2];
                book[ctr2].bday[0] = temp_data[0];
                book[ctr2].bday[1] = temp_data[1];
                book[ctr2].bday[2] = temp_data[2];
            }
        }
    }
    return Znak1.zodiac > Znak2.zodiac;
}
ostream& operator<<(ostream& out, TZnak& Znak)
{
    out << setw(20) << setfill('.') << setiosflags(ios::left) << Znak.name
        << Znak.zodiac << Znak.bday[0] << "." << Znak.bday[1] << "."
        << Znak.bday[2] << endl;
    return out;
}
istream& operator>>(istream& in, TZnak& Znak)
{
    cout << "Vvedite FIO\n";
    in >> Znak.name;
    cout << "Vvedite Zodiac\n";
    in >> Znak.zodiac;
    cout << "Vvedite Birthday";
    in >> setw(2) >> Znak.bday[0];
    cin.ignore();
    in >> setw(2) >> Znak.bday[1];
    cin.ignore();
    cin >> setw(4) >> Znak.bday[2];
    cin.get();
    return in;
}

int main()
{
    TZnak Student1 = { "Ivanov", "Deva", 30, 12, 2006 };
    cout << Student1 << endl;
    TZnak Student2 = { "Petrov", "Strelez", 30, 12, 2666 };
    TZnak Student3;
    ++Student1;

    Student3 = Student1 + Student2;
    cout << Student3 << endl;
    // Student3("Sidorov","Oven",67564536);//Student3={"Sidorov",5};
    cout << Student3 << endl;
    const int n = 3;

    TZnak StudentMas[n];
    //организуем ввод и вывод массива структур
    for (int i = 0; i < n; i++)
        cin >> StudentMas[i];
    //Вывод на экран
    for (int i = 0; i < n; i++)
        cout << StudentMas[i] << endl;
    //Вывод в файл
    ofstream out("f.txt");
    for (int i = 0; i < n; i++)
        out << StudentMas[i] << endl;
    cin.get();
    return 0;
}
int getIntZodiak(char* str) // функция возвращает порядковый номер знака зодиака
{
    for (int counter = 0; counter < 12; counter++) {
        if (!strcmp(str, sign_zodiac[counter])) // если знаки зодиака совпадают, то
            // вернуть порядковый номер
            return counter;
    }
    return -1; // возвращаемое значение, в случае, если имя передаваемое как
    // параметр не совпало ни с одним знаком зодиака
}
