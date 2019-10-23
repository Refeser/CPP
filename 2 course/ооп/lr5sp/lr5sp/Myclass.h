
#include <iostream>
#include <string>
using namespace std;
class MusicInstrument {
public:
	string Orkestr[9];
	int n = 0;
	virtual void Get();
	virtual void Show();
};

class Udarnij :MusicInstrument {
public:
	string Udar[3] = { "Bochka", "Baraban", "TamTam" };
};

class Strunnij : public MusicInstrument {
public:
	string Strun[3] = { "Skripka" ,"Ukulele" ,"Gitara" };
};

class Duhovoj : public MusicInstrument {
public:
	string Duh[3] = { "Tuba" ,"Truba" ,"Goboi" };
};

MusicInstrument *Instrument;
Udarnij *ud;
Strunnij *str;
Duhovoj *duh;
