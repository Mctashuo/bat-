#include<iostream>
#include<cstring>
void InPre2Post(const char * pInOrder,const char * pPreOrder,int nLength,char * pPostOrder,int &nIndex) {
    if(nLength <= 0) 
        return;
    else if(nLength == 1) {
        pPostOrder[nIndex] = *pPreOrder;
        nIndex++;
        return;
    }
    char root = *pPreOrder;
    int nRoot = 0;
    for(;nRoot < nLength;nRoot++) {
        if(root == pInOrder[nRoot])
            break;
    }
    InPre2Post(pInOrder,pPreOrder + 1,nRoot,pPostOrder,nIndex);
    InPre2Post(pInOrder + nRoot + 1,pPreOrder + nRoot + 1,nLength - nRoot - 1,pPostOrder,nIndex);
    pPostOrder[nIndex++] = root;
}
int main() {
    using namespace std;
    char pPreOrder[] = "GDAFEMHZ";
    char pInOrder[] = "ADEFGHMZ";
    int size = strlen(pPreOrder);

    char * pPostOrder = new char[size + 1];
    int nIndex  = 0;
    InPre2Post(pInOrder,pPreOrder,size,pPostOrder,nIndex);
    pPostOrder[size] = '\0';
    cout<<pPostOrder<<endl;
    delete [] pPostOrder;
    return 0;
}
