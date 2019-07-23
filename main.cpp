#include "creditclass.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
 {
	
	system("color 5A");
//	
	fullscreen();
//	TREE_SUBJECT t;
//	InitTreeSubject(t);
	
//	SUBJECT sj;
//	string id = "int123";
//	string name = " ctdl&gt";
//	strcpy(sj.idSubject, id.c_str());
//	strcpy(sj.nameSubject, name.c_str());
//	sj.numberPractice = 1;
//	sj.numberTheory = 4;
//	InsertSubjectToTree(t, sj);
	//cout << arrSubject[0]->idSubject;
//	LoadSubjectFormFile(t);
//	MenuSubjectManager(t);
//	SaveSubjectToFile(t);
//	LIST_STUDENT l;
//	InitListStudent(l);
//	MenuManagerStudent(l);
//	NODE_SUBJECT* p =	FindSubject(t, arrSubject[0]->idSubject);
//	cout << p->_subject.idSubject;
//	OutputListSubjectPerPage(t, 0);

	PTR_LISTCLASS l = new LISTCLASS;
	MenuManageCreditClass(l);
			                  
	return 0;
}
