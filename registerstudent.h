#ifndef _REGISTERSTUDENT_H
#define _REGISTERSTUDENT_H

#include "subject.h"
#include "student.h"

struct RegisterStudent {
	char idStudent[13];
	float point = 0;
};

typedef struct RegisterStudent REGISTER_STUDENT;

struct NodeRegisterStudent{
	REGISTER_STUDENT _registerStudent;
	struct NodeRegisterStudent* pNext;
};
typedef struct NodeRegisterStudent NODE_REGISTERSTUDENT;

struct ListRegisterStudent{
	int n = 0;
	NODE_REGISTERSTUDENT *pHead, *pTail;
};
typedef struct ListRegisterStudent LIST_REGISTERSTUDENT;

NODE_REGISTERSTUDENT* GetNodeRegisterStudent(REGISTER_STUDENT data)
{
	NODE_REGISTERSTUDENT* p = new NODE_REGISTERSTUDENT;
	if(p == NULL)
		return NULL;
	p->_registerStudent = data;
	p->pNext = NULL;
	
	return p;
}

void InitListRegisterStudent(LIST_REGISTERSTUDENT &l)
{
	l.pHead = l.pTail = NULL;
}

bool ListRegisterStudentIsEmty(LIST_REGISTERSTUDENT l)
{
	return l.pHead == NULL;
}

void AddHeadListRegister(LIST_REGISTERSTUDENT &l, REGISTER_STUDENT data)
{
	NODE_REGISTERSTUDENT* p = GetNodeRegisterStudent(data);
	p->pNext = l.pHead;
	l.pHead = p;
	++l.n;
}

void AddTailListRegister(LIST_REGISTERSTUDENT &l, REGISTER_STUDENT data)
{
	NODE_REGISTERSTUDENT* p = GetNodeRegisterStudent(data);
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
	++l.n;	
}

NODE_REGISTERSTUDENT* FindRegisterStudent(LIST_REGISTERSTUDENT l, char *id)
{
	if(l.pHead == NULL) return NULL;
	for(NODE_REGISTERSTUDENT *p = l.pHead; p != NULL; p = p->pNext)
	{
		if (strcmp(p->_registerStudent.idStudent, id) == 0)
			return p;
	}
	return NULL;
}

NODE_REGISTERSTUDENT* FindRegisterStudentByOrdinal(LIST_REGISTERSTUDENT l, int ordinal)
{
	if(l.pHead == NULL) return NULL;
	if(l.n - 1 < ordinal) return NULL;
	if(l.n - 1 == ordinal) return l.pTail;
	if(ordinal == 0) return l.pHead;
	
	NODE_REGISTERSTUDENT *p = l.pHead;
	int count = 0;
	while(count != ordinal)
	{
		p = p->pNext;
		count++;
	}
	return p;
}

int FindIndexRegister(LIST_REGISTERSTUDENT l, char* id)
{
	int index = -1;
	if (l.pHead == NULL) return -1;
	for (NODE_REGISTERSTUDENT *p = l.pHead; p != NULL; p = p->pNext)
	{
		++index;
		if (strcmp(p->_registerStudent.idStudent, id) == 0)
			return index;
	}
	return 0;
}

bool ClearListRegisterStudent(LIST_REGISTERSTUDENT &l)
{
	if (l.pHead) return false;
	NODE_REGISTERSTUDENT* temp;
	while (l.pHead != NULL)
	{
		temp = l.pHead;
		l.pHead = l.pHead->pNext;
		delete temp;
	}
	return true;
}

void InsertOrderForListRegisterStudent(LIST_REGISTERSTUDENT &l, REGISTER_STUDENT data)
{
	if(l.pHead == NULL)
	{	
		AddHeadListRegister(l, data);
		return;
	}
	
	NODE_REGISTERSTUDENT *p, *pAfter, *pBefore;	
	p = GetNodeRegisterStudent(data);
	
	for(pAfter = l.pHead; pAfter != NULL && (strcmp(pAfter->_registerStudent.idStudent, data.idStudent) < 0); pBefore = pAfter, pAfter = pAfter->pNext);
	
	if(pAfter == l.pHead) 
		AddHeadListRegister(l, p->_registerStudent);
	else
	{
		p->pNext = pAfter;
		pBefore->pNext = p;
		++l.n;
	}
}

NODE_REGISTERSTUDENT* Middle_1(NODE_REGISTERSTUDENT* start, NODE_REGISTERSTUDENT* last)
{
	if (start == NULL)
		return NULL;
	NODE_REGISTERSTUDENT * slow = start;
	NODE_REGISTERSTUDENT * fast = start->pNext;

	while (fast != last)
	{
		fast = fast->pNext;
		if (fast != last)
		{
			slow = slow->pNext;
			fast = fast->pNext;
		}
	}
	return slow;
}


NODE_REGISTERSTUDENT* BinarySearchRegisterStudent(LIST_REGISTERSTUDENT l, char* id)
{
	NODE_REGISTERSTUDENT* start = l.pHead;
	NODE_REGISTERSTUDENT* last = NULL;
	if(l.pHead == NULL) return NULL;
	do
	{	
		NODE_REGISTERSTUDENT* p = Middle_1(start, last);
		
		if(p == NULL) return NULL;
		
		if (strcmp(p->_registerStudent.idStudent, id) == 0)
			return p;		
		else if (strcmp(p->_registerStudent.idStudent, id) < 0)
		{		
				
			start = p->pNext;			
		}
		else
		{	
		
			last = p;
		}
	} 
	while ( start != last);
	return NULL; // value not present;
}
#endif
