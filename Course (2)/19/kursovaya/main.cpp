#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

struct vokzal
{
    string poezd;
    string station;
    string otpravka;
    string put;
    string bilet;
};
void otprvka_do (int kolvozn, vokzal tz[]);
void bileti_number (int kolvozn, vokzal tz[]);

int main()
{
	ifstream f;  /* ссылка на входной файл */
	char n;   /* номер пункта меню */
	int i;
	char sl;
	string sl1;
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	f.open("vokzal.txt");
	if (!f.is_open())
	{
		cout << "Файл не может быть открыт!\n";
		cin.get();
		return 1;
	}
	else if (!f.eof())
	{
		vokzal tz[88];
		for (i = 0; f.good();i++)
		{
			if ((sl=f.get())=='\n'&&i!=0)
			getline(f, tz[i].poezd,',');
			else
			{
				tz[i].poezd += sl;
				getline(f, sl1, ',');
				tz[i].poezd += sl1;
			}
			f  >> tz[i].station>>tz[i].otpravka>>tz[i].put;
			if ((sl = f.get()) == ' ')
			getline(f, tz[i].bilet,'.');
			cout << tz[i].poezd<<" "<< tz[i].station <<" " << tz[i].otpravka<<" "<<tz[i].put<<" "<<tz[i].bilet<<" "<<endl;
		}

		int kolvozn = i - 1;
		do
		{
			cout << "========================================================"<<endl;
			cout << "Выберите номер пункта меню:"<<endl;
			cout << "1 - информация о поездах, уходящих до заданного времени" << endl;
			cout << "2 - количество билетов на заданные поезда"<<endl;
			cout << "3 - выход"<<endl;
			cout << "------------------------------------------------------"<<endl;
			n=cin.get();
			cin.sync();
			switch (n)
			{
			case '1': otprvka_do(kolvozn,tz); break;
			case '2': bileti_number(kolvozn,tz); break;
			case '3': break;
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

void otprvka_do (int kolvozn, vokzal tz[])
{
	int n = 0;
	int i=0;
	string t;
	cout<<"укажите время отправки в виде XXXX: "<<endl;
	getline(cin, t);
    cout << "№  Станция вр.отправки вр.пути кол-во билетов" << endl;
    cout << "---------------------------------------------" << endl;
	while (i != kolvozn)
    {
        if (tz[i].otpravka < t)
			cout << ++n << tz[i].poezd <<" "<< tz[i].station<<" "<< tz[i].otpravka<<" "<< tz[i].put<<" "<< tz[i].bilet<<endl;
			i++;
    }
	if (n == 0)  cout<<"\nСовпадений не надено";
	else cout << "Вывод завершен";
}

void bileti_number (int kolvozn, vokzal tz[])
{
    int i=0, k=0;
    string num;
    cout<<"Введите номер поезда в виде XXX: "<<endl;
    getline(cin, num);
    while (i!=kolvozn)
    {
        if(num == tz[i].poezd)
        {
            cout<<"Кол-во билетов на заданный поезд = "<<tz[i].bilet<<endl;
            k++;
        }
        i++;
    }
    if (k==0)
        cout<<"Поезд с таким номером не найден!"<<endl;
}

