#include "header.h"
void PechSp(EL_SP *p)
{
	EL_SP *i;
	cout << "���������: " << endl;
	for (i = p; i != NULL; i = i->sled)
		cout << i->id << endl;
}
