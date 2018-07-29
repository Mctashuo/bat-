#include<iostream>
using namespace std;
//冒泡排序
void sort(int *a,int size) {
    int i,j;
    for(i = 0;i < size;i++) {
        for(j = i;j < size;j++) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void Print(int * a,int size) {
    for(int i = 0;i < size;i++) {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}
void MinSubarray(int *a,int size) {
    int * sum = new int(size + 1);

    sum[0] = 0;
    a--;
    int i;
    for(i = 1;i <= size;i++) {
        sum[i] = sum[i - 1] + a[i];  
    }
    sum++;
    Print(sum,size);
    sort(sum,size);
    Print(sum,size);

    //查找相邻元素差最小的绝对值
    
    int min = 100;
    for(i = 1;i < size;i++) {
       int temp;
       sum[i] - sum[i - 1] > 0 ? temp = sum[i] - sum[i - 1] : temp = sum[i - 1] - sum[i];
       if(temp < min)
           min = temp;
    }
    cout<<min<<endl;
    delete [] --sum;
}
int main() {
    //int a[] = {1,4,-5,-3,2,6,7,2};
    int a[] = {1,-2,3,10,-4,7,2,-5};
    int size = sizeof(a)/sizeof(int);
    //cout<<size<<endl;
    cout<<endl;
    MinSubarray(a,size);
    return 0;
}
