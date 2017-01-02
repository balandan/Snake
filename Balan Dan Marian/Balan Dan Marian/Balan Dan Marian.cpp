#include"stdafx.h"
#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
int i, j, inaltime = 25, latime = 50, poz1, ok = 1, poz2,Ifruct,Jfruct,SCORE;
int Icoada[100], Jcoada[100],top[3];
int lungime_Coada;
bool gameOver;
enum directie { STOP, SUS, JOS, STANGA, DREAPTA };
directie dir;
void setari()
{   
	SCORE = 0;
	dir = STOP;
	lungime_Coada = 0;
	gameOver = false;
	poz1 = 6;
	poz2 = 3;
}

void harta()
{
	system("cls");
	Sleep(10);
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

			else if (i == poz1 && j == poz2) cout <<char(254);//capul sarpelui
			else if (i == Ifruct && j == Jfruct) cout << "?";
			else
			{
				bool afisare = false;
				for (int k = 0; k < lungime_Coada; k++)
				{

					if (Icoada[k] == i && Jcoada[k] == j)
					{
						cout <<char(254);
						afisare = true;
					}
					
				}
				if (!afisare)
					cout << " ";
			}
		}
		cout << endl;
	}
	cout << "SCORE:"<<SCORE;
}

void generare_fruct()
{
	Ifruct = rand() % 10;
	Jfruct = rand() % 10;
}

void Miscare_sarpe()
{

	if (GetAsyncKeyState(0x57)) dir = SUS;
	else if (GetAsyncKeyState(0x41))  dir = STANGA; 
	else if (GetAsyncKeyState(0x44))  dir = DREAPTA; 
	else if (GetAsyncKeyState(0x53))  dir = JOS; 


}

void miscare()
{
	int J_anterior = Jcoada[0];
	int I_anterior = Icoada[0];
	int I_anteriorX2, J_anteriorX2;
	Icoada[0] = poz1;
	Jcoada[0] = poz2;
	for (int l = 1; l < lungime_Coada; l++)
	{
		I_anteriorX2 = Icoada[l];
		J_anteriorX2 = Jcoada[l];
		Icoada[l] = I_anterior;
		Jcoada[l] = J_anterior;
		I_anterior = I_anteriorX2;
		J_anterior = J_anteriorX2;
	}
	switch (dir)
	{
	case SUS:
		poz1--;
		break;
	case JOS:
		poz1++;
		break;
	case STANGA:
		poz2--;
		break;
	case DREAPTA:
		poz2++;
		break;
	default:
		break;
	}
	if (poz1 == 0	 || poz2 == 0) gameOver = true; 
	else if (poz1 == inaltime - 1 || poz2 == latime - 1) gameOver = true;
}

void Colectare_fruct()
{
	if (poz1 == Ifruct && poz2 == Jfruct) 
	{
		SCORE = SCORE + 10;
		lungime_Coada++;
		Ifruct = rand() % 13;
		Jfruct = rand() % 13;
		if (Ifruct == 0 || Jfruct == 0)
		{
			Ifruct = rand() % 14;
			Jfruct = rand() % 14;
		}
		
	}

}


int matrice_meniu[31][57] =
{   
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,1,0,1,0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,1,1,1,0,0,0,1,1,1,0,1,0,0,0,1,1,1,0,1,0,0,0,0,0,1,0,1,1,1,0,1,1,1,0,0 },
	{ 0,0,1,0,0,0,0,0,1,1,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0 },
	{ 0,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,0,0,0,1,1,1,0,1,0,0,0,1,1,1,0,0,0,1,0,1,0,0,0,1,1,1,0,1,1,1,0,0 },
	{ 0,0,0,0,1,0,1,0,1,0,0,1,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,0,0,0 },
	{ 2,3,1,1,1,0,1,0,1,0,0,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,1,0,0,0,1,1,1,0,1,0,1,0,0,0,0,1,0,0,0,0,1,1,1,0,1,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,1,0,1,0,0,0,1,1,1,0,1,0,0,0,0,0,1,0,1,1,1,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,1,1,1,0,1,1,1,0,0 },
	{ 0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0 },
	{ 0,0,1,1,1,0,1,0,0,0,1,1,1,0,0,0,1,0,1,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,1,0,0 },
	{ 0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0 },
	{ 4,3,1,0,0,0,1,1,1,0,1,0,1,0,0,0,0,1,0,0,0,0,1,1,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,1,1,1,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,1,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,0,0,0,1,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,3,1,0,0,1,0,1,0,1,1,1,0,1,0,0,1,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,1,1,0,0,0,1,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,1,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,1,1,0,0,1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 6,3,1,1,1,1,0,1,0,1,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
};


