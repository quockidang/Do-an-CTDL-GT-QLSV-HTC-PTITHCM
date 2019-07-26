#include "subject.h"
#include "processs.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "creditclass.h"
#include "student.h"
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
	
	
	MergeAll(listCC, t, l);
	
	SaveCreditClassToFile(listCC);
	SaveStudentToFile(l);
	SaveSubjectToFile(t);
		                  
	return 0;
}
