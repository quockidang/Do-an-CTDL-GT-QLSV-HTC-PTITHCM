#ifndef _PROCESSS_H
#define _PROCESSS_H

#include <fstream>
#include "creditclass.h"

#include "student.h"

//------------------------------------DATABASE------------------------------------------
//void LoadCreditClass(PTR_LISTCREDITCLASS &pList)
//{
//	int sizeRegisterStudent = sizeof(REGISTER_STUDENT) - sizeof(string);
//	int sizeCreditClass = sizeof(CREDITCLASS) - sizeof(LIST_REGISTERSTUDENT);
//	
//	fstream filedata("DSLTC.txt", ios::in);
//	while(!filedata.eof())
//	{
//		pList->listCreditClass[++pList->n] = new CREDITCLASS;
//		filedata.read(reinterpret_cast<char*>(pList->listCreditClass[pList->n]), sizeCreditClass);
//		InitListRegisterStudent(pList->listCreditClass[pList->n]->listRegisterStudent);
//		
//		int nRegisterStudent = pList->listCreditClass[pList->n]->listRegisterStudent->n;
//	}
//}









void SaveCreditClass(PTR_CREDITCLASS cc, fstream &file)
{
	file << cc->idClass << endl;
	file << cc->nameSubject << endl;
	file << cc->idSubject << endl;
	file << cc->shoolYear << endl;
	file << cc->semester << endl;
	file << cc->group << endl;
	file << cc->studentMax << endl;
	file << cc->studentMin << endl;
	
	file << cc->listRegisterStudent.n << endl;
	for(NODE_REGISTERSTUDENT* p = cc->listRegisterStudent.pHead; p != NULL; p = p->pNext)
	{
		file << p->_registerStudent.idStudent << endl;
		file << p->_registerStudent.point << endl;
	}

}

void SaveCreditClassToFile(PTR_LISTCREDITCLASS l)
{
	fstream outFile;
	outFile.open("DSLTC1.txt", ios::out );
	if (outFile.is_open())
	{
		outFile << l->n <<endl;
		for(int i = 0; i<= l->n;i++)
		{
			SaveCreditClass(l->listCreditClass[i], outFile);
		}
	}else
	{
		
		cout << "KET NOI VOI FILE THAT BAI! ";
	}
	
	outFile.close();
}


void LoadCreditClassFromFile(PTR_LISTCREDITCLASS &l)
{
	fstream inFile;
	
	int nCreditClass, nRegisterStudent;
	
	
	inFile.open("DSLTC1.txt", ios::in);
	
	if(inFile.is_open())
	{
		string temp;		
		inFile >> nCreditClass;
		
		for(int i = 0; i <= nCreditClass; i++)
		{
		
			l->listCreditClass[i] = new CREDITCLASS;
			// load thong tin vao LTC
			inFile >> l->listCreditClass[i]->idClass;
			getline(inFile, temp);
			inFile.getline(l->listCreditClass[i]->nameSubject, 30, '\n');
			inFile.getline(l->listCreditClass[i]->idSubject, 10, '\n');
			
			inFile >> l->listCreditClass[i]->shoolYear;
			
			inFile >> l->listCreditClass[i]->semester;
			inFile >> l->listCreditClass[i]->group;
			inFile >> l->listCreditClass[i]->studentMax;
			inFile >> l->listCreditClass[i]->studentMin;
			
			inFile >> nRegisterStudent;
			
			InitListRegisterStudent(l->listCreditClass[i]->listRegisterStudent);
			REGISTER_STUDENT rs;
			for(int j = 0; j < nRegisterStudent; j++)
			{
				getline(inFile, temp);
				inFile.getline(rs.idStudent, 12, '\n');
				inFile >> rs.point;
				
				AddTailListRegister(l->listCreditClass[i]->listRegisterStudent, rs);
			}			
			
			++l->n;
			//delete l->listCreditClass[i];
		}
	}
	
	
	inFile.close();
}













void Save(TREE_SUBJECT t, fstream &file)
{
	file << t->_subject.idSubject << endl;
	file << t->_subject.nameSubject << endl;
	file << t->_subject.numberPractice << endl;
	file << t->_subject.numberTheory << endl;
}

