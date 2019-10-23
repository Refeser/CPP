#include "header.h"
void PechSp(EL_SP *p)
{
	EL_SP *i;
	cout << "Результат: " << endl;
	for (i = p; i != NULL; i = i->sled)
		cout << i->id << endl;
}
