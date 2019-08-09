#include "subject.h"
#include "processs.h"
#include "creditclass.h"
#include "student.h"
#include<iostream>
#include <typeinfo>
using namespace std;


int main()
 {
	system("color 5A");	
	fullscreen();	
	PTR_LISTCREDITCLASS listCC = new LIST_CREDITCLASS;
	TREE_SUBJECT t;
	LIST_STUDENT l;
	
	InitTreeSubject(t);
	InitListStudent(l);
	
	LoadCreditClassFromFile(listCC);	
	LoadSubjectFormFile(t);
	LoadStudentFromFile(l);
	
	MergeAll(listCC, t, l);	
	
	SaveCreditClassToFile(listCC);
	SaveStudentToFile(l);
	SaveSubjectToFile(t);

	return 0;
}
