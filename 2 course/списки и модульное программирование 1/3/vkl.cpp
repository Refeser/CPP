#include "header.h"
void Vkl(EL_SP **p, string t_id)
{
	EL_SP *pt;
	EL_SP *k = NULL;
	EL_SP *j = NULL;
	pt = new EL_SP();
	pt->id = t_id;
	if (*p == NULL || pt->id<(*p)->id)
	{
		pt->sled = *p;
		*p = pt;
	}
	else
	{
		k = *p;
		while (k != NULL&&pt->id >= k->id)
		{
			j = k;
			k = k->sled;
		}
		j->sled = pt;
		pt->sled = k;
	}

}
