#include"Gra.h"
#include<iostream>
#include<stdlib.h>

Gra::Gra()
{
	std::cout << "\nPodaj wielkosc planszy:";
	std::cin >> WielkoscPlanszy;
	std::cout << "\nPodaj ilosc pol w jednej linii potrzebnych do wygranej:";
	std::cin >> IloscWLini;
	Plansza = new int *[WielkoscPlanszy+IloscWLini];
	for (int i = 0; i < WielkoscPlanszy + IloscWLini; i++)
		Plansza[i] = new int[WielkoscPlanszy + IloscWLini];
	for (int i = 0; i < WielkoscPlanszy + IloscWLini; i++)
		for (int j = 0; j < WielkoscPlanszy + IloscWLini; j++)
			Plansza[i][j] = 0;
}

void Gra::Ruch()
{
	if (RuchGracza1)
	{
		int i=0, j=0;
		std::cout << "Ruch Gracza1\n";
		std::cout << "Podaj nr kolumny:";
		std::cin >> i;
		std::cout << "\nPodaj nr wiersza:";
		std::cin >> j;
		Plansza[j-1][i-1] = -1;
		RuchGracza1 = false;
		RuchGracza2 = true;
		IloscRuchow++;
	}
	else 
		if (RuchGracza2)
		{
			int i = 0, j = 0;
			std::cout << "Ruch Gracza2\n";
			std::cout << "Podaj nr kolumny:";
			std::cin >> i;
			std::cout << "\nPodaj nr wiersza:";
			std::cin >> j;
			Plansza[j-1][i-1] = 1;
			RuchGracza1 = true;
			RuchGracza2 = false;
			IloscRuchow++;
		}
}

bool Gra::getWygranaGracza1()
{	return WygranaGracza1;}

bool Gra::getWygranaGracza2()
{	return WygranaGracza2;}

bool Gra::remis()
{
	for (int i = 0; i < WielkoscPlanszy; i++)
		for (int j = 0; j < WielkoscPlanszy; j++)
			if (Plansza[i][j] == 0)
				return false;
	return true;
}

void Gra::WyswietlPlansze()
{
	for (int i = 0; i < WielkoscPlanszy; i++)
	{
		for (int j = 0; j < WielkoscPlanszy; j++)
		{
			if (Plansza[i][j] == 0)
			{
				std::cout.width(3);
				std::cout << " ";
			}
			else if (Plansza[i][j] == -1)
			{
				std::cout.width(3);
				std::cout << " X ";
			}
			else if (Plansza[i][j] == 1)
			{
				std::cout.width(3);
				std::cout << " O ";
			}
			if (j != WielkoscPlanszy - 1)
			{
				std::cout.width(1);
				std::cout << "|";
			}
		}
		std::cout << "\n";
		if(i!=WielkoscPlanszy-1)
			for (int j = 0; j < WielkoscPlanszy; j++)
			{
				std::cout.width(4);
				std::cout << "----";
			}
		std::cout << "\n";
	}
}

int Gra::SprawdzenieWygranej()
{
	for (int i = 0; i < WielkoscPlanszy; i++)
		for (int j = 0; j < WielkoscPlanszy; j++)
		{
		//dla gracza1
		//Poziom
			for (int l = 0; l < IloscWLini; l++)
			{
				if (Plansza[i + l][j] == -1)
				{
					if (l == IloscWLini - 1)
					{
						WygranaGracza1 = true;
						return -10;
					}
				}
				else
					break;
		}
		//Pion
		for (int l = 0; l < IloscWLini; l++)
		{
			if (Plansza[i][j + l] == -1)
			{
				if (l == IloscWLini - 1)
				{
					WygranaGracza1 = true;
					return -10;
				}
			}
			else
				break;
		}
		//Skos
		for (int l = 0; l < IloscWLini; l++)
		{
			if (Plansza[i + l][j + l] == -1)
			{
				if (l == IloscWLini - 1)
				{
					WygranaGracza1 = true;
					return -10;
				}
			}
			else
				break;
		}


		//Skos2
		for (int l = 0; l < IloscWLini; l++)
		{
			if (Plansza[i + l][j - l] == -1)
			{
				if (l == IloscWLini - 1)
				{
					WygranaGracza1 = true;
					return -10;
				}
			}
			else
				break;
		}
		// dla gracza2
		//Poziom
		for (int l = 0; l < IloscWLini; l++)
		{

			if (Plansza[i + l][j] == 1)
			{
				if (l == IloscWLini - 1)
				{
					WygranaGracza2 = true;
					return 10;
				}
			}
			else
				break;

		}
		//Pion
		for (int l = 0; l < IloscWLini; l++)
		{
			if (Plansza[i][j + l] == 1)
			{
				if (l == IloscWLini - 1)
				{
					WygranaGracza2 = true;
					return 10;
				}
			}
			else
				break;
		}
		//Skos	
		for (int l = 0; l < IloscWLini; l++)
		{
			if (Plansza[i + l][j + l] == 1)
			{
				if (l == IloscWLini - 1)
				{
					WygranaGracza2 = true;
					return 10;
				}
			}
			else
				break;
		}
		//Skos2
		for (int l = 0; l < IloscWLini; l++)
		{
			if (Plansza[i + l][j - l] == 1)
			{
				if (l == IloscWLini - 1)
				{
					WygranaGracza2 = true;
					return 10;
				}
			}
			else
				break;
		}
	}



return 0;

}