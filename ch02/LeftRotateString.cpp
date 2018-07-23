#include <iostream>
using namespace std;
/*
 * 字符串循环左移
 */
void ReserveString(char * s,int from,int to) {
    while(from < to) {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}
//m为长度,n为左移位数
void LeftRotateString(char * s,int m,int n) {
    n %= m;
    ReserveString(s,0,n-1);
    cout<<s<<endl;
    ReserveString(s,n,m-1);
    ReserveString(s,0,m-1);

}
int main() {
    char s[7] = "abcdef";
    cout<<s<<endl;
    LeftRotateString(s,6,2);
    cout<<s<<endl;

    return 0;
}
