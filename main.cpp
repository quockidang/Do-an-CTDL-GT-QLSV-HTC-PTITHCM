#include "subject.h"
#include "processs.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "creditclass.h"
#include "student.h"
int main()
 {
	
	system("color 5A");	
	fullscreen();
	TREE_SUBJECT t;
	InitTreeSubject(t);
	LoadSubjectFormFile(t);
//	MenuSubjectManager(t);
	SaveSubjectToFile(t);

	PTR_LISTCREDITCLASS l = new LIST_CREDITCLASS;
	LoadCreditClassFromFile(l);
	//MenuManageCreditClass(l, t);
	MenuManageCreditClass(l, t);
	SaveCreditClassToFile(l);
//	LIST_STUDENT l;
//	InitListStudent(l);
//	
//	LoadStudentFromFile(l);
//	
//	
//	MenuManagerStudent(l);
//	SaveStudentToFile(l);
			                  
	return 0;
}
