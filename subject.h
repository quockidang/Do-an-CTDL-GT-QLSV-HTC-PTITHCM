#ifndef _SUBJECT_H
#define _SUBJECT_H


#include "display.h"

struct Subject{
	int numberTheory; //so tin chi ly thuyet
	int numberPractice; //so tin chi thuc hanh
	char idSubject[11]; // ma mon hoc, key
	char nameSubject[31]; //ten mon hoc
};
typedef struct Subject SUBJECT;

struct NodeSubject{
	SUBJECT _subject;
	struct NodeSubject *pLeft, *pRight;
};
typedef struct NodeSubject NODE_SUBJECT;

typedef NODE_SUBJECT* TREE_SUBJECT;
TREE_SUBJECT binaryTree = NULL;
TREE_SUBJECT rp;

int indexOutSubject = -1;
// ........................define tree subject...................

SUBJECT arrSubject[200];
 

// khoi tao cay nhi phan
void InitTreeSubject(TREE_SUBJECT &root)
{
	nSubject = -1;
	root = NULL;
}

//check NULL
bool IsEmpty(TREE_SUBJECT t)
{
	return(t == NULL ? true : false); //? : = if true return true else false
}

// check ma mon hoc da ton tai
bool CheckIdExists(TREE_SUBJECT t, char* idSubject )
{
	if(t != NULL)
	{
		if(strcmp(idSubject,t->_subject.idSubject)==0)
			return true;
		else if(strcmp(idSubject,t->_subject.idSubject)<0)
			CheckIdExists(t->pLeft, idSubject);
		else if(strcmp(idSubject,t->_subject.idSubject)>0)
			CheckIdExists(t->pRight, idSubject);
	}
	return false;
}

NODE_SUBJECT* FindSubject(TREE_SUBJECT t, char* idSubject) //return p = null if not found
{
	if(t != NULL)
	{ 
		NODE_SUBJECT* p = t;
		while(p != NULL)
		{
			if(strcmp(idSubject, p->_subject.idSubject) == 0)
				return p;
			else if(strcmp(idSubject, p->_subject.idSubject) > 0)
				p = p->pRight;
			else
				p = p->pLeft;
		}
	}
	return NULL;	
}



// them data vao tree;
void InsertSubjectToTree(TREE_SUBJECT &t, SUBJECT data)
{
	// tree emty, data is root of tree
	if(t == NULL)
	{
		NODE_SUBJECT* p = new NODE_SUBJECT;
		p->_subject = data;
		p->pLeft = p->pRight = NULL;
		t = p;
		
		arrSubject[++nSubject] = data;				
	}
	else //tree not empty
	{
		if(strcmp(data.idSubject,t->_subject.idSubject) < 0 )
			InsertSubjectToTree(t->pLeft, data);
		else if(strcmp(data.idSubject,t->_subject.idSubject) > 0 )
			InsertSubjectToTree(t->pRight, data);	
	}

}

void QuickSort(int left, int right, SUBJECT arr[]) {	
	SUBJECT key = arr[(left + right) / 2];
	SUBJECT temp;
	int i = left;
	int j = right;
	do {
		while(strcmpi(arr[i].nameSubject, key.nameSubject) < 0 ) i++;
		//while(strcmp(arr[i].nameSubject, key.nameSubject) == 0) continue;
		while(strcmpi(arr[j].nameSubject, key.nameSubject) > 0) j--;
		if (i <= j) {			
			if(i < j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			i++; j--;
		}
	} while (i <= j);
	if (left < j) QuickSort(left, j, arr);
	if (right > i) QuickSort(i, right, arr);
}

void DeleteSubjectCase_3 ( TREE_SUBJECT &r )
{
	if (r->pLeft != NULL)
		DeleteSubjectCase_3 (r->pLeft);
	//den day r la nut cuc trai cua cay con ben phai co nut goc la rp}
	else
	{
		rp->_subject = r->_subject; //Chep noi dung cua r sang rp ; // de lat nua free(rp)
		rp = r;
		r = rp->pRight;
	}
}

void FindReplace(NODE_SUBJECT* &p, NODE_SUBJECT* &q)
{
	if (q->pRight != NULL)
	{
		FindReplace(p, q->pRight);
	}
	else
	{
		p->_subject = q->_subject;
		p = q;
		q = q->pLeft;
	}
}

// xoa Mon hoc trong tree
bool IsDeleteSubject(TREE_SUBJECT &t, SUBJECT x)
{
	if(t == NULL)
	{
		return false;
	}
	else
	{
		if(strcmp(x.idSubject,t->_subject.idSubject) > 0)
			IsDeleteSubject(t->pRight, x);
		else if(strcmp(x.idSubject,t->_subject.idSubject) < 0)
			IsDeleteSubject(t->pLeft, x);
		else // data.id == t->data.id
		{
			NODE_SUBJECT* temp = t;
			if(t->pLeft == NULL)
				t = t->pRight;
			else if(t->pRight == NULL)
				t = t->pLeft;
			else // node co 2 child
			{
				DeleteSubjectCase_3(t->pRight);
			}
			delete temp;			
			return true;
		}
	}
}





void OutputSubject(SUBJECT s, int locate) // vi tri == locate
{
	DeleteOldData(sizeof(keyDisplaySubject) / sizeof(string), locate);	
	Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 3 + locate); cout << s.idSubject;
	Gotoxy(xKeyDisplay[1] + 1, Y_DISPLAY + 3 + locate); cout << s.nameSubject;
	Gotoxy(xKeyDisplay[2] + 1, Y_DISPLAY + 3 + locate); cout << s.numberTheory;
	Gotoxy(xKeyDisplay[3] + 1, Y_DISPLAY + 3 + locate); cout << s.numberPractice;
}



