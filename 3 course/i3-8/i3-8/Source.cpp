#include <iostream>
#include<string>
#include <windows.h>

using namespace std;

struct EL_SP
{
	string id;
	EL_SP *sled;
};
void Vkl(EL_SP **p, string t_id)
{
	EL_SP *pt;
	EL_SP *k = NULL;
	EL_SP *j = NULL;
	pt = new EL_SP();
	pt->id = t_id;
	if (*p == NULL)
	{
		pt->sled = *p;
		*p = pt;
	}
	else
	{
		k = *p;
		while (k != NULL)
		{
			j = k;
			k = k->sled;
		}
		j->sled = pt;
		pt->sled = k;
	}

}
void PechSp(EL_SP *p)
{
	EL_SP *i;
	cout << "���������: " << endl;
	for (i = p; i != NULL; i = i->sled)
		cout << i->id << endl;
}
void zamenapredposlednego(EL_SP *p)
{
	EL_SP *i;

	string zamenyaemoe, zamena;

	cout << endl << "������� ����� ����� ��������" << endl;
	cin >> zamenyaemoe;
	cout << endl;
	cout << "������� �� ����� ����� ��������" << endl;
	cin >> zamena;
	cout << endl;

	int j = 1;

	for (i = p, j; i != NULL; i = i->sled, j++)
	{
		if (i->id == zamenyaemoe) {
			i->id = zamena;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int kol;
	char n;
	EL_SP *p;
	unsigned i;
	string t_id;
	p = NULL;
	cout << "������� �����" << endl << "����� ������� ������� ENTER" << endl;
	for (i = 1;; i++)
	{
		getline(cin, t_id);
		cin.sync();
		cin.clear();
		if (t_id.size() == 0)
		{
			i--;
			cout << "���� ���� ��������" << endl;
			break;
		}
		else
			Vkl(&p, t_id);
	}
	cout << endl;
	PechSp(p);
	zamenapredposlednego(p);
	PechSp(p);

	cout << endl;
	system("pause");
	return 1;
}