void WriteSubjectToFile(TREE_SUBJECT t, fstream &file)
{
	if (t != NULL)
	{
		Save(t, file);
		WriteSubjectToFile(t->pLeft, file);
		WriteSubjectToFile(t->pRight, file);	
	}
}

void SaveSubjectToFile(TREE_SUBJECT t)
{
	fstream outFile;
	outFile.open("DSMH.txt", ios::out);
	if (outFile.is_open())
	{
		
		outFile << nSubject << endl;
		WriteSubjectToFile(t, outFile);
	}
	else
	{
		cout << "KET NOI VOI FILE DSMH THAT BAI! ";
	}
	outFile.close();
}

void LoadSubjectFormFile(TREE_SUBJECT &t)
{
	fstream inFile;
	SUBJECT sj;
	int n;
	inFile.open("DSMH.txt", ios::in);
	if (inFile.is_open())
	{
		string temp;		
		inFile >> n;
		
		for(int i = 0; i <= n; i++)
		{
			getline(inFile, temp);
			inFile.getline(sj.idSubject, 10, '\n');
			inFile.getline(sj.nameSubject, 30, '\n');
			inFile >> sj.numberPractice;
			inFile >> sj.numberTheory;
			
			InsertSubjectToTree(t, sj);
		}
	}
	else {
		cout << "KET NOI VOI FILE DSMH THAT BAI! ";
	}

	inFile.close();
}

// -------------- DSSV----------------------------

void SaveStudent(STUDENT st, fstream &file)
{
	file << st.idClass << endl;
	file << st.idStudent << endl;
	file << st.fistName << endl;
	file << st.lastName << endl;
	file << st.phoneNUmber << endl;
	file << st.yearAdmission << endl;
	file << st.sex << endl;
	
}


void SaveStudentToFile(LIST_STUDENT l)
{
	fstream outFile;
	outFile.open("DSSV.txt", ios::out);
	if (outFile.is_open())
	{
		outFile << l.n << endl;
		// so doc gia..
		for(NODE_STUDENT* k = l.pHead; k != NULL; k = k->pNext)
		{
			SaveStudent(k->_student, outFile);
		}
	}
	else
	{
		cout << "KET NOI VOI FILE DSMH THAT BAI! ";
	}
	outFile.close();
}

void LoadStudentFromFile(LIST_STUDENT &l)
{
	fstream inFile;
	STUDENT st;
	int n;
	inFile.open("DSSV.txt", ios::in);
	if (inFile.is_open())
	{
		string temp;		
		inFile >> n;
		
		for(int i = 0; i < n; i++)
		{
			getline(inFile, temp);
			inFile.getline(st.idClass, 15, '\n');
			inFile.getline(st.idStudent, 12, '\n');
			inFile.getline(st.fistName, 20, '\n');
			inFile.getline(st.lastName, 10, '\n');
			inFile.getline(st.phoneNUmber, 12, '\n');
			inFile >> st.yearAdmission;
			inFile >> st.sex;
			
			AddTailListStudent(l, st);
		}
	}
	else {
		cout << "KET NOI VOI FILE DSMH THAT BAI! ";
	}

	inFile.close();
}
// -------------------------------End Database----------------------------------------


//------------------------------Output list student on resgister credit class-------------------
void input(string &idSubject, int &shoolYear, int &semester, int &group, TREE_SUBJECT t)
{
	int ordinal = 0;
	bool isMoveUp = false;
	bool isSave = false;
	bool idIsExist = false;
	Gotoxy(X_NOTIFY, Y_NOTIFY + 1); cout << "An F10 de hoan tat viec nhap data";
	
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
				CheckMoveAndValidateNumber(semester,isMoveUp, ordinal, isSave,24, 3);
				break;
			case 3:
				CheckMoveAndValidateNumber(group,isMoveUp, ordinal, isSave,26, 3);
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
			if (ordinal == 3)
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
			}
			else if(idSubject.empty() || semester == 0 || shoolYear == 0 || group == 0)
			{
				Gotoxy(X_NOTIFY, Y_NOTIFY - 1);
				cout << "Cac truong du lieu khong dc de trong";
			}
			else
			{
				DeleteMenuAdd();
				return;
			}
		
			
		}
		isSave = false;
	}
}

