#ifndef _PROCESSS_H
#define _PROCESSS_H

#include <fstream>
#include "creditclass.h"
#include "processstemp.h"
#include "ScoreSubjectofClass.h"

void SaveCreditClass(PTR_CREDITCLASS cc, fstream &file)
{
	file << cc->idClass << endl;
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

//-------------------------------Register Credit Class----------------------------------------------
void RegisterCreditClassIsSucceed(PTR_LISTCREDITCLASS &lcc, LIST_STUDENT lst, TREE_SUBJECT t)
{
backMenu:
	clrscr();
	Gotoxy(X_TITLE, Y_TITLE); cout << "NHAP THONG TIN DE DANG KI LTC";
	DisplayEdit(keyFindRegisterStudent, sizeof(keyFindRegisterStudent) / sizeof(string), 35);
	int schoolYear = 0;
	int semester = 0;
	int key;
	string idStudent;
	inputDataFindCreditClass(schoolYear, semester, idStudent, lst);
	
	Gotoxy(X_NOTIFY - 10, Y_NOTIFY + 1);
	cout <<"ENTER: TIEO TUC - ESC: THOAT - AN PHIM BAT KI DE NHAP LAI";
	key = _getch();
	if(key == ESC)
		return;
	else if(key == ENTER)
	{
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
			Gotoxy(X_NOTIFY, Y_NOTIFY); cout << "ban khong thuoc dien dang ky trong thoi gian nay!";
			_getch();
			return;
		}
		
			
		pageNowCreditClass = 1;
		currposCreditClass = 0;
		currposPrecCreditClass = 0;
		clrscr();
		NODE_STUDENT* P = FindStudent(lst, (char*)idStudent.c_str());
		Gotoxy(X_TITLE - 10, Y_TITLE); cout << "DANG KI LOP TIN CHI CHO SV " + (string)P->_student.fistName + " " + (string)P->_student.lastName;
		//Gotoxy(X_TITLE - 10, Y_TITLE + 1); cout << "Nhan F10 de luu toan bo cac lop da chon va F2 de chon lop tin chi moi";
		
				
		Display(keyDisplayCreditClass, sizeof(keyDisplayCreditClass) / sizeof(string));
		OutputListCreditClassPerPage(temp, t, 0);
		Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 40);
		cout << setw(xKeyDisplay[8] - xKeyDisplay[0]-1) << setfill(' ') << " ";
		
		Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 40);
		cout << setw(xKeyDisplay[8] - xKeyDisplay[0]-1) << "F2: CHON LTC DE DANG KI - F10: LUU TOAN BO DANG KI" << setfill(' ');
		
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
						Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 40);
						cout << setw(xKeyDisplay[8] - xKeyDisplay[0]-1) << setfill(' ') << " ";
		
						Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 40);
						cout << setw(xKeyDisplay[8] - xKeyDisplay[0]-1) << "F2: CHON LTC DE DANG KI - F10: LUU TOAN BO DANG KI" << setfill(' ');
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
							
						
							for(NODE_REGISTERSTUDENT* p = temp->listCreditClass[k]->listRegisterStudent.pHead; p != NULL; p = p->pNext)
							{
								if(strcmp(p->_registerStudent.idStudent, P->_student.idStudent) == 0)
								{
									flag = true;
								}
							}
							
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
						for(int i = 0; i< dem; i++)
						{
							cout << registerCreditClass[i];
						}
						for(int i = 0; i < dem; i++)
						{	
							AddTailListRegister(BinarySearchCreditClass(lcc, lcc->n, registerCreditClass[i])->listRegisterStudent, rs);			
						
						}
						
						Gotoxy(X_NOTIFY + 10, Y_NOTIFY - 10);
						cout << setw(50) << setfill(' ') << " ";
								
						Gotoxy(X_NOTIFY + 10, Y_NOTIFY  - 9);
						cout << setw(50) << setfill(' ') << " ";
						
						Gotoxy(X_NOTIFY + 10, Y_NOTIFY - 10); cout << "Dang ky thanh cong";
						Gotoxy(X_NOTIFY + 10, Y_NOTIFY - 9); cout << "An phim bat ky de thoat";
						delete temp;
						_getch();
						return;
					}	                     
				}
			}  	                     
		} 	
	}else goto backMenu;
	  	                 
                                      


}
// --------------------End Register Credit Class --------------------------------

