#include<iostream>
#include<cstring>
//Hanoi塔状态问题
//将前N-1个盘子放在辅助aux柱上:2^(n-1) - 1;
//将最大盘子放在目标to柱上:1
//将后N-1个盘子放在to柱上2^(n-1) -1;
using namespace std;
int Calc(const char * state,int size,char from,char to,char aux) {
    if(size == 0) 
        return 0;
    if(aux == state[size - 1]) {
        return -1;
    }else if(to == state[size - 1]) {
        int n = Calc(state,size - 1,aux,to,from);
        if(n == -1) {
            return -1;
        }
        return (1<<(size - 1)) + n;
    }
    else return Calc(state,size - 1,from,aux,to);
}
int main() {
    char str[] = "ABC";
    cout<<Calc(str,3,'A','C','B')<<endl;
    strcpy(str,"AAC");
    cout<<Calc(str,3,'A','C','B')<<endl;
    strcpy(str,"CCC");
    cout<<Calc(str,3,'A','C','B')<<endl;
    return 0;
}