void OutputListSubject(TREE_SUBJECT t)
{
	if (t != NULL)
	{
		OutputListSubject(t->pLeft);
		OutputSubject(t->_subject, ++indexOutSubject);
		OutputListSubject(t->pRight);
	}
}

void OutputListSubjectPerPage(TREE_SUBJECT t , int indexBegin)
{
	for(int i = 0; i + indexBegin <= nSubject && i < QUANTITY_PER_PAGE; i++)
	{
		
		
		NODE_SUBJECT* s = FindSubject(t, arrSubject[i + indexBegin].idSubject);
		//if(s == NULL) cout << "Fail";

		OutputSubject(s->_subject, i * 2);
	}
	Gotoxy(X_PAGE, Y_PAGE);
	cout << "Trang "<< pageNowSubject << "/" << totalPageSubject;
}


void SetDefaultChosenSubject(SUBJECT p, int ordinal)
{
	SetBGColor(GREEN);
	OutputSubject(p, ordinal % QUANTITY_PER_PAGE);
	SetBGColor(PURPLE);
}

void EffectiveMenuSubject(int index, SUBJECT newSubject, SUBJECT oldSubject)
{
	int current = index;

	SetBGColor(GREEN);
	OutputSubject(newSubject, (current % QUANTITY_PER_PAGE) * 2);
	SetBGColor(PURPLE);
	OutputSubject(oldSubject, (currposPrecSubject % QUANTITY_PER_PAGE)  * 2);
	currposPrecSubject = current;
}

void ChangePageSubject(TREE_SUBJECT t)
{
	currposSubject = (pageNowSubject - 1) * QUANTITY_PER_PAGE;
	currposPrecSubject = (pageNowSubject - 1) * QUANTITY_PER_PAGE;
	
	clrscr();
	Display(keyDisplaySubject, sizeof(keyDisplaySubject) / sizeof(string));
	DeleteNote(sizeof(keyDisplaySubject) / sizeof(string));
}


NODE_SUBJECT* ChooseSubject(TREE_SUBJECT &t)
{
	if (t == NULL) return NULL;
	ShowCur(false);
	
	int key;
	int keyboard_read = 0;
	int PASS = 1;
	
	QuickSort(0, nSubject, arrSubject);
		
	Display(keyDisplaySubject, sizeof(keyDisplaySubject) / sizeof(string));
	
	pageNowSubject = 1;
	currposSubject = (pageNowSubject - 1) * QUANTITY_PER_PAGE;
	currposPrecSubject = (pageNowSubject - 1) * QUANTITY_PER_PAGE;
	
	NODE_SUBJECT* newSubject = FindSubject(t, arrSubject[0].idSubject);
	
	//OutputListSubject(t);
	OutputListSubjectPerPage(t, 0);
	SetDefaultChosenSubject(newSubject->_subject, currposSubject);
	NODE_SUBJECT* oldSubject = NULL;
	
	Gotoxy(X_PAGE, Y_PAGE);
	cout << "Trang " << pageNowSubject << "/" << totalPageSubject;
	
	while (PASS)
	{
		keyboard_read = _getch();
		if (keyboard_read == 0)
			keyboard_read = _getch();

		switch (keyboard_read)
		{

		
			case KEY_UP:
				if(currposSubject % QUANTITY_PER_PAGE > 0)
				{
					currposSubject = currposSubject - 1;
					oldSubject = newSubject;
					
					newSubject = FindSubject(t, arrSubject[currposSubject].idSubject);
					EffectiveMenuSubject(currposSubject, newSubject->_subject, oldSubject->_subject);
				}							
				break;
				
			case KEY_DOWN:
				if (currposSubject % QUANTITY_PER_PAGE < QUANTITY_PER_PAGE - 1 && currposSubject < nSubject)
				{
					currposSubject = currposSubject + 1;
					oldSubject = newSubject;
					
					newSubject = FindSubject(t, arrSubject[currposSubject].idSubject);
					EffectiveMenuSubject(currposSubject, newSubject->_subject, oldSubject->_subject);
				}
				break;
			case PAGE_DOWN:
				if(pageNowSubject < totalPageSubject)
				{
					pageNowSubject++;
					ChangePageSubject(t);
					
					newSubject = FindSubject(t, arrSubject[currposSubject].idSubject);
					oldSubject = newSubject;
					
					OutputListSubjectPerPage(t, (pageNowSubject - 1) * QUANTITY_PER_PAGE);
					SetDefaultChosenSubject(newSubject->_subject, currposSubject);
				}
				break;
			case PAGE_UP:
				if(pageNowSubject > 1)
				{
					pageNowSubject--;
					ChangePageSubject(t);
					
					newSubject = FindSubject(t, arrSubject[currposSubject].idSubject);
					oldSubject = newSubject;
					
					OutputListSubjectPerPage(t, (pageNowSubject - 1) * QUANTITY_PER_PAGE);
					SetDefaultChosenSubject(newSubject->_subject, currposSubject);
				}
				break;
			case ENTER:  //enter
				PASS = 0;
				ShowCur(true);
				return newSubject;
				break;
			case ESC:
				ShowCur(true);
				return NULL;
				break;
		}
	}
}

