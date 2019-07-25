#include "subject.h"
#include "processs.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "creditclass.h"
#include "student.h"
int main()
 {
	
	system("color 5A");	
//	fullscreen();
	TREE_SUBJECT t;
	InitTreeSubject(t);
//	LoadSubjectFormFile(t);
//	MenuSubjectManager(t);
//	SaveSubjectToFile(t);
	
	SUBJECT sj;
	
	string id = "mh0123";
	
	string name = "ctdl&gt";
	//sj.idSubject = "mh0123";
	//sj.nameSubject ="ctdl&gt";
	strcpy(sj.idSubject, id.c_str());
	strcpy(sj.nameSubject, name.c_str());
	sj.numberPractice =1;
	sj.numberTheory = 3;
	InsertSubjectToTree(t, sj);
	
	TREE_SUBJECT temp;
	temp = FindSubject(t, strcpy(sj.idSubject, id.c_str()));
	cout << temp->_subject.idSubject;
	
//	PTR_LISTCREDITCLASS l = new LIST_CREDITCLASS;
	//MenuManageCreditClass(l)
			                  
	return 0;
}
