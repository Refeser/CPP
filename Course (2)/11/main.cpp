// Курсовая.cpp: определяет точку входа для консольного приложения.

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;


struct pacient		/* структура записи входного файла */
{
	string  shifr; /* шифр */
	string  name; 	/* наименование  */
	string  colvo;	/* кол-во товара */
	string  price;	/* цена */
};

/* прототипы функций */
void Date(int kolvozn, pacient tz[]);
void MiddleAge(int kolvozn, pacient tz[]);
void Diagnos(int kolvozn, pacient tz[]);
int  Age(string gr);
void outputf1(char a[300], char b[300], char c[300], char d[300], char s[40]);
/*----------------------*/
/*    главная функция   */
/*----------------------*/

int main()
{
	ifstream f;  /* ссылка на входной файл */
	char n;   /* номер пункта меню */
	int i;
	char sl;
	string sl1;
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	f.open("patient.txt");
	if (!f.is_open()) // если файл не открыт
	{
		cout << "Файл не может быть открыт!\n";
		cin.get();
		return 1;
	}
	else if (!f.eof())
	{
		pacient tz[88];
		for (i = 0; f.good();i++)
		{
			if ((sl=f.get())=='\n'&&i!=0)
			getline(f, tz[i].shifr,',');
			else
			{
				tz[i].shifr += sl;
				getline(f, sl1, ',');
				tz[i].shifr += sl1;
			}
			f  >> tz[i].name >> tz[i].colvo >> tz[i].price;
			if ((sl = f.get()) == ' ')
			getline(f, tz[i].name,'.');
			cout << tz[i].shifr<<" "<< tz[i].name <<" " << tz[i].colvo<<" "<< tz[i].price<<endl;
		}

		int kolvozn = i - 1;
		do
		{
			cout << "========================================================"<<endl;
			cout << "Выберите номер пункта меню:"<<endl;
			cout << "1 - вывод списка пациентов, поступивших в заданный день" << endl;
			cout << "2 - определение среднего возраста пациентов"<<endl;
			cout << "3 - запись в новый файл списка пациентов с заданным диагнозом"<<endl;
			cout << "4 - выход"<<endl;
			cout << "------------------------------------------------------"<<endl;
			n=cin.get();
			cin.sync();
			switch (n)
			{
            case '1': Date(kolvozn,tz); break;
//			case '2': MiddleAge(kolvozn,tz); break;
			case '3': Diagnos(kolvozn,tz); break;
			case '4': break;
			default: cout << "\nНужно вводить номер пункта от 1 до 4";
			}
			if (n != '4')
			{
				cout << "\nДля продолжения нажмите любую клавишу";
				cin.get();
			}
		} while (n != '4');
		f.close();
	}
	else
	cout << "Файл пуст!\n";
	//cin.get();
	return 0;
}

void Date(int kolvozn, pacient tz[])
{

    int n=0;
	int i=0;
	while (i != kolvozn) {

			if (n == 0)
			{
				cout << "№ Шифр   Н-ие  К-во Цена" << endl;
				cout << "--------------------------------------------------" << endl;
			}
			cout << ++n << " " << tz[i].shifr<<" "<< tz[i].name <<" " << tz[i].colvo<<" "<< tz[i].price<<endl;
			i++;


	}
	if (n == 0)  cout<<"\nНет пациентов, поступивших в заданный день";
	else cout << "Вывод завершен";

}

void Diagnos(int kolvozn,pacient tz[])
{
	string s1;
	ofstream fout; // открываем файл для добавления информации к концу файла
    fout.open("patient.txt", ios_base::app); // открываем файл для добавления информации к концу файла
    getline(cin,s1);

	fout<<s1;

	fout.close();

	 cout<<"Запись в файл завершена";

}





/*



void MiddleAge(int kolvozn, pacient tz[])
{
	float  s = 0;
	int i = 0;
	while (i != kolvozn)
	{
		s += Age(tz[i].gr);
		i++;
	}
	if (i) cout<<"\nСредний возраст пациентов:\n" << s / kolvozn;
	else cout<<"\nФайл patient.txt пустой";
}


int  Age(string gr)
{
	//int igr = atoi(gr.c_str());
	int igr;
	istringstream ss(gr);
	ss >> igr;
	SYSTEMTIME obj;
	GetSystemTime(&obj);

	//cout << obj.wDay << "." << obj.wMonth << "." << obj.wYear << endl;
	return obj.wYear - igr;
}




void Diagnos(int kolvozn,pacient tz[])
{
	char fname[80];
	ofstream fout;
	string zdiag;
	int net = 1;

	cout<<"\nВведите имя выходного файла: ";
	cin.getline(fname,80);
	cin.sync();
	fout.open(fname);
	cout<<"Укажите диагноз: ";
	getline(cin,zdiag);
	int i = 0;
	while (i != kolvozn)
	{
		if (tz[i].diag == zdiag)
		{
			net = 0;
			fout << tz[i].fio << " " << tz[i].gr << " " << tz[i].data << endl;
		}
		i++;
	}
	fout.close();
	if (net) {
		cout<<"Нет пациентов с заданным диагнозом";
		remove(fname);
	}
	else cout<<"Запись в файл завершена";

}
*/
