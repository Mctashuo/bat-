#include<iostream>
#include<cstring>
void InPost2Pre(const char * pInOrder,const char  * pPostOrder,int nLength,char * pPreOrder,int &nIndex);
int main() {
    char pPostOrder[] = "AEFDHZMG";
    char pInOrder[] = "ADEFGHMZ";
    int size = strlen(pPostOrder);

    char *pPreOrder = new char[size + 1];
    int nIndex = 0;
    InPost2Pre(pInOrder,pPostOrder,size,pPreOrder,nIndex);
    pPreOrder[size] = '\0';
    std::cout<<pPreOrder<<std::endl;
    delete [] pPreOrder;
    return 0;
}

void InPost2Pre(const char * pInOrder,const char  * pPostOrder,int nLength,char * pPreOrder,int &nIndex){
    if(nLength <= 0) 
       return;
    if(nLength == 1) {
        pPreOrder[nIndex] = pPostOrder[nIndex];
        nIndex++;
        return;
    }
    char root = pPostOrder[nLength - 1];
    pPreOrder[nIndex]=root;
    nIndex++;
    int nRoot = 0;
    for(;nRoot < nLength;nRoot++) {
        if(pInOrder[nRoot] == root) {
            break;
        }
    }
    InPost2Pre(pInOrder,pPostOrder,nRoot,pPreOrder,nIndex);
    InPost2Pre(pInOrder+nRoot+1,pPostOrder+nRoot,nLength-nRoot-1,pPreOrder,nIndex);
}
