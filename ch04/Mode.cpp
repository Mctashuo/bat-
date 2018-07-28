#include<iostream>
using namespace std;
//给定N个数,求某个众数出现次数大于N/2
//删除数组中两个不同的数,所求众数不变
//记m为候选众数,出现次数为c,初始化为0
//遍历数组,
//若c==0,c=a[i]
//若c!=0且m!=a[i]同时删掉m和a[i]
//若c!=0且m==a[i]c++;
int Mode(int * a,int size) {
    int mode = -1;
    int m;
    int c = 0;
    for(int i = 0;i < size;i++) {
        if(c == 0) {
            m = a[i];
            c++;
        }
        else if(m != a[i] ) {
            c--;     
        }
        else{ //m == a[i]
            c++;
        }
    }
    return m; 
}

int main() {
    int b[] = {1,2,1,3,1};
    cout<<Mode(b,5)<<endl;
    return 0;
}
