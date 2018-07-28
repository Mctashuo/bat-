#include<iostream>

using namespace std;

//拆半查找法
//
//

int find(int f,int *a,int size) {
    int left = 0;
    int right = size - 1;
    int mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if(a[mid] == f) {
            return mid;
        }else if( a[mid] < f ) {
            left = mid + 1;
        }else if( a[mid] > f ) {
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<find(11,a,10)<<endl;
    return 0;
}
