#include<iostream>
//Hanoi塔问题
//假设有一个秘书帮你把n-1个盘子从借助C,A->B,
//老板只需要把最后一个盘子从A->C
//最后秘书把借助A把B->C
using namespace std;
void MoveOne(char from,char to) {
    cout<<from<<"->"<<to<<endl;
}
void Move(char from,char to,char aux,int n) {
    if(n == 1) {
        MoveOne(from,to);
        return;
    }
    Move(from,aux,to,n-1);
    MoveOne(from,to);
    Move(aux,to,from,n-1);
}
int main() {
    int n = 3;
    Move('A','C','B',n);
    return 0;
}
