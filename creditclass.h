#ifndef _CREDITCLASS_H
#define _CREDITCLASS_H

#include "registerstudent.h"
#include "display.h"
// define DS LTC

struct CreditClass{
	unsigned int idClass;
	char idSubject[10]; // ma mon hoc // key
	int shoolYear; // nien khoa
	int semester; // hoc ki
	int group; // nhom
	int studentMax;
	int studentMin;

	LIST_REGISTERSTUDENT listRegisterStudent;	
};
typedef struct CreditClass CREDITCLASS;
typedef CREDITCLASS* PTR_CREDITCLASS;	 


struct ListCreaditClass{
	
	int n = -1;
	PTR_CREDITCLASS *listCreditClass = new PTR_CREDITCLASS[5000]; 
};
typedef struct ListCreaditClass LIST_CREDITCLASS;
typedef LIST_CREDITCLASS* PTR_LISTCREDITCLASS;
 //.................define List class.....................
 

 //-----------------define temp
 // Tim kiem lop dua tren id -- find class with id
PTR_CREDITCLASS FindCreditClass(PTR_LISTCREDITCLASS l, unsigned int id)
{
	if(l->n < 0) return NULL;
	for(int i = 0; i <= l->n; i++)
	{
		if(l->listCreditClass[i]->idClass == id)
			return l->listCreditClass[i];
		return NULL;
	}
}

// find index of class -- tim kiem index cua class
int FindIndexClass(PTR_LISTCREDITCLASS l, unsigned int idClass)
{
	if(l->n < 0) return -1;
	for(int i = 0; i <= l->n; i++)
	{
		if(l->listCreditClass[i]->idClass == idClass)
			return i;		
	}
	return -1;
}

//check when input

// Hoa vi hai lop
void SwapClass(PTR_CREDITCLASS &a, PTR_CREDITCLASS &b)
{
	PTR_CREDITCLASS temp = a;
	a = b;
	b = temp;
}