void meniu()
{
	for (int i = 0; i < 33; i++)
	{
		for (int j = 0; j < 57; j++)
		{
			if (matrice_meniu[i][j] == 0) cout << " ";
			else if (matrice_meniu[i][j] == 1) cout << char(219);
			else if (matrice_meniu[i][j] == 2)cout << char(49);
			else if (matrice_meniu[i][j] == 3)cout << char(46);
			else if (matrice_meniu[i][j] == 4)cout << char(50);
			else if (matrice_meniu[i][j] == 5)cout << char(51);
			else if (matrice_meniu[i][j] == 6)cout << char(52);
		}
		cout << endl;
	}
	cout << "PRESS 1 , 2 , 3 OR 4 FOR YOUR OPTION!";
}

int matrice_Game_over[8][57] =
{
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,0,1,1,1,0,1,0,0,0,0,1,0,1,1,1,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,0,0,0,1,0,1,0,1,1,0,0,1,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,0,1,0,1,1,1,0,1,0,1,1,0,1,0,1,1,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0 },
};

void Afisare_Gameover()
{
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 57; j++)
		{
			if (matrice_Game_over[i][j] == 1)cout << char(219);
			else cout << " ";
		}
		cout << endl;
	}
}

void optiunea_jucatorului()
{
	while (ok == 1)
		if (GetAsyncKeyState(0x31))
		{
			system("cls");
			cout << endl;
			cout << endl;
			cout << "LOADING";
			Sleep(0700);
			cout << ".";
			Sleep(0700);
			cout << ".";
			Sleep(0700);
			cout << ".";
			Sleep(0700);
			setari();
			generare_fruct();
			while (gameOver != 1) {

				harta();
				Sleep(1000);
				Colectare_fruct();
				Miscare_sarpe();
				miscare();
				
			}
			if (gameOver == 1) 
			{
				if (SCORE >= top[0]) 
				{
					top[2] = top[1];
					top[1] = top[0];
					top[0] = SCORE;
			    }
				else if (SCORE >= top[1])
				{
					top[2] = top[1];
					top[1] = SCORE;
				}
				else if (SCORE > top[2])
				{
					top[2] = SCORE;
				}
				Afisare_Gameover();

			}
			

		}
		else if (GetAsyncKeyState(0x32))
		{
			system("cls");
			cout << endl;
			cout << endl;
			cout << "LOADING";
			Sleep(0700);
			cout << ".";
			Sleep(0700);
			cout << ".";
			Sleep(0700);
			cout << ".";
			Sleep(0700);
			system("cls");
			cout << "ai ales sa joci cu computerul";

		}
		else if (GetAsyncKeyState(0x33))
		{
			system("cls");
			cout << endl;
			cout << endl;
			cout << "LOADING";
			Sleep(0700);
			cout << ".";
			Sleep(0700);
			cout << ".";
			Sleep(0700);
			cout << ".";
			Sleep(0700);
			system("cls");
			cout << "locul 1:" <<top[0]<<endl;
			cout << "locul 2:" <<top[1]<<endl;
			cout << "locul 3:" <<top[2]<<endl;
		}
		else if (GetAsyncKeyState(0x34))
		{
			system("cls");
			cout << endl;
			cout << endl;
			cout << "LOADING";
			Sleep(0700);
			cout << ".";
			Sleep(0700);
			cout << ".";
			Sleep(0700);
			cout << ".";
			Sleep(0700);
			system("cls");
			cout << "Ai iesit din joc";
			gameOver = 1;
		}
}





int main()
{   

	meniu();
	optiunea_jucatorului();
	cin.get();
}

