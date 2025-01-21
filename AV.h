#pragma once
#include <iostream>
#include <wchar.h>

class Aviao
{
   private:

	   bool Missao = false;
	   bool pouso = false;
	   bool EstaAr;
	   bool loopPoints = false;
	   bool MatrizDeFuncao[10][20] = { false };
	   int gasolina = { 64 };
	   int PontosColetados{ 0 };
	   int posX{ 4 }; //linha
	   int posY{ 9 }; //coluna
	   int VU = 0;
	   char AvAr;
	   char Direcao;
	   char Tabuleiro[10][20] = {
	   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	   {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
	   {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
	   {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
	   {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '^', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
	   {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
	   {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
	   {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
	   {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
	   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
	   };
	   
	   

   public:
	   bool frente();
	   bool atras();
	   bool left();
	   bool right();
	   
	   bool VerGasolina();
	   bool MissaoFim();
	   bool PointsC();
	   int Decolar();
	   char Mov();
	   void InicializarAV();

	   Aviao()//construtor inicializador
	   {
		   Decolar();
	   }


};