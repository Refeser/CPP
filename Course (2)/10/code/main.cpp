#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

struct sessia
{
    string fio;
    string zachet;
    string z1, z2, z3, z4;
};
void ne_doljen (int kolvozn, sessia tz[]);
void procent_ne_uspevaushih (int kolvozn, sessia tz[]);

int main()
{
	ifstream f;  /* ������ �� ������� ���� */
	char n;   /* ����� ������ ���� */
	int i;
	char sl;
	string sl1;
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	f.open("sessia.txt");
	if (!f.is_open())
	{
		cout << "���� �� ����� ���� ������!\n";
		cin.get();
		return 1;
	}
	else if (!f.eof())
	{
		sessia tz[88];
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
			f  >> tz[i].z1;
			if ((sl = f.get()) == ' ')
            {
			f>>tz[i].z2;
            }
            if ((sl = f.get()) == ' ')
            {
			f>>tz[i].z3;
            }
            if ((sl = f.get()) == ' ')
            {
			f>>tz[i].z4;
            }
			if ((sl = f.get()) == ' ')
            {
			getline(f, tz[i].zachet,'.');
            }
			cout << tz[i].fio<<" "<<" " << tz[i].z1<<" "<<" " << tz[i].z2<<" " << tz[i].z3<<" " << tz[i].z4<<" " << tz[i].zachet <<" "<<endl;
		}

		int kolvozn = i - 1;
		do
		{
			cout << "========================================================"<<endl;
			cout << "�������� ����� ������ ����:"<<endl;
			cout << "1 - ������ ��������� ��� ������������ " << endl;
			cout << "2 - ������� ������������ ��������� "<<endl;
			cout << "3 - �����"<<endl;
			cout << "------------------------------------------------------"<<endl;
			n=cin.get();
			cin.sync();
			switch (n)
			{
			case '1': ne_doljen(kolvozn,tz); break;
			case '2': procent_ne_uspevaushih(kolvozn,tz); break;
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

void ne_doljen (int kolvozn, sessia tz[])
{
	int n = 0;
	int i=0;
	cout << "� ������� �.�. ����� �������" << endl;
    cout << "----------------------------" << endl;
	while (i != kolvozn)
    {
			if ((tz[i].zachet == "�����")&&(tz[i].z1 != "2")&&(tz[i].z2 != "2")&&(tz[i].z3 != "2")&&(tz[i].z4 != "2"))
			cout <<++n<<" "<< tz[i].fio <<" "<<endl;
			i++;
    }
	if (n == 0)  cout<<"\n���� ����";
	else cout << "����� ��������";
}

void procent_ne_uspevaushih (int kolvozn, sessia tz[])
{
    double procent;
    int i=0, m=0, k=0;
    while(i!=kolvozn)
    {
    if ((tz[i].zachet != "�����")||(tz[i].z1 == "2")||(tz[i].z2 == "2")||(tz[i].z3 == "2")||(tz[i].z4 == "2"))
        k++;
        i++;
        m++;
    }
    procent = k;
    procent = procent/m;
    procent = procent*100;
    if (k!=0)
    cout<<"������� ������������ = "<<procent<<endl;
    else
    cout<<"���� ����"<<endl;
}


