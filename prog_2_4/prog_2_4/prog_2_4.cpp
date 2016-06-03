//// prog_2_4.cpp: определяет точку входа для консольного приложения.
////

#include "stdafx.h"
//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <string>
//using namespace std;
// 
//struct TZnak{
//
//	char name[50]; // фамилия, имя
//    char zodiac[20]; // знак зодиака
//    int bday1; 
//	int bday2;
//	int bday3;
//	 operator int() const {return (bday1), (bday2), (bday3); }
// void operator()(char* str, char* str2, int mybday1, int mybday2, int mybday3 )
// {
//	 strcpy(name,str);
//	 strcpy(zodiac, str2);
//	 bday1=mybday1;
//	 bday2=mybday2;
//	 bday3=mybday3;
// }	
//};
////TZnak& operator ++(TZnak &Znak)
////{
////	++Znak.bday[3];
////	return Znak;
////}
////TZnak& operator --(TZnak &Znak)
////{
////	--Znak.bday[3];
////	return Znak;
////}
////TZnak operator +( const TZnak &Znak1, const TZnak &Znak2)
////{
////	TZnak Znak=Znak1;
////	strcat(Znak.name,Znak2.name);
////	Znak.bday[3]+=Znak2.bday[3];
////	return Znak;
////}
////
////bool operator >(const TZnak &Znak1, const TZnak &Znak2)
////{
////	return Znak1.bday[3]>Znak2.bday[3];
////}
//bool operator == (const TZnak &Znak, char zodiac)
//{
//
//	if(Znak.zodiac == "oven")
//        return 1;
//    else if(Znak.zodiac == "telec")
//        return 2;
//    else if(Znak.zodiac == "bliznec")
//        return 3;
//    else if(Znak.zodiac == "rak")
//        return 4;
//    else if(Znak.zodiac == "lev")
//        return 5;
//    else if(Znak.zodiac == "deva")
//        return 6;
//    else if(Znak.zodiac == "vesi")
//        return 7;
//    else if(Znak.zodiac == "scorpion")
//        return 8;
//    else if(Znak.zodiac == "strelec")
//        return 9;
//    else if(Znak.zodiac == "kozerog")
//        return 10;
//    else if(Znak.zodiac == "vodoley")
//        return 11;
//    else if(Znak.zodiac == "riba")
//        return 12;
//    return 1;
//}
//bool operator >(const TZnak&Znak, const TZnak&Znak2)
//{
//	/*const char *sign_zodiac[12] = {"Овен", "Телец", "Близнецы", "Рак" , "Лев", "Дева",
//                         "Весы", "Скорпион", "Стрелец", "Козерог", "Водолей", "Рыбы" };*/
//	TZnak tmp;
//     for(int i = 0; i < 12; ++i)
//    {           
//        for(int j = 0; j < 12; ++j)
//        {    
//            if (GetZodiacNo(data.at(j + 1).zodiac) < GetZodiacNo(data.at(j).zodiac))
//            {
//                tmp = data.at(j + 1);
//                data.at(j + 1) = data.at(j);
//                data.at(j) = tmp;
//            }
//        }
//    }
//            
//                   
// 
//}
//ostream& operator<<(ostream& out,TZnak &Znak)
//{
//	out<<setw(20)<<setfill('.')<<setiosflags(ios::left)<<Znak.name<<Znak.zodiac<< Znak.bday1<<'.'<<Znak.bday2<<'.'<<Znak.bday3<<endl;
//	return out;
//}
////istream& operator>>(istream& in,TZnak &Znak)
////{
////	cout<<"Vvedite FIO\n";
////	in>>Znak.name;
////	cout<<"Vvedite Bal\n";
////	in>>Znak.bday[3];
////	return in;
////}
//
//
//istream& operator>>(istream& in, TZnak & Znak)
//{
//	cout<<"Vvedite name\n";
//	in>>Znak.name;
//	cout<<"Vvedite znak zodiaka\n";
//	in>>Znak.zodiac;
//	cout<<"VVedite day\n";
//	in>> (Znak.bday1); // считать первые два символа, т.е. день
//	cout<<"VVedite month\n";
//    in >> Znak.bday2; // считать следующие два символа, т.е. месяц
//	cout<<"VVedite year\n";
//    in >> Znak.bday3; // считать четыре символа, т.е. год
//    cin.get(); // считываем символ новой строки '\n'
// return in;
//}
//
//
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	TZnak Student1={"Ivanov","oven", 13, 10,1996};
//	TZnak Student2={"Petrov","deva",10, 12, 2010};
//	TZnak Student3;
//
//	//Student1--;//Student1={"Ivanov",2};
//	//Student2++;//Student2={"Petrov",6};
//	cout<<Student1<<endl;
//	cout<<Student2<<endl;
//	//Student3=Student1+Student2;//Student3={"IvanovPetrov",8};
//	/*cout<<Student3<<endl;*/
//	//Student3("Sidorov",5);//Student3={"Sidorov",5};
//	/*cout<<Student3<<endl;*/
//	
//	const int n=3;
//	TZnak StudentMas[n];
//	//организуем ввод и вывод массива структур
//	for(int i=0;i<n;i++)
//		cin>>StudentMas[i];
//	//Вывод на экран
//	for(int i=0;i<n;i++)
//		cout<<StudentMas[i]<<endl;
//	//Вывод в файл
//	ofstream out("f.txt");
//	for(int i=0;i<n;i++)
//		out<<StudentMas[i]<<endl;
//	cin.get();
//	
//
//	return 0;
//}
//
