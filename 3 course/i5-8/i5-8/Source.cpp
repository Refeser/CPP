#include "Header.h"

void Workers::Soedinenie() {
	for (int i = 0; i < 3; i++)
		Work->Rabochie[i] += Man->Managers[i];
	for (int i = 3; i < 6; i++)
		Work->Rabochie[i] += Adm->Admins[i-3];
	for (int i = 6; i < 9; i++)
		Work->Rabochie[i] += Prog->Programmers[i - 6];
}

void Workers::Vivod() {
	cout << "Состав работников: " << endl;
	cout << "Менеджеры: " << endl;
	for (int i = 0; i < 3; i++)
		cout << "		" << Rabochie[i] << endl;
	cout << "Администраторы: " << endl;
	for (int i = 3; i < 6; i++)
		cout << "		" << Rabochie[i] << endl;
	cout << "Программисты: " << endl;
	for (int i = 6; i < 9; i++)
		cout << "		" << Rabochie[i] << endl;
}

int main() {
	setlocale(LC_ALL, "Rus");
	Work = new Workers();
	Man = new Manager();
	Adm = new Admin();
	Prog = new Programmer();

	Work->Soedinenie();
	Work->Vivod();

	system("pause");
	return 0;
}