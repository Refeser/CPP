#include "header.h"
void zamenaposlednego(EL_SP *p, int kol1)
{
    EL_SP *i;
    int k=0;
	string zd_id;
	cout << "ВВедите на какой элемент заменить";
	cin >> zd_id;
	int j = 1;

    for (i = p,j; i != NULL; i = i->sled,j++)
        k++;
        j=1;
    for (i = p,j; i != NULL&&j<k; i = i->sled,j++)
        continue;
       i->id=zd_id;
       cout<<"замена выполнена"<<endl;
}
