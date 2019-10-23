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
	cout << "Введите индентифактор" << endl << "После каждого нажмите ENTER" << endl;
	for (i = 1;; i++)
	{
		getline(cin, t_id);
		cin.sync();
		cin.clear();
		if (t_id.size() > 8)
		{
			i--;
			cout << "Ошибка!" << endl << "Введите индентификатор не более 8 символов" << endl;
		}
		else if (t_id.size() == 0)
		{
			i--;
			cout << "Ввод индентификаторов закончен" << endl;
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
		cout << "Выберите номер пункта меню:" << endl;
		cout << "1 - вывод идентификаторов в алфавитном порядке" << endl;
		cout << "2 - удалить второй элемент" << endl;
		cout << "3 - заменить на заданный идентификатор последний элемент" << endl;
		cout << "4 - кол-во идентификаторов до заданного элемента" << endl;
		cout << "5 - выход" << endl;
		cout << "------------------------------------------------------" << endl;
		n = cin.get();
		cin.sync();
		switch (n)
		{
        case '1': PechSp(p); break;
		case '2': udalenievtorogo(&p); break;
		case '3': zamenaposlednego(p,kol); break;
		case '4': koldo(p); break;

		default: cout << "\nНужно вводить номер пункта от 1 до 5";
		}
		if (n != '5')
		{
			cout << "\nДля продолжения нажмите любую клавишу";
			cin.get();
		}
	} while (n != '5');

	cout << endl;
	return 1;
}
