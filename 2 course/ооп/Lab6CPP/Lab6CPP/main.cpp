#include <conio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ofstream vvod;
ifstream vivod;
int wordscount = 0;
string text[10000];

struct date
{
	char day[20];
};
//=========class Aeroflot===============
class Aeroflot
{
	char flight[30];//private
	date t;
	string adres;
	char hourmin[10];

public:
	Aeroflot();
	char *getday();
	char *gethour();
	string getadr();
	void show();
};

Aeroflot::Aeroflot()
{
	vvod.open("Aeroflot.txt", ios_base::app);
	cout << "Input flight:"; cin >> flight;
	vvod << flight;
	vvod << ' ';
	wordscount++;
	cout << "Input adr:"; cin >> adres;
	vvod << adres;
	vvod << ' ';
	wordscount++;
	cout << "Day of week:"; cin >> t.day;
	vvod << t.day;
	vvod << ' ';
	wordscount++;
	cout << "Input time of flight (format - HHMM) :"; cin >> hourmin;
	vvod << hourmin;
	wordscount++;
	vvod << endl;
	cout << endl;
	vvod.close();
}

void Aeroflot::show()
{
	vivod.open("Aeroflot.txt", ios_base::in);
	if (!vivod.is_open()) cout << "Error: File is not founded!";
	else
	{
		for (int i = 0; i < wordscount; i++)
		{
			vivod >> text[i];
			text[i] += ' ';
		}
		for (int i = 0; i < wordscount; i++) {
			cout << "Flight			: " << text[i];
			i++; cout << endl;
			cout << "Address			: " << text[i];
			i++; cout << endl;
			cout << "Day of week		: " << text[i];
			i++; cout << endl;
			cout << "Time of flight		: " << text[i];
			cout << endl;
			cout << "=================================" << endl;
		}
		vivod.close();
	}
}

string Aeroflot::getadr() { return adres; }
char *Aeroflot::getday() { return t.day; }
char *Aeroflot::gethour() { return hourmin; }

string search_adres;
void spisadr(Aeroflot spis[], int n)//Список рейсов заданного пункта назначения
{
	cout << "Input adr:"; cin >> search_adres;
	cout << "Result:" << endl;
	vivod.open("Aeroflot.txt", ios_base::in);
	if (!vivod.is_open()) cout << "Error: File is not founded!";
	else {
		for (int i = 0; i < wordscount; i++) {
			string adr;
			vivod >> adr;
			if (adr == search_adres) {
				cout << "Flight			: " << text[i];
				i++; cout << endl;
				cout << "Address			: " << text[i];
				i++; cout << endl;
				cout << "Day of week		: " << text[i];
				i++; cout << endl;
				cout << "Time of flight		: " << text[i];
				cout << endl;
			}
			adr = "";
		}
	}
	vivod.close();
}

void spisday(Aeroflot spis[], int n)//Список рейсов заданного дня недели
{
	string day;
	cout << "Input day:"; cin >> day;
	cout << "Result:" << endl;
	vivod.open("Aeroflot.txt", ios_base::in);
	if (!vivod.is_open()) cout << "Error: File is not founded!";
	else {
		for (int i = 0; i < wordscount; i++) {
			string strday;
			vivod >> strday;
			if (strday == day) {
				i -= 2;
				cout << "Flight			: " << text[i];
				cout << endl; i++;
				cout << "Address			: " << text[i];
				cout << endl; i++;
				cout << "Day of week		: " << text[i];
				cout << endl; i++;
				cout << "Time of flight		: " << text[i];
				cout << endl;
			}
			strday = "";
		}
	}
	vivod.close();
}

void spisdaytime(Aeroflot spis[], int n)//Список рейсов заданного дня недели и больше заданного времени
{
	string day, time;
	cout << "Input day: "; cin >> day;
	cout << "Input time: "; cin >> time;
	cout << "Result: " << endl;
	vivod.open("Aeroflot.txt", ios_base::in);
	if (!vivod.is_open()) cout << "Error: File is not founded!";
	else {
		for (int i = 0; i < wordscount; i++) {
			string strday;
			int inttime;
			vivod >> strday;
			i += 1;
			vivod >> inttime;
			i -= 1;
			if (day == strday && stoi(time) > inttime) {
				i -= 2;
				cout << "Flight			: " << text[i];
				cout << endl; i++;
				cout << "Address			: " << text[i];
				cout << endl; i++;
				cout << "Day of week		: " << text[i];
				cout << endl; i++;
				cout << "Time of flight		: " << text[i];
				cout << endl;
			}
			inttime = 0;
			strday = "";
			
		}
	}
	vivod.close();
}

//==============main==================
void main()
{
	Aeroflot *spis;
	int n;
	cout << "Input a number of flights: "; cin >> n;
	spis = new Aeroflot[n];
	for (int i = 0; i < 1; i++)
	{
		cout << "=================================" << endl;
		spis[i].show();
	}
	cout << endl << "----------1st task----------" << endl;
	spisadr(spis, n);
	cout << endl << "----------2nd task----------" << endl;
	spisday(spis, n);
	cout << endl << "----------3rd task----------" << endl;
	spisdaytime(spis, n);
	cout << endl;

	delete[] spis;
	system("pause");
}