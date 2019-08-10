#ifndef _SCORESUBJECTOFCLASS_H
#define _SCORESUBJECTOFCLASS_H

#include "student.h"
#include "creditclass.h"



struct pointSubject{
	char idSubject[11];
	float point = -1;
};
typedef struct pointSubject POINTSUBJECT;

struct nodePointSubject{
	POINTSUBJECT _pointSubject;
	struct nodePointSubject *pNext;
};
typedef struct nodePointSubject NODE_POINTSUBJECT;

struct listPointSubject{
	NODE_POINTSUBJECT *pHead, *pTail;
	int n;
};
typedef struct listPointSubject LIST_POINTSUBJECT;

struct ReportStudent{
	char idStudent[13];
	char fistName[21], lastName[11];
	
	LIST_POINTSUBJECT listPointSubject;
};
typedef struct ReportStudent REPORTSTUDENT;


void InitListPointSubject(LIST_POINTSUBJECT &l)
{
	l.pHead = l.pTail = NULL;
	l.n = 0;
}

NODE_POINTSUBJECT* GetNodePointSubject(POINTSUBJECT DATA)
{
	NODE_POINTSUBJECT *p = new NODE_POINTSUBJECT; //init pointer
	if (p == NULL)
		return NULL;
	p->_pointSubject = DATA; // export data to node;
	p->pNext = NULL; //init link list
	return p;
}

void AddHeadListPointSubject(LIST_POINTSUBJECT &l, POINTSUBJECT data)
{

	NODE_POINTSUBJECT *p = GetNodePointSubject(data);
	p->pNext = l.pHead;
	l.pHead = p;
	++l.n;
}

void AddTailListPointSubject(LIST_POINTSUBJECT &l, POINTSUBJECT data)
{
	NODE_POINTSUBJECT* p = GetNodePointSubject(data);
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;		
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;	
	}

	++l.n;	
}

void InsertOrderForListPointSubject(LIST_POINTSUBJECT &l, POINTSUBJECT data)
{
	if(l.pHead == NULL)
	{	
		AddHeadListPointSubject(l, data);
		return;
	}
	
	NODE_POINTSUBJECT *p, *pAfter, *pBefore;	
	p = GetNodePointSubject(data);
	
	for(pAfter = l.pHead; pAfter != NULL && (strcmp(pAfter->_pointSubject.idSubject, data.idSubject) < 0);
	pBefore = pAfter, pAfter = pAfter->pNext);
	
	if(pAfter == l.pHead) 
		AddHeadListPointSubject(l, p->_pointSubject);
	else
	{
		p->pNext = pAfter;
		pBefore->pNext = p;
		++l.n;
	}	
}

NODE_POINTSUBJECT* Middle_1_1(NODE_POINTSUBJECT* start, NODE_POINTSUBJECT* last)
{
	if (start == NULL)
		return NULL;
	NODE_POINTSUBJECT * slow = start;
	NODE_POINTSUBJECT * fast = start->pNext;

	while (fast != last)
	{
		fast = fast->pNext;
		if (fast != last)
		{
			slow = slow->pNext;
			fast = fast->pNext;
		}
	}
	return slow;
}


NODE_POINTSUBJECT* BinarySearchPointSubject(LIST_POINTSUBJECT l, char* id)
{
	NODE_POINTSUBJECT* start = l.pHead;
	NODE_POINTSUBJECT* last = NULL;
	if(l.pHead == NULL) return NULL;
	do
	{	
		NODE_POINTSUBJECT* p = Middle_1_1(start, last);
		
		if(p == NULL) return NULL;
		
		if (stricmp(p->_pointSubject.idSubject, id) == 0)
			return p;		
		else if (stricmp(p->_pointSubject.idSubject, id) < 0)
		{		
				
			start = p->pNext;			
		}
		else
		{	
			last = p;
		}
	} 
	while ( start != last);
	return NULL; // value not present;
}



