#include<iostream>
using namespace std;

void Holland1(int * a,int size) {
    int begin,cur,end;
    begin = cur = 0;
    end = size - 1;
    while(cur < end) {
        if(a[cur] == 2) {
            int temp = a[cur];
            a[cur] = a[end];
            a[end] = temp;
            end--;
        }else if(a[cur] == 1) {
            cur++;
        }else if(a[cur] == 0) {
            if(cur == begin) {
                cur++;
                begin++;
            }
            else {
                int temp = a[cur];
                a[cur] = a[begin];
                a[begin] = temp; 
                begin++;
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
int main() {
    int a[] = {1,0,2,2,0,1,1,0,2,2,0,1,1,1,2,1,2,1,0,0,0,1,2,1};
    int size = sizeof(a)/sizeof(int);
    Holland1(a,size);
    Print(a,size);
    return 0;
}
