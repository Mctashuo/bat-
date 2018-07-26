#include<iostream>
#include<cstring>
using namespace std;

//给字符串添加gap
char * addGap(const char *a, int size) {
    char *b = new char(2 * size +2);
    b[0] = '$';
    for(int i = 0;i < size;i++) {
        b[2 + i * 2] = a[i];
        b[i * 2 + 1] = '#'; 
    }
    b[2 * size + 1] = '#';
    return b;

}
void Print(int * a,int size) {
    for(int i = 0;i < size;i++) {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}
void Manacher(const char * a,int size) {
    int P[size] = {0};
    P[0] = 1;
    int mx,id;
    int i = 1;
    id = 0;
    mx = 1;

    a++;
    while(i < size) {
        if(mx > i) {
            mx - i > P[2 * id - i] ? P[i] = P[2*id-i] : P[i] = mx - i; 
        }
        else {
            P[i] = 1;
        }
        for(;a[i + P[i] ] == a[i-P[i]];P[i]++);
        
        if(mx < i + P[i]) {
            mx = i+P[i];
            id = i;
        }
        i++;
    }
    Print(P,size);
}
int main() {
    const char * a = "12212321";
    char * b = addGap(a,strlen(a));
    cout<<b<<endl;
    Manacher(b,2 * strlen(a) + 1);
    delete [] b;
    return 0;
}
