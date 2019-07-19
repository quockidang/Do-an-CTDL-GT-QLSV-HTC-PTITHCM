#ifndef _STUDENT_H
#define _STUDENT_H
#include"Subject.h"

struct student{
	char idStudent[12];
	char idClass[15];
	char fistName[20], lastName[20];
	int sex = 1; // 1 male, 2 female
	char phoneNumber[15];
	int yearAdmission; // nam nhap hoc
};
typedef struct student STUDENT;

struct NodeStudent{
	STUDENT data;
	struct NodeStudent *pNext;
};
typedef struct NodeStudent NODE_STUDENT;

struct ListStudent{
	int n = 0;
	NODE_STUDENT *pHead, *pTail;
};
typedef struct ListStudent LIST_STUDENT;

// get node student -- lay dia chi cua mot sinh vie
NODE_STUDENT* GetNodeStudent(STUDENT DATA)
{
	NODE_STUDENT *p = new NodeStudent; //init pointer
	if (p == NULL)
		return NULL;
	p->data = DATA; // export data to node;
	p->pNext = NULL; //init link list
	return p;
}

// init List student -- khoi tao danh sach sinh vien
void InitListStudent(LIST_STUDENT &l)
{
	l.pHead = l.pTail = NULL;
}

// check list rong
bool ListStudentIsEmty(LIST_STUDENT l)
{
	return l.pHead == NULL;
}

// Them vao dau danh sach -- add head list student

void AddHeadListStudent(LIST_STUDENT &l, STUDENT data)
{
	NODE_STUDENT* p = GetNodeStudent(data);
	
	p->pNext = l.pHead;
	l.pHead = p;
	++l.n;
}

// add tail list student
void AddTailListStudent(LIST_STUDENT &l, STUDENT data)
{
	NODE_STUDENT* p = GetNodeStudent(data);
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
	
	++l.n;
}

// tim kiem voi maSV
NODE_STUDENT* FindStudent(LIST_STUDENT l, char* id)
{
	if(l.pHead == NULL) return NULL;
	for(NODE_STUDENT* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (_strcmpi(p->data.idStudent, id) == 0)
			return p;
	}
	return NULL;
}

// tim index cua sinh vien
int FindIndexStudent(LIST_STUDENT l, char *id)
{
	int index = -1;
	if(l.pHead == NULL) return -1;
	for(NODE_STUDENT *p = l.pHead; p != NULL; p = p->pNext)
	{
		++index;
		if(_strcmpi(p->data.idStudent, id) == 0);
			return index;
	}
	return 0;
}


// insert apter - them vao sau
void InsertAfter(NODE_STUDENT* p, STUDENT &data)
{
	if(p == NULL) return;
	NODE_STUDENT* q = new NODE_STUDENT;
	
	q->data = data;
	q->pNext = p->pNext;
	p->pNext = q;
}

// xoa dau - delete head
bool IsDeletedHead(LIST_STUDENT &l)
{
	if(ListStudentIsEmty(l)) return false;
	NODE_STUDENT *p =l.pHead; 
	
	l.pHead = p->pNext;
	delete p;
	--l.n;
	return true;
}


// delete tail -- xoa cuoi
bool IsDeletedTail(LIST_STUDENT &l)
{
	if(ListStudentIsEmty(l)) return false;
	
	NODE_STUDENT *beforeP = NULL;
	for (NODE_STUDENT *p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p == l.pTail)
		{
			l.pTail = beforeP;
			beforeP->pNext = NULL;
			delete p;
			--l.n;
			return true;
		}
		beforeP = p;
	}
}

// delete after node p
bool IsDeletedAfter(LIST_STUDENT &l, NODE_STUDENT*p)
{
	if (p == NULL || p->pNext == NULL) return false;
	NODE_STUDENT* nodeDeleted = p->pNext;
	p->pNext = nodeDeleted->pNext;
	delete nodeDeleted;
	--l.n;
	return true;
}

// delete with id Student
bool IsDeletedStudentWithId(LIST_STUDENT &l, STUDENT data)
{
	NODE_STUDENT* nodeDeleted = FindStudent(l, data.idStudent);
	if (nodeDeleted == NULL) return false;
	if (nodeDeleted == l.pHead) return IsDeletedHead(l);
	if (nodeDeleted == l.pTail) return IsDeletedTail(l);
	else
	{
		NODE_STUDENT* temp = l.pHead;
		while (temp->pNext != nodeDeleted)
			temp = temp->pNext;
		return IsDeletedAfter(l,temp);
	}
}

// xoa danh sach Sinh vien
bool ClearListStudent(LIST_STUDENT &l)
{
	if (l.pHead) return false;
	NODE_STUDENT* temp;
	while (l.pHead != NULL)
	{
		temp = l.pHead;
		l.pHead = l.pHead->pNext;
		delete temp;
	}
	return true;
}

void inputStudent()
#endif

