#include<iostream>
//给定序列判断是不是二叉查找树的后序遍历
bool CanPostOrder(const int *a,int size);
int main() {
    int a[] = {1,2,5,4,3};
    bool b = CanPostOrder(a,sizeof(a)/sizeof(int));
    std::cout<<b<<std::endl;
    return 0;
}
//中序遍历递增
//后序遍历最后一个结点是根结点,根结点划分,左右子树,如果左子树结点都
//小于根结点,右子树结点都大于根结点,则是后序遍历的结果
bool CanPostOrder(const int *a,int size) {
    if(size <= 1)
        return true;
    int nLeft,nRight,root;
    root = a[size -1];
    for(nLeft = 0;nLeft < size - 1;nLeft++)
        if(a[nLeft] > root)
            break;
    for(nRight = size - 2;nRight >= 0;nRight--)
        if(a[nRight] < root)
            break;

    if(nLeft-1 != nRight) {
        return false;
    }
    return CanPostOrder(a,nLeft) && CanPostOrder(a + nLeft,size - nLeft - 1);
}
