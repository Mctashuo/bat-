#include<iostream>
using namespace std;
//利用循环不变式查找第一个缺失的数字
//
int FirstMissNumber(int * a,int size) {
    int i = 1;
    int N = size;
    a--;
    while(i <= N) {
        if(a[i] == i) 
            i++;
        else if(a[i] < i || a[i] > N || a[a[i]] == a[i]) {
            a[i] = a[N];
            N--;
        }
        else if(a[i] > i) {
            int temp = a[a[i]];
            a[a[i]] = a[i];
            a[i] = temp;
        }

    }
    return i;
}
int main() {
    int a[] = {3,5,1,2,-3,7,4,8};
    cout<<FirstMissNumber(a,sizeof(a)/sizeof(int))<<endl;
    return 0;
}
