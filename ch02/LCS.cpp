#include<iostream>
#include<cstring>
using namespace std;
int LCS(const char * str1,const char *str2) {
    int str1Len = (int)strlen(str1) + 1;  
    int str2Len = (int)strlen(str2) + 1;
    int C[str1Len][str2Len];
    int i,j;
    str1--;
    str2--;
    for(i = 0;i < str1Len;i++) {
        C[i][0] = 0;
    }
    for(i = 0;i< str2Len;i++) {
        C[0][i] = 0;
    }

    for(i = 1; i < str1Len;i++) {
        for(j = 1;j < str2Len;j++) {
            if(str1[i] == str2[j]) {
                C[i][j] = C[i-1][j-1] + 1;
            }else {
                C[i][j] = C[i-1][j] > C[i][j-1]? C[i-1][j]:C[i][j-1];
            }
        }
    }
    for(i = 0;i < str1Len;i++) {
        for(j = 0;j < str2Len;j++) {
            cout<<C[i][j]<<"\t";
        }
        cout<<endl;
    }
    i = str1Len - 1;
    j = str2Len - 1;
    int len = C[str1Len - 1][str2Len - 1];
    char s2[len];
    s2[len] = '\0';
    while((i != 0) && (j != 0)) {
        if(str1[i] == str2[j]) {
            s2[--len] = (str1[i]);
            i--;
            j--;
        }
        else {
            if(C[i-1][j] > C[i][j-1]) {
                i--;
            }else j--;
        }
    }
    cout<<s2<<endl; 
    return C[str1Len - 1][str2Len - 1];
    
}
int main() {
    //const char * str1 = "TCGGATCGACTT";
    //const char * str2 = "AGCCTACGTA";
    const char * str1 = "ABCBDAB";
    const char * str2 = "BDCABA";
    cout<<LCS(str1,str2)<<endl;
    return 0;
}
