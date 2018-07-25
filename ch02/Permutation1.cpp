#include<iostream>
using namespace std;
//字符串的全排列
//隐式图的DFS
//有重复
//带重复字符的全排列是每个字符分别与它后面拓重复出现的字符交换
//即:第i个字符中(前)与第j个字符(后)交换时,要求[i,j)中没有与第j个字符相等的数
void Print(int *a,int size) {
    for(int i = 0;i < size;i++) {
        cout<<a[i]<<"\t";
    }
    cout<<endl;

}
void swap(int * a,int * b) {
    int temp = *a;
    *a = *b;
    *b = temp; 
}
bool IsDuplicate(int * a,int i,int j) {
    for(;i < j;i++) {
        if(a[i] == a[j]) return true;
    }
    return false;
}
void Permutaion(int *a,int size,int n) {
    if(n == size - 1) {
        Print(a,size);
        return;
    } 

    for(int i = n;i < size;i++) {
        if(!IsDuplicate(a,n,i))    swap(a[i],a[n]);
        else continue;
        Permutaion(a,size,n+1);
        swap(a[n],a[i]);
    }
}
int main() {
    int a[] = {1,2,2,3};
    Permutaion(a,4,0);
    return 0;
}