void inputSubject(TREE_SUBJECT &t, SUBJECT &data, bool isEdited = false)
{		
	ShowCur(true);
	
	bool isMoveUp = false;
	bool isSave = false;
	int ordinal = 0;
	
	
	string id, name;
	int numberPractice = 0, numberTheory = 0;
	
	bool idIsExits = false;
	
	if(isEdited)
	{
		id = data.idSubject;
		name = data.nameSubject;
		numberPractice = data.numberPractice;
		numberTheory = data.numberTheory;
		
		Gotoxy(X_ADD + 20 + 7, 0 * 3 + Y_ADD);
		cout << id;
		Gotoxy(X_ADD + 21 + 7, 1 * 3 + Y_ADD);
		cout << name;
		Gotoxy(X_ADD + 22 + 7, 2 * 3 + Y_ADD);
		cout << numberPractice;
		Gotoxy(X_ADD + 22 + 7, 3 * 3 + Y_ADD);
		cout << numberTheory;		
	}
	
	while(true)
	{
		switch(ordinal)
		{
			case 0:
				if(isEdited) break;
				CheckMoveAndValidateID(id, isMoveUp, ordinal, isSave, 20 + 7, 10);
				
				strcpy(data.idSubject, id.c_str());
				
				if(FindSubject(t, data.idSubject) == NULL)
				{
					idIsExits = false;
					break;
				}
				idIsExits = true;
				break;
			case 1:
				CheckMoveAndValidateNameSubject(name, isMoveUp, ordinal, isSave, 21 + 7, 25);
				break;
			case 2:
				CheckMoveAndValidateNumber(numberTheory,isMoveUp, ordinal, isSave,22 + 7, 4);
				break;
			case 3:
				CheckMoveAndValidateNumber(numberPractice,isMoveUp, ordinal, isSave,22 + 7,  4);
			
		}
		
		if (isMoveUp)
		{
			if (ordinal == 0)
				isMoveUp = false;
			ordinal--;

		}
		else
		{
			if (ordinal == 4)
				isMoveUp = true;
			ordinal++;
		}
		if (isSave)
		{
			Gotoxy(X_NOTIFY, Y_NOTIFY);
			cout << setw(50) << setfill(' ') << " ";
			if (id.empty() || name.empty() || numberPractice == 0 || numberTheory == 0)
			{
				Gotoxy(X_NOTIFY, Y_NOTIFY);
				cout << "Cac truong du lieu khong dc de trong";
			}
			else if (idIsExits)
			{
				Gotoxy(X_NOTIFY, Y_NOTIFY);
				cout << "Ma MH khong duoc trung";
			}
		
		
			else
			{
				
				
				//strcpy(data.idSubject, id.c_str());
				strcpy(data.nameSubject, name.c_str());
				//data.nameSubject = name;
				data.numberPractice = numberPractice;
				data.numberTheory = numberTheory;
				
				if(isEdited)
				{
					
					NODE_SUBJECT* p = FindSubject(t, data.idSubject);
					p->_subject = data;	
					
					for(int i = 0; i<= nSubject; i++)
					{
						if(stricmp(arrSubject[i].idSubject, data.idSubject) == 0)
						{
							arrSubject[i] = data;
							break;
						}
					}			
				}
				else
				{
					InsertSubjectToTree(t, data);
				}
								
				DeleteMenuAdd();
				Gotoxy(X_NOTIFY, Y_NOTIFY + 1);
				cout << "                    ";
				return;
			}
			isSave = false;
		}
		else
			isSave = false;
	}
	
	ShowCur(false);
}