//------------------------------Output list student on resgister credit class-------------------
bool StatisticStudentOnCreditClassIsSucceed(PTR_LISTCREDITCLASS l, TREE_SUBJECT t, LIST_STUDENT listStudent)
{
	
	Gotoxy(X_TITLE, Y_TITLE); cout << "NHAP THON TIN DE KET XUAT DSSV";
	DisplayEdit(keyFindCreditClass, sizeof(keyFindCreditClass) / sizeof(string), 35);
	string id;
	int schoolYear = 0, semester = 0, group = 0;
	int key;
	input(id, schoolYear, semester, group, t);
	
	PTR_CREDITCLASS temp = FindCrediClassWithCondition(l, (char*)id.c_str(), schoolYear, semester, group);
//	cout << temp->listRegisterStudent.pHead->pNext->_registerStudent.idStudent;

	
	LIST_STUDENT tempStudetn;
	InitListStudent(tempStudetn);
	for (NODE_REGISTERSTUDENT *p = temp->listRegisterStudent.pHead; p != NULL; p = p->pNext)
	{	
		NODE_STUDENT* q = BinarySearchStudent(listStudent, p->_registerStudent.idStudent);
		InsertOrderForListStudent(tempStudetn, q->_student);			
	}
	clrscr();
	NodeSubject* p = FindSubject(t, (char*)id.c_str());
	pageNowStudent = 1;
	totalPageStudent = ((tempStudetn.n - 1) / QUANTITY_PER_PAGE) + 1;
	Gotoxy(X_TITLE, Y_TITLE); cout << "DSSV DANG KI LTC CO MA MH LA: " + (string)p->_subject.nameSubject;	
	Display(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string));
	DeleteNote(sizeof(keyDisplayStudent) / sizeof(string));
	OutputListStudentWithIdClassPerPage(tempStudetn, 0);

	while(true)
	{
		key = _getch();
		if(key == PAGE_UP && pageNowStudent > 1)
		{
			pageNowStudent--;
			clrscr();
			
			Gotoxy(X_TITLE, Y_TITLE); cout << "DSSV DANG KI LTC CO MA MH LA: " + (string)p->_subject.nameSubject;	
			Display(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string));
			DeleteNote(sizeof(keyDisplayStudent) / sizeof(string));
			OutputListStudentWithIdClassPerPage(tempStudetn, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
		}else if(key == PAGE_DOWN && pageNowStudent < totalPageStudent)
		{
			pageNowStudent++;
			clrscr();
			
			Gotoxy(X_TITLE, Y_TITLE); cout << "DSSV DANG KI LTC CO MA MH LA: " + (string)p->_subject.nameSubject;	
			Display(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string));
			DeleteNote(sizeof(keyDisplayStudent) / sizeof(string));
			OutputListStudentWithIdClassPerPage(tempStudetn, (pageNowStudent - 1) * QUANTITY_PER_PAGE);		
		}else if(key == ESC)
		{
			ClearListStudent(tempStudetn);
			return true;
			_getch();
		}
	}
}
//------------------------------End output list student on resgister credit class-------------------


//---------------------Output List Student of CLass sort by idStudent -------
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
	Gotoxy(X_TITLE, Y_TITLE);
	cout << "NHAP VAO MA LOP CAN QUAN LY: ";
	DisplayEdit(keyDisplayEditClass, sizeof(keyDisplayEditClass) / sizeof(string), 35);
	CheckMoveAndValdateIdClass(idClass, 28);
	Gotoxy(X_NOTIFY - 10, Y_NOTIFY);
	cout << "BAN CO MUON SUA LAI MA LOP";
	Gotoxy(X_NOTIFY - 10, Y_NOTIFY + 1);
	cout <<"ENTER NEU MA LOP DA DUNG HOAC NHAN PHIM BAT KI DE NHAP LAI";
	key = _getch();
	if(key != ENTER) goto backMenu;
	else{
		LIST_STUDENT temp;
		InitListStudent(temp);	
		for(NODE_STUDENT* p = l.pHead; p != NULL; p = p->pNext)
		{
			if(strcmp(p->_student.idClass, (char*)idClass.c_str()) == 0)
			{
				AddTailListStudent(temp, p->_student);
			}
		}
		clrscr();
		pageNowStudent = 1;
		totalPageStudent = ((temp.n -1) / QUANTITY_PER_PAGE) + 1;
		Display(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string));
		DeleteNote(sizeof(keyDisplayStudent) / sizeof(string)); 
		OutputListStudentWithIdClassPerPage(temp, 0);
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
						DeleteNote(sizeof(keyDisplayStudent) / sizeof(string));
						ChangePageManageStudent(temp, idClass);
					}
					else if(key == PAGE_UP && pageNowStudent > 1)
					{
						pageNowStudent--;
						DeleteNote(sizeof(keyDisplayStudent) / sizeof(string));
						ChangePageManageStudent(temp, idClass);
					}
				}
				else if(key == ESC)
				{
					ClearListStudent(temp);
					_getch();
					return true;
				}
			}
			
		}		
	}
	
	
	
}

