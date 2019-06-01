#include<iostream>
#include"Gra.h"

int main()
{
	std::cout << "Hello\n";
	Gra gra;
	gra.WyswietlPlansze();
	bool CzyKoniec = false;
	while (!CzyKoniec)
	{
		system("CLS");
		gra.WyswietlPlansze();
		gra.Ruch();
		system("CLS");
		gra.WyswietlPlansze();
		if (gra.SprawdzenieWygranej() == -10)
		{
			std::cout << "Gracz1 wygral!\n";
			CzyKoniec = true;
		}
		else if (gra.SprawdzenieWygranej() == 10)
		{
			std::cout << "Gracz2 wygral!\n";
			CzyKoniec = true;
		}
		else if (gra.SprawdzenieWygranej() == 0)
		{
			std::cout << "Remis!\n";
			CzyKoniec = true;
		}
	}
	std::cin.ignore();
	std::cin.ignore();
	return 0;
}