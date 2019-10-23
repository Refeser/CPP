#include "header.h"
void udalenievtorogo(EL_SP **p)
{
int j = 1, k = 1;
EL_SP *i = *p, *j1=NULL;
while (i != NULL)
{
if (k==2)
{
j1->sled = i->sled;
delete i;
 cout << "удаление выполнено " << endl;
i = i->sled;
k++;
}
else
{
j1 = i;
i = i->sled;
j++;
k++;
}
}
}