//---------------------Output List Student of CLass sort by idStudent -------

//-------------------Input Score for list register student----------------------------------
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
	Gotoxy(X_TITLE, Y_TITLE); cout << "Nhap diem cho mon hoc: " << + p->_subject.nameSubject;
	Gotoxy(X_TITLE, Y_TITLE + 1); cout << "Nien khoa: " << schoolYear << " Hoc ki: " << semester << " Nhom: " << group;
	pageNowStudent = 1;
	totalPageStudent = (templs.n - 1) / QUANTITY_PER_PAGE + 1;
	
	Display(keyDisplayInputScoreCreditClass, sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));
	DeleteNote(sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));	
	Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 40);
	cout << setw(xKeyDisplay[5] - xKeyDisplay[0]-1) << "F2: NHAP DIEM - ESC: Thoat" << setfill(' ');
	
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
				else if(key == PAGE_DOWN && pageNowStudent < totalPageStudent)
				{
					pageNowStudent++;
					ChangePageManageScore(templs, tempCC->listRegisterStudent, p);
					DeleteNote(sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));	
					Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 40);
					cout << setw(xKeyDisplay[5] - xKeyDisplay[0]-1) << "F2: NHAP DIEM - ESC: Thoat" << setfill(' ');
				}
				else if(key == PAGE_UP && pageNowStudent > 1)
				{
					pageNowStudent--;
					ChangePageManageScore(templs, tempCC->listRegisterStudent, p);
					
					DeleteNote(sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));	
					Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 40);
					cout << setw(xKeyDisplay[5] - xKeyDisplay[0]-1) << "F2: NHAP DIEM - ESC: thoat" << setfill(' ');
				}
			}
			else if(key == ESC)
			{
				_getch();
				return true;
			}
							
		}
	}	
}
// end input score

// output score of student 
bool outputScoreofCreditClass(PTR_LISTCREDITCLASS pListCC, LIST_STUDENT lst, TREE_SUBJECT t)
{
	Gotoxy(X_TITLE, Y_TITLE); cout << "NHAP THON TIN DE KET XUAT DIEM CUA LTC";
	DisplayEdit(keyFindCreditClass, sizeof(keyFindCreditClass) / sizeof(string), 35);
	string idSubject;
	int schoolYear = 0, semester = 0, group = 0;
	input(idSubject, schoolYear, semester, group, t);
	
	PTR_CREDITCLASS tempCC = FindCrediClassWithCondition(pListCC, (char*)idSubject.c_str(), schoolYear, semester, group);
	NODE_SUBJECT* p = FindSubject(t, tempCC->idSubject);
	LIST_STUDENT templs;
	InitListStudent(templs);
	int n = 0;
	for(NODE_REGISTERSTUDENT* k = tempCC->listRegisterStudent.pHead; k != NULL; k = k->pNext)
	{
		
		if(k->_registerStudent.point != -1)
		{
			NODE_STUDENT* i = BinarySearchStudent(lst, k->_registerStudent.idStudent);
			InsertOrderForListStudent(templs, i->_student);
			n++;
		}
		
	}
	clrscr();
	Gotoxy(X_TITLE, Y_TITLE); cout << "BAN DIEM MON HOC: " << + p->_subject.nameSubject;
	Gotoxy(X_TITLE, Y_TITLE + 1); cout << "Nien khoa: " << schoolYear << " Hoc ki: " << semester << " Nhom: " << group;
	pageNowStudent = 1;
	totalPageStudent = (n - 1) / QUANTITY_PER_PAGE + 1;
	Display(keyDisplayInputScoreCreditClass, sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));
	DeleteNote(sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));
	int key;
	outputListScoreCreditClassPerPage1(tempCC->listRegisterStudent, templs, 0);
	
	while(true)
	{
		key = _getch();
		if(key == PAGE_UP && pageNowStudent > 1)
		{
			pageNowStudent--;
			clrscr();
			Gotoxy(X_TITLE, Y_TITLE); cout << "BAN DIEM MON HOC: " << + p->_subject.nameSubject;
			Gotoxy(X_TITLE, Y_TITLE + 1); cout << "Nien khoa: " << schoolYear << " Hoc ki: " << semester << " Nhom: " << group;
						
			Display(keyDisplayInputScoreCreditClass, sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));
			DeleteNote(sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));
			outputListScoreCreditClassPerPage1(tempCC->listRegisterStudent, templs, (pageNowCreditClass - 1) * QUANTITY_PER_PAGE);
		}
		else if(key == PAGE_DOWN && pageNowStudent < totalPageStudent)
		{
			pageNowStudent++;
			clrscr();
			Gotoxy(X_TITLE, Y_TITLE); cout << "BAN DIEM MON HOC: " << + p->_subject.nameSubject;
			Gotoxy(X_TITLE, Y_TITLE + 1); cout << "Nien khoa: " << schoolYear << " Hoc ki: " << semester << " Nhom: " << group;
			
			
			Display(keyDisplayInputScoreCreditClass, sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));
			DeleteNote(sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));
			outputListScoreCreditClassPerPage1(tempCC->listRegisterStudent, templs, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
		}else if(key == ESC)
		{
			ClearListStudent(templs);
			_getch();
			return true;		
		}
	}
}



