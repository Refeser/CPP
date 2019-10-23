#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

struct shkola
{
    string fio;
    string Nklass;
    string Bklass;
};
void spisok_uchenikov (int kolvozn, shkola tz[]);
void kolvo_uchenikov (int kolvozn, shkola tz[]);

int main()
{
	ifstream f;  /* ������ �� ������� ���� */
	char n;   /* ����� ������ ���� */
	int i;
	char sl;
	string sl1;
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	f.open("shkola.txt");
	if (!f.is_open())
	{
		cout << "���� �� ����� ���� ������!\n";
		cin.get();
		return 1;
	}
	else if (!f.eof())
	{
		shkola tz[88];
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
			f  >> tz[i].Nklass;
			if ((sl = f.get()) == ' ')
			getline(f, tz[i].Bklass,'.');
			cout << tz[i].fio<<" "<< tz[i].Nklass <<" "<< tz[i].Bklass <<" "<<endl;
		}

		int kolvozn = i - 1;
		do
		{
			cout << "========================================================"<<endl;
			cout << "�������� ����� ������ ����:"<<endl;
			cout << "1 - ������ �������� ��������� ������" << endl;
			cout << "2 - ���-�� �������� � ������ ������ � ������������ �������"<<endl;
			cout << "3 - �����"<<endl;
			cout << "------------------------------------------------------"<<endl;
			n=cin.get();
			cin.sync();
			switch (n)
			{
			case '1': spisok_uchenikov(kolvozn,tz); break;
			case '2': kolvo_uchenikov(kolvozn,tz); break;
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

void spisok_uchenikov (int kolvozn, shkola tz[])
{
	int i = 0, n=0;
	string klassN, klassB;
	cout<<"������� � ������: "<<endl;
	getline(cin, klassN);
	cout<<"������� ����� ������: "<<endl;
	getline(cin, klassB);
	cout << "� ������� ���              " << endl;
    cout << "---------------------------" << endl;
	while (i != kolvozn)
    {
			if ((tz[i].Nklass == klassN)&&(tz[i].Bklass == klassB))
			cout <<++n <<" "<< tz[i].fio <<" "<<endl;
			i++;
    }
    if(i==0)
        cout<<"���� ����!"<<endl;
}

void kolvo_uchenikov (int kolvozn, shkola tz[])
{
    string klass;
    int a=0,b=0,v=0;
    cout<<"������� � ������: "<<endl;
	getline(cin, klass);
    int i=0;
    while (i!=kolvozn)
    {
        if(tz[i].Nklass == klass)
        {
            if (tz[i].Bklass == "�")
                a++;
            else
                if (tz[i].Bklass == "�")
                    b++;
                else
                    if (tz[i].Bklass == "�")
                        v++;
        }
        i++;
    }
    cout<<"� ������ "<<klass<<" � ������ "<<a<<" ��������."<<endl;
    cout<<"� ������ "<<klass<<" � ������ "<<b<<" ��������."<<endl;
    cout<<"� ������ "<<klass<<" � ������ "<<v<<" ��������."<<endl;
}

