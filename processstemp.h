#ifndef _PROCESSSTEMP_H
#define _PROCESSSTEMP_H
#include "creditclass.h"
#include "subject.h"
#include <sstream>
// regsiter credit class  
void inputDataFindCreditClass(int &schoolYear, int &semester, string &idStudent, LIST_STUDENT l) // input data
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

// end register credit class

// output list student on register redit class
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


// end output list student on register credit class

// input score for student register credit class
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
		
		counts++;
		if(counts == indexBegin)
		{
			int i = -1; 
			while (q != NULL && i < QUANTITY_PER_PAGE - 1)
			{
				NODE_STUDENT* p = FindStudent(ls, q->_registerStudent.idStudent);
				outputScoreCretdiClass(p->_student, q->_registerStudent, (++i) * 2);
				q = q->pNext;
			}
			break;
		}
	}
	
	Gotoxy(X_PAGE, Y_PAGE);
	cout << "Trang " << pageNowStudent << "/" << totalPageStudent;
	
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

bool Check_STN(string s)
{
	bool flag = true;
	for(int i = 0; i< s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9' )
		{
			flag = true;
		}else
		{
			flag = false;
			break;
		}
	}
	return flag;
}

bool isFloat( string myString ) {
    std::istringstream iss(myString);
    float f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail(); 
}
void  inputScoreCreditClass(LIST_REGISTERSTUDENT &lrs, REGISTER_STUDENT &rs) // nhap  Lop TC
{	
backMenu:	
	string res;
	fflush(stdin);
	Gotoxy(X_ADD + 26, Y_ADD);
	getline(cin, res);
			
	if(isFloat(res))
	{
		rs.point = atof((char*)res.c_str());				
		NODE_REGISTERSTUDENT* rsx = FindRegisterStudent(lrs, rs.idStudent);
		rsx->_registerStudent = rs;
		return;
	}else
	{
		Gotoxy(X_NOTIFY, Y_NOTIFY); cout << "diem khong hop le";
		Gotoxy(X_ADD + 26, Y_ADD);
		cout << setw(8) << setfill(' ') << " ";
		goto backMenu;
	}
		
			

	
}	
 // end input score




//  output score subject of class
float MediumScoreOfStudent(PTR_LISTCREDITCLASS lcc, TREE_SUBJECT t, char* idStudent)
{
	float totalScore = 0;
	int totalCredit = 0;
	for(int i = 0; i <= lcc->n; i++)
	{
		NODE_REGISTERSTUDENT* p = BinarySearchRegisterStudent(lcc->listCreditClass[i]->listRegisterStudent, idStudent);
		if(p == NULL)continue;
		else{
			
			if(p->_registerStudent.point != -1)
			{
				NODE_SUBJECT* q = FindSubject(t, lcc->listCreditClass[i]->idSubject);				
				totalCredit += q->_subject.numberPractice + q->_subject.numberTheory;
				totalScore += p->_registerStudent.point * (q->_subject.numberPractice + q->_subject.numberTheory);
			}			
		}
	}
	return (totalScore / (float)totalCredit);
}

void outputMediumScoreOfStudent(STUDENT _student, int ordinal)
{		
	DeleteOldData(sizeof(keyDisplayInputScoreCreditClass) / sizeof(string), ordinal);
	Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 3 + ordinal); cout << _student.idStudent;
	Gotoxy(xKeyDisplay[1] + 1, Y_DISPLAY + 3 + ordinal); cout << _student.fistName;
	Gotoxy(xKeyDisplay[2] + 1, Y_DISPLAY + 3 + ordinal); cout << _student.lastName;
	Gotoxy(xKeyDisplay[3] + 1, Y_DISPLAY + 3 + ordinal); cout << _student.mediumScore;
	Gotoxy(xKeyDisplay[4] + 1, Y_DISPLAY + 3 + ordinal); cout << ordinal / 2;
}

void outputMediumScoreOfStudentPerPage(LIST_STUDENT ls, int indexBegin)
{
	if(ls.n == 0) return;
	int counts = -1;
	
	for(NODE_STUDENT* q = ls.pHead; q != NULL; q = q->pNext)
	{
		counts++;
		if(counts == indexBegin)
		{
			int i = -1; 
			while (q != NULL && i < QUANTITY_PER_PAGE - 1)
			{
				outputMediumScoreOfStudent(q->_student, (++i) * 2);
				q = q->pNext;
			}
			break;
		}
	}
	
	Gotoxy(X_PAGE, Y_PAGE);
	cout << "Trang " << pageNowStudent << "/" << totalPageStudent;
	
}

void ChangePageManageStudent_1(LIST_STUDENT l, string idClass, int schoolYear)
{
	clrscr();
	Gotoxy(X_TITLE, Y_TITLE); cout << "BANG THONG KE DIEM TRUNG BINH KHOA HOC";
	Gotoxy(X_TITLE + 2, Y_TITLE + 1); cout << "Lop: " << idClass << "  - Nam nhap hoc: " << schoolYear ;
	outputMediumScoreOfStudentPerPage(l, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
	Display(keyDisplayInputScoreCreditClass, sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));
	DeleteNote(sizeof(keyDisplayInputScoreCreditClass) / sizeof(string));
}
// ---- end

// output score of credit class
void outputListScoreCreditClassPerPage1(LIST_REGISTERSTUDENT lrs, LIST_STUDENT ls, int indexBegin)
{
	
	if(ls.n == 0) return;
	int counts = -1;
	
	for(NODE_STUDENT* q = ls.pHead; q != NULL; q = q->pNext)
	{
		
		counts++;
		if(counts == indexBegin)
		{
			int i = -1; 
			while (q != NULL && i < QUANTITY_PER_PAGE - 1)
			{
				NODE_REGISTERSTUDENT* p = FindRegisterStudent(lrs, q->_student.idStudent);
				outputScoreCretdiClass(q->_student, p->_registerStudent, (++i) * 2);
				q = q->pNext;
			}
			break;
		}
	}
	
	Gotoxy(X_PAGE, Y_PAGE);
	cout << "Trang " << pageNowStudent << "/" << totalPageStudent;
	
}

//end


#endif

