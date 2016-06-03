// prog_2_5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
	
struct Znak
{
    char name[50];
    char zodiac[20]; 
    int bday[4]; 
};
 
int main()
{
	
	int i;
	const int n=4;
	cout<<"Nachalo:"<<endl;
	ifstream file("D:\\f1.txt");
	Znak zodiac[n];
	char str[90];
	char strdd[50], strmm[50], stryy[50];
	//Чтение информации из файла
	for(i=0;i<n;i++)
	{
		file.getline(zodiac[i].name,90);
		file.getline(zodiac[i].zodiac, 90);
		file.getline(str, 90);
		file.getline(strdd,50);
		zodiac[i].bday[0]=atoi(strdd);
			file.getline(strmm,50);
		zodiac[i].bday[1]=atoi(strmm);
			file.getline(stryy,50);
		zodiac[i].bday[2]=atoi(stryy);
	}//конец чтения из файла

	ofstream binout("D:\\f2.txt",ios::binary); //поток для записи в бинарный файл
	binout.write((char*)&zodiac[0],sizeof(Znak)*n);
	binout.close();
	
	Znak zodiac2[n];
	
	ifstream bincin("D:\\f2.txt",ios::binary); //поток для чтения из бинарного файла
	for(i=0;i<n;i++)
	{
		bincin.read((char*)&zodiac2[i],sizeof(Znak));
	}
	bincin.close();
	/*конец чтения из бинарного файла*/
	cout<<"Result: "<<endl;
	for(i=0;i<n;i++) 
	{
		cout<<resetiosflags(ios::right);
		cout.setf(ios::left);
		cout<<setw(20)<<setfill('.');
		cout<<zodiac2[i].name;
		cout<<zodiac2[i].zodiac;
		cout.width(20);
		cout.setf(ios::right);
		cout<<zodiac2[i].bday[0]<<'.'<<zodiac2[i].bday[1]<<'.'<<zodiac2[i].bday[2]<<'\n'; 
	}
	cout.fill('.');
	ofstream out("D:\\f3.txt"); //Запись текстового файла
	for(i=0;i<n;i++) 
	{
		out<<resetiosflags(ios::right);
		out.setf(ios::left);
		out<<setw(20)<<setfill('.');
		out<<zodiac2[i].name;
		out<<zodiac[i].zodiac;
		out.width(20);
		out.setf(ios::right);
		out<<zodiac2[i].bday[0]<<'.'<<zodiac2[i].bday[1]<<'.'<<zodiac2[i].bday[2]<<'.'<<"\n"<<endl; 
		out<<endl;
	}
	bincin.close();
	cout<<endl;
	cout<<"End"<<endl;
	system("PAUSE");
	return 0;
}

