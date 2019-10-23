#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

struct avto
{
    string fio;
    string marka;
    string nomer;
};
struct EL_SP
{
	string id;
	EL_SP *sled;
};
/*---------------------------------------------------------------------------------------------------*/
void fio_nomer (int kolvozn, avto tz[]);
void kolvo_marki (int kolvozn, avto tz[]);

void PechSp(EL_SP *p)
{
	EL_SP *i;
	cout << "Результат: " << endl;
	for (i = p; i != NULL; i = i->sled)
		cout << i->id << endl;
}



int main()
{
    EL_SP *p;
	ifstream f;  /* ссылка на входной файл */
	char n;   /* номер пункта меню */
	int i;
	char sl;
	string sl1, t_id;
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	f.open("avto.txt");
	if (!f.is_open())
	{
		cout << "Файл не может быть открыт!\n";
		cin.get();
		return 1;
	}
	else if (!f.eof())
	{
		avto tz[88];
		for (i = 0; f.good();i++)
		{
			if ((sl=f.get())=='\n'&&i!=0)
			getline(f, tz[i].fio,',');
			else
			{
				tz[i].fio += sl;
				getline(f, sl1, ',');
				tz[i].fio += sl1;
			}
			f  >> tz[i].marka;
			if ((sl = f.get()) == ' ')
			getline(f, tz[i].nomer,'.');
			cout << tz[i].fio<<" "<< tz[i].marka <<" " << tz[i].nomer<<" "<<endl;
		}

		int kolvozn = i - 1;
		do
		{
			cout << "========================================================"<<endl;
			cout << "Выберите номер пункта меню:"<<endl;
			cout << "1 - вывод списка владельцев автомобилей и их номеров" << endl;
			cout << "2 - вывод марок автомобилей и их количество"<<endl;
			cout << "3 - выход"<<endl;
			cout << "------------------------------------------------------"<<endl;
			n=cin.get();
			cin.sync();
			switch (n)
			{
			case '1': fio_nomer(kolvozn,tz); break;
			case '2': kolvo_marki(kolvozn,tz); break;
			case '3': break;
			case '4': PechSp(p); break;
			default: cout << "\nНужно вводить номер пункта от 1 до 4";
			}
			if (n != '3')
			{
				cout << "\nДля продолжения нажмите любую клавишу";
				cin.get();
			}
		} while (n != '3');
		f.close();
	}
	else
	cout << "Файл пуст!\n";
	//cin.get();
	return 0;
}

void fio_nomer (int kolvozn, avto tz[])
{
	int n = 0;
	int i=0;
	while (i != kolvozn)
    {
			if (n == 0)
			{
				cout << "№ Фамилия И.О. № Машины" << endl;
				cout << "--------------------------------------------------" << endl;
			}
			cout <<++n <<" "<< tz[i].fio <<" "<< tz[i].nomer<<endl;
			i++;
    }
	if (n == 0)  cout<<"\nФайл пуст";
	else cout << "Вывод завершен";
}

void kolvo_marki (int kolvozn, avto tz[])
{
    string mark;
	int n = 0, kolvo=0, i=0, j=0, c=-1, k=0, f=0;
	while (i!=kolvozn)
    {
        c++;
        for (k=0;k<c;k++)
            if(tz[i].marka==tz[k].marka)
            f++;
                for (j=i; j<kolvozn; j++)
                   if (tz[i].marka==tz[j].marka)
                    kolvo++;


			if (n == 0)
			{
				cout << "№ Марка Кол-во" << endl;
				cout << "------------------------------------------------" << endl;
			}
			if (f==0)
			cout <<++n<<" "<<tz[i].marka<<" "<<kolvo<<endl;
			kolvo=0;
			f=0;
			i++;
		}
	if (n == 0)  cout<<"\nфайл пуст";
	else cout << "Вывод завершен";
}