PTR_CREDITCLASS FindCrediClassWithCondition(PTR_LISTCREDITCLASS l, char* idSubject, int shoolYear, int semester, int group)
{
	PTR_LISTCREDITCLASS temp = new LIST_CREDITCLASS;
	PTR_CREDITCLASS p = new CREDITCLASS;
	for(int i = 0; i <= l->n; i++)
	{
		if(strcmp(l->listCreditClass[i]->idSubject,idSubject) == 0)
		{
			cout << l->listCreditClass[i]->listRegisterStudent.pHead->_registerStudent.idStudent;
			temp->listCreditClass[++temp->n] = l->listCreditClass[i];
		}
	}
	
	for(int j = 0; j <= temp->n; j++)
	{
		if(temp->listCreditClass[j]->shoolYear = shoolYear && temp->listCreditClass[j]->semester == semester && temp->listCreditClass[j]->group == group)
			p =  temp->listCreditClass[j];
	}
	delete temp;
	return p;
}


bool StatisticStudentOnCreditClassIsSucceed(PTR_LISTCREDITCLASS l, TREE_SUBJECT t, LIST_STUDENT listStudent)
{
	
	Gotoxy(X_TITLE, Y_TITLE); cout << "NHAP THON TIN DE KET XUAT DSSV";
	DisplayEdit(keyFindCreditClass, sizeof(keyFindCreditClass) / sizeof(string), 35);
	string id;
	int schoolYear = 0, semester = 0, group = 0;
	
	input(id, schoolYear, semester, group, t);
	
	PTR_CREDITCLASS temp = FindCrediClassWithCondition(l, (char*)id.c_str(), schoolYear, semester, group);
//	cout << temp->listRegisterStudent.pHead->pNext->_registerStudent.idStudent;
	string arrIdStudent[100];
	
	LIST_STUDENT tempStudetn;
	InitListStudent(tempStudetn);
	int index = 0;
	
	for (NODE_REGISTERSTUDENT *p = temp->listRegisterStudent.pHead; p != NULL; p = p->pNext)
	{
		cout << p->_registerStudent.point;
		strcpy((char*)arrIdStudent[index].c_str(), p->_registerStudent.idStudent);
		index++;
	}
	
	
	for(int i = 0; i < index; i++)
	{
		NODE_STUDENT* q = FindStudent(listStudent, (char*)arrIdStudent[i].c_str());
		AddHeadListStudent(tempStudetn, q->_student);
	}
	clrscr();
	Gotoxy(X_TITLE, Y_TITLE); cout << "DSSV DANG KI LTC CO MA MH LA: " + (string)temp->idSubject ;
	
	Display(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string));
	int count = -1;
	for(NODE_STUDENT* k = tempStudetn.pHead; k != NULL; k = k->pNext)
	{
		count++;
		OutputStudent(k->_student, count);
	}
	_getch();
	return true;
}
//------------------------------End output list student on resgister credit class-------------------



//-------------------------------Register Credit Class----------------------------------------------
void inputDataFindCreditClass(int &schoolYear, int &semester, string &idStudent, LIST_STUDENT l)
{
	int ordinal = 0;
	bool isMoveUp = false;
	bool isSave = false;
	bool idIsExist = false;
	Gotoxy(X_NOTIFY, Y_NOTIFY + 1); cout << "An F10 de hoan tat viec nhap data";
	
	while(true)
	{
		switch(ordinal)
		{
			case 0:
				CheckMoveAndValidateID(idStudent, isMoveUp, ordinal, isSave, 34, 12);								
				if(FindStudent(l, (char*)idStudent.c_str()) == NULL)
				{
					idIsExist = false;
					break;
				}else
					idIsExist = true;
				break;	
			case 1:
				CheckMoveAndValidateNumber(schoolYear,isMoveUp, ordinal, isSave,31, 2019);
				break;
			case 2:
				CheckMoveAndValidateNumber(semester,isMoveUp, ordinal, isSave,29, 3);
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
			if (ordinal == 2)
				isMoveUp = true;
			ordinal++;
		}
		if (isSave)
		{
			Gotoxy(X_NOTIFY, Y_NOTIFY - 1);
			cout << setw(50) << setfill(' ') << " ";
		
			if(idStudent.empty() || semester == 0 || schoolYear == 0)
			{
				Gotoxy(X_NOTIFY, Y_NOTIFY - 1);
				cout << "Cac truong du lieu khong dc de trong";
			}else if(!idIsExist)
			{
				Gotoxy(X_NOTIFY, Y_NOTIFY - 1);
				cout << "Ma Sinh Vien khong ton tai";
			}
			else 
			{
				DeleteMenuAdd();
				return;
			}
		
			
		}
		isSave = false;
	}
}



