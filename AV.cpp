#include "AV.h"
#include <iostream>
#include <cstdlib>


//caso a gasolina esgote esta função sera chamada
bool Aviao::VerGasolina()
{
	if (gasolina == 0)
	{
		std::cout << "combustivel esgotado... motores falhando... \n";
		Tabuleiro[posX][posY] = ' ';
		pouso = true;
	}else{}
	return false;
}

//função para decolar o avião
int Aviao::Decolar()
{
	bool Condi{ 0 };

	while (Condi == 0)
	{
		std::cout << "Aperte F para Decolar: ";
			std::cin >> AvAr;
		system("CLS");

		if (AvAr == 'f' || AvAr == 'F')
		{
			system("CLS");
			if (PontosColetados == 8)
			{
				std::cout << "\nMissão comcluida\n";
			}
			std::cout << "Aviao decolou com sucesso\n";
				Condi = 1;

			std::cout << "Pressione qualquer tecla para continuar...\n";
			std::cin.ignore();
			std::cin.get();
			system("CLS");
			Aviao::InicializarAV();
		}
		else
		{
			std::cout << "Não foi possivel decolar tente novamente\n";
			std::cout << "Pressione qualquer tecla para continuar...\n";
			std::cin.ignore();
			std::cin.get();
			system("CLS");

		}
	}

	return 0;
}

// exibe o tabuleiro, mas tbm atualiza a posição do avião
void Aviao::InicializarAV()
{
	PointsC();
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			std::cout << Tabuleiro[i][j];

		}
		std::cout << std::endl;
	}
}

//sistema de movimentação do aviao
char Aviao::Mov()
{
	while (pouso == false)
	{
		std::cout << "Combustivel restante: " << gasolina << "\n";
		std::cout << "Pontos coletados: " << PontosColetados << "\n";
		std::cout << "X" << posX << " Y" << posY << "\n";
		std::cout << " Mov\n W A S D\n pousar\n F\n";
		
		std::cin >> Direcao;
		

		if (Direcao == 'w' || Direcao == 'W')
		{
			frente();
			system("cls");
			Aviao::InicializarAV();
		}
		else if (Direcao == 'S' || Direcao == 's')
		{
			atras();
			system("cls");
			Aviao::InicializarAV();
		}
		else if (Direcao == 'A' || Direcao == 'a')
		{
			left();
			system("cls");
			Aviao::InicializarAV();
		}
		else if (Direcao == 'd' || Direcao == 'D')
		{
			right();
			system("cls");
			Aviao::InicializarAV();
		}
		else if (Direcao == 'F' || 'f')
		{
			if (Tabuleiro[posX][posY] == Tabuleiro[4][9])
			{
				system("CLS");
				std::cout << "pouso realizado com sucesso\n";
				MissaoFim();
				pouso = true;
			}
			else
			{
				std::cout << "impossivel realizar este pouso\n";
					pouso = false;
			}
		}
		else
		{
			system("cls");
		}

		if (gasolina == 0)
		{
			VerGasolina();
			MissaoFim();
		}
		else if (PontosColetados == 8)
		{
			if (VU == 0) 
			{
				MissaoFim(); 
				VU == 1;
			}
		}else{}

	}
	return 0;
}

//chamado se todos os potos coletados tbm em caso de fracasso da missão/sucesso da missao
bool Aviao::MissaoFim()
{
	if (PontosColetados == 8)
	{
		
			if (VU == 0)
			{
				std::cout << "total de pontos coletados dirija-se a base de pouso na coordenada X4 Y9\n";
		    }
			
	}
	else if(gasolina == 0)
	{
		std::cout << "Combustivel esgotado Missão fracassada\n";
	}
	else { std::cout << "Fracasso na missão"; }
	return false;
}

//coloca os pontos no tabuleiro e retira eles
bool Aviao::PointsC()
{
	while (loopPoints == false)
	{

		MatrizDeFuncao[2][5] = true;
		MatrizDeFuncao[8][1] = true;
		MatrizDeFuncao[4][1] = true;
		MatrizDeFuncao[7][9] = true;
		MatrizDeFuncao[2][17] = true;
		MatrizDeFuncao[6][11] = true;
		MatrizDeFuncao[5][3] = true;
		MatrizDeFuncao[3][3] = true;
		

		Tabuleiro[2][5] = '*';
		Tabuleiro[8][1] = '*';
		Tabuleiro[4][1] = '*';
		Tabuleiro[7][9] = '*';
		Tabuleiro[2][17] = '*';
		Tabuleiro[6][11] = '*';
		Tabuleiro[5][3] = '*';
		Tabuleiro[3][3] = '*';
		

		loopPoints = true;
	}

	if (MatrizDeFuncao[posX][posY] == true)
	{
		PontosColetados++;
		MatrizDeFuncao[posX][posY] = false;
	}else{}
	return false;
}

//abaixo sistema verificador de caixa de colisão
bool Aviao::frente()
{
	if (posX == 1)
	{
		return false;
	}
	else
	{
		Tabuleiro[posX][posY] = ' ';
		posX--;
		Tabuleiro[posX][posY] = '^';
		gasolina--;
		return true;
	}
}

bool Aviao::atras()
{
	if (posX == 8)
	{
		return false;
	}
	else
	{
		Tabuleiro[posX][posY] = ' ';
		posX++;
		Tabuleiro[posX][posY] = '^';
		gasolina--;
		return true;
	}
}

bool Aviao::left()
{
	if (posY == 1)
	{
		return false;
	}
	else
	{
		Tabuleiro[posX][posY] = ' ';
		posY--;
		Tabuleiro[posX][posY] = '^';
		gasolina--;
		return true;
	}
}

bool Aviao::right()
{
	if (posY == 18)
	{
		return false;
	}
	else
	{
		Tabuleiro[posX][posY] = ' ';
		posY++;
		Tabuleiro[posX][posY] = '^';
		gasolina--;
		return true;
	}
}
