#include<iostream>
#include<cstring>
using namespace std;



void GetNext(const char * p,int next[]) {
    int size = strlen(p); 
    int k = -1;
    int j = 0;
    next[0] = -1;
    while(j < size - 1) {
        //此刻,k即next[j-1] 且p[k]表示前缀,p[j]表示后缀
        //注:k == -1表示未找到k前缀与k后缀相等,首次分析可先忽略
        if(k == -1 || p[k] == p[j]) {
            j++;
            k++;
            next[j] = k;
        }else {
            //P[j]与p[k]失配,则递归计算前缀p[next[k]]
            k = next[k];
        }
    }

}
void Print(int * a,int size) {
    for(int i  = 0;i < size;i++) {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}
int main() {
    const char * p = "abaabcaba";
    int next[strlen(p)];
    GetNext(p,next);
    Print(next,strlen(p));
    return 0;
}
