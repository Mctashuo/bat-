#include <iostream>
using namespace std;

typedef struct tagSNode {
    int value;
    tagSNode * pNext;
    tagSNode(int v):value(v),pNext(NULL){}

}SNode;

void destory(SNode * head) {
    SNode * temp;
    while(head) {
        temp = head->pNext;
        delete head;
        head = temp;
    }
}

void print(SNode * head) {
    while(head) {
        cout<<head->value<<"->";
        head = head->pNext;
    }
    cout<<endl;
}

void Partition(SNode * head,int val) {
    SNode * p1 = new SNode(0);
    SNode *p2 = new SNode(0);
    SNode *p1Head = p1;
    SNode *p2Head = p2;
    SNode * pHead = head->pNext;

    while(pHead) {
        if(pHead->value >= val) {
            p2->pNext = pHead; 
            p2 = p2->pNext;
        }else {
            p1->pNext = pHead;
            p1 = p1->pNext;
        }
        pHead = pHead->pNext;
    }
    p1->pNext = p2Head->pNext;
    p2->pNext = NULL;
    head->pNext = p1Head->pNext;
    delete p1Head;
    delete p2Head;

}
int main() {
    SNode * head = new SNode(0);
    //int data[] = {2,3,3,5,7,8,8,8,9,9,30};
    //int size = sizeof(data) / sizeof(int);
    for(int i = 10;i >= 0;i--) {
        SNode * p = new SNode(rand() % 10);
        p->pNext = head->pNext;
        head->pNext = p;
    }
    print(head);
    Partition(head,5);
    print(head);
    destory(head);
    return 0;
}
