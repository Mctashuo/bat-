#include <iostream>
using namespace std;

typedef struct tagSNode {
    int value;
    tagSNode * pNext;
    tagSNode(int v):value(v),pNext(NULL){}
}SNode;

void print(tagSNode *t) {
    while(t->pNext != NULL) {
        t = t->pNext;
        cout<<t->value<<"->";
    } 
    cout<<endl;
}

void destroy(tagSNode *t) {
    tagSNode *temp = t;
    while(t->pNext != NULL) {
        t = t->pNext; 
        delete temp;
        temp = t;
    }
}

void Reserve(SNode * head,int m,int n) {
    SNode * pHead =head->pNext;

    int len = n - m + 1;

    SNode *pre_head;
    SNode *sub_head;

    while(pHead && --m) {
        pre_head = pHead;
        pHead = pHead->pNext; 
    }

    sub_head = pHead;
    SNode * temp = NULL;
    while(len--) {
        SNode * next = pHead->pNext;
        pHead->pNext = temp;
        temp = pHead;
        pHead = pHead->pNext;
    }
    sub_head->pNext = pHead;
}

int main() {
    SNode * pHead1 = new SNode(0);
    int i;
    for(i = 0;i < 10;i++) {
        SNode * p = new SNode(rand() % 10);
        p->pNext = pHead1->pNext;
        pHead1->pNext = p;
    }
    print(pHead1);
    Reserve(pHead1,3,7);
    print(pHead1);
    destroy(pHead1);


    return 0;
}