void RegisterCreditClassIsSucceed(PTR_LISTCREDITCLASS &lcc, LIST_STUDENT lst, TREE_SUBJECT t)
{

	clrscr();
	Gotoxy(X_TITLE, Y_TITLE); cout << "NHAP THONG TIN DE DANG KI LTC";
	DisplayEdit(keyFindRegisterStudent, sizeof(keyFindRegisterStudent) / sizeof(string), 35);
	int schoolYear = 0;
	int semester = 0;
	string idStudent;
	inputDataFindCreditClass(schoolYear, semester, idStudent, lst);
	
	PTR_LISTCREDITCLASS temp = new LIST_CREDITCLASS;
	unsigned int registerCreditClass[10];
	int dem = 0;
	for(int i = 0; i <= lcc->n; i++)
	{
		
		if(lcc->listCreditClass[i]->shoolYear == schoolYear && lcc->listCreditClass[i]->semester == semester)
		{
			temp->listCreditClass[++temp->n] = lcc->listCreditClass[i];
		}
		
	}
	
	if(temp->n == -1)
	{
		clrscr();
		return;
	}
	
	int key;	
	pageNowCreditClass = 1;
	currposCreditClass = 0;
	currposPrecCreditClass = 0;
	clrscr();
	NODE_STUDENT* P = FindStudent(lst, (char*)idStudent.c_str());
	Gotoxy(X_TITLE - 10, Y_TITLE); cout << "DANG KI LOP TIN CHI CHO SV " + (string)P->_student.fistName + " " + (string)P->_student.lastName;
	Gotoxy(X_TITLE - 10, Y_TITLE + 1); cout << "Nhan F10 de luu toan bo cac lop da chon va F2 de chon lop tin chi moi";
	
	Display(keyDisplayCreditClass, sizeof(keyDisplayCreditClass) / sizeof(string));
	OutputListCreditClassPerPage(temp, 0);
	
	
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
					int k = ChooseCreditClass(temp, t);
					if(k == -1)
					{
						clrscr();
						return;
					}
					
					Gotoxy(X_NOTIFY + 10, Y_NOTIFY - 10);
					cout << "Ban co muon dang ky LTC nay khong!";
					
					Gotoxy(X_NOTIFY + 10, Y_NOTIFY - 9);
					cout << "An ENTER neu dong y";
					key = _getch();
					if(key == ENTER)
					{
						bool flag = false;
						for(int i = 0; i < dem; i++)
						{					
							if(registerCreditClass[i] == temp->listCreditClass[k]->idClass)
							{
								flag = true;
							}	
						}
							
						
						if(flag == true)
						{
							Gotoxy(X_NOTIFY + 10, Y_NOTIFY - 10);
							cout << setw(50) << setfill(' ') << " ";
							
							Gotoxy(X_NOTIFY + 10, Y_NOTIFY - 9);
							cout << setw(50) << setfill(' ') << " ";	
							
							Gotoxy(X_NOTIFY + 10, Y_NOTIFY - 10); cout << "Ban da chon lop tin chi nay roi";
						}
						else{
							registerCreditClass[dem++] = temp->listCreditClass[k]->idClass;
							
							Gotoxy(X_NOTIFY + 10, Y_NOTIFY - 10);
							cout << setw(50) << setfill(' ') << " ";
							
							Gotoxy(X_NOTIFY + 10, Y_NOTIFY  - 9);
							cout << setw(50) << setfill(' ') << " ";
							
							Gotoxy(X_NOTIFY + 10, Y_NOTIFY - 10); cout << "Chon lop tin chi thanh cong";
							
					
						}
					}
					
				}else if(key == KEY_F10)
				{
					REGISTER_STUDENT rs;
					strcpy(rs.idStudent, idStudent.c_str());
					rs.point = -1;
					for(int i = 0; i < dem; i++)
					{				
						AddTailListRegister(lcc->listCreditClass[i]->listRegisterStudent, rs);
					}
					
					Gotoxy(X_NOTIFY + 10, Y_NOTIFY - 10);
					cout << setw(50) << setfill(' ') << " ";
							
					Gotoxy(X_NOTIFY + 10, Y_NOTIFY  - 9);
					cout << setw(50) << setfill(' ') << " ";
					
					Gotoxy(X_NOTIFY + 10, Y_NOTIFY - 10); cout << "Dang ky thanh cong";
					Gotoxy(X_NOTIFY + 10, Y_NOTIFY - 9); cout << "An phim bat ky de thoat";
					_getch();
					return;
				}	                     
			}
		}  	                     
	}   	                 
                                      


}
// --------------------End Register Credit Class --------------------------------

