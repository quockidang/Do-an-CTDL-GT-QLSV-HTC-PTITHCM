#include "subject.h"
#include "processs.h"
#include "creditclass.h"
#include "student.h"
#include<iostream>
#include <typeinfo>
#include "ScoreSubjectofClass.h"
using namespace std;
#include <Windows.h>


int main()
 {

	COORD coord;
	coord.X =2000;
	coord.Y = 500;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
	fullscreen();
	system("color 5A");
	    //ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	    	SetConsoleScreenBufferSize(handle, coord);	
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
