#include <iostream>
#include "AV.h"
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "portuguese");
	Aviao AviaoMain;
	AviaoMain.Mov();
}