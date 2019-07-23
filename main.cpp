#include "subject.h"
#include "processs.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
 {
	
	system("color 5A");	
	fullscreen();
	TREE_SUBJECT t;
	InitTreeSubject(t);
	LoadSubjectFormFile(t);
	MenuSubjectManager(t);
	SaveSubjectToFile(t);
	
			                  
	return 0;
}
