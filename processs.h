#ifndef _PROCESSS_H
#define _PROCESSS_H

#include <fstream>

#include "subject.h"


//------------------------------------DATABASE------------------------------------------

//void LoadCreaditClass(PTR_CREDIT_CLASS &l)
//{
//	int SizeFlight = sizeof(FLIGHT) - sizeof(TICKET*);
//	int SizeCreditClass = sizeof(CREDIT_CLASS) - sizeof(LIST_FLIGHT);
//	fstream fileData("DSLTC.txt", ios::in | ios::binary);
//}



void WriteSubjectToFile(NODE_SUBJECT* p, fstream &file, int size) // ghi du lieu vao file
{
	if (p != NULL)
	{
		file.write(reinterpret_cast<const char*>(&p->_subject), size);
		WriteSubjectToFile(p->pLeft, file, size);
		WriteSubjectToFile(p->pRight, file, size);
	}
}

void SaveSubject(TREE_SUBJECT t)  // luu du lieu vao file
{
	fstream myfile("DSMH.txt", ios::out | ios::binary);
	myfile << nSubject;
	int sizeData = sizeof(SUBJECT);
	TREE_SUBJECT p = t;
	WriteSubjectToFile(p, myfile, sizeData);
	myfile.close();
}


void LoadSubject(TREE_SUBJECT &t)
{
	fstream myfile("DSMH.txt", ios::in | ios::binary);
	int n;
	myfile >> n;
	int sizeData = sizeof(SUBJECT);
	SUBJECT sj;
	for (int i = 0; i <= n; i++)
	{
		myfile.read(reinterpret_cast<char*>(&sj), sizeData);
		InsertSubjectToTree(t, sj);
		//todo them vao mang
		
	}
}

#endif

