#ifndef DLINKLIST_H
#define DLINKLIST_H
typedef int ElemType;
typedef struct DNode
{
	ElemType data;
	struct Dnode* prior;
	struct Dnode* next;
}DLinkNode;
//建立双链表
//头插法建立双链表
void CreateListF(DLinkNode*& L, ElemType a[], int n);
//尾插法建立双链表
void CreateListR(DLinkNode*& L, ElemType a[], int n);
//销毁双链表
void DestroyList(DLinkNode*& L);
//判断双链表是否为空
bool ListEmpty(DLinkNode* L);
//求双链表的长度
int ListLength(DLinkNode* L);
//获取双链表中第i个元素的值
bool GetElem(DLinkNode* L, int i, ElemType& e);
//在双链表中查找值为e的元素，返回其位置
int LocateElem(DLinkNode* L, ElemType e);
//在双链表中第i个位置插入元素e
bool ListInsert(DLinkNode*& L, int i, ElemType e);
//在双链表中删除第i个位置的元素，并用e返回其值
bool ListDelete(DLinkNode*& L, int i, ElemType& e);
//遍历双链表
void ListTraverse(DLinkNode* L, void(*visit)(ElemType& e));

#endif
