#include "header.h"
void koldo(EL_SP *p )
{
	string zd_id;
	cout << "������� �������������";
	getline (cin, zd_id);
	int kol=0;
	EL_SP *i;
	i=p;
	while (i->id != zd_id)
	{
            kol++;
			i = i->sled;
	}
		cout << "���������� ��������������� �� " <<zd_id<<" = "<<kol<< endl;
}
