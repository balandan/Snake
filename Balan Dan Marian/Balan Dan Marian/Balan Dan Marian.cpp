#include"stdafx.h"
#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
int i, j, inaltime = 25, latime = 50, poz1, ok = 1, poz2,Icap,Jcap,Ifruct,Jfruct,SCORE,SCORE2;
int Icoada[100], Jcoada[100],I2coada[100],J2coada[100],top[3];
int lungime_Coada,lungime_Coada2;
bool gameOver,Sarpe2,activare,puncteX2;
enum directie { STOP, SUS, JOS, STANGA, DREAPTA };
directie dir,dir_auto;


void setari()
{
	SCORE2 = 0;
	SCORE = 0;
	dir = STOP;
	lungime_Coada = 0;
	lungime_Coada2 = 0;
	gameOver = false;
	poz1 = 6;// linia sarpelui controlat de player
	poz2 = 3;//coloana sarpelui controlat de player
	Icap = 10;//linia capului sarpelui controlat de computer
	Jcap = 12;//coloana capului sarpelui controlat de computer
}

void generare_fruct()
{
	Ifruct = rand() % (inaltime-1) ;
	Jfruct = rand() % (latime - 1);
}

void harta()
{   
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 263);
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
			else if (i == poz1 && j == poz2) cout <<char(254);//capul sarpelui
			else if (i == Ifruct && j == Jfruct && i % 2 == 0 && j % 2 == 0)
			{
				cout << "!";
				puncteX2 = 1;
			}                                                                  
			else if (i == Ifruct && j == Jfruct) cout << "?";
			else if (Sarpe2 == 1 && i == Icap && j == Jcap) cout << char(254);
			else if(activare==1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 265);
				bool afisare_sarpe2 = false;
				for (int k = 0; k < lungime_Coada2; k++)
				{
					if (Icap == I2coada[k] && Jcap == J2coada[k]) gameOver = true;
					else if (Ifruct == I2coada[k] && Jfruct == J2coada[k]) generare_fruct();// sa nu mai genereze fructe pe corpul sarpelui
					else if (poz1 == I2coada[k] && poz2 == J2coada[k]) gameOver = true;
					else  if (I2coada[k] == i && J2coada[k] == j)
					{
						cout << char(254);
						afisare_sarpe2 = true;
					}

				}
				{   
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 260);
					for (int k = 0; k < lungime_Coada; k++)
					{
						if (poz1 == Icoada[k] && poz2 == Jcoada[k]) gameOver = true;
						else if (Ifruct == Icoada[k] && Jfruct == Jcoada[k]) generare_fruct();
						else if (Icap == Icoada[k] && Jcap == Jcoada[k]) gameOver = true;
						else  if (Icoada[k] == i && Jcoada[k] == j)
						{
							cout << char(254);
							afisare_sarpe2 = true;
						}

					}
					if (!afisare_sarpe2)
						cout << " ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 263);
				}
			}
			else 
			{
				
				bool afisare = false;
				for (int k = 0; k < lungime_Coada; k++)
				{
					if (poz1 == Icoada[k] && poz2 == Jcoada[k]) gameOver = true;
					else if (Ifruct == Icoada[k] && Jfruct == Jcoada[k]) generare_fruct();
					else  if (Icoada[k] == i && Jcoada[k] == j)
					{
						cout << char(254);
						afisare = true;
					}

				}
				if (!afisare)
					cout << " ";
			}
		}
		cout << endl;
	}
	cout << "SCORE:" << SCORE << endl;
	cout << "SCORE2:" << SCORE2;
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

void Al_doilea_sarpe()
{
		if (Icap < Ifruct && dir_auto == SUS) dir_auto = DREAPTA;
		else if (Icap < Ifruct) dir_auto = JOS;
		else if (Icap > Ifruct && dir_auto == JOS) dir_auto = STANGA;
		else if (Icap > Ifruct)dir_auto = SUS;
		else if (Icap == Ifruct && Jcap > Jfruct && dir_auto == DREAPTA) dir_auto = SUS;
		else if (Icap == Ifruct && Jcap > Jfruct) dir_auto = STANGA;
		else if (Icap == Ifruct && Jcap < Jfruct && dir_auto == STANGA) dir_auto = JOS;
		else if (Icap == Ifruct && Jcap < Jfruct) dir_auto = DREAPTA;
		else if (Icap == Ifruct && Jcap == Jfruct)
		{
			SCORE2 = SCORE2 + 10;
			lungime_Coada2++;
			Ifruct = rand() % (inaltime - 2);
			Jfruct = rand() % (latime - 2);
			if (Ifruct == 0 || Jfruct == 0)
			{
				Ifruct = rand() % (inaltime - 3);
				Jfruct = rand() % (latime - 3);
			}
		
		}
}

void Al_doilea_sarpe_miscare()
{

	int J2_anterior = J2coada[0];
	int I2_anterior = I2coada[0];
	int I2_anteriorX2, J2_anteriorX2;
	I2coada[0] = Icap;
	J2coada[0] = Jcap;
	for (int l = 1; l < lungime_Coada2; l++)
	{
		I2_anteriorX2 = I2coada[l];
		J2_anteriorX2 = J2coada[l];
		I2coada[l] = I2_anterior;
		J2coada[l] = J2_anterior;
		I2_anterior = I2_anteriorX2;
		J2_anterior = J2_anteriorX2;
	}
	switch (dir_auto)
	{
	case SUS:
		Icap--;
		break;
	case JOS:
		Icap++;
		break;
	case STANGA:
		Jcap--;
		break;
	case DREAPTA:
		Jcap++;
		break;
	default:
		break;
	}
	if (Icap == 0 || Jcap== 0) gameOver = true;
	else if (Icap == inaltime - 1 || Jcap == latime - 1) gameOver = true;
}

void Colectare_fruct()
{
	if (poz1 == Ifruct && poz2 == Jfruct) 
	{
		if (puncteX2 == 1) 
		{ 
			lungime_Coada = lungime_Coada +2 ;
			SCORE = SCORE + 20;
			puncteX2 = 0;
		}
		else
		{
			lungime_Coada++;
			SCORE = SCORE + 10;
		}
		Ifruct = rand() % (inaltime-2);
		Jfruct = rand() % (latime-2);
		if (Ifruct == 0 || Jfruct == 0)
		{
			Ifruct = rand() % (inaltime-3);
			Jfruct = rand() % (latime-3);
		}
		
	}

}


int matrice_meniu[26][57] =
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
	
};


void meniu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 258);
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 57; j++)
		{
			if (matrice_meniu[i][j] == 0) cout << " ";
			else if (matrice_meniu[i][j] == 1) cout << char(219);
			else if (matrice_meniu[i][j] == 2)cout << char(49);
			else if (matrice_meniu[i][j] == 3)cout << char(46);
			else if (matrice_meniu[i][j] == 4)cout << char(50);
			else if (matrice_meniu[i][j] == 5)cout << char(51);
		}
		cout << endl;
	}
	cout << "PRESS 1 , 2 , 3 FOR YOUR OPTION!";
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 263);
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
			while (gameOver != 1) 
		  {
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 265);
				harta();
				Sleep(100);
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
			setari();
			generare_fruct();
			activare = 1;
			Sarpe2 = true;
			while (gameOver != 1) {
				
				harta();
			    Sleep(0700);
				Colectare_fruct();
				Miscare_sarpe();
				miscare();
				Al_doilea_sarpe_miscare();
				Al_doilea_sarpe();
				

			}
			if (gameOver==1)
			{
				activare = 0;
				Sarpe2 = 0;
			}

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

