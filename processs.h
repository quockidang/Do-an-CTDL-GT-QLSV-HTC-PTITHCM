#ifndef _PROCESSS_H
#define _PROCESSS_H

#include <fstream>

#include "subject.h"
#include "student.h"

//------------------------------------DATABASE------------------------------------------
void Save(TREE_SUBJECT t, fstream &file)
{
	file << t->_subject.idSubject << endl;
	file << t->_subject.nameSubject << endl;
	file << t->_subject.numberPractice << endl;
	file << t->_subject.numberTheory << endl;
}

void WriteSubjectToFile(TREE_SUBJECT t, fstream &file)
{
	if (t != NULL)
	{
		Save(t, file);
		WriteSubjectToFile(t->pLeft, file);
		WriteSubjectToFile(t->pRight, file);	
	}
}

void SaveSubjectToFile(TREE_SUBJECT t)
{
	fstream outFile;
	outFile.open("DSMH.txt", ios::out);
	if (outFile.is_open())
	{
		// so doc gia..
		outFile << nSubject << endl;
		WriteSubjectToFile(t, outFile);
	}
	else
	{
		cout << "KET NOI VOI FILE DSMH THAT BAI! ";
	}
	outFile.close();
}

void LoadSubjectFormFile(TREE_SUBJECT &t)
{
	fstream inFile;
	SUBJECT sj;
	int n;
	inFile.open("DSMH.txt", ios::in);
	if (inFile.is_open())
	{
		string temp;		
		inFile >> n;
		
		for(int i = 0; i <= n; i++)
		{
			getline(inFile, temp);
			inFile.getline(sj.idSubject, 10, '\n');
			inFile.getline(sj.nameSubject, 30, '\n');
			inFile >> sj.numberPractice;
			inFile >> sj.numberTheory;
			
			InsertSubjectToTree(t, sj);
		}
	}
	else {
		cout << "KET NOI VOI FILE DSMH THAT BAI! ";
	}

	inFile.close();
}
#endif

