#include "header.h"
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
	cout << "������� �������������" << endl << "����� ������� ������� ENTER" << endl;
	for (i = 1;; i++)
	{
		getline(cin, t_id);
		cin.sync();
		cin.clear();
		if (t_id.size() > 8)
		{
			i--;
			cout << "������!" << endl << "������� �������������� �� ����� 8 ��������" << endl;
		}
		else if (t_id.size() == 0)
		{
			i--;
			cout << "���� ���������������� ��������" << endl;
			break;
		}
		else

			Vkl(&p, t_id);
	}
	kol = i;
	cout << kol;
	do
	{
		cout << "========================================================" << endl;
		cout << "�������� ����� ������ ����:" << endl;
		cout << "1 - ����� ��������������� � ���������� �������" << endl;
		cout << "2 - ������� ������ �������" << endl;
		cout << "3 - �������� �� �������� ������������� ��������� �������" << endl;
		cout << "4 - ���-�� ��������������� �� ��������� ��������" << endl;
		cout << "5 - �����" << endl;
		cout << "------------------------------------------------------" << endl;
		n = cin.get();
		cin.sync();
		switch (n)
		{
        case '1': PechSp(p); break;
		case '2': udalenievtorogo(&p); break;
		case '3': zamenaposlednego(p,kol); break;
		case '4': koldo(p); break;

		default: cout << "\n����� ������� ����� ������ �� 1 �� 5";
		}
		if (n != '5')
		{
			cout << "\n��� ����������� ������� ����� �������";
			cin.get();
		}
	} while (n != '5');

	cout << endl;
	return 1;
}
