#ifndef _REGISTERSTUDENT_H
#define _REGISTERSTUDENT_H

#include "subject.h"
#include "student.h"
struct RegisterStudent {
	char idStudent[12];
	float point;
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
		if (_strcmpi(p->_registerStudent.idStudent, id) == 0)
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
		if (_strcmpi(p->_registerStudent.idStudent, id) == 0)
			return index;
	}
	return 0;
}
#endif
