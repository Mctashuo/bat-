#include<iostream>
using namespace std;
//求数组的一个局部最大值
//用二分法

int LocalMax(int *a,int size) {
    int left = 0;
    int right = size -1;
    int mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if(a[mid] > a[mid+1])
            right = mid;
        else if(a[mid] < a[mid+1])
            left = mid + 1;
        if(left == right)
            return a[left];
    }
}
int main() {
    int a[] = {1,2,1,3,4,3,5,6,5,7,8,7};
    cout<<LocalMax(a,sizeof(a)/sizeof(int))<<endl;
    return 0;
}
