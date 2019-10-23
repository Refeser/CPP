#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;


struct tovar		/* ��������� ������ �������� ����� */
{
	string  shifr; /* ���� */
	string  name; 	/* ������������  */
	string  colvo;	/* ���-�� ������ */
	string  price;	/* ���� */
};

/* ��������� ������� */
void Dobavlenie(int kolvozn, tovar tz[]);
void Vivod(int kolvozn, tovar tz[]);
/*----------------------*/
/*    ������� �������   */
/*----------------------*/

int main()
{
	ifstream f;  /* ������ �� ������� ���� */
	char n;   /* ����� ������ ���� */
	int i;
	char sl;
	string sl1;
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	f.open("tovar.txt");
	if (!f.is_open()) // ���� ���� �� ������
	{
		cout << "���� �� ����� ���� ������!\n";
		cin.get();
		return 1;
	}
	else if (!f.eof())
	{
		tovar tz[88];
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
			cout << "�������� ����� ������ ����:"<<endl;
			cout << "1 - ���������� ����� ������ � ����� �����" << endl;
			cout << "2 - ������ ������"<<endl;
			cout << "3 - �����"<<endl;
			cout << "------------------------------------------------------"<<endl;
			n=cin.get();
			cin.sync();
			switch (n)
			{
            case '1': Dobavlenie(kolvozn,tz); break;
			case '2': Vivod(kolvozn,tz); break;
			case '3': break;
			default: cout << "\n����� ������� ����� ������ �� 1 �� 3";
			}
			if (n != '3')
			{
				cout << "\n��� ����������� ������� ����� �������";
				cin.get();
			}
		} while (n != '3');
		f.close();
	}
	else
	cout << "���� ����!\n";
	//cin.get();
	return 0;
}

void Dobavlenie(int kolvozn,tovar tz[])
{
	string s1;
	ofstream fout; // ��������� ���� ��� ���������� ���������� � ����� �����
    fout.open("tovar.txt", ios_base::app); // ��������� ���� ��� ���������� ���������� � ����� �����
    getline(cin,s1);

	fout<<endl<<s1;

	fout.close();

    cout<<"������ � ���� ���������";

}

void Vivod(int kolvozn, tovar tz[])
{
	ifstream f;
	string sl1;
    char sl;
    int i=0, n=0;
	f.open("tovar.txt");
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
			if (n == 0)
			{
				cout << "� ����   �-��  �-�� ����" << endl;
				cout << "--------------------------------------------------" << endl;
			}
			cout << ++n << tz[i].shifr<<" "<< tz[i].name <<" " << tz[i].colvo<<" "<< tz[i].price<<endl;
        }
        f.close();
	if (n == 0)  cout<<"\n���������� � ������� �����������!";
	else cout << "����� ��������";

}
