#include <conio.h>
#include <string.h>
#include <iostream>

using namespace std;

struct date
{
	char day[20];
	char hourmin[5];
};
//=========class Aeroflot===============
class Aeroflot
{
	char flight[30];//private
	date t;
	char adr[30];
public:
	Aeroflot();
	char *getadr();
	char *getday();
	char *gethour();
	void show();
};

Aeroflot::Aeroflot()
{
	cout << "Input flight: "; cin >> flight;
	cout << "Input adr: "; cin >> adr;
	cout << "Input date of flight\n";
	cout << "Day of week: "; cin >> t.day;
	cout << "Input time of flight h:min : "; cin >> t.hourmin;
}

void Aeroflot::show()
{
	cout << "Flight				:"<<flight<<endl;
	cout << "Address			:" << adr << endl;
	cout << "Day of week		:" << t.day << endl;
	cout << "Time of flight		:" << t.hourmin << endl;
}

char *Aeroflot::getadr() { return adr; }
char *Aeroflot::getday() { return t.day; }
char *Aeroflot::gethour() { return t.hourmin; }

void spisadr(Aeroflot spis[], int n)//—писок рейсов заданного пункта назначени€
{
	char adres[20];
	cout << "Input adr:"; cin >> adres;
	for (int i = 0; i < n; i++)
		if (strcmp(spis[i].getadr(), adres) == 0)
			spis[i].show();
}

void spisday(Aeroflot spis[], int n)//—писок рейсов заданного дн€ недели
{
	char day[20];
	cout << "Input day:"; cin >> day;
	for (int i = 0; i < n; i++)
		if (strcmp(spis[i].getday(), day) == 0)
			spis[i].show();
}

void spisdaytime(Aeroflot spis[], int n)//—писок рейсов заданного дн€ недели и больше заданного времени
{
	char day[20];
	char hourmin[5];
	cout << "Input day:"; cin >> day;
	cout << "Input time:"; cin >> hourmin;
	for (int i = 0; i < n; i++)
		if ((strcmp(spis[i].getday(), day) == 0)&&(spis[i].gethour() >= hourmin))
			spis[i].show();
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
	spisadr(spis, n);
	//spisday(spis, n);
	//spisdaytime(spis, n);
	delete[] spis;
	getchar();
}