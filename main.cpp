#include "processs.h"
#include "subject.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
 {
	
	system("color 5A");
	
	fullscreen();
		
	TREE_SUBJECT t;
	InitTreeSubject(t);
	//LoadSubject(t);
	
	
	MenuSubjectManager(t);
	
	//Display(keyDisplaySubject, sizeof(keyDisplaySubject) / sizeof(string));	
//	QuickSort(0, 4, keyDisplaySubject);
//	for(int i =0;i<5;i++)
//	{
//		cout << keyDisplaySubject[i]<<endl;
//	}
	return 0;
}