//
//void initListReportStudent(LIST_STUDENT l, string idClass)
//{
//	
//	for(NODE_STUDENT* p = l.pHead; p != NULL; p = p->pNext)
//	{
//		if(_stricmp(p->_student.idClass, (char*)idClass.c_str()) == 0)
//		{
//			strcpy(prSubject[indexprSubject].idStudent, p->_student.idStudent);
//			strcpy(prSubject[indexprSubject].fistName, p->_student.fistName);  
//			strcpy(prSubject[indexprSubject].lastName, p->_student.lastName);
//			InitListPointSubject(prSubject[indexprSubject].listPointSubject);
//			indexprSubject++;
//		}
//	}
//}
//
//void FindSubjectInCreditClass(PTR_LISTCREDITCLASS l)
//{
//	for(int j = 0; j < indexprSubject; j++)
//	{
//		for(int i = 0; i <= l->n; i++)
//		{
//			NODE_REGISTERSTUDENT* k = BinarySearchRegisterStudent(l->listCreditClass[i]->listRegisterStudent, prSubject[j].idStudent);
//			
//			if(k != NULL)
//			{
//				POINTSUBJECT psj;
//				NODE_POINTSUBJECT* q = BinarySearchPointSubject(prSubject[j].listPointSubject, l->listCreditClass[i]->idSubject);
//				if(q != NULL)
//				{
//					if(q->_pointSubject.point < k->_registerStudent.point)
//					{
//						q->_pointSubject.point = k->_registerStudent.point;					
//					}
//				}
//				else
//				{
//					strcpy(psj.idSubject,l->listCreditClass[i]->idSubject);
//					psj.point = k->_registerStudent.point;
//					InsertOrderForListPointSubject(prSubject[j].listPointSubject, psj);
//				}					
//			}		
//		}
//	}
//}

void insertOrderString(string arr[], int &length, string x)
{
	if(length == 0)
	{
		arr[0] = x;
		
		length++;
		//cout << arr[0];
		return;
	} 
	int i = 0;
	for (int k = 0 ; k < length; k++)
	{
		if (arr[k] == x)
		return;
	}
	if (arr[length-1] < x)
	{
		
		arr[length] = x;
		++length;
		//cout << arr[nIdSubject];
		return;
	}
	
	for (i; i < length; i++)
	{
		if (x < arr[i])
		{ 
			for(int j = length - 1; j >= i; j--)
			{ 
					arr[j+1] = arr[j];
			}
					arr[i]= x; 	
					length++;
					return;
		}
	}
}

bool checkString(string arr[], int length, string data)
{
	bool flag = false; // string khong ton tai
	for(int i = 0; i < length; i++)
	{
		if(data == arr[i])
			flag == true;
	}
	return flag;
}

//void CreateArridSubject()
//{
//	for(int k = 0; k < indexprSubject; k++)
//	{
//		for(NODE_POINTSUBJECT* p = prSubject[k].listPointSubject.pHead; p != NULL; p = p->pNext)
//		{
//			if(checkString(idSubject, nIdSubject, p->_pointSubject.idSubject) == false)
//			{
//				insertOrderString(idSubject, nIdSubject, p->_pointSubject.idSubject);
//			}			
//		}
//	}
//}


void Display_1(string key[], int xKeyDisplay[], int nKey)
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
}

