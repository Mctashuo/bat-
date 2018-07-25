#include<iostream>
using namespace std;
//全排列非递归算法
//起点:字典序最小的排列,12345
//终点:字典序最大的排列 54321
//过程:从当前排列生成字典序刚好比它大的下一个排列
//
//
//步骤:后找,小大,交换,翻转
//后找:字符串中最后一个升序的位置i
//小大:S[i+1....N-1]中比Ai大的最小值Sj
//交换:Si,Sj;
//翻转:S[i+1...N-1]

void reverse(int *from,int *to){
    while(from < to) {
        int temp = *to;
        *to = *from;
        *from = temp;
        from++;
        to--;
    }
}
void Print(int *a,int size) {
    for(int i =0;i < size;i++) {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}
bool GetNextPermutation(int *a,int size) {
    int i = size - 2;
    //后找
    while((i >= 0) && (a[i] >= a[i+1])) 
        i--;
    if(i < 0) 
        return false;
    //小大
    int j = size - 1;
    while(a[j] <= a[i])
        j--;
    //交换
    int temp = a[j];
    a[j] = a[i];
    a[i] = temp;
    //翻转
    reverse(a + i + 1,a + size - 1);
    
    return true; 
}
int main() {
    int a[] = {1,2,3,4};
    Print(a,4);
    while(GetNextPermutation(a,4)) 
        Print(a,4);
    return 0;
}
