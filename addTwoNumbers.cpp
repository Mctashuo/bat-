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
SNode * Add(SNode * pHead1,SNode *pHead2) {

    SNode * pSum = new SNode(0);
    SNode * pTail = pSum;
    SNode * p1 = pHead1->pNext;
    SNode * p2 = pHead2->pNext;

    int carry = 0;
    int value;

    //相加
    while(p1 && p2) {
        value = p1->value + p2->value + carry;
        carry = value / 10;
        value = value % 10;
        p1 = p1->pNext;
        p2 = p2->pNext;
        
        pTail->pNext = new SNode(value); 
        pTail = pTail->pNext;
    }


    //
    //处理较长链
    //
    
    SNode *p = p1? p1:p2;

    while(p) {
        value = carry + p->value;
        carry = value / 10;
        value = value % 10;
        
        pTail->pNext = new SNode(value);
        pTail = pTail->pNext;

        p = p->pNext;
    }

    if(carry != 0) {
        pTail->pNext = new SNode(carry);
    }
    return pSum;

}

int main() {
    SNode * pHead1 = new SNode(0);
    int i;
    for(i = 0;i < 6;i++) {
        SNode * p = new SNode(rand() % 10);
        p->pNext = pHead1->pNext;
        pHead1->pNext = p;
    }
    SNode * pHead2 = new SNode(0);

    for(i = 0;i < 9;i++) {
        SNode * p = new SNode(rand() % 10);
        p->pNext = pHead2->pNext;
        pHead2->pNext = p;
    }
    print(pHead1);
    print(pHead2);
    SNode * res = Add(pHead1,pHead2);
    print(res);
    destroy(pHead1);
    destroy(pHead2);
    destroy(res);


    return 0;
}

