#ifndef GRA_H
#define GRA_H

class Gra
{
	int IloscWLini;
	int WielkoscPlanszy;
	int **Plansza;
	bool RuchGracza1 = 1;
	bool RuchGracza2 = 0;
	int IloscRuchow;
	bool WygranaGracza1 = 0;
	bool WygranaGracza2 = 0;
public:
	Gra();
	void Ruch();
	bool getWygranaGracza1();
	bool getWygranaGracza2();
	bool remis();
	void WyswietlPlansze();
	int SprawdzenieWygranej();
};
#endif