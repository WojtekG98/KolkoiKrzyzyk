#ifndef GRA_H
#define GRA_H

class Gra
{
	int IloscWLini;				// Zmienna ustalaj¹ca ile znaków ma byæ w linii ¿eby wygraæ
	int WielkoscPlanszy;		// Zmienna ustalaj¹ca wielkosc planszy do gry 
	int **Plansza;				// Tablica dwuwymiarowa symulujaca plansze do gry, -1 dla Gracza1, 1 dla Gracza2, 0 dla pola wolnego
	bool RuchGracza1 = 1;		// Zmienna mówi¹ca czy jest teraz kolej na ruch Gracza1
	bool RuchGracza2 = 0;		// Zmienna mówi¹ca czy jest teraz kolej na ruch Gracza2
	bool WygranaGracza1 = 0;	// Zmienna mówi¹ca czy wygra³ Gracz1
	bool WygranaGracza2 = 0;	// Zmienna mówi¹ca czy wygra³ Gracz2
public:
	Gra();										// Konstruktor
	void Ruch();								// Ruch jednego z graczy
	bool getWygranaGracza1();					// Zwraca zmienna WygranaGracza1
	bool getWygranaGracza2();					// Zwraca zmienna WygranaGracza2
	bool remis();								// Zwraca true jesli remis
	void WyswietlPlansze();						// Wyswietla plansze w terminalu
	int SprawdzenieWygranej();					// Sprawdza kto wygra³, je¿eli Gracz1 to zwraca -10, je¿eli Gracz2 to zwraca 10, je¿eli remis to zwraca 0
	int Maximum(int a, int b);					// Zwraca Maximum z dwoch liczb a i b
	int Minimum(int a, int b);					// Zwraca Minimum z dwoch liczb a i b
	int MinMax(int **plansza,int AktualnaGlebokosc, bool CzyRuchGracza, int alpha, int beta); //Zwraca optymalna wartoœæ koñca gry dla aktualnego gracza
	void ZnajdzNajlepszyRuch(int **plansza, int &nrwiersza, int &nrkolumny); // Znajduje najlepszy ruch dla danej planszy i zapisuje indeksy najlepszego miejsca na planszy do zmiennych nrwiersza i nrkolumny
};
#endif