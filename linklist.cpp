// linklist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

typedef struct LNode* NodePtr;
typedef NodePtr Position;
typedef NodePtr List;

struct LNode {
	int data;
	NodePtr next;
};

int length(List L)
{
	Position p = L;
	int i = 0;
	while (p)
	{
		p = p->next;
		i++;
	}
		
	return i;
}
Position find1(List L,int n)
{
	Position p = L;
	int i = 0;
	while (p&&i < n)
	{
		p = p->next;
		i++;
	}
	if (i == n)
		return p;
	else
		return NULL;
}

Position find2(List L, int x)
{
	Position p = L;
	while (p&&p->data != x)
	{
		p = p->next;
	}
	return p;
}

bool insert(List L, int X, Position P)
{
	Position temp, pre;
	for (pre = L; pre&&pre != P; pre++);
	if (!pre)
	{
		cout << "错误的插入位置" << endl;
		return false;
	}
	temp = new LNode();
	temp->data = X;
	temp->next = P;
	pre->next = temp;
	return true;
}

bool Delete(List L, Position P)
{
	Position pre;
	for (pre = L; pre&&pre != P; pre++);
	if (!pre)
	{
		cout << "错误的插入位置" << endl;
		return false;
	}
	pre->next = P->next;
	free(P);
	return true;
}