void OutputCreditClass(PTR_CREDITCLASS cc, int ordinal) // ordinal == thu tu
{
	DeleteOldData(sizeof(keyDisplayCreditClass) / sizeof(string), ordinal);
	Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->idClass;
	Gotoxy(xKeyDisplay[1] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->idSubject;
	Gotoxy(xKeyDisplay[2] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->shoolYear;
	Gotoxy(xKeyDisplay[3] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->semester;
	Gotoxy(xKeyDisplay[4] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->group;
	Gotoxy(xKeyDisplay[5] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->studentMax;
	Gotoxy(xKeyDisplay[6] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->studentMin;
	
}




void OutputListCredit(PTR_LISTCREDITCLASS l)
{
	if(l == NULL) return;
	for(int i = 0; i <= l->n; i++)
	{
		OutputCreditClass(l->listCreditClass[i], i);
	}
}

void OutputListCreditClassPerPage(PTR_LISTCREDITCLASS l, int indexBegin)
{
	if(l == NULL) return;
	for(int i = 0; i + indexBegin <= l->n && i < QUANTITY_PER_PAGE; i++)
	{
		OutputCreditClass(l->listCreditClass[i + indexBegin], i * 2);
	}
	Gotoxy(X_PAGE, Y_PAGE);
	cout << "Trang " << pageNowCreditClass << "/" << totalPageCreditClass;
}

bool DeleteCreditClassIsSuccess(PTR_LISTCREDITCLASS &l, unsigned int id)
{
	int index = FindIndexClass(l, id);
	
	if(index == -1)return false;
	if(l->listCreditClass[index]->listRegisterStudent.pHead != NULL) return false;
	for(int i = index; i < l->n; i++)
	{
		l->listCreditClass[i] = l->listCreditClass[i + 1];
		
	}
	l->n--;
	return true;
}

void InputCreditClass(PTR_LISTCREDITCLASS &l, PTR_CREDITCLASS cc, TREE_SUBJECT t, bool isEdited = false) // nhap  Lop TC
{
	ShowCur(true);
	
	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 0;
	bool isMoveUp = false;
	bool isSave = false;
	bool idIsExist = false;
	
	unsigned int id = ++idCreditClass;
	string idSubject; // ma mon hoc
	int shoolYear = 0; // nien khoa
	int semester = 0; // hoc ki 
	int group = 0; // nhom
	int studentMax = 0;
	int studentMin = 0;
	

	
	if(isEdited)
	{
		id = cc->idClass;
		idSubject = cc->idSubject;
		shoolYear = cc->shoolYear;
		semester = cc->semester;
		studentMin = cc->studentMin;
		studentMax = cc->studentMax;
		group = cc->group;
		
		// binding data;
		
		Gotoxy(X_ADD + 20 + 7, 0 * 3 + Y_ADD);
		cout << idSubject;
		
		Gotoxy(X_ADD + 17 + 7, 1 * 3 + Y_ADD);
		cout << shoolYear;
		
		Gotoxy(X_ADD + 21 + 7, 2 * 3 + Y_ADD);
		cout << semester;
		
		Gotoxy(X_ADD + 19 + 7, 3 * 3 + Y_ADD);
		cout << group;
		
		Gotoxy(X_ADD + 20 + 7, 4 * 3 + Y_ADD);
		cout << studentMax;
		
		Gotoxy(X_ADD + 20 + 7, 5 * 3 + Y_ADD);
		cout << studentMin;		
	}
	
	
	while(true)
	{
		switch(ordinal)
		{
											
			case 0:
				CheckMoveAndValidateID(idSubject, isMoveUp, ordinal, isSave, 27, 10);
				if(FindSubject(t, (char*)idSubject.c_str()) == NULL)
				{
					idIsExist = false;
					break;
				}
				else
					idIsExist = true;
				break;
				
			case 1:
				CheckMoveAndValidateNumber(shoolYear,isMoveUp, ordinal, isSave,24, 2019);
				break;
			case 2:
				CheckMoveAndValidateNumber(semester,isMoveUp, ordinal, isSave,28, 3);
				break;
			case 3:
				CheckMoveAndValidateNumber(group,isMoveUp, ordinal, isSave,26, 3);
				break;
			case 4:
				CheckMoveAndValidateNumber(studentMax,isMoveUp, ordinal, isSave,27, MAX_STUDENT);
				break;
			case 5:
				CheckMoveAndValidateNumber(studentMin,isMoveUp, ordinal, isSave,27, MIN_STUDENT);
				break;				
		}
		
		if (isMoveUp)
		{
			if (ordinal == 0)
				isMoveUp = false;
			ordinal--;

		}
		else
		{
			if (ordinal == 5)
				isMoveUp = true;
			ordinal++;
		}
		if (isSave)
		{
			Gotoxy(X_NOTIFY + 10, Y_NOTIFY);
			cout << setw(50) << setfill(' ') << " ";
			if(!idIsExist)
			{
				Gotoxy(X_NOTIFY + 10, Y_NOTIFY);
				cout << "Ma MH KHONG TON TAI";
			}else
			{
				PTR_CREDITCLASS temp = new CREDITCLASS;
				strcpy(temp->idSubject, idSubject.c_str());
				temp->idClass = id;
				temp->semester = semester;
				temp->shoolYear = shoolYear;
				temp->studentMax = studentMax;
				temp->studentMin = studentMin;
				temp->group = group;
				
	
				strcpy(cc->idSubject, idSubject.c_str());
				cc->idClass = id;
				cc->group = group;
				cc->shoolYear = shoolYear;
				cc->studentMax = studentMax;
				cc->studentMin = studentMin;
				cc->semester = semester;
				
				if(isEdited)
				{
					int index = FindIndexClass(l, cc->idClass);
					l->listCreditClass[index] = cc;
				}else
				{
					InitListRegisterStudent(cc->listRegisterStudent);
					l->listCreditClass[++l->n] = new CREDITCLASS;
					l->listCreditClass[l->n] = cc;
									
				}
				DeleteMenuAdd();
				totalPageCreditClass = l->n / QUANTITY_PER_PAGE + 1;
				return;
				
				
			}
			isSave = false;
		}
		isSave = false;
	}
	ShowCur(false);
	
	
}


void SetDefaultChosenCreditClass(PTR_LISTCREDITCLASS l, int ordinal)
{
	SetBGColor(GREEN);
	OutputCreditClass(l->listCreditClass[ordinal], (ordinal % QUANTITY_PER_PAGE) * 2);
	SetBGColor(PURPLE);
}

void EffectiveMenuCreditClass(int ordinal, PTR_LISTCREDITCLASS l)
{
	int current = ordinal;
	SetDefaultChosenCreditClass(l, current);
	OutputCreditClass(l->listCreditClass[currposPrecCreditClass], (currposPrecCreditClass % QUANTITY_PER_PAGE) * 2);
	currposPrecCreditClass = current;
}

void ChangePageCreditClass( PTR_LISTCREDITCLASS l)
{
	clrscr();
	Display(keyDisplayCreditClass, sizeof(keyDisplayCreditClass) / sizeof(string));
	DeleteNote(sizeof(keyDisplayCreditClass) / sizeof(string));
	currposCreditClass = (pageNowCreditClass - 1) * QUANTITY_PER_PAGE;
	currposPrecCreditClass = (pageNowCreditClass - 1) * QUANTITY_PER_PAGE;
	
	Gotoxy(X_PAGE, Y_PAGE);
	cout << "Trang " << pageNowCreditClass << "/" << totalPageCreditClass;
}

int ChooseCreditClass(PTR_LISTCREDITCLASS l)
{
	ShowCur(false);
	int key;
	int keyboard_read = 0;
	pageNowCreditClass = 1;
	currposCreditClass = 0;
	currposPrecCreditClass = 0;
	clrscr();
	Display(keyDisplayCreditClass, sizeof(keyDisplayCreditClass) / sizeof(string));
	OutputListCreditClassPerPage(l, 0);
	SetDefaultChosenCreditClass(l, currposCreditClass);
	
	while(true)
	{
		while(_kbhit())
		{
			keyboard_read = _getch();
			if(keyboard_read == 0)
				keyboard_read = _getch();
			switch(keyboard_read)
			{
				case KEY_UP:
					if(currposCreditClass % QUANTITY_PER_PAGE > 0)
					{
						currposCreditClass = currposCreditClass - 1;
						EffectiveMenuCreditClass(currposCreditClass, l);
					}
					break;
				case KEY_DOWN:
					if(currposCreditClass % QUANTITY_PER_PAGE < QUANTITY_PER_PAGE - 1 && currposCreditClass < l->n)
					{
						currposCreditClass = currposCreditClass + 1;
						EffectiveMenuCreditClass(currposCreditClass, l);
					}
					break;
				case PAGE_UP:
					if(pageNowCreditClass > 1)
					{
						pageNowCreditClass--;
						ChangePageCreditClass(l);
						OutputListCreditClassPerPage(l, (pageNowCreditClass -1) * QUANTITY_PER_PAGE);
						SetDefaultChosenCreditClass(l, currposCreditClass);
					}
					break;
				case PAGE_DOWN:
					if(pageNowCreditClass < totalPageCreditClass)
					{
						pageNowCreditClass++;
						ChangePageCreditClass(l);
						OutputListCreditClassPerPage(l, (pageNowCreditClass -1) * QUANTITY_PER_PAGE);
						SetDefaultChosenCreditClass(l, currposCreditClass);		
					}
					break;	
				case ESC:
					ShowCur(false);
					return -1;
					break;
				case ENTER:
					ShowCur(false);
					return currposCreditClass;
					break;
			}
		}
	}
}

void ChangePageManageCreaditClass(PTR_LISTCREDITCLASS l)
{
	clrscr();
	Gotoxy(X_TITLE, Y_TITLE); cout << "QUAN LY DANH SACH LOP TIN CHI";
	OutputListCreditClassPerPage(l, (pageNowCreditClass - 1) * QUANTITY_PER_PAGE);
	Display(keyDisplayCreditClass, sizeof(keyDisplayCreditClass) / sizeof(string));
}

void MenuManageCreditClass(PTR_LISTCREDITCLASS &l, TREE_SUBJECT t)
{
	backMenu:
		clrscr();
		pageNowCreditClass = 1;
		
		if(l->n != -1)
		{
			OutputListCreditClassPerPage(l, 0);
		}
		
		Display(keyDisplayCreditClass, sizeof(keyDisplayCreditClass) / sizeof(string));
		int key;
		
		Gotoxy(X_TITLE, Y_TITLE); cout << "QUAN LY DANH SACH LOP TIN CHI";
		Gotoxy(X_PAGE, Y_PAGE);
		cout << "Trang " << pageNowCreditClass << "/" << totalPageCreditClass;
		while(true)
		{
			while(_kbhit())
			{
				key = _getch();
				if(key == 0 || key == 224)
				{
					key = _getch();
					if(key == KEY_F2)
					{
						PTR_CREDITCLASS cc = new CREDITCLASS;
						DisplayEdit(keyDisplayCreaditClassEdit, sizeof(keyDisplayCreaditClassEdit) / sizeof(string), 35);
						InputCreditClass(l, cc, t);
						clrscr();
						
						Display(keyDisplayCreditClass, sizeof(keyDisplayCreditClass) / sizeof(string));		
						Gotoxy(X_TITLE, Y_TITLE); cout << "QUAN LY DANH SACH LOP TIN CHI";
					
						totalPageCreditClass = l->n / QUANTITY_PER_PAGE + 1;
						pageNowCreditClass = 1;
						OutputListCreditClassPerPage(l, (pageNowCreditClass - 1) * QUANTITY_PER_PAGE);
						Gotoxy(X_PAGE, Y_PAGE);
						cout << "Trang " << pageNowCreditClass << "/" << totalPageCreditClass;
						Gotoxy(X_NOTIFY + 10, Y_NOTIFY);
						cout << "THEM THANH CONG!";
					}
					else if(key == KEY_F3)
					{
						
						int k = ChooseCreditClass(l);
						if(k == -1) goto backMenu;
						Gotoxy(X_NOTIFY, Y_NOTIFY);
						cout << "BAN CO CHAC CHAN XOA? ENTER DE DONG Y";
						key = _getch();
						
						Gotoxy(X_NOTIFY, Y_NOTIFY);
						cout << setw(50) << setfill(' ') << " ";
						
						if(key == ENTER)
						{
							bool isDeleted = DeleteCreditClassIsSuccess(l, l->listCreditClass[k]->idClass);
							if(!isDeleted)
							{
								Gotoxy(X_NOTIFY + 10, Y_NOTIFY);
								cout << "Xoa that bai."<<endl;
								Gotoxy(X_NOTIFY + 10, Y_NOTIFY+1);
								cout << "Nhap phim bat ky de tiep tuc ";
								_getch();
								goto backMenu;		
							}else
							{
								clrscr();
								Gotoxy(X_TITLE, Y_TITLE); cout << "QUAN LY DANH SACH LOP TIN CHI";
								Gotoxy(X_PAGE, Y_PAGE);
								cout << "Trang " << pageNowCreditClass << "/" << totalPageCreditClass;
								Display(keyDisplayCreditClass, sizeof(keyDisplayCreditClass) / sizeof(string));
								if((l->n + 1) % QUANTITY_PER_PAGE == 0) pageNowCreditClass--;
								totalPageCreditClass = l->n / QUANTITY_PER_PAGE + 1;
								OutputListCreditClassPerPage(l, (pageNowCreditClass - 1) * QUANTITY_PER_PAGE);
								
								Gotoxy(X_PAGE, Y_PAGE);
								cout << "Trang " << pageNowCreditClass << "/" << totalPageCreditClass;	
								
								Gotoxy(X_NOTIFY, Y_NOTIFY);
								cout << "Xoa thanh cong";
							}
						}else
							goto backMenu;
					}
					else if(key == KEY_F4)
					{
						int k = ChooseCreditClass(l);
						if(k == -1) goto backMenu;
						Gotoxy(X_ADD, 40);
						DisplayEdit(keyDisplayCreaditClassEdit, sizeof(keyDisplayCreaditClassEdit) / sizeof(string), 35);
						InputCreditClass(l, l->listCreditClass[k], t, true);
						
						clrscr();
						Gotoxy(X_TITLE, Y_TITLE); cout << "QUAN LY DANH SACH LOP TIN CHI";						
						Display(keyDisplayCreditClass, sizeof(keyDisplayCreditClass) / sizeof(string));
						OutputListCreditClassPerPage(l, (pageNowCreditClass - 1) * QUANTITY_PER_PAGE);
						
						Gotoxy(X_PAGE, Y_PAGE);
						cout << "Trang " << pageNowCreditClass << "/" << totalPageCreditClass;
						Gotoxy(X_NOTIFY + 10, Y_NOTIFY);
						cout << "SUA THANH CONG";
					}
					else if(key == PAGE_DOWN && pageNowCreditClass < totalPageCreditClass)
					{
						pageNowCreditClass++;
						ChangePageManageCreaditClass(l);
					}
					else if(key == PAGE_UP && pageNowCreditClass > 1)
					{
						pageNowCreditClass--;
						ChangePageManageCreaditClass(l);
					}
				}
				else if(key == ESC)
					return;
			}
		}
}

#endif

