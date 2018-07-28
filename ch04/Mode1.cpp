#include<iostream>
using namespace std;
//给定N个数,求某个众数出现次数大于N/3
//一个数组中N/3众数不会超过2个
//删除数组中三个不同的数,所求众数不变
//
//记m为候选众数1,n为候选数组2,出现次数分别为cm,cn,初始化为0
//遍历数组,
//若cm==0,m=a[i]
//else cn == 0 n = a[i];
//若cm!=0且cn != 0 m==a[i]同时删掉m和a[i]
//若cm!=0且cn != 0 n==a[i]同时删掉n和a[i]
//若都不满足同时删掉m,n,和a[i]
void Mode(int * a,int size) {
    int m,n;
    int cm = 0,cn = 0;
    int i;
    for(i = 0;i < size;i++) {
        if(cm == 0) {
            m = a[i];
            cm = 1;
        }
        else if(cn == 0 && m != a[i]) {
            n = a[i];
            cn = 1;
        }else if(m == a[i]) {
            cm++;
        }else if(n == a[i])
            cn++;
        else{ //情况都不满足
            cm--;
            cn--;
        }
    }
    cm = cn = 0;
    for(i = 0;i < size;i++) {
        if(a[i] == m) 
            cm++;
        else if(a[i] == n) {
            cn++;   
        }
    }
    if(cm > (size / 3)) 
        cout<<m<<endl;
    if(cn > (size / 3))
        cout<<n<<endl;
}

int main() {
    //int b[] = {1,2,3,2,5,2,2,3,3,2,3};
    //  int b[] = {1,1,1,3,5,2,2,2};
    int b[] = {1,1,2,3,5,2,2,1};
    Mode(b,sizeof(b)/sizeof(int));
    return 0;
}
