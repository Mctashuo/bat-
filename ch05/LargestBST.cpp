#include "CBinaryTree.h"
#include <iostream>
#include <ctime>
void PrintValue(int);
void ChangeValue(int);

int main() {
    CBinaryTree tree;
    srand(time(NULL));
    for(int i=0;i < 10;i++) {
        int temp = rand() % 100;
        tree.Insert(temp);
    
    }
    std::cout<<std::endl;
    /*
    tree.Insert(15);
    tree.Insert(16);
    tree.Insert(20);
    tree.Insert(18);
    tree.Insert(23);
    tree.Insert(5);
    tree.Insert(12);
    tree.Insert(3);
    tree.Insert(10);
    tree.Insert(13);
    tree.Insert(6);
    tree.Insert(7);

    */
    tree.InOrder(PrintValue);
    std::cout<<std::endl;

    tree.PreOrder(PrintValue);
    std::cout<<std::endl;

    STreeNode * pNode;
    int nLargestNumber = tree.LargestBST(pNode);
    std::cout<<pNode->value<<'\t'<<nLargestNumber<<std::endl;


    return 0;
}
void PrintValue(int value) {
    std::cout<<value<<'\t';
}
