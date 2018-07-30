#include<iostream>
using namespace std;
int MaxSequence(int *a,int size) {
    int m = 1;
    int i,from,to,sum;
    from = 0;
    sum = 1;
    for(i = 1;i < size;i++) {
        if(a[i] - a[i-1] == 1) {
            sum += 1;
            if(sum > m) {
                m = sum;
                to = i;
            }
        }else {
            sum = 1;
        }
        
    }

    from = to - m + 1;
    cout<<m<<endl;
    for(i = from;i <= to;i++) {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}
int main() {
    int a[] = {1,2,3,34,56,57,58,59,60,61,99,121};
    MaxSequence(a,sizeof(a)/sizeof(int));
    return 0;
}
