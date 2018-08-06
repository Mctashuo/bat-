#include <iostream>
#include "CUnionFindSet.h"
using namespace std;
int CalCompoment() {
    const int N = 10;
    CUnionFindSet com(N);
    com.Union(2,6);
    com.Union(5,6);
    com.Union(1,8);
    com.Union(2,9);
    com.Union(5,3);
    com.Union(4,8);
    com.Union(4,0);

    int componet[N] = {0};
    int i;
    for(i = 0; i< N;i++) {
        componet[com.Find(i)]++;
    }

    int count = 0;
    for(i = 0;i < N;i++) {
        if(componet[i] != 0)
            count++;
    }
    return count;

}
int main() {
    cout<<CalCompoment()<<endl;
    return 0;
}
