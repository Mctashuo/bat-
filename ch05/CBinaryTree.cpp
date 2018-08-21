#include"CBinaryTree.h"
#include <stack>
#include <climits>


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
        STreeNode * pCur = m_pRoot;
        while(pNode) {
            pCur = pNode;
            if(value < pNode->value) 
                pNode = pNode->pLeft;
            else if(value > pNode->value) 
                pNode = pNode->pRight;
            else 
                return false;
        }
        if(value > pCur->value) {
            pCur->pRight = new STreeNode(value);
        
        }else if(value < pCur->value) {
            pCur->pLeft = new STreeNode(value);
        }
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
    //查找
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

    //分情况
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

void CBinaryTree::PreOrder(VISIT Visit) const {
    _PreOrder2(Visit);
}

void CBinaryTree::_PreOrder(STreeNode * pRoot,VISIT Visit) const {
    Visit(pRoot->value);
    _PreOrder(pRoot->pLeft,Visit);
    _PreOrder(pRoot->pRight,Visit);
}

void CBinaryTree::_PreOrder2(VISIT Visit) const {
    if(!m_pRoot) {
        return;
    } 
    std::stack<STreeNode *> s;
    s.push(m_pRoot);
    STreeNode * pCur = m_pRoot;
    while(!s.empty()) {
        pCur = s.top();
        s.pop();
        Visit(pCur->value);
        if(pCur->pRight)
            s.push(pCur->pRight);
        if(pCur->pLeft)
            s.push(pCur->pLeft);
    }
}


void CBinaryTree::InOrder(VISIT Visit) const {
    _InOrder2(Visit);
}
void CBinaryTree::_InOrder(STreeNode * pRoot,VISIT Visit) const {
    _InOrder(pRoot->pLeft,Visit);
    Visit(pRoot->value);
    _InOrder(pRoot->pRight,Visit);
}

void CBinaryTree::_InOrder2(VISIT Visit) const {
    if(!m_pRoot) {
        return;
    } 
    std::stack<STreeNode *> s;
    STreeNode * pCur = m_pRoot;
    while(pCur || !s.empty()) {
        //找最左节点
        while(pCur) {
            s.push(pCur);
            pCur = pCur->pLeft;
        }


        if(!s.empty()) {
            pCur = s.top();
            s.pop();
            Visit(pCur->value);
            pCur = pCur->pRight;

        }
    }
}
void CBinaryTree::_InOrder3(VISIT Visit) const {
    if(!m_pRoot)
        return;
    std::stack <std::pair<STreeNode *,int>> s;
    s.push(std::make_pair(m_pRoot,0));
    STreeNode * pCur;
    int time;
    while(!s.empty()) {
        pCur = s.top().first;
        time = s.top().second;
        if(0 == time) { //第一次压栈
            if(pCur->pRight)    //结点存在右结点,先保存
                s.push(std::make_pair(pCur->pRight,0));     
            s.push(std::make_pair(pCur,1)); //第二次压栈
            if(pCur->pLeft)
                s.push(std::make_pair(pCur->pLeft,0));      //后进先出,先访问左结点
        }else {
            Visit(pCur->value);
        }
    }
}
void CBinaryTree::PostOrder(VISIT Visit) const{
    _PreOrder2(Visit);
}
void CBinaryTree::_PostOrder(STreeNode *pRoot,VISIT Visit) const{
    _PreOrder(pRoot->pLeft,Visit);
    _PreOrder(pRoot->pRight,Visit);
    Visit(pRoot->value);
     
}

void CBinaryTree::_PostOrder2(VISIT Visit) const {
    if(!m_pRoot) 
        return;
    std::stack <std::pair<STreeNode *,int>> s;
    s.push(std::make_pair(m_pRoot,0));

    STreeNode * pCur;
    int time;
    while(!s.empty()) {
        pCur = s.top().first;
        time = s.top().second;
        s.pop();
        if(0 == time) {
            s.push(std::make_pair(pCur,1));
            if(pCur->pRight)
                s.push(std::make_pair(pCur->pRight,0));
            if(pCur->pLeft)
                s.push(std::make_pair(pCur->pLeft,0));
        }else {
            Visit(pCur->value);
        }
    }
}
//count记录总最大结点数,nNmuber记录当前的节点数
bool CBinaryTree::_LargestBST(STreeNode *pRoot,int & nMin,int &nMax,int & count,int &nNumber,STreeNode * & pNode) const { //最大二叉搜索子树
    count = 0;
    if(!pRoot) {
        return true;
    }
    int nMax1 = INT_MIN;
    int nMax2 = INT_MIN;
    int nMin1 = INT_MAX;
    int nMin2 = INT_MAX;
    int c1,c2;
    c1 = c2 = 0;
    if(!_LargestBST(pRoot->pLeft,nMin1,nMax1,c1,nNumber,pNode))
        return false;
    if(!_LargestBST(pRoot->pRight,nMin2,nMax2,c2,nNumber,pNode))
        return false;
    if(pRoot->value > nMin2 || pRoot->value < nMax1)
       return false;
    count = c1 + c2 + 1;
    
    nMin1 < pRoot->value ? nMin = nMin1:nMin = pRoot->value;
    nMax1 > pRoot->value ? nMax = nMax1:nMax = pRoot->value;
    
    if(count > nNumber) {
        nNumber = count;
        pNode = pRoot;
    }

    return true;


}

int CBinaryTree::LargestBST(STreeNode *& pNode) const {
    int nMin,nMax,count;
    int nNumber = 0;
    _LargestBST(m_pRoot,nMin,nMax,count,nNumber,pNode);
    return nNumber;
}