void ChangePageMenuSubject(TREE_SUBJECT t)
{
	
	Display(keyDisplaySubject, sizeof(keyDisplaySubject) / sizeof(string));
	Gotoxy(X_TITLE, Y_TITLE); cout << " QUAN LY DANH SACH MON HOC ";
	QuickSort(0, nSubject, arrSubject);
	OutputListSubjectPerPage(t, (pageNowSubject - 1) * QUANTITY_PER_PAGE);

}


void MenuSubjectManager(TREE_SUBJECT &t)
{
	backMenu:
		totalPageSubject = nSubject/ QUANTITY_PER_PAGE + 1;
		pageNowSubject = 1;
		indexOutSubject = -1;
		if(nSubject  != -1)
		{
			QuickSort(0, nSubject, arrSubject);
		}
		
		Display(keyDisplaySubject, sizeof(keyDisplaySubject) / sizeof(string));
		if(nSubject != -1)
			OutputListSubjectPerPage(t, 0);
		Gotoxy(X_TITLE, Y_TITLE); cout << " QUAN LY DANH SACH MON HOC ";
		
		int key;
		while(true)
		{
			while(_kbhit())
			{
				key = _getch();
				
				if(key == 0 || key == 224)
				{
					key = _getch();
					Gotoxy(X_NOTIFY, Y_NOTIFY);
					cout << setw(35) << setfill(' ') << " ";
					
					if(key == KEY_F2)
					{
						SUBJECT sj;
						DisplayEdit(keyDisplaySubject, sizeof(keyDisplaySubject) / sizeof(string), 35);
						inputSubject(t, sj);
						
						Gotoxy(X_NOTIFY, Y_NOTIFY); cout << "Them thanh cong";
						totalPageSubject = nSubject/ QUANTITY_PER_PAGE + 1;
						pageNowSubject = 1;
						QuickSort(0, nSubject, arrSubject);;
						OutputListSubjectPerPage(t, (pageNowSubject - 1) * QUANTITY_PER_PAGE);		
					}
					else if(key == KEY_F3)
					{
						clrscr();
						Gotoxy(X_TITLE, Y_TITLE); cout << " QUAN LY DANH SACH MON HOC ";                     
						Gotoxy(X_PAGE, Y_PAGE); cout << "Trang "<< pageNowSubject << "/" << totalPageSubject;
						
						NODE_SUBJECT* k = ChooseSubject(t);
						if(k == NULL) goto backMenu;
						
						Gotoxy(X_NOTIFY, Y_NOTIFY);
						cout << "Ban co chan chan xoa? ENTER == dong y";
						key = _getch();
						if(key == ENTER)
						{
							clrscr();
							Gotoxy(X_TITLE, Y_TITLE); cout << " QUAN LY DANH SACH MON HOC ";
							Display(keyDisplaySubject, sizeof(keyDisplaySubject) / sizeof(string));
							for(int i = 0; i <= nSubject; i++)
							{
								
								if(strcmp(k->_subject.idSubject, arrSubject[i].idSubject) == 0)
								{
									for(int j = i; j < nSubject; j++)
										arrSubject[j] = arrSubject[j+1];
									nSubject--;
									break;
								}
							}	
							if(IsDeleteSubject(t, k->_subject))
							{
								if((nSubject + 1) / QUANTITY_PER_PAGE == 0) pageNowSubject--;
								Gotoxy(X_NOTIFY, Y_NOTIFY);
								cout << "Xoa thanh cong";
								ChangePageMenuSubject(t);
							}
						}
						else
							goto backMenu;
					}
					else if(key == KEY_F4)
					{
						NODE_SUBJECT* k = ChooseSubject(t);
						if(k == NULL) goto backMenu;
						
						DisplayEdit(keyDisplaySubject, sizeof(keyDisplaySubject) / sizeof(string), 35);
						inputSubject(t, k->_subject, true);
						Gotoxy(X_NOTIFY, Y_NOTIFY);
						cout << "Edit thanh cong";
						ChangePageMenuSubject(t);						
					}
					else if( key == PAGE_DOWN && pageNowSubject < totalPageSubject)
					{
						clrscr();
						pageNowSubject++;
						ChangePageMenuSubject(t);
					}
					else if(key == PAGE_UP && pageNowSubject > 1)
					{
						clrscr();					
						pageNowSubject--;
						ChangePageMenuSubject(t);
					}					
				}				
				else if(key == ESC)
				{
					return;	
				}
			}			
		}
}


#endif
