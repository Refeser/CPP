#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

struct sotrudniki
{
    string fio;
    string god;
    string doljnost;
    string adres;
    string fio_b;
    string god_b;
    string doljnost_b;
    string adres_b;
};

void izmenenie_doljnosti_i_adresa (int kolvozn, sotrudniki tz[]);
void iskluchenie_zapisi (int kolvozn, sotrudniki tz[]);
void vivod_spiska (int kolvozn, sotrudniki tz[]) ;

int main()
{
	ifstream f;  /* ������ �� ������� ���� */
	ifstream F;
	char n;   /* ����� ������ ���� */
	int i;
	char sl;
	string sl1;
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	f.open("sotrudniki.txt");
	if (!f.is_open())
	{
		cout << "���� �� ����� ���� ������!\n";
		cin.get();
		return 1;
	}
	else if (!f.eof())
	{
		sotrudniki tz[88];
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
			f  >> tz[i].god >> tz[i].doljnost;
			if ((sl = f.get()) == ' ')
			getline(f, tz[i].adres,'.');
			cout << tz[i].fio<<" "<< tz[i].god <<" " << tz[i].doljnost<<" "<< tz[i].adres <<" "<<endl;
		}
		F.open("sotrudniki_buff.txt");
		for (i = 0; F.good();i++)
		{
			if ((sl=F.get())=='\n'&&i!=0)
			getline(F, tz[i].fio_b,',');
			else
			{
				tz[i].fio_b += sl;
				getline(F, sl1, ',');
				tz[i].fio_b += sl1;
			}
			F  >> tz[i].god_b >> tz[i].doljnost_b;
			if ((sl = F.get()) == ' ')
			getline(F, tz[i].adres_b,'.');
		}


		int kolvozn = i - 1;
		do
		{
			cout << "========================================================"<<endl;
			cout << "�������� ����� ������ ����:"<<endl;
			cout << "1 - �������� ��������� ��� �������� ����� ����������" << endl;
			cout << "2 - ��������� ���������� �� �����"<<endl;
			cout << "3 - ����� ������ �����������"<<endl;
			cout << "4 - �����"<<endl;
			cout << "------------------------------------------------------"<<endl;
			n=cin.get();
			cin.sync();
			switch (n)
			{
			case '1': izmenenie_doljnosti_i_adresa(kolvozn,tz); break;
			case '2': iskluchenie_zapisi(kolvozn,tz); break;
			case '3': vivod_spiska (kolvozn,tz); break;
			case '4': break;
			default: cout << "\n����� ������� ����� ������ �� 1 �� 4";
			}
			if (n != '4')
			{
				cout << "\n��� ����������� ������� ����� �������";
				cin.get();
			}
		} while (n != '4');
		F.close();
		f.close();
	}
	else
	cout << "���� ����!\n";
	//cin.get();
	return 0;
}

void izmenenie_doljnosti_i_adresa (int kolvozn, sotrudniki tz[])
{
    int n=0, i=0, k=0, sot=0;
    string v_imya, v_izm;
    cout<<"������� �.�.�. ����������, ��������� ��� �������� ����� �������� ������ ��������"<<endl;
    getline (cin, v_imya);
    cout<<"������� ����� ��������� ��� �����: "<<endl;
    getline(cin, v_izm);
    while (i != kolvozn)
    {
        if (tz[i].fio == v_imya)
        {
            cout<< "������� ��� ������ �� ������ ��������:" <<endl
               << "1. ��������� ����������" <<endl
               << "2. �������� ����� ����������" <<endl;
               cin>>k;
               if (k==1)
               {
                   tz[i].doljnost = v_izm;
                   cout<<"��������� �������� "<<endl;
                   break;
               }
               else
               {
                   if (k==2)
                   {
                        tz[i].adres = v_izm;
                        cout<<"����� �������! "<<endl;
                        break;
                   }
                   else
                   {
                    cout<<"�� ������� �������� �����! "<<endl;
                    break;
                   }
               }
               sot++;
        }

        i++;
    }
    i=0;
    while(i!=kolvozn)
    {
        cout << tz[i].fio<<" "<< tz[i].god <<" " << tz[i].doljnost<<" "<< tz[i].adres <<" "<<endl;
        i++;
    }
    if (sot==0)
        cout<<"�������� ���������!"<<endl;
}

void iskluchenie_zapisi (int kolvozn, sotrudniki tz[])
{
    string fio_udal;
    int i=0,z=0;
    cout<<"������� ��� ����������: "<<endl;
    getline(cin,fio_udal);
    fstream f;
    fstream F;
    F.open("sotrudniki_buff.txt", ios::out|ios::in|ios::trunc);
    if(!F.is_open())
    {
        cout<<"���� �� ����� ���� ������!\n";
    }
    else
    {
        while (i!=kolvozn)
        {
            if (tz[i].fio != fio_udal)
                F << tz[i].fio <<", "<< tz[i].god <<" "<< tz[i].doljnost <<" "<< tz[i].adres <<"."<<"\n";
            i++;
        }
    }

        F.close();

        /*---------------------------------------------------------*/
        i=0;
        f.open("sotrudniki.txt", ios::out|ios::in|ios::trunc);
    if(!f.is_open())
    {
        cout<<"���� �� ����� ���� ������!\n";
    }
    else
    {
        while (i!=kolvozn)
        {
            if (tz[i].fio_b != fio_udal)
                f << tz[i].fio_b<<", "<< tz[i].god_b <<" "<< tz[i].doljnost_b <<" "<< tz[i].adres_b <<"."<<"\n";
            i++;
            z++;
        }
    }

        f.close();

        if(z!=0)
        cout<<"��������� "<<fio_udal<<" ��� ������ �� �����!"<<endl;
        else
            cout<<"��������� �� ������!"<<endl;

}

void vivod_spiska(int kolvozn, sotrudniki tz[])
{
    char sl;
	string sl1;
    ifstream f;
	int i=0;
    cout << "������� �.�.     ��� �������� ���������           �������� �����" << endl;
    cout << "------------------------------------------------------------------" << endl;
    f.open("sotrudniki.txt");
	if (!f.is_open())
	{
		cout << "���� �� ����� ���� ������!\n";
	}
	else if (!f.eof())
	{
		sotrudniki tz[88];
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
			f  >> tz[i].god >> tz[i].doljnost;
			if ((sl = f.get()) == ' ')
			getline(f, tz[i].adres,'.');
			cout << tz[i].fio<<" "<< tz[i].god <<" " << tz[i].doljnost<<" "<< tz[i].adres <<" "<<endl;
		}
    }
	f.close();
}

