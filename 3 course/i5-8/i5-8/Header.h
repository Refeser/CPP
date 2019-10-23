#pragma once

#include <iostream>
#include <string>
using namespace std;
class Workers {
public:
	string Rabochie[9];
	virtual void Soedinenie();
	virtual void Vivod();
};

class Manager :Workers {
public:
	string Managers[3] = { "Irina", "Vladislava", "Alexandra" };
};

class Admin :Workers {
public:
	string Admins[3] = { "Niyaz", "Vladimir", "Rashid" };
};

class Programmer :Workers {
public:
	string Programmers[3] = { "Muhutdinov", "Timerhan", "Aglyamovich" };
};

Workers *Work;
Manager *Man;
Admin *Adm;
Programmer *Prog;
