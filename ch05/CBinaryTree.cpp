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


//删除算法
//分三种情况处理,
//p为叶子结点
//p为单支结点
//p的左子树和右子树均不空
//
void CBinaryTree::DeleteChildLess(STreeNode * pParent,STreeNode * pNode) {
    if(m_pRoot == pParent) {
        m_pRoot = NULL;
    }else if(pParent->pLeft == pNode) 
        pParent->pLeft = NULL;
    else if(pParent->pRight == pNode)
       pParent->pRight = NULL; 
    delete pNode;
}
//删除单支结点
void CBinaryTree::DeleteSingleSon(STreeNode & pParent,STreeNode * pNode) {
    //找pNode的子结点
    STreeNode * pSub;
    if(pNode->pLeft != NULL)
        pSub=pNode->pLeft;
    else
        pSub = pNode->pRight;
    if(pParent.pLeft == pNode) {
        pParent.pLeft = pSub;
    }
    else 
        pParent.pRight = pSub;
    delete pNode;

    
}

//根据值删除结点
bool CBinaryTree::Delete(int value) {
    STreeNode * pNode = m_pRoot;
    STreeNode * pParent = pNode;
    while(pNode) {
        if(value < pNode->value) {
           pParent = pNode;
           pNode = pNode->pLeft; 
        }else if(value > pNode->value) {
            pParent = pNode;
            pNode = pNode->pRight;
        } else 
            break; 
    }

    if(!pNode) 
        return false;

    if(pNode->pLeft == NULL && pNode->pRight ==NULL) {
        DeleteChildLess(pParent,pNode);
        return true;
    }else if(pNode->pLeft == NULL || pNode->pRight == NULL) {
        DeleteSingleSon(*pParent,pNode);
        return true;
    }
    else {
        STreeNode *pCur = pNode;        
        while(pNode) {
            pParent = pNode;
            pNode= pNode->pLeft;
        }

        pCur->value = pNode->value;
        if(pNode->pRight)
            DeleteSingleSon(*pParent,pNode);
        else
            DeleteChildLess(pParent,pNode);
        return true;
    }
    
}
