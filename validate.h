#pragma once


#include <cstdlib>

#include <math.h>
#include <conio.h>
#include <stdio.h>

#include <stdlib.h>
#include <dos.h>
#include <string.h>

#include <windows.h>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "lib.h"
#include"constant.h"
#include "globalvariable.h"


using namespace std;


//only char and number
void CheckMoveAndValidateID(string &result, bool &isMove, int &ordinal, bool &isSave, int distance, int condition)
{
	int lengh = result.length();
	Gotoxy(X_ADD + distance , ordinal * 3 + Y_ADD);
	cout << result;
	int count = lengh;
	while (true)
	{
		while (_kbhit())
		{
			int key = _getch();
			if (key != 224 && key != SPACE && key != 0)
			{
				if ((key >= 65 && key <= 90) || (key >= 97 && key <= 122)  || (key >= 48 && key <= 57))
				{
					if (count < condition)
					{
						count++;
						cout << (char)key;
						result += (char)key;
					}
					
				}
				else if (key == ENTER)
					return;
				else if (key == BACKSPACE && count >0)
				{
					cout << "\b" << " " << "\b";
					result.erase(result.length() - 1,1);
					count--;

				}
			}
			else if (key == 224)
			{
				key = _getch();
				if (key == KEY_UP)
				{
					isMove = true;
					return;
				}
				else
				{
					isMove = false;
					return;
				}
			}
			else if (key == 0)
			{
				key = _getch();
				if (key == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
		}//kbhit
	}//while true

}

void CheckMoveAndValdateIdClass(string &result, int distance)
{
	int lengh = result.length();
	Gotoxy(X_ADD + distance , Y_ADD);
	cout << result;
	int count = lengh;
	while (true)
	{
		while (_kbhit())
		{
			int key = _getch();
			if (key != 224 && key != SPACE && key != 0)
			{
				if ((key >= 65 && key <= 90) || (key >= 97 && key <= 122)  || (key >= 48 && key <= 57))
				{
					if (count < 15)
					{
						count++;
						cout << (char)key;
						result += (char)key;
					}
					
				}
				else if (key == ENTER)
					return;
				else if (key == BACKSPACE && count >0)
				{
					cout << "\b" << " " << "\b";
					result.erase(result.length() - 1,1);
					count--;

				}
			}
		
		}//kbhit
	}//while true
}


void CheckMoveAndValidateName(string &result, bool &isMove, int &ordinal, bool &isSave,int distance, int condition)
{
	int lengh = result.length();
	Gotoxy(X_ADD + distance, ordinal * 3 + Y_ADD);
	cout << result;
	int count = lengh;
	bool isSpaced = false;
	while (true)
	{
		while (_kbhit())
		{
			int key = _getch();
			if (key != 224  && key != 0)
			{
				if ((key >= 65 && key <= 90) || (key >= 97 && key <= 122) || key == SPACE )
				{
					if (count < condition)
					{
						count++;
						if (!isSpaced && key == SPACE)
						{
							cout << (char)key;
							result += (char)key;
							isSpaced = true;
						}
						else
						{
							cout << (char)key;
							result += (char)key;
							isSpaced = false;
						}
					}
				}
				else if (key == ENTER)
					return;
				else if (key == BACKSPACE && count >0)
				{
					cout << "\b" << " " << "\b";
					result.erase(result.length() - 1, 1);
					count--;
				}
			}
			else if (key == 224)
			{
				key = _getch();
				if (key == KEY_UP)
				{
					isMove = true;
					return;
				}
				else
				{
					isMove = false;
					return;
				}
			}
			else if (key == 0)
			{
				key = _getch();
				if (key == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
		}//kbhit
	}//true
}

void CheckMoveAndValidateNameSubject(string &result, bool &isMove, int &ordinal, bool &isSave, int distance, int condition)
{
	int lengh = result.length();
	Gotoxy(X_ADD + distance, ordinal * 3 + Y_ADD);
	cout << result;
	int count = lengh;
	bool isSpaced = false;
	while (true)
	{
		while (_kbhit())
		{
			int key = _getch();
			if (key != 224  && key != 0)
			{
				if ((key >= 65 && key <= 90) || (key >= 97 && key <= 122) || key == SPACE || (key >= 48 && key <= 57) || key == 46 )
				{
					if (count < condition)
					{
						count++;
						if (!isSpaced && key == SPACE)
						{
							cout << (char)key;
							result += (char)key;
							isSpaced = true;
						}
						else
						{
							cout << (char)key;
							result += (char)key;
							isSpaced = false;
						}
					}
				}
				else if (key == ENTER)
					return;
				else if (key == BACKSPACE && count >0)
				{
					cout << "\b" << " " << "\b";
					result.erase(result.length() - 1, 1);
					count--;
				}
			}
			else if (key == 224)
			{
				key = _getch();
				if (key == KEY_UP)
				{
					isMove = true;
					return;
				}
				else
				{
					isMove = false;
					return;
				}
			}
			else if (key == 0)
			{
				key = _getch();
				if (key == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
		}//kbhit
	}//true
}
void CheckMoveAndValidateNumber(int &result, bool &isMove, int &ordinal, bool &isSave,int distance, int condition)
{
	int lengh;
	if (result != 0)
		lengh = (int)log10(result)+1;
	else lengh = 0;
	Gotoxy(X_ADD + distance, ordinal * 3 + Y_ADD);
	if (result != 0)
	cout << result;
	int count = lengh;
	while (true)
	{
		while (_kbhit())
		{
			int key = _getch();
			if (key != 224 && key != SPACE && key!= 0 )
			{
				if (key >= 48 && key <= 57)
				{
					int f = key - 48;
					if (count == 0 && key == 48)
						continue;
					else
						if (result * 10 + (f) <= condition)
						{
							cout << f;
							result = result * 10 + (f);
							count++;
						}
				}
				else if (key == ENTER)
				{
					if (result > condition)
						continue;
					return;
					
				}
				else if (key == BACKSPACE && count >0)
				{
					cout << "\b" << " " << "\b";
					count--;
					result /= 10;
				}
			}
			else if (key == 224)
			{
				key = _getch();
				if (key == KEY_UP)
				{
					isMove = true;
					return;
				}
				else
				{
					isMove = false;
					return;
				}
			}
			else if (key == 0)
			{
				key = _getch();
				if (key == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
		}//kbhit
	}//while tru

}

void StandardName(char *a)
{
	a[0] = toupper(a[0]);
	int length = strlen(a);
	for (int i = 1; i < length; ++i)
	{
		if (a[i -1] == ' ' && a[i] != ' ') a[i] = toupper(a[i]);
		else a[i] = tolower(a[i]);
	}
}
/// input subject

//string idSubject = "";
//	string nameSubject = "";
//	
//	VONGLAP:
//	do
//	{
//		Gotoxy(X_ADD + 13, 0 * 3 + Y_ADD);
//		fflush(stdin);
//		getline(cin, idSubject);
//		for(int i = 0; i< idSubject.length(); i++)
//		{
//			if( idSubject[i] == 32)
//			{
//				Gotoxy(X_NOTIFY, Y_NOTIFY);
//				cout << "Ma mon hoc khong chua khoang trang";
//				
//				goto VONGLAP;
//				
//			}
//		}
//		
//		if(idSubject.length() > 10 || idSubject.empty())
//		{
//			clrscr();
//			goto VONGLAP;
//		}
//	}while(idSubject.length() > 10 || idSubject.empty());	
//	strcpy(data.idSubject, idSubject.c_str());
//	
//	
//	
//	do
//	{
//		Gotoxy(X_ADD + 13, 1 * 3 + Y_ADD);
//		fflush(stdin);
//		getline(cin, nameSubject);
//		if(nameSubject.length() > 30 || nameSubject.empty())
//		{
//			
//		}		
//	}while(nameSubject.length() > 30 || nameSubject.empty());
//	strcpy(data.nameSubject, nameSubject.c_str());	
//	
//	do
//	{
//	
//		Gotoxy(X_ADD + 13, 2 * 3 + Y_ADD);
//		cin >> data.numberTheory;
//	}while(data.numberTheory <= 0 || data.numberTheory > 4);
//	
//	do
//	{
//		Gotoxy(X_ADD + 13, 3 * 3 + Y_ADD);
//		cin >> data.numberPractice;
//	}while(data.numberPractice <= 0 || data.numberPractice > 4);
//	
//	
//	InsertSubjectToTree(t, data);
//	
//	DeleteMenuAdd();
//	Gotoxy(X_NOTIFY, Y_NOTIFY + 1);
//	cout << "                    ";
//	
//	ShowCur(false);
