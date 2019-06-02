#include"Gra.h"
#include<iostream>
#include<stdlib.h>

Gra::Gra()
{
	WielkoscPlanszy = 0;
	IloscWLini = 0;
	std::cout << "\nPodaj wielkosc planszy:";
	std::cin >> WielkoscPlanszy;
	while (WielkoscPlanszy < 2)												//zabezpieczenie przed blednymi danymi
	{
		std::cout << "\nBledna wartosc! \nPodaj ponownie wielkosc planszy:";
		std::cin >> WielkoscPlanszy;
	}
	std::cout << "\nPodaj ilosc pol w jednej linii potrzebnych do wygranej:";
	std::cin >> IloscWLini;
	while (IloscWLini<1 || IloscWLini>WielkoscPlanszy)						//zabezpieczenie przed blednymi danymi
	{
		std::cout << "\nBledna Wartosc! \nPodaj ponownie ilosc pol w jednej linii potrzebnych do wygranej:";
		std::cin >> IloscWLini;
	}
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
		int i = 0, j = 0;
		std::cout << "Ruch Gracza1\n";
		std::cout << "Podaj nr kolumny:";
		std::cin >> i;
		std::cout << "\nPodaj nr wiersza:";
		std::cin >> j;
		while (i<1 || j<1 || i>WielkoscPlanszy || j>WielkoscPlanszy) //Zabezpieczenie przed wprowadzeniem b³êdnych danych
		{
			std::cout << "Wybrane pole nie jest czescia planszy!\n";
			std::cout << "Podaj nr kolumny:";
			std::cin >> i;
			std::cout << "\nPodaj nr wiersza:";
			std::cin >> j;
		}
		if (Plansza[j-1][i-1]==0) //Zabezpieczenie przed wybraniem zajêtego pola
			Plansza[j-1][i-1] = -1;
		else
		{
			while (i<1 || j<1 || i>WielkoscPlanszy || j>WielkoscPlanszy || Plansza[j - 1][i - 1] != 0)
			{
				std::cout << "Pole zajete! Sproboj ponownie:\n";
				std::cout << "Podaj nr kolumny:";
				std::cin >> i;
				std::cout << "\nPodaj nr wiersza:";
				std::cin >> j;
			}
			Plansza[j - 1][i - 1] = -1;
		}
		RuchGracza1 = false;
		RuchGracza2 = true;
	}
	else 
		if (RuchGracza2)
		{
			int i = 0, j = 0;
			/* Wersja dla dwoch graczy
			std::cout << "Ruch Gracza2\n";
			std::cout << "Podaj nr kolumny:";
			std::cin >> i;
			std::cout << "\nPodaj nr wiersza:";
			std::cin >> j;
			*/
			ZnajdzNajlepszyRuch(Plansza, i, j);  // Wersja do gry z algorytmem
			Plansza[i][j] = 1;
			RuchGracza1 = true;
			RuchGracza2 = false;
		}
}

bool Gra::getWygranaGracza1()
{	return WygranaGracza1;}

bool Gra::getWygranaGracza2()
{	return WygranaGracza2;}

bool Gra::remis() // Jezeli kazde pole jest zajete i nikt nie wygral to remis
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
	if (remis())
		return 0;
	return -1;
}

int Gra::Maximum(int a, int b) //zwraca wieksza wartosc
{
	if (a > b)
		return a;
	else
		return b;
}

int Gra::Minimum(int a, int b) //zwraca mniejsza wartosc
{
	if (a < b)
		return a;
	else
		return b;
}

int Gra::MinMax(int **plansza, int AktualnaGlebokosc, bool CzyRuchGracza, int alpha, int beta)
{
	int WynikGry = SprawdzenieWygranej();

	if (WynikGry == 10) //Wygrywa algorytm
		return WynikGry - AktualnaGlebokosc;

	if (WynikGry == -10)									//Wygrywa Gracz
		return WynikGry + AktualnaGlebokosc;

	if (remis())
		return 0;

	if (CzyRuchGracza) {										//Jesli ruch gracza maksymalizujacego
		int NajlepszyWynik = -1000;
		for (int i = 0; i < WielkoscPlanszy; i++) {				//Przejscie po kazdym elemencie planszy
			for (int j = 0; j < WielkoscPlanszy; j++) {
				if (plansza[i][j] == 0) {						//Jezeli element planszy jest wolny
					plansza[i][j] = 1;							//symulujemy ruch Algorytmu w tym miejscu
					int Pom = MinMax(plansza, AktualnaGlebokosc + 1, false, alpha, beta);		//Wywolujemy MinMax rekurencyjnie
					NajlepszyWynik = Maximum(NajlepszyWynik, Pom);								//Wybieramy wieksza wartosc
					alpha = Maximum(NajlepszyWynik, alpha);
					plansza[i][j] = 0;															//cofamy symulacje ruchu Algorytmu
					if (beta <= alpha)							//Ciecie alfa beta
						break;
				}
				if (beta <= alpha)								//Ciecie alfa beta
					break;
			}
		}
		return NajlepszyWynik;
	}
	else														//Jesli ruch gracza minimalizujacego
	{
		int NajlepszyWynik = 1000;
		for (int i = 0; i < WielkoscPlanszy; i++) {				//Przejscie po kazdym elemencie planszy
			for (int j = 0; j < WielkoscPlanszy; j++) {
				if (plansza[i][j] == 0) {						//Jezeli element planszy jest wolny
					plansza[i][j] = -1;							//symulujemy ruch Gracza w tym miejscu
					int Pom = MinMax(plansza, AktualnaGlebokosc + 1, true, alpha, beta);		//Wywolujemy MinMax rekurencyjnie
					NajlepszyWynik = Minimum(NajlepszyWynik, Pom);								//Wybieramy mniejsza wartosc
					beta = Minimum(NajlepszyWynik, beta);
					plansza[i][j] = 0;															//cofamy symulacje ruchu Gracza
					if (beta <= alpha)															//Ciecie alfa beta
						break;
				}
				if (beta <= alpha)																//Ciecie alfa beta
					break;
			}
		}
		return NajlepszyWynik;
	}
}

void Gra::ZnajdzNajlepszyRuch(int **plansza, int &nrwiersza, int &nrkolumny)
{
	int Naj = -1000;
	int alpha = -1000;
	int beta = 1000;
	for (int i = 0; i < WielkoscPlanszy; i++)
		for (int j = 0; j < WielkoscPlanszy; j++)						//Przejscie po kazdym elemencie planszy
			if (plansza[i][j] == 0)										// Jezeli element planszy jest wolny
			{
				plansza[i][j] = 1;										// sumulejmy ruch Algorytmu w tym miejscu 
				int Ruch = MinMax(plansza, 0, false , alpha, beta);		//Wywolujemy MinMax
				plansza[i][j] = 0;										// cofamy symulacje ruchu
				if (Ruch > Naj)											//Jesli wartosc aktualnego ruchu jest lepsza od Najlepszego to aktualizujemy	
				{
					nrwiersza = i;
					nrkolumny = j;
					Naj = Ruch;
				}
			}
}