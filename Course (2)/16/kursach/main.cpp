#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

string gorodok;

struct plane
{
    string num;
    string gorod;
    string otpravka;
    string pribitie;
    string bilet;
};

void inf_gorod (int kolvozn, plane tz[]);
void kolvo_biletov (int kolvozn, plane tz[]);
int main()
{
	ifstream f;  /* ������ �� ������� ���� */
	char n;   /* ����� ������ ���� */
	int i;
	char sl;
	string sl1, t_id;
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	f.open("plane.txt");
	if (!f.is_open())
	{
		cout << "���� �� ����� ���� ������!\n";
		cin.get();
		return 1;
	}
	else if (!f.eof())
	{
		plane tz[88];
		for (i = 0; f.good();i++)
		{
			if ((sl=f.get())=='\n'&&i!=0)
			getline(f, tz[i].num,',');
			else
			{
				tz[i].num += sl;
				getline(f, sl1, ',');
				tz[i].num += sl1;
			}
			f  >>tz[i].gorod>>tz[i].otpravka>>tz[i].pribitie;
			if ((sl = f.get()) == ' ')
			getline(f, tz[i].bilet,'.');
			cout << tz[i].num<<" "<< tz[i].gorod <<" " << tz[i].otpravka<<" "<<tz[i].pribitie<<" "<<tz[i].bilet<<" "<<endl;
		}

		int kolvozn = i - 1;
		do
		{
			cout << "========================================================"<<endl;
			cout << "�������� ����� ������ ����:"<<endl;
			cout << "1 - ����� � ����� ����������� � �������� ��������� � �������� �����" << endl;
			cout << "2 - ������� ��������� ���� �� ��������� ����  � ���� �����"<<endl;
			cout << "3 - �����"<<endl;
			cout << "------------------------------------------------------"<<endl;
			n=cin.get();
			cin.sync();
			switch (n)
			{
			case '1': inf_gorod(kolvozn,tz); break;
			case '2': kolvo_biletov(kolvozn,tz); break;
			case '3': break;
			default: cout << "\n����� ������� ����� ������ �� 1 �� 4";
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

void inf_gorod (int kolvozn, plane tz[])
{
    int i=0;
    int k=0;
    int ki=0;
	cout<<"������� �������� ������:"<<endl;
	getline(cin, gorodok);
	while (i!= kolvozn)
    {
        if (tz[i].gorod == gorodok)
        {
            ki++;
            if(ki==1)
            {
                cout << "�      |��.����. |��.����.|���-�� �������"<<endl;
                cout << "-------|---------|--------|--------------"<<endl;
                ki++;
            }
            cout << tz[i].num<<" |"<< tz[i].otpravka<<"    |"<<tz[i].pribitie<<"   |"<<tz[i].bilet<<" "<<endl;
            k++;
        }
        i++;
    }
    if (k=0)
        cout<<"����� �� ������"<<endl;
}

void kolvo_biletov (int kolvozn, plane tz[])
{
    string nomer;
    int i=0, kb=0;
    cout<<"������� ����� �����:"<<endl;
    getline(cin,nomer);
    while (i!=kolvozn)
    {
        if (tz[i].num == nomer)
        {
            if (tz[i].gorod == gorodok)
            {
            cout<<"���������� ������� �� �������� ����: ";
            cout<<tz[i].bilet<<endl;
            kb++;
            }
        }
        i++;
    }
   if(kb==0)
    cout<<"���� � ����� ������� �� ����� � ������ ����� ����������!"<<endl;
}

