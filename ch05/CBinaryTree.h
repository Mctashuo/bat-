#ifndef _CBINARYTREE
#define _CBINARYTREE
#include <cstddef>
typedef struct tagStreeNode {
    int value;
    tagStreeNode * pLeft;
    tagStreeNode * pRight;
    tagStreeNode(int v):value(v),pLeft(nullptr),pRight(nullptr) {}
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
        void _PreOrder2(VISIT Visit) const;      //非
        void _InOrder(STreeNode * pRoot,VISIT Visit) const;
        void _InOrder2(VISIT Visit) const;
        void _InOrder3(VISIT Visit) const;      //记录次数
        void _PostOrder(STreeNode * pRoot,VISIT Visit) const;
        void _PostOrder2(VISIT Visit) const;

        void DeleteChildLess(STreeNode * pParent,STreeNode * pNode);    //pNode无子
        void DeleteSingleSon(STreeNode & pParent,STreeNode * pNode);    //pNode是pParent的唯一子结点
        bool _LargestBST(STreeNode *pRoot,int & nMin,int &nMax,int & count,int &nNumber,STreeNode * & pNode) const; //最大二叉搜索子树
    public:
        CBinaryTree() {m_pRoot = nullptr;}
        bool Insert(int value);
        bool Delete(int value);
        STreeNode * Find(int value) const;
        void PreOrder(VISIT Visit) const;
        void InOrder(VISIT Visit) const;
        void PostOrder(VISIT Visit) const;
        int LargestBST(STreeNode * &pNode) const;
        
        ~CBinaryTree() {}
};
#endif //_CBINARYTREE
