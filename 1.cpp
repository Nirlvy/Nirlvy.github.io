#include <iostream>
#include <malloc.h>

using namespace std;

#define ElemType int

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    printf("请输入数据：");
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        printf("请输入数据：");
        scanf("%d", &x);
    }
    return L;
}

LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    printf("请输入数据：");
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        printf("请输入数据：");
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

LNode *GetElem(LinkList L, int i)
{
    int j = 1;
    LNode *p = L->next;
    if (i == 0)
    {
        return L;
    }
    if (i < 1)
    {
        return NULL;
    }
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

int main()
{
    while (1)
    {
        int choice;
        LinkList list;
        cout << "请输入选择 1:头插法 2:尾插法 3:按序号查找 4:按值查找 5:插入节点";
        cin >> choice;
        if (choice == 1)
        {
            list = NULL;
            list = List_HeadInsert(list);
            cout << "L:" << list << endl;
        }
        else if (choice == 2)
        {
            list = NULL;
            cout << "L:" << List_TailInsert(list) << endl;
        }
        else if (choice == 3)
        {
            int node;
            cout << "请输入需要查找的节点:" << endl;
            cin >> node;
            cout << "结果为:" << GetElem(list, node) << endl;
        }
    }

    return 0;
}