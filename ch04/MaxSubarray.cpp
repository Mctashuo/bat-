#include<iostream>
using namespace std;
int MaxSubarray(const int *a,int size) {
    int result;
    int sum = a[0];
    result = sum;
    int from,to;
    for(int i = 0;i < size;i++) {
        if(sum > 0) 
            sum += a[i];
        else {
            sum = a[i];
            from = i;
        }
        if(sum > result)  {
            result = sum;
            to = i;
        }
    }
    for(int i = from;i <= to;i++) {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    return result;
     
}
int main() {
    int a[] = {1,-2,3,10,-4,7,2,-5};
    cout<<MaxSubarray(a,sizeof(a)/sizeof(int))<<endl;
    return 0;
}
