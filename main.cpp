#include "subject.h"
#include "processs.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "creditclass.h"
#include "student.h"
#include<iostream>
using namespace std;
int main()
 {
	
	system("color 5A");	
	fullscreen();
	
	PTR_LISTCREDITCLASS listCC = new LIST_CREDITCLASS;
	LoadCreditClassFromFile(listCC);
	
	TREE_SUBJECT t;
	InitTreeSubject(t);
	LoadSubjectFormFile(t);
	
	LIST_STUDENT l;
	InitListStudent(l);
	LoadStudentFromFile(l);
	//MenuManageCreditClass(listCC, t);
	//MenuManagerStudent(l);
	MergeAll(listCC, t, l);
	
	SaveCreditClassToFile(listCC);
	SaveStudentToFile(l);
	SaveSubjectToFile(t);
////     	int a = 10;
////     	int c = 9;
////     	float b = a + ((float)c / 10);
//	cout << b;

//	LIST_STUDENT l;
//	InitListStudent(l);
//	STUDENT st;
////	st.yearAdmission = 2017;
////	string fistName = "dang";
////	string lastName = "ki";
////	strcmp(st.fistName, (char*)fistName.c_str());
////	strcmp(st.lastName, (char*)lastName.c_str());
//	
//	string idStudent = "cda";
//	strcpy(st.idStudent, (char*)idStudent.c_str());
//	InsertOrderForListStudent(l, st);
//	
//	//cout << l.pHead->_student.idStudent;
//	STUDENT st1;
//	string idStudent1 = "abc";
//	strcpy(st1.idStudent, (char*)idStudent1.c_str());
//	InsertOrderForListStudent(l, st1);
//	
//	STUDENT st2;
//	string id2 = "bca";
//	strcpy(st2.idStudent, (char*)id2.c_str());
//	InsertOrderForListStudent(l, st2);
//	cout << l.pHead->pNext->_student.idStudent;
	return 0;
}
