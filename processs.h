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
	file << cc->idSubject<< endl;
	file << cc->idClass<< endl;
	file << cc->group<< endl;
	file << cc->semester<< endl;
	file << cc->shoolYear<< endl;
	file << cc->studentMax<< endl;
	file << cc->studentMin<< endl;
	
	file << cc->listRegisterStudent.n << endl;
	for(NODE_REGISTERSTUDENT* p = cc->listRegisterStudent.pHead; p != NULL; p->pNext)
	{
		file << p->_registerStudent.idStudent << endl;
		file << p->_registerStudent.point << endl;
	}

}

void SaveCreditClassToFile(PTR_LISTCREDITCLASS l)
{
	fstream outFile;
	outFile.open("DSLCT.txt", ios::out );
	if (outFile.is_open())
	{
		outFile << l->n <<endl;
		for(int i = 0; i<= l->n;i++)
		{
			SaveCreditClass(l->listCreditClass[i], outFile);
		}
	}else
	{
		
		cout << "KET NOI VOI FILE DocGia THAT BAI! ";
	}
	
	outFile.close();
}


void LoadCreditClassFromFile(PTR_LISTCREDITCLASS &l)
{
	fstream inFile;
	
	int nCreditClass, nRegisterStudent;
	
	
	inFile.open("DSLCT.txt", ios::in);
	
	if(inFile.is_open())
	{
		string temp;		
		inFile >> nCreditClass;
		getline(inFile, temp);
		for(int i = 0; i <= nCreditClass; i++)
		{
		
			l->listCreditClass[i] = new CREDITCLASS;
			// load thong tin vao LTC
			inFile.getline(l->listCreditClass[i]->idSubject, 10, '\n');
			inFile >> l->listCreditClass[i]->idClass;
			inFile >> l->listCreditClass[i]->group;
			inFile >> l->listCreditClass[i]->semester;
			inFile >> l->listCreditClass[i]->shoolYear;
			inFile >> l->listCreditClass[i]->studentMax;
			inFile >> l->listCreditClass[i]->studentMin;
			
			inFile >> nRegisterStudent;
			getline(inFile, temp);
			
			InitListRegisterStudent(l->listCreditClass[i]->listRegisterStudent);
			REGISTER_STUDENT rs;
			for(int j = 0; j < nRegisterStudent; j++)
			{
				inFile.getline(rs.idStudent, 10, '\n');
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
	for(int i = 0; i <= l->n; i++)
	{
		if(l->listCreditClass[i]->idSubject == idSubject)
		{
			temp->listCreditClass[++temp->n] = l->listCreditClass[i];
		}
	}
	
	for(int j = 0; j <= temp->n; j++)
	{
		if(temp->listCreditClass[j]->shoolYear = shoolYear && temp->listCreditClass[j]->semester == semester && temp->listCreditClass[j]->group == group)
			return temp->listCreditClass[j];
	}
}


bool StatisticStudentOnCreditClassIsSucceed(PTR_LISTCREDITCLASS l, TREE_SUBJECT t)
{
	
	Gotoxy(X_TITLE, Y_TITLE); cout << "NHAP THON TIN DE KET XUAT DSSV";
	DisplayEdit(keyFindCreditClass, sizeof(keyFindCreditClass) / sizeof(string), 35);
	string id;
	int schoolYear = 0, semester = 0, group = 0;
	
	input(id, schoolYear, semester, group, t);
	char* idSubject;
	strcpy(idSubject, id.c_str());
	PTR_CREDITCLASS temp = FindCrediClassWithCondition(l, idSubject, schoolYear, semester, group);
	
	clrscr();
		
	_getch();
	return true;
}




void MergeAll(PTR_LISTCREDITCLASS &pListCC, TREE_SUBJECT &t, LIST_STUDENT &l)
{
	while(true)
	{
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
				MainMenu(keyStatistic, sizeof(keyStatistic) / sizeof(string));
				int chosenStatistic = ChooseMainMenu(keyStatistic, sizeof(keyStatistic) / sizeof(string));
				
				switch(chosenStatistic)
				{
					case 0:
						clrscr();
						if(StatisticStudentOnCreditClassIsSucceed(pListCC, t) == false) continue;
						break;
				}
				
				
		}
		
		clrscr();
	}// while true
}// void















#endif

