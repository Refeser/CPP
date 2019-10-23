// ��������.cpp: ���������� ����� ����� ��� ����������� ����������.

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;


struct pacient		/* ��������� ������ �������� ����� */
{
	string  shifr; /* ���� */
	string  name; 	/* ������������  */
	string  colvo;	/* ���-�� ������ */
	string  price;	/* ���� */
};

/* ��������� ������� */
void Date(int kolvozn, pacient tz[]);
void MiddleAge(int kolvozn, pacient tz[]);
void Diagnos(int kolvozn, pacient tz[]);
int  Age(string gr);
void outputf1(char a[300], char b[300], char c[300], char d[300], char s[40]);
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
	f.open("patient.txt");
	if (!f.is_open()) // ���� ���� �� ������
	{
		cout << "���� �� ����� ���� ������!\n";
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
			cout << "�������� ����� ������ ����:"<<endl;
			cout << "1 - ����� ������ ���������, ����������� � �������� ����" << endl;
			cout << "2 - ����������� �������� �������� ���������"<<endl;
			cout << "3 - ������ � ����� ���� ������ ��������� � �������� ���������"<<endl;
			cout << "4 - �����"<<endl;
			cout << "------------------------------------------------------"<<endl;
			n=cin.get();
			cin.sync();
			switch (n)
			{
            case '1': Date(kolvozn,tz); break;
//			case '2': MiddleAge(kolvozn,tz); break;
			case '3': Diagnos(kolvozn,tz); break;
			case '4': break;
			default: cout << "\n����� ������� ����� ������ �� 1 �� 4";
			}
			if (n != '4')
			{
				cout << "\n��� ����������� ������� ����� �������";
				cin.get();
			}
		} while (n != '4');
		f.close();
	}
	else
	cout << "���� ����!\n";
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
				cout << "� ����   �-��  �-�� ����" << endl;
				cout << "--------------------------------------------------" << endl;
			}
			cout << ++n << " " << tz[i].shifr<<" "<< tz[i].name <<" " << tz[i].colvo<<" "<< tz[i].price<<endl;
			i++;


	}
	if (n == 0)  cout<<"\n��� ���������, ����������� � �������� ����";
	else cout << "����� ��������";

}

void Diagnos(int kolvozn,pacient tz[])
{
	string s1;
	ofstream fout; // ��������� ���� ��� ���������� ���������� � ����� �����
    fout.open("patient.txt", ios_base::app); // ��������� ���� ��� ���������� ���������� � ����� �����
    getline(cin,s1);

	fout<<s1;

	fout.close();

	 cout<<"������ � ���� ���������";

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
	if (i) cout<<"\n������� ������� ���������:\n" << s / kolvozn;
	else cout<<"\n���� patient.txt ������";
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

	cout<<"\n������� ��� ��������� �����: ";
	cin.getline(fname,80);
	cin.sync();
	fout.open(fname);
	cout<<"������� �������: ";
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
		cout<<"��� ��������� � �������� ���������";
		remove(fname);
	}
	else cout<<"������ � ���� ���������";

}
*/
