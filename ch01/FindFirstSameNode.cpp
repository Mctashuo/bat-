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

int CalculatorLength(SNode * head) {
    int count = 0;
    while(head) {
        count++;
        head = head->pNext;
    }
    return count;
}
int FindFirstSameNode(SNode * head1,SNode * head2) {
    int p1Len = CalculatorLength(head1->pNext);
    int p2Len = CalculatorLength(head2);
    
    SNode * p1 = head1->pNext;
    SNode * p2 = head2;

    int len = p1Len - p2Len;
    
    if(p1Len < p2Len) {
        SNode * temp = p1;
        p1 = p2;
        p2 = temp;
        len = -len;
    }
    while(len--) {
        p1 = p1->pNext;
    }

    while(p1) {
        if(p1 == p2) 
            return p1->value;

        p1 = p1->pNext;
        p2 = p2->pNext;
    }

    return 0;


}

int main() {
    SNode * head = new SNode(0);
    int data[] = {2,3,3,5,7,8,8,8,9,9,30};
    int size = sizeof(data) / sizeof(int);
    for(int i = 10;i >= 0;i--) {
        SNode * p = new SNode(data[i]);
        p->pNext = head->pNext;
        head->pNext = p;
    }
    SNode * head2;
    head2 = head->pNext->pNext->pNext;
    print(head);
    print(head2);
    cout<<FindFirstSameNode(head,head2)<<endl;
    destory(head);
    return 0;
}
