#include "Myclass.h" 

void MusicInstrument::Get(){
	for (int i = 0; i < 9; i++) {
		switch (i) {
		case 0:
			Instrument->Orkestr[i] = ud->Udar[0];
			break;
		case 1:
			Instrument->Orkestr[i] = ud->Udar[1];
			break;
		case 2:
			Instrument->Orkestr[i] = ud->Udar[2];
			break;
		case 3:
			Instrument->Orkestr[i] = str->Strun[0];
			break;
		case 4:
			Instrument->Orkestr[i] = str->Strun[1];
			break;
		case 5:
			Instrument->Orkestr[i] = str->Strun[2];
			break;
		case 6:
			Instrument->Orkestr[i] = duh->Duh[0];
			break;
		case 7:
			Instrument->Orkestr[i] = duh->Duh[1];
			break;
		case 8:
			Instrument->Orkestr[i] = duh->Duh[2];
			break;
		}
	}
}

void MusicInstrument::Show() {
	cout << "Состав оркестра" << endl
		<< "***************" << endl
		<< "Ударные: " << endl;
	for (int i = 0; i < 3; i++) {
		cout << "	" << Orkestr[i] << endl;
	}
	cout << "Струнные:" << endl;
	for (int i = 3; i < 6; i++) {
		cout << "	" << Orkestr[i] << endl;
	}
	cout << "Духовые:" << endl;
	for (int i = 6; i < 9; i++) {
		cout << "	" << Orkestr[i] << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	Instrument = new MusicInstrument();
	ud = new Udarnij();
	str = new Strunnij();
	duh = new Duhovoj();
	Instrument->Get();
	Instrument->Show();

	system("pause");
	return 0;
}