//---------------------Output List Student of CLass sort by name -------
void OutputListStudentPerpage(LIST_STUDENT l, int indexBegin, string arr[], int n)
{
	for(int i = 0; i + indexBegin < n && i < QUANTITY_PER_PAGE; i++)
	{
		
		
		NODE_STUDENT* s = FindStudent(l, (char*)arr[i + indexBegin].c_str());
		

		OutputStudent(s->_student, i * 2);
	}
	Gotoxy(X_PAGE, Y_PAGE);
	cout << "Trang "<< pageNowSubject << "/" << totalPageSubject;
}

bool PrintListStudentIsSucceed(LIST_STUDENT l)
{
backMenu:
	clrscr();
	
	int key;
	string idClass;
	Gotoxy(X_ADD - 7 , Y_ADD);
	cout << "NHAP VAO MA LOP CAN QUAN LY: ";
	CheckMoveAndValdateIdClass(idClass, 22);
	Gotoxy(X_NOTIFY - 10, Y_NOTIFY);
	cout << "BAN CO MUON SUA LAI MA LOP";
	Gotoxy(X_NOTIFY - 10, Y_NOTIFY + 1);
	cout <<"ENTER NEU MA LOP DA DUNG HOAC NHAN PHIM BAT KI DE NHAP LAI";
	key = _getch();
	if(key != ENTER) goto backMenu;
	
	
	LIST_STUDENT temp;
	InitListStudent(temp);
	string arrIdStudent[100];
	int n = 0;
	
	for(NODE_STUDENT* p = l.pHead; p != NULL; p = p->pNext)
	{
		if(_stricmp(p->_student.idClass, (char*)idClass.c_str()) == 0)
		{
			AddTailListStudent(temp, p->_student);
			arrIdStudent[n++] = (string)p->_student.idStudent;
		}
	}

	SelectionSort(arrIdStudent, n);
	for(int i = 0; i<n;i++)
	{
		cout << arrIdStudent[i] << endl;
	}
	_getch();
	clrscr();
	pageNowStudent = 1;
	Display(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string));
	OutputListStudentPerpage(temp, 0, arrIdStudent, n);
	Gotoxy(X_TITLE, Y_TITLE); cout << "DS SINH VIEN LOP: " + idClass ;
	
	while(true)
	{
		while(_kbhit())
		{
			key = _getch();
			if (key == 0 || key == 224)
			{
				key = _getch();
				if(key == PAGE_DOWN && pageNowStudent < totalPageStudent)
				{
					pageNowStudent++;
					ChangePageManageStudent(temp, (char*)idClass.c_str());
				}
				else if(key == PAGE_UP && pageNowStudent > 1)
				{
					pageNowStudent--;
					ChangePageManageStudent(temp, (char*)idClass.c_str());
				}
			}
			else if(key == ESC)
			{
				return true;
			}
		}
		
	}	
}

//---------------------Output List Student of CLass sort by name -------



//-------------------Input Score for list register student----------------------------------



void outputScoreCretdiClass(STUDENT _student, REGISTER_STUDENT _registerStudent, int ordinal)
{		
	DeleteOldData(sizeof(keyDisplayInputScoreCreditClass) / sizeof(string), ordinal);
	Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 3 + ordinal); cout << _student.idStudent;
	Gotoxy(xKeyDisplay[1] + 1, Y_DISPLAY + 3 + ordinal); cout << _student.fistName;
	Gotoxy(xKeyDisplay[2] + 1, Y_DISPLAY + 3 + ordinal); cout << _student.lastName;
	Gotoxy(xKeyDisplay[3] + 1, Y_DISPLAY + 3 + ordinal); cout << _registerStudent.point;
	Gotoxy(xKeyDisplay[4] + 1, Y_DISPLAY + 3 + ordinal); cout << ordinal / 2;
}

