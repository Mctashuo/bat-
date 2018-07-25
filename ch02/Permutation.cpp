#include<iostream>
using namespace std;
//字符串的全排列
//隐式图的DFS

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
void Permutaion(int *a,int size,int n) {
    if(n == size - 1) {
        Print(a,size);
        return;
    } 

    for(int i = n;i < size;i++) {
        swap(a[i],a[n]);
        Permutaion(a,size,n+1);
        swap(a[n],a[i]);
    }
}
int main() {
    int a[] = {1,2,3,4};
    Permutaion(a,4,0);
    return 0;
}
