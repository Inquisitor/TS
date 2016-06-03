// prog_2_5.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Znak {
    char name[50];
    char zodiac[20];
    int bday[4];
};

int main()
{

    int i;
    const int n = 4;
    cout << "Nachalo:" << endl;
    ifstream file("D:\\f1.txt");
    Znak zodiac[n];
    char strdd[50], strmm[50], stryy[50];
    //������ ���������� �� �����
    for (i = 0; i < n; i++) {
        file.getline(zodiac[i].name, 90);
        file.getline(zodiac[i].zodiac, 90);
        file.getline(strdd, 50);
        zodiac[i].bday[0] = atoi(strdd);
        file.getline(strmm, 50);
        zodiac[i].bday[1] = atoi(strmm);
        file.getline(stryy, 50);
        zodiac[i].bday[2] = atoi(stryy);
    } //����� ������ �� �����

    ofstream binout("D:\\f2.txt", ios::binary); //����� ��� ������ � �������� ����
    binout.write((char*)&zodiac[0], sizeof(Znak) * n);
    binout.close();

    Znak zodiac2[n];

    ifstream bincin("D:\\f2.txt", ios::binary); //����� ��� ������ �� ��������� �����
    for (i = 0; i < n; i++) {
        bincin.read((char*)&zodiac2[i], sizeof(Znak));
    }
    bincin.close();
    /*����� ������ �� ��������� �����*/
    cout << "Result: " << endl;
    for (i = 0; i < n; i++) {
        cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left)
             << setw(20) << setfill('.') << zodiac2[i].name
             << setw(20) << setfill('.') << zodiac2[i].zodiac
             << resetiosflags(ios::adjustfield) << setiosflags(ios::right)
             << setw(2) << setfill('0') << zodiac2[i].bday[0] << '.'
             << setw(2) << setfill('0') << zodiac2[i].bday[1] << '.'
             << setw(4) << setfill('0') << zodiac2[i].bday[2] << endl;
    }
    cout.fill('.');
    ofstream out("D:\\f3.txt"); //������ ���������� �����
    for (i = 0; i < n; i++) {
        out << resetiosflags(ios::adjustfield) << setiosflags(ios::left)
             << setw(20) << setfill('.') << zodiac2[i].name
             << setw(20) << setfill('.') << zodiac2[i].zodiac
             << resetiosflags(ios::adjustfield) << setiosflags(ios::right)
             << setw(2) << setfill('0') << zodiac2[i].bday[0] << '.'
             << setw(2) << setfill('0') << zodiac2[i].bday[1] << '.'
             << setw(4) << setfill('0') << zodiac2[i].bday[2] << endl;
    }
    bincin.close();
    cout << endl;
    cout << "End" << endl;
    system("PAUSE");
    return 0;
}