void outputListScoreCreditClassPerPage(LIST_REGISTERSTUDENT lrs, LIST_STUDENT ls, int indexBegin)
{
	if(lrs.n == 0) return;
	int counts = -1;
	
	for(NODE_REGISTERSTUDENT* q = lrs.pHead; q != NULL; q = q->pNext)
	{
		NODE_STUDENT* p = FindStudent(ls, q->_registerStudent.idStudent);
		counts++;
		if(counts == indexBegin)
		{
			int i = -1; 
			while (q != NULL && i < QUANTITY_PER_PAGE - 1)
			{
				outputScoreCretdiClass(p->_student, q->_registerStudent, (++i) * 2);
				q = q->pNext;
			}
			break;
		}
	}
	
	Gotoxy(X_PAGE, Y_PAGE);
	cout << "Trang " << pageNowStudent << "/" << totalPageStudent;
	return;
}

void SetDefaultChooseScoreCreditClass(STUDENT st, REGISTER_STUDENT rs, int ordinal)
{
	SetBGColor(GREEN);
	outputScoreCretdiClass(st, rs, (ordinal % QUANTITY_PER_PAGE) * 2);
	SetBGColor(PURPLE);
}

void EffectiveMenuScoreCreditClass(int ordinal, STUDENT stnew, STUDENT stold, REGISTER_STUDENT rsnew, REGISTER_STUDENT rsold)
{
	int current = ordinal;
	SetDefaultChooseScoreCreditClass(stnew, rsnew, current);
	outputScoreCretdiClass(stold, rsold, (currposPrecStudent % QUANTITY_PER_PAGE) * 2);
	currposPrecStudent = current;
}

void ChangePageChooseSocreCreditClass()
{
	clrscr();
	Display(keyDisplayInputScoreCreditClass, sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));
	currposStudent = (pageNowStudent - 1) * QUANTITY_PER_PAGE;
	currposPrecStudent = (pageNowStudent - 1) * QUANTITY_PER_PAGE;
}

