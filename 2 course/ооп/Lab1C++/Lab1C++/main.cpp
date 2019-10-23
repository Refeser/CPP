#include <conio.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

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
	cout << "Input flight:"; cin >> flight;
	cout << "Input adr:"; cin >> adres;
	cout << "Day of week:"; cin >> t.day;
	cout << "Input time of flight (format - HHMM) :"; cin >> hourmin;
	cout << endl;
}

void Aeroflot::show()
{
	cout << "Flight				:" << flight << endl;
	cout << "Address			:" << adres << endl;
	cout << "Day of week		:" << t.day << endl;
	cout << "Time of flight		:" << hourmin << endl;
}

string Aeroflot::getadr() { return adres; }
char *Aeroflot::getday() { return t.day; }
char *Aeroflot::gethour() { return hourmin; }

string search_adres;
void spisadr(Aeroflot spis[], int n)//—писок рейсов заданного пункта назначени€
{
	cout << "Input adr:"; cin >> search_adres;
	cout << "Result:" << endl;
	for (int i = 0; i < n; i++)
		if (spis[i].getadr() == search_adres)
			spis[i].show();
		else cout << "Flight not found";
}

void spisday(Aeroflot spis[], int n)//—писок рейсов заданного дн€ недели
{
	char day[20];
	cout << "Input day:"; cin >> day;
	cout << "Result:" << endl;
	for (int i = 0; i < n; i++)
		if (strcmp(spis[i].getday(), day) == 0)
			spis[i].show();
		else cout << "Flight not found";
}

void spisdaytime(Aeroflot spis[], int n)//—писок рейсов заданного дн€ недели и больше заданного времени
{
	char day[20];
	char hourmin[5];
	cout << "Input day:"; cin >> day;
	cout << "Input time (format - HHMM):"; cin >> hourmin;
	cout << "Result:" << endl;
	for (int i = 0; i < n; i++)
		if ((strcmp(spis[i].getday(), day) == 0)&&(spis[i].gethour() >= hourmin))
			spis[i].show();
		else cout << "Flight not found";
}

//==============main==================
void main()
{
	Aeroflot *spis;
	int n;
	cout << "Input a number of flights: "; cin >> n;
	spis = new Aeroflot[n];
	for (int i = 0; i < n; i++)
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