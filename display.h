#ifndef _DISPLAY_H
#define _DISPLAY_H




#include "validate.h"




void DeleteMenuAdd()
{
	system("color 5A");
	for (int i = 0; i < 20; i++)
	{
		Gotoxy(X_ADD -2, Y_ADD+i-1);
		cout << setw(60) << setfill(' ') << " ";
	}
}


void CreateBox(int x, int y, string text, int length)
{
	Gotoxy(x - 2, y - 1);
	cout << char(201) << setw(length) << setfill(char(205)) << char(205) << char(187);

	Gotoxy(x - 2, y);
	cout << char(186) << text << setw(length - text.length() + 1) << setfill(' ') << char(186);

	Gotoxy(x - 2, y + 1);
	cout << char(200) << setw(length) << setfill(char(205)) << char(205) << char(188);
}

int xKeyDisplay[8] = { 5,25,45,65,85,95, 105, 115 };

//---------------------------------------------------------------------------------------------
string keyDisplayCreaditClass[7] = {"Ma Lop", "Ma Mon Hoc", "Nien Khoa", "Hoc Ki", "Nhom", "So Sinh Vien Max", "so Sinh Vien Min" };
string keyDisplayStudent[7] = { "Ma SV", "Ma Lop","Ho","Ten","Phai", "So DT", "Nam NH" };
string keyDisplaySubject[4] = {"Ma MH", "Ten MH", "So TCLT", "So TCTH"};
// ---------------------------------------------------------------------------------------------

void DeleteOldData(int nKey, int locate)
{
	for (int i = 0; i < nKey; i++)
	{
		Gotoxy(xKeyDisplay[i] + 1, Y_DISPLAY + 3 + locate);
		cout << setw(xKeyDisplay[i + 1] - xKeyDisplay[i] - 2) << setfill(' ') << " ";
	}
}


void Display(string key[], int nKey)
{
	
	//show key
	for (int i = 0; i < nKey; i++)
	{
		Gotoxy(xKeyDisplay[i] + 3, Y_DISPLAY+ 1);
		cout << key[i];
	}

	//show column 2 side
	for (int j = Y_DISPLAY; j <= Y_DISPLAY + 40; j++)
	{
		for (int i = 0; i < nKey+1; i++)
		{
			Gotoxy(xKeyDisplay[i], j);
			cout << char(186);
		}
	}

	//border left->right
	for (int i = xKeyDisplay[0]; i <= xKeyDisplay[nKey]; i++)
	{
		//border top (key)
		Gotoxy(i, Y_DISPLAY);
		if (i == xKeyDisplay[1] || i == xKeyDisplay[2] || i == xKeyDisplay[3] || i == xKeyDisplay[4])
			cout << char(203);//nga 3
		else if (i == xKeyDisplay[0])
		{
			cout << char(201); //moc phai
		}
		else if (i == xKeyDisplay[nKey])
		{
			cout << char(187);//moc trai
		}  
		else
		{
			cout << char(205); //duong thang ngang
		}

		//border bottom(key)
		Gotoxy(i, Y_DISPLAY + 2);
		if (i == xKeyDisplay[1] || i == xKeyDisplay[2] || i == xKeyDisplay[3] || i == xKeyDisplay[4])
			cout << char(206); //nga 4
		else if (i == xKeyDisplay[0])
		{
			cout << char(204); //nga 3 sang phai
		}
		else if (i == xKeyDisplay[nKey])
		{
			cout << char(185);//nga 3 sang trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}


		//border top (note)
		Gotoxy(i, Y_DISPLAY + 39);
		if (i == xKeyDisplay[nKey])
		{
			cout << char(185); //nga 3 sang trai
		}
		else if (i == xKeyDisplay[1] || i == xKeyDisplay[2] || i == xKeyDisplay[3] || i == xKeyDisplay[4])
			cout << char(202);
		else if (i == xKeyDisplay[0])
			cout << char(204); //nga 3 sang phai
		else
		{
			cout << char(205); //duong thang ngang
		}


		//border bottom (note)
		Gotoxy(i, Y_DISPLAY + 41);
		if (i == xKeyDisplay[0])
		{
			cout << char(200); //qeo sang phai
		}
		else if (i == xKeyDisplay[nKey])
		{
			cout << char(188); //qeo sang trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}
	}
	// SHOW note
	Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 40);
	cout << setw(xKeyDisplay[nKey] - xKeyDisplay[0]-1) << "F2: them F3: Xoa F4: Hieu Chinh F10: Save" << setfill(' ');
}

void DisplayEdit(string key[], int nKey,int length)
{
	int yAdd = Y_ADD;
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(X_ADD + 15, yAdd,key[i],length);
		yAdd += 3;
	}
}

void DeleteNote(int nColumn)
{
	Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 40);
	cout << setw(xKeyDisplay[nColumn] - xKeyDisplay[0] - 1) << " " << setfill(' ');
}


#endif