NODE_REGISTERSTUDENT* ChooseStudentForScoreCreditClass(LIST_STUDENT ls, LIST_REGISTERSTUDENT lrs)
{
	int keyboard_read = 0;
	ShowCur(false);
	pageNowStudent = 1;
	currposStudent = (pageNowStudent - 1) * QUANTITY_PER_PAGE;
	currposPrecStudent = (pageNowStudent - 1) * QUANTITY_PER_PAGE;
	totalPageStudent = ((lrs.n-1) / QUANTITY_PER_PAGE) + 1;
	
	NODE_STUDENT* newNodeStudent = FindStudentByOrdinal(ls, currposStudent);
	NODE_STUDENT* oldNodeStudent = NULL;
	
	NODE_REGISTERSTUDENT* newNodeRS = FindRegisterStudentByOrdinal(lrs, currposStudent);
	NODE_REGISTERSTUDENT* oldNodeRS = NULL;
	
	outputListScoreCreditClassPerPage(lrs, ls, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
	SetDefaultChooseScoreCreditClass(newNodeStudent->_student, newNodeRS->_registerStudent, currposStudent);
	
	while(true)
	{
		keyboard_read = _getch();
		if (keyboard_read == 0)
			keyboard_read = _getch();
		switch (keyboard_read)
		{
			case KEY_UP:
				if(currposStudent % QUANTITY_PER_PAGE > 0)
				{
					currposStudent = currposStudent - 1;
					oldNodeStudent = newNodeStudent;
					oldNodeRS = newNodeRS;
					
					for(newNodeStudent = ls.pHead; newNodeStudent->pNext != oldNodeStudent; newNodeStudent = newNodeStudent->pNext);
					for(newNodeRS = lrs.pHead; newNodeRS->pNext != oldNodeRS; newNodeRS = newNodeRS->pNext);
					EffectiveMenuScoreCreditClass(currposStudent, newNodeStudent->_student, oldNodeStudent->_student, newNodeRS->_registerStudent, oldNodeRS->_registerStudent);				
				}
				break;
			case KEY_DOWN:
				if(currposStudent % QUANTITY_PER_PAGE < QUANTITY_PER_PAGE - 1 && newNodeStudent->pNext != NULL)
				{
					currposStudent = currposStudent + 1;
					oldNodeStudent = newNodeStudent;
					newNodeStudent = newNodeStudent->pNext;
					
					oldNodeRS = newNodeRS;
					newNodeRS = newNodeRS->pNext;
					
					EffectiveMenuScoreCreditClass(currposStudent, newNodeStudent->_student, oldNodeStudent->_student, newNodeRS->_registerStudent, oldNodeRS->_registerStudent);
				}
				break;
			case PAGE_DOWN:
				if(pageNowStudent < totalPageStudent)
				{
					pageNowStudent++;
					ChangePageChooseSocreCreditClass();
					outputListScoreCreditClassPerPage(lrs, ls, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
					
					newNodeStudent = FindStudentByOrdinal(ls, currposStudent);
					newNodeRS = FindRegisterStudentByOrdinal(lrs, currposStudent);
					SetDefaultChooseScoreCreditClass(newNodeStudent->_student, newNodeRS->_registerStudent, currposStudent);
				
				}
				break;
			case PAGE_UP:
				if(pageNowStudent > 1)
				{
					pageNowStudent--;
					ChangePageChooseSocreCreditClass();
					outputListScoreCreditClassPerPage(lrs, ls, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
					newNodeStudent = FindStudentByOrdinal(ls, currposStudent);
					newNodeRS = FindRegisterStudentByOrdinal(lrs, currposStudent);
					SetDefaultChooseScoreCreditClass(newNodeStudent->_student, newNodeRS->_registerStudent, currposStudent);
				}
				break;
			case ENTER:  //enter
				ShowCur(true);
				return newNodeRS;
				break;
			case 27: 
				return NULL; 
				break;	
		}
	}
	
}

void ChangePageManageScore(LIST_STUDENT ls, LIST_REGISTERSTUDENT lrs, NODE_SUBJECT* p)
{
	clrscr();
	Gotoxy(X_TITLE, Y_TITLE); cout << "NHAP DIEM CHO SINH VIEN LTC CO TEN MON HOC LA: " << + p->_subject.nameSubject;
	outputListScoreCreditClassPerPage(lrs, ls, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
	Display(keyDisplayInputScoreCreditClass, sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));
}

void  inputScoreCreditClass(LIST_REGISTERSTUDENT &lrs, REGISTER_STUDENT &rs) // nhap  Lop TC
{
	ShowCur(true);
	float res;
	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 0;
	bool isMoveUp = false;
	bool isSave = false;
	
	int original = 0; // nien khoa
	int decimal = 0; // hoc ki 
	
	while(true)
	{
		switch(ordinal)
		{
			case 0:
				CheckMoveAndValidateNumber(original,isMoveUp, ordinal, isSave,27 + 6, 10);
				break;
			case 1:
				CheckMoveAndValidateNumber(decimal,isMoveUp, ordinal, isSave,27 + 8, 99);
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
			if (ordinal == 1)
				isMoveUp = true;
			ordinal++;
		}
		if (isSave)
		{	
			if(decimal < 10)
			{
				res = original + ((float)decimal / 10);
			}else
				res = original + ((float)decimal / 100);
			
			rs.point = res;
			
			NODE_REGISTERSTUDENT* rsx = FindRegisterStudent(lrs, rs.idStudent);
			rsx->_registerStudent = rs;
			DeleteMenuAdd();
			return;
		}
		else
			isSave = false;
	}
	ShowCur(false);
	
}	

bool inputSocreCreditClassIsSuccedd(PTR_LISTCREDITCLASS &pListCC, TREE_SUBJECT t, LIST_STUDENT l)
{
	Gotoxy(X_TITLE, Y_TITLE); cout << "NHAP THON TIN LTC DE NHAP DIEM";
	DisplayEdit(keyFindCreditClass, sizeof(keyFindCreditClass) / sizeof(string), 35);
	string idSubject;
	int schoolYear = 0, semester = 0, group = 0;
	input(idSubject, schoolYear, semester, group, t);
	
	PTR_CREDITCLASS tempCC = FindCrediClassWithCondition(pListCC, (char*)idSubject.c_str(), schoolYear, semester, group);
	NODE_SUBJECT* p = FindSubject(t, tempCC->idSubject);
	LIST_STUDENT templs;
	InitListStudent(templs);
	
	for(NODE_REGISTERSTUDENT* k = tempCC->listRegisterStudent.pHead; k != NULL; k = k->pNext)
	{
		NODE_STUDENT* i = FindStudent(l, k->_registerStudent.idStudent);
		AddTailListStudent(templs, i->_student);
	}
	
	
	/// end nhap data input
	clrscr();
	Gotoxy(X_TITLE, Y_TITLE); cout << "NHAP DIEM CHO SINH VIEN LTC CO TEN MON HOC LA: " << + p->_subject.nameSubject;
	pageNowStudent = 1;
	Display(keyDisplayInputScoreCreditClass, sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));
	int key;
	outputListScoreCreditClassPerPage(tempCC->listRegisterStudent, templs, 0);
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
					NODE_REGISTERSTUDENT* k = ChooseStudentForScoreCreditClass(templs, tempCC->listRegisterStudent);
					DisplayEdit(keyDisplayEditInputScore, sizeof(keyDisplayEditInputScore) / sizeof(string), 35);
					inputScoreCreditClass(tempCC->listRegisterStudent, k->_registerStudent);
					clrscr();
					ChangePageManageScore(templs, tempCC->listRegisterStudent, p);
					//outputListScoreCreditClassPerPage(tempCC->listRegisterStudent, templs, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
					Gotoxy(X_NOTIFY, Y_NOTIFY); cout << "Nhap diem thanh cong";
				}
				else if(key == PAGE_DOWN && pageNowCreditClass < totalPageCreditClass)
				{
					pageNowStudent++;
					ChangePageManageScore(templs, tempCC->listRegisterStudent, p);
				}
				else if(key == PAGE_UP && pageNowCreditClass > 1)
				{
					pageNowStudent--;
					ChangePageManageScore(templs, tempCC->listRegisterStudent, p);
				}
			}
			else if(key == KEY_F10)
				return true;			
		}
	}
	
	
	
	Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 40);
	cout << setw(xKeyDisplay[5] - xKeyDisplay[0]-1) << setfill(' ') << "";
	
	Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 40);
	cout << setw(xKeyDisplay[5] - xKeyDisplay[0]-1) << "F10: Luu Diem" << setfill(' ');
	_getch();
	return true;
	
}


