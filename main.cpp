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
//     	int a = 10;
//     	int c = 9;
//     	float b = a + ((float)c / 10);
//	cout << b;
	return 0;
}