// output score medium of class
bool outputScoreSubjectOfCreditClass(PTR_LISTCREDITCLASS lcc, LIST_STUDENT l, TREE_SUBJECT t)
{
	Gotoxy(X_TITLE, Y_TITLE); cout << "NHAP MA LOP DE KET XUAT DIEM TRUNG BINH";
	string idClass;
	DisplayEdit(keyDisplayEditClass, sizeof(keyDisplayEditClass) / sizeof(string), 35);
	CheckMoveAndValdateIdClass(idClass, 28);
	int key;
	
	LIST_STUDENT temp;
	InitListStudent(temp);
	for(NODE_STUDENT* p = l.pHead; p != NULL; p = p->pNext)
	{
		if(strcmp(p->_student.idClass, (char*)idClass.c_str()) == 0 )
		{
			float temps = MediumScoreOfStudent(lcc, t, p->_student.idStudent);
			if(temps < 0)
			{
				temps = 0;
				p->_student.mediumScore = temps;	
				AddTailListStudent(temp, p->_student);
			}else
			{
				p->_student.mediumScore = temps; 	
				AddTailListStudent(temp, p->_student);
			}
		}
	}
	pageNowStudent = 1;
	totalPageStudent = ((temp.n -1) / QUANTITY_PER_PAGE) + 1;
	
	Gotoxy(X_TITLE, Y_TITLE); cout << "BANG THONG KE DIEM TRUNG BINH KHOA HOC";
	Gotoxy(X_TITLE + 2, Y_TITLE + 1); cout << "Lop: " << idClass << "  - Nam nhap hoc: " << temp.pHead->_student.yearAdmission ;
	
	Display(keyDisplayInputScoreCreditClass, sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));
	DeleteNote(sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));
	outputMediumScoreOfStudentPerPage(temp, 0);
	
	
	while(true)
	{
		key = _getch();
		if(key == PAGE_UP && pageNowStudent > 1)
		{
			pageNowStudent--;
			ChangePageManageStudent(temp, idClass, temp.pHead->_student.yearAdmission);
		}
		else if(key == PAGE_DOWN && pageNowStudent < totalPageStudent)
		{
			pageNowStudent++;
			ChangePageManageStudent(temp, idClass, temp.pHead->_student.yearAdmission);
		}else if(key == ESC)
		{
			ClearListStudent(temp);
			_getch();
			return true;		
		}
	}
}
// end output medium score of class



void OutputScoreTableOfClass()
{
	
}

bool SummaryTableScoreOfClassIsSucced(PTR_LISTCREDITCLASS lcc, LIST_STUDENT l, TREE_SUBJECT t)
{
	
	int key;
	string idClass = "d17cqpt01";
	Gotoxy(X_TITLE, Y_TITLE);
	cout << "NHAP VAO MA LOP CAN KET XUAT: ";
	//DisplayEdit(keyDisplayEditClass, sizeof(keyDisplayEditClass) / sizeof(string), 35);
	//CheckMoveAndValdateIdClass(idClass, 28);	
	
//	initListReportStudent(l, idClass);
//	FindSubjectInCreditClass(lcc);
//	CreateArridSubject();

	caucuoi(l, lcc, idClass);
	
//	for(int i = 0; i < nIdSubject; i++)
//	{
//		cout << idSubject[i] << endl;
//	}
//	// display

	
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
						if(StatisticStudentOnCreditClassIsSucceed(pListCC, t, l) == false) continue; // in danh sach LTC
						break;
					case 1:
						clrscr();
						if(PrintListStudentIsSucceed(l) == false) continue; // in DSSV
						break;
					case 2:
						clrscr();
						if(inputSocreCreditClassIsSuccedd(pListCC,t, l) == false) continue; // nhap diem	
						break;
					case 3:
						clrscr();
						if(outputScoreofCreditClass(pListCC, l, t) == false) continue; // in ban diem mon hoc
						break;
					case 4:
						clrscr();
						if(outputScoreSubjectOfCreditClass(pListCC, l, t) == false) continue;
						break;
					case 5:
						clrscr();
						if(SummaryTableScoreOfClassIsSucced(pListCC, l, t) == false) continue;
					
						break;
					default:
						break;
				}
		}
		clrscr();
	}
}// void















#endif