void MergeAll(PTR_LISTCREDITCLASS &pListCC, TREE_SUBJECT &t, LIST_STUDENT &l)
{
	while(true)
	{
		clrscr();
		MainMenu(keyMainMenu, sizeof(keyMainMenu) / sizeof(string));
		
		int type = ChooseMainMenu(keyMainMenu, sizeof(keyMainMenu) / sizeof(string));
		
		totalPageCreditClass = pListCC->n / QUANTITY_PER_PAGE + 1;
		totalPageSubject = nSubject / QUANTITY_PER_PAGE + 1;
		totalPageStudent = l.n / QUANTITY_PER_PAGE + 1;
		
		switch(type)
		{
			case -1:
				return;
			case 0:
				MenuManageCreditClass(pListCC, t);
				break;
			case 1:
				clrscr();
				MenuManagerStudent(l);
				break;
				
			case 2:
				clrscr();				
				MenuSubjectManager(t);
				break;
			case 3:
				clrscr();
				RegisterCreditClassIsSucceed(pListCC, l, t);
				break;
			case 4:
				clrscr();
				MainMenu(keyStatistic, sizeof(keyStatistic) / sizeof(string));
				int chosenStatistic = ChooseMainMenu(keyStatistic, sizeof(keyStatistic) / sizeof(string));
				
				switch(chosenStatistic)
				{
					case 0:
						clrscr();
						if(StatisticStudentOnCreditClassIsSucceed(pListCC, t, l) == false) continue;
						break;
					case 1:
						clrscr();
						if(PrintListStudentIsSucceed(l) == false) continue;
						break;
					case 2:
						clrscr();
						if(inputSocreCreditClassIsSuccedd(pListCC,t, l) == false) continue;	
						break;
					default:
						break;
				}
			
		}
		clrscr();
	}
}// void















#endif

