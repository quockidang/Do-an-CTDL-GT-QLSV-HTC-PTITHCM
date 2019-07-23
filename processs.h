#ifndef _PROCESSS_H
#define _PROCESSS_H

#include <fstream>


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

// -------------- DSSV----------------------------

void SaveStudent(STUDENT st, fstream &file)
{
	file << st.idClass << endl;
	file << st.idStudent << endl;
	file << st.fistName << endl;
	file << st.lastName << endl;
	file << st.phoneNUmber << endl;
	file << st.yearAdmission << endl;
	file << st.sex << endl;
	
}


void SaveStudentToFile(LIST_STUDENT l)
{
	fstream outFile;
	outFile.open("DSSV.txt", ios::out);
	if (outFile.is_open())
	{
		outFile << l.n << endl;
		// so doc gia..
		for(NODE_STUDENT* k = l.pHead; k != NULL; k = k->pNext)
		{
			SaveStudent(k->_student, outFile);
		}
	}
	else
	{
		cout << "KET NOI VOI FILE DSMH THAT BAI! ";
	}
	outFile.close();
}

void LoadStudentFromFile(LIST_STUDENT &l)
{
	fstream inFile;
	STUDENT st;
	int n;
	inFile.open("DSSV.txt", ios::in);
	if (inFile.is_open())
	{
		string temp;		
		inFile >> n;
		
		for(int i = 0; i < n; i++)
		{
			getline(inFile, temp);
			inFile.getline(st.idClass, 15, '\n');
			inFile.getline(st.idStudent, 12, '\n');
			inFile.getline(st.fistName, 10, '\n');
			inFile.getline(st.lastName, 20, '\n');
			inFile.getline(st.phoneNUmber, 12, '\n');
			inFile >> st.yearAdmission;
			inFile >> st.sex;
			
			AddTailListStudent(l, st);
		}
	}
	else {
		cout << "KET NOI VOI FILE DSMH THAT BAI! ";
	}

	inFile.close();
}

#endif

