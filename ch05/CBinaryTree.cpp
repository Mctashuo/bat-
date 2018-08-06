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
//二叉查找树的插入,递归算法
bool CBinaryTree::_Insert(STreeNode * pRoot,int value) {
    if(!pRoot) {
        pRoot = new STreeNode(value);
        return true;
    }
    else {
        if(value < pRoot->value) 
            return _Insert(pRoot->pLeft,value);
        else if(value > pRoot->value) 
            return _Insert(pRoot->pRight,value);
    }
    return false;
        
}
//二叉查找树的插入非递归算法
//
bool CBinaryTree::_Insert2(int value) {
    if(!m_pRoot) {
        m_pRoot = new STreeNode(value);
        return true;
    }else {
        STreeNode * pNode = m_pRoot;
        while(pNode) {
            if(value < pNode->value) 
                pNode = pNode->pLeft;
            else if(value > pNode->value) 
                pNode = pNode->pRight;
            else 
                return false;
        }
        pNode = new STreeNode(value);
        return true;
    }
    return false;
}
bool CBinaryTree::Insert(int value) {
    return _Insert2(value);
}
