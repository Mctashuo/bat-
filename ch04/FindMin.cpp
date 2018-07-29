#include<iostream>
using namespace std;
//查找旋转数组中的最小值
//用索引left,right分别指向首尾元素
//若数组是普通升序数组则A[left]<A[right]
//若数组是循环升序数组则A[right]>A[left]
//取mid=(left+right) /2
//如果A[mid] > A[left]说明
//[left-min]为普通数组
//[mid-right]为循环升序数组
//left = mid + 1;
//否则right = mid
//!!!旋转数组的最小值最后只会出现在左边所以这种比较方法不对
int FindMin(int *a,int size) {
    int left = 0;
    int right = size - 1;
    int mid;
    while(left < right) {
        mid = (left + right) / 2;
        if(a[mid] > a[left]) {
            left = mid;
        }
        else if( a[mid] < a[left] )
            right = mid - 1;
    }
    return a[right];
}
int main() {
    int a[] = {4,5,6,7,0,1,2};
    cout<<FindMin(a,sizeof(a)/sizeof(int))<<endl;
    return 0;
}
