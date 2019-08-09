#ifndef _CREDITCLASS_H
#define _CREDITCLASS_H

#include "registerstudent.h"
#include "display.h"

//#include "processstemp.h"
// define DS LTC

struct CreditClass{
	unsigned int idClass;
	char idSubject[11]; // ma mon hoc // key
	char nameSubject[31];
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
PTR_CREDITCLASS FindCreditClassWithBinariSearch(PTR_LISTCREDITCLASS l, unsigned int id)
{
	if(l->n < 0) return NULL;
	for(int i = 0; i <= l->n; i++)
	{
		if(l->listCreditClass[i]->idClass == id)
			return l->listCreditClass[i];
		return NULL;
	}
}

PTR_CREDITCLASS BinarySearchCreditClass(PTR_LISTCREDITCLASS l, int n, unsigned int id)
{ // Ph?m vi ban d?u tìm ki?m là t? left=0 ?right =n-1
	int left=0;
	int right=n;
	int j;
	while (left <= right)
	{ 
		j=(left + right) /2; 
		if (l->listCreditClass[j]->idClass == id) return l->listCreditClass[j];
		if (id > l->listCreditClass[j]->idClass)
			left=j+1;
		else right=j-1;
	}
	return NULL;
}

int FindCreditClassWithIdSubject(PTR_LISTCREDITCLASS l, char* idSubject)
{
	if(l->n < 0) return NULL;
	for(int i = 0; i <= l->n; i++)
	{
		if(strcmp(l->listCreditClass[i]->idSubject, idSubject) == 0)
			return i;
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


void OutputCreditClass(PTR_CREDITCLASS cc, TREE_SUBJECT t, int ordinal) // ordinal == thu tu
{
	DeleteOldData(sizeof(keyDisplayCreditClass) / sizeof(string), ordinal);
	Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->idClass;
	Gotoxy(xKeyDisplay[1] + 1, Y_DISPLAY + 3 + ordinal); cout << FindSubject(t, cc->idSubject)->_subject.nameSubject;
	Gotoxy(xKeyDisplay[2] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->idSubject;
	Gotoxy(xKeyDisplay[3] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->shoolYear;
	Gotoxy(xKeyDisplay[4] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->semester;
	Gotoxy(xKeyDisplay[5] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->group;
	Gotoxy(xKeyDisplay[6] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->studentMax;
	Gotoxy(xKeyDisplay[7] + 1, Y_DISPLAY + 3 + ordinal); cout << cc->studentMin;	
}

bool dataCreditClassIsEmty(PTR_CREDITCLASS temp)
{
	if(temp->group == 0 || temp->semester == 0 || temp->shoolYear == 0 || temp->studentMax == 0 || temp->studentMin == 0) return true;
	if(strlen(temp->idSubject) == 0) return true;
	return false;
}


//void OutputListCredit(PTR_LISTCREDITCLASS l)
//{
//	if(l == NULL || l->n == -1) return;
//	for(int i = 0; i <= l->n; i++)
//	{	
//		OutputCreditClass(l->listCreditClass[i], i);
//	}
//}

void OutputListCreditClassPerPage(PTR_LISTCREDITCLASS l, TREE_SUBJECT t, int indexBegin)
{
	if(l == NULL || l->n == -1) return;
	for(int i = 0; i + indexBegin <= l->n && i < QUANTITY_PER_PAGE; i++)
	{
		
		OutputCreditClass(l->listCreditClass[i + indexBegin], t, i * 2);
	}
	Gotoxy(X_PAGE, Y_PAGE);
	cout << "Trang " << pageNowCreditClass << "/" << totalPageCreditClass;
}

void DeleteCreditClass(PTR_LISTCREDITCLASS &l, unsigned int id)
{
	int index = FindIndexClass(l, id);
	delete l->listCreditClass[index];
	if(index == -1)return;
	if(l->listCreditClass[index]->listRegisterStudent.pHead != NULL) return;
	
	for(int i = index; i < l->n; i++)
	{
		l->listCreditClass[i] = l->listCreditClass[i + 1];
		
	}
	
	l->n--;
	
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
PTR_CREDITCLASS FindCrediClassWithCondition(PTR_LISTCREDITCLASS l, char* idSubject, int shoolYear, int semester, int group)
{

	for(int i = 0; i <= l->n; i++)
	{
		if(strcmp(l->listCreditClass[i]->idSubject,idSubject) == 0 &&
			l->listCreditClass[i]->shoolYear == shoolYear && l->listCreditClass[i]->semester == semester && l->listCreditClass[i]->group == group)
		{
			return l->listCreditClass[i];
		}
	}
	return NULL;
}



void InputCreditClass(PTR_LISTCREDITCLASS &l, PTR_CREDITCLASS &cc, TREE_SUBJECT t, bool isEdited = false) // nhap  Lop TC
{
	ShowCur(true);
	
	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 0;
	bool isMoveUp = false;
	bool isSave = false;
	bool idIsExist = false;
	
	
	string idSubject; // ma mon hoc
	int shoolYear = 0; // nien khoa
	int semester = 0; // hoc ki 
	int group = 0; // nhom
	int studentMax = 0;
	int studentMin = 0;
	

	
	if(isEdited)
	{
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
			
			PTR_CREDITCLASS temp = new CREDITCLASS;
			strcpy(temp->idSubject, idSubject.c_str());
			temp->idClass = 0;
			temp->semester = semester;
			temp->shoolYear = shoolYear;
			temp->studentMax = studentMax;
			temp->studentMin = studentMin;
			temp->group = group;
			
			if (dataCreditClassIsEmty(temp))
			{
				Gotoxy(X_NOTIFY, Y_NOTIFY); cout << "Cac truong du lieu khong duoc de trong";
			}
			else if(FindCrediClassWithCondition(l, (char*)idSubject.c_str(), shoolYear, semester, group) != NULL)
			{
				Gotoxy(X_NOTIFY, Y_NOTIFY); cout << "Lop tin chi da ton tai";
			}else if(studentMax < studentMin)
			{
				Gotoxy(X_NOTIFY, Y_NOTIFY); cout << "So luong sinh vien khong hop le";
			}
			else
			{
				strcpy(cc->idSubject, idSubject.c_str());
				NODE_SUBJECT* p = FindSubject(t, cc->idSubject);
				
				strcpy(cc->nameSubject, p->_subject.nameSubject);
				//cc->idClass = ++l->n;
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
					cc->idClass = ++l->n;
					InitListRegisterStudent(cc->listRegisterStudent);
					l->listCreditClass[l->n] = new CREDITCLASS;
					l->listCreditClass[l->n] = cc;
									
				}
				DeleteMenuAdd();
				totalPageCreditClass = l->n / QUANTITY_PER_PAGE + 1;
				return;
				
				
			}
			isSave = false;
		}
		else
			isSave = false;
	}
	ShowCur(false);
	
	
}


void SetDefaultChosenCreditClass(PTR_LISTCREDITCLASS l, TREE_SUBJECT t, int ordinal)
{
	SetBGColor(GREEN);
	OutputCreditClass(l->listCreditClass[ordinal], t, (ordinal % QUANTITY_PER_PAGE) * 2);
	SetBGColor(PURPLE);
}

void EffectiveMenuCreditClass(int ordinal, PTR_LISTCREDITCLASS l, TREE_SUBJECT t)
{
	int current = ordinal;
	SetDefaultChosenCreditClass(l, t, current);
	OutputCreditClass(l->listCreditClass[currposPrecCreditClass], t, (currposPrecCreditClass % QUANTITY_PER_PAGE) * 2);
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

int ChooseCreditClass(PTR_LISTCREDITCLASS l, TREE_SUBJECT t)
{
	ShowCur(false);
	int key;
	int keyboard_read = 0;
	pageNowCreditClass = 1;
	currposCreditClass = 0;
	currposPrecCreditClass = 0;
	
	Display(keyDisplayCreditClass, sizeof(keyDisplayCreditClass) / sizeof(string));
	
	
	
	OutputListCreditClassPerPage(l, t, 0);
	SetDefaultChosenCreditClass(l, t, currposCreditClass);
	
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
						EffectiveMenuCreditClass(currposCreditClass, l, t);
					}
					break;
				case KEY_DOWN:
					if(currposCreditClass % QUANTITY_PER_PAGE < QUANTITY_PER_PAGE - 1 && currposCreditClass < l->n)
					{
						currposCreditClass = currposCreditClass + 1;
						EffectiveMenuCreditClass(currposCreditClass, l, t);
					}
					break;
				case PAGE_UP:
					if(pageNowCreditClass > 1)
					{
						pageNowCreditClass--;
						ChangePageCreditClass(l);
						OutputListCreditClassPerPage(l, t, (pageNowCreditClass -1) * QUANTITY_PER_PAGE);
						SetDefaultChosenCreditClass(l, t, currposCreditClass);
					}
					break;
				case PAGE_DOWN:
					if(pageNowCreditClass < totalPageCreditClass)
					{
						pageNowCreditClass++;
						ChangePageCreditClass(l);
						OutputListCreditClassPerPage(l, t, (pageNowCreditClass -1) * QUANTITY_PER_PAGE);
						SetDefaultChosenCreditClass(l, t, currposCreditClass);		
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

void ChangePageManageCreaditClass(PTR_LISTCREDITCLASS l, TREE_SUBJECT t)
{
	clrscr();
	Gotoxy(X_TITLE, Y_TITLE); cout << "QUAN LY DANH SACH LOP TIN CHI";
	OutputListCreditClassPerPage(l, t, (pageNowCreditClass - 1) * QUANTITY_PER_PAGE);
	Display(keyDisplayCreditClass, sizeof(keyDisplayCreditClass) / sizeof(string));
}

void MenuManageCreditClass(PTR_LISTCREDITCLASS &l, TREE_SUBJECT &t)
{
	backMenu:
		clrscr();
		pageNowCreditClass = 1;
		totalPageCreditClass = 0;
		OutputListCreditClassPerPage(l, t, 0);
		
		Display(keyDisplayCreditClass, sizeof(keyDisplayCreditClass) / sizeof(string));
		int key;
		
		Gotoxy(X_TITLE, Y_TITLE); cout << "QUAN LY DANH SACH LOP TIN CHI";
		Gotoxy(X_PAGE, Y_PAGE);
		totalPageCreditClass = l->n / QUANTITY_PER_PAGE + 1;
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
						
						totalPageCreditClass = l->n / QUANTITY_PER_PAGE + 1;
						pageNowCreditClass = 1;
						ChangePageManageCreaditClass(l, t);
						Gotoxy(X_NOTIFY + 10, Y_NOTIFY);
						cout << "THEM THANH CONG!";
					}
					else if(key == KEY_F3)
					{
						
						int k = ChooseCreditClass(l, t);
						if(k == -1) goto backMenu;
						
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
								if((l->n + 1) % QUANTITY_PER_PAGE == 0) pageNowCreditClass--;
								totalPageCreditClass = l->n / QUANTITY_PER_PAGE + 1;
								ChangePageManageCreaditClass(l, t);
								Gotoxy(X_NOTIFY, Y_NOTIFY);
								cout << "Xoa thanh cong";
							}
						}else
							goto backMenu;
					}
					else if(key == KEY_F4)
					{
						int k = ChooseCreditClass(l, t);
						if(k == -1) goto backMenu;
						Gotoxy(X_ADD, 40);
						DisplayEdit(keyDisplayCreaditClassEdit, sizeof(keyDisplayCreaditClassEdit) / sizeof(string), 35);
						InputCreditClass(l, l->listCreditClass[k], t, true);
						
						ChangePageManageCreaditClass(l, t);
						Gotoxy(X_NOTIFY + 10, Y_NOTIFY);
						cout << "SUA THANH CONG";
					}
					else if(key == PAGE_DOWN && pageNowCreditClass < totalPageCreditClass)
					{
						pageNowCreditClass++;
						ChangePageManageCreaditClass(l, t);
					}
					else if(key == PAGE_UP && pageNowCreditClass > 1)
					{
						pageNowCreditClass--;
						ChangePageManageCreaditClass(l, t);
					}
				}
				else if(key == ESC)
					return;
			}
		}
}

#endif

