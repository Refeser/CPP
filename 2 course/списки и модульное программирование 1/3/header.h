#pragma once
#include <iostream>
#include<string>
#include <windows.h>
using namespace std;
struct EL_SP
{
	string id;
	EL_SP *sled;
};
void Vkl(EL_SP **p, string t_id);
void PechSp(EL_SP *p);
void udalenievtorogo(EL_SP **p);
void zamenaposlednego(EL_SP *p, int kol1);
void koldo(EL_SP *p );
