#include<iostream>
using namespace std;
//字符串的全排列
//隐式图的DFS
//有重复
//带重复字符的全排列是每个字符分别与它后面拓重复出现的字符交换
//即:第i个字符中(前)与第j个字符(后)交换时,要求[i,j)中没有与第j个字符相等的数
//降低时间复杂度,空间换时间
void Print(char *a,int size) {
    for(int i = 0;i < size;i++) {
        cout<<a[i]<<"\t";
    }
    cout<<endl;

}
void swap(char * a,int * b) {
    char temp = *a;
    *a = *b;
    *b = temp; 
}
void Permutaion(char *a,int size,int n) {
    if(n == size - 1) {
        Print(a,size);
        return;
    } 

    int dup[256] = {0};
    for(int i = n;i < size;i++) {
        if(dup[a[i]] == 1)  continue;
        dup[a[i]] = 1;
        swap(a[i],a[n]);
        Permutaion(a,size,n+1);
        swap(a[n],a[i]);
    }
}
int main() {
    char str[] = "abbc"; 
    Permutaion(str,4,0);
    return 0;
}
