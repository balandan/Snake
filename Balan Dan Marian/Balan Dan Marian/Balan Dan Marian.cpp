#include"stdafx.h"
#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
int i, j, inaltime, latime, poz1, poz2;
void setari()
{
	inaltime = 15;
	latime = 30;
	poz1 = 3;
	poz2 = 3;
}
void harta()
{
	system("cls");
	for (i = 0; i < inaltime; i++)
	{
		for (j = 0; j < latime; j++)
		{
			if (i == 0 && j == 0) cout << char(201);//colt stanga sus

			else if (i == 0 && j == latime - 1) cout << char(187);//colt dreapta sus

			else if (i == inaltime - 1 && j == 0) cout << char(200);//colt stanga jos

			else if (i == inaltime - 1 && j == latime - 1) cout << char(188);//colt dreapta jos

			else if (i == 0 && j != 0) cout << char(205);//marginea superioara 

			else if (j == 0 && i != 0 && i != inaltime - 1) cout << char(186);//marginea din stanga exceptand colturile

			else if (j == latime - 1 && i != 0 && i != inaltime - 1) cout << char(186);//marginea din dreapta fara colturi -sus,jos

			else if (i == inaltime - 1 && j != 0 && j != latime - 1) cout << char(205);//marginea de jos fara colturi 

			else if (i == poz1 && j == poz2) cout << char(254);//capul sarpelui
			else cout << " ";
		}
		cout << endl;
	}

}

int main()
{
	setari();
	harta();
	cin.get();
}