void caucuoi(LIST_STUDENT l, PTR_LISTCREDITCLASS lcc, string idClass)
{
	REPORTSTUDENT* prSubject = new REPORTSTUDENT[100];
	int indexprSubject = 0;

	string idSubject[300];
	int nIdSubject = 0;
	
//	initListReportStudent(l, idCLass);
	for(NODE_STUDENT* p = l.pHead; p != NULL; p = p->pNext)
	{
		if(_stricmp(p->_student.idClass, (char*)idClass.c_str()) == 0)
		{
			strcpy(prSubject[indexprSubject].idStudent, p->_student.idStudent);
			strcpy(prSubject[indexprSubject].fistName, p->_student.fistName);  
			strcpy(prSubject[indexprSubject].lastName, p->_student.lastName);
			InitListPointSubject(prSubject[indexprSubject].listPointSubject);
			indexprSubject++;
		}
	}


	//FindSubjectInCreditClass(lcc);
	for(int j = 0; j < indexprSubject; j++)
	{
		for(int i = 0; i <= lcc->n; i++)
		{
			NODE_REGISTERSTUDENT* k = BinarySearchRegisterStudent(lcc->listCreditClass[i]->listRegisterStudent, prSubject[j].idStudent);
			
			if(k != NULL)
			{
				POINTSUBJECT psj;
				NODE_POINTSUBJECT* q = BinarySearchPointSubject(prSubject[j].listPointSubject, lcc->listCreditClass[i]->idSubject);
				if(q != NULL)
				{
					if(q->_pointSubject.point < k->_registerStudent.point)
					{
						q->_pointSubject.point = k->_registerStudent.point;					
					}
				}
				else
				{
					strcpy(psj.idSubject,lcc->listCreditClass[i]->idSubject);
					psj.point = k->_registerStudent.point;
					InsertOrderForListPointSubject(prSubject[j].listPointSubject, psj);
				}					
			}		
		}
	}
	
	
	
	for(int k = 0; k < indexprSubject; k++)
	{
		for(NODE_POINTSUBJECT* p = prSubject[k].listPointSubject.pHead; p != NULL; p = p->pNext)
		{
			if(checkString(idSubject, nIdSubject, p->_pointSubject.idSubject) == false)
			{
				insertOrderString(idSubject, nIdSubject, p->_pointSubject.idSubject);
			}			
		}
	}
	
		string keyDisplayScoreSubject[nIdSubject + 3];
	keyDisplayScoreSubject[0] = "STT";
	keyDisplayScoreSubject[1] = "MSSV";
	keyDisplayScoreSubject[2] = "Ho ten";
	

	
	for(int i = 3; i< nIdSubject + 3; i++)
	{
		keyDisplayScoreSubject[i] = idSubject[i - 3];
		//cout << keyDisplayScoreSubject[i] << endl;
	}
	
	int xKeyDisplay_1[nIdSubject + 4];
	xKeyDisplay_1[0] = 2;
	xKeyDisplay_1[1] = 7;
	xKeyDisplay_1[2] = 20;
	xKeyDisplay_1[3] = 50;
	xKeyDisplay_1[4] = 65;
	for(int i = 5; i < nIdSubject + 4; i++)
	{
		xKeyDisplay_1[i] = xKeyDisplay_1[i -1] + 17;
	}
	string temp[3] = {"sdfhsdfsd", "asdasdhgafsd", "asgdfahsdhasd"};
	int x[4] = {2, 22, 42, 800};
	Display_1(keyDisplayScoreSubject, xKeyDisplay_1, nIdSubject + 3);
	//Display_1(temp, x, 3);
	for(int i = 0; i < indexprSubject; i++)
	{
		Gotoxy(xKeyDisplay_1[0] + 1, Y_DISPLAY + 3 + (i * 2));cout << i;
		Gotoxy(xKeyDisplay_1[1] + 1, Y_DISPLAY + 3 + (i * 2));cout << prSubject[i].idStudent;
		Gotoxy(xKeyDisplay_1[2] + 1, Y_DISPLAY + 3 + (i * 2));cout << (string)prSubject[i].fistName + " " + (string)prSubject[i].lastName;
		for(NODE_POINTSUBJECT* k = prSubject[i].listPointSubject.pHead; k != NULL; k = k->pNext)
		{
			for(int j = 0; j < nIdSubject; j++)
			{
				if(stricmp(k->_pointSubject.idSubject, (char*)idSubject[j].c_str()) == 0)
				{
					Gotoxy(xKeyDisplay_1[j + 3] + 1, Y_DISPLAY + 3 + (i * 2));cout << k->_pointSubject.point;
				}
			}
		}
	}
	
}
	

#endif

