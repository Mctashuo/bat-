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

void deleteDuplicaNode(SNode * head) {
    SNode * pHead = head->pNext;
    SNode * pre = head;

    bool flag;
    while(pHead) {
        SNode * temp = pHead->pNext;
        flag = false;
        while(temp && pHead->value == temp->value) {
            delete pHead;
            pHead = temp;
            temp = temp->pNext;
            flag  = true;
        }
        if(flag) {
            pHead = temp->pNext;
            pre->pNext = pHead;
            delete temp;
        }
        else {
            pHead = temp;
            pre = pre->pNext;
        }
    }
}
int main() {
    SNode * head = new SNode(0);
    int data[] = {2,3,3,5,7,8,8,8,9,9,30};
    int size = sizeof(data) / sizeof(int);
    for(int i = size-1;i >= 0;i--) {
        SNode * p = new SNode(data[i]);
        p->pNext = head->pNext;
        head->pNext = p;
    }
    print(head);
    deleteDuplicaNode(head);
    print(head);
    destory(head);
    return 0;
}
