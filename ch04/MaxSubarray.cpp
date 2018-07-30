#include<iostream>
using namespace std;
int MaxSubarray(const int *a,int size) {
    int result;
    int sum = a[0];
    result = sum;
    for(int i = 0;i < size;i++) {
        if(sum > 0) 
            sum += a[i];
        else
            sum = a[i];
        if(sum > result) 
            result = sum;
    }
    return result;
     
}
int main() {
    int a[] = {1,-2,3,10,-4,7,2,-5};
    cout<<MaxSubarray(a,sizeof(a)/sizeof(int))<<endl;
    return 0;
}
