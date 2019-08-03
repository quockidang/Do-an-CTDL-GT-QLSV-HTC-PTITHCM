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

//	st.yearAdmission = 2017;
//	string fistName = "dang";
//	string lastName = "ki";
//	strcmp(st.fistName, (char*)fistName.c_str());
//	strcmp(st.lastName, (char*)lastName.c_str());
	

//	STUDENT st2;
//	string id2 = "bca";
//	strcpy(st2.idStudent, (char*)id2.c_str());
//	InsertOrderForListStudent(l, st2);
//	cout << l.pHead->pNext->_student.idStudent;
	return 0;
}
