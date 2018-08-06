#ifndef _CBINARYTREE
#define _CBINARYTREE
#include <cstddef>
typedef struct tagStreeNode {
    int value;
    tagStreeNode * pLeft;
    tagStreeNode * pRight;
    tagStreeNode(int v):value(v),pLeft(NULL),pRight(NULL) {}
}STreeNode;

typedef void (*VISIT) (int value);

class CBinaryTree {
    private:
        STreeNode * m_pRoot;

    private:
        void Destroy(STreeNode * pRoot);
        bool _Insert(STreeNode * pRoot,int value);  //递归算法
        bool _Insert2(int value);                   //非递归算法
        void _PreOrder(STreeNode * pRoot,VISIT Visit) const;    //递归
        void _PreOrder(VISIT Visit) const;      //非


    public:
        CBinaryTree();
        bool Insert(int value);
        STreeNode * Find(int value) const;
        ~CBinaryTree();
};
#endif //_CBINARYTREE
