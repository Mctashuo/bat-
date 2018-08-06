#include"CBinaryTree.H"

CBinaryTree::CBinaryTree() {

}

CBinaryTree::~CBinaryTree() {

}


//二叉查找树
//左子树上的所有结点值均小于根结点值
//右子树上的所有结点值均大于根结点值
//左右子树也满足以上条件
STreeNode * CBinaryTree::Find(int value) const {
    if(!m_pRoot)
        return NULL;
    STreeNode * pNode = m_pRoot;
    while(pNode) {
        if(value > pNode->value) {
            pNode = pNode->pRight;
        }else if(value < pNode->value) 
            pNode = pNode->pLeft;
        else 
            return pNode;
    }    
    return NULL;
}
