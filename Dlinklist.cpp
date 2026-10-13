#include"Dlinklist.h"
#include<iostream>
using namespace std;
//建立双链表
//头插法建立双链表
void CreateListF(DLinkNode*& L, ElemType a[], int n) {
	DLinkNode* s;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior = NULL;
	L->next = NULL;
	for (int i = 0;i < n;i++) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL) {
			L->next->prior = s;
		}
		L->next = s;
		s->prior = L;

	}

}
//尾插法建立双链表
void CreateListR(DLinkNode*& L, ElemType a[], int n) {
	DLinkNode* s, * r;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	r = L;
	for (int i = 0;i < n;i++) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	} 
	r->next = NULL;
}
//销毁双链表
void DestroyList(DLinkNode*& L) {
	DLinkNode* p = L;
	while (p != NULL) {
		L = L->next;
		free(p);
		p = L;
	}
}
//判断双链表是否为空
bool ListEmpty(DLinkNode* L) {
	if (L->next == NULL) {
		return true;
	}
	else {
		return false;
	}
}
//求双链表的长度
int ListLength(DLinkNode* L) {
	int length = 0;
	DLinkNode* p = L->next;
	while (p != NULL) {
		length++;
		p = p->next;
	}
	return length;
}
//获取双链表中第i个元素的值
bool GetElem(DLinkNode* L, int i, ElemType& e) {
	if (i < 1 || i > ListLength(L)) {
		return false;
	}
	DLinkNode* p = L->next;
	for (int j = 1; j < i; j++) {
		p = p->next;
	}
	e = p->data;
	return true;
}
//在双链表中查找值为e的元素，返回其位置
int LocateElem(DLinkNode* L, ElemType e) {
	int i = 1;
	DLinkNode* p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
		i++;
	}
	if (p == NULL) {
		return 0;
	}
	else {
		return i;
	}
}
//在双链表中第i个位置插入元素e
bool ListInsert(DLinkNode*& L, int i, ElemType e) {
	if (i < 1 || i > ListLength(L) + 1) {
		return false;
	}
	DLinkNode* p = L;
	for (int j = 1; j < i; j++) {
		p = p->next;
	}
	DLinkNode* s = (DLinkNode*)malloc(sizeof(DLinkNode));
	s->data = e;
	s->next = p->next;
	if (p->next != NULL) {
		p->next->prior = s;
	}
	p->next = s;
	s->prior = p;
	return true;
}
//在双链表中删除第i个位置的元素，并用e返回其值
bool ListDelete(DLinkNode*& L, int i, ElemType& e) {
	if (i < 1 || i > ListLength(L)) {
		return false;
	}
	DLinkNode* p = L;
	for (int j = 1; j < i; j++) {
		p = p->next;
	}
	e = p->data;
	p->prior->next = p->next;
	if (p->next != NULL) {
		p->next->prior = p->prior;
	}
	free(p);
	return true;
}
//遍历双链表
void ListTraverse(DLinkNode* L, void(*visit)(ElemType& e)) {
	DLinkNode* p = L->next;
	while (p != NULL) {
		visit(p->data);
		p = p->next;
	}
}
