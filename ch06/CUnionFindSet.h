#ifndef __CUnionFindSet__H
#define __CUnionFindSet__H
class CUnionFindSet {
    private:
        int m_nN;
        int * m_pParent;
    public:
        //初始化数组并将父结点指向自己
        CUnionFindSet(int n);
        //销毁指针数组
        ~CUnionFindSet();
        //将两个结点的父结点联在一起
        void Union(int i,int j);
        //查找集合内的所有结点,并将结点统一指向父结点
        int Find(int i);
        void Print() const;
};

#endif //__CUnionFindSet__H

CUnionFindSet::CUnionFindSet(int n) {
    m_nN = n;
    m_pParent = new int(n);
    for(int i = 0;i < n;i++) {
        m_pParent[i] = i;
    }
}

CUnionFindSet::~CUnionFindSet() {
    delete [] m_pParent;
}

int CUnionFindSet::Find(int i ) {
    if(i < 0 || i > m_nN) {
        return -1;
    }
    int root = i;
    while(root != m_pParent[root]) {
        root = m_pParent[root];
    }

    int p,t;
    t = i;
    while(t != root) {
        p = m_pParent[t];    //t的原父结点
        m_pParent[t] = m_pParent[root]; //t的父结点直接赋值给根t
        t = p;   //原父结点向上找

    }
    return root;
}

void CUnionFindSet::Union(int i,int j) {
    if(i < 0 || i > m_nN || j < 0 || j > m_nN) {
        return;
    }    
    int ri = Find(i);
    int rj = Find(j);
    if(ri != rj) 
        m_pParent[ri] = rj;
}
