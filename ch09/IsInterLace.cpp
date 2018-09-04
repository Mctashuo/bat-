#include<iostream>
#include<cstring>
using namespace std;
//dp[i][j]表示s1[1..i]和s2[1...j]的字符组成即dp[i][j]取值范围为true/false.
bool IsInterLace(const char *s1,const char *s2,const char *s3);
int main()
{
    const char *s1 = "aabcc";
    const char *s2 = "dbbca";
    const char *s3 = "aadbbcbcac";
    bool flag = IsInterLace(s1,s2,s3);

    cout<<(flag?"Yes":"No")<<endl;
	return 0;
}
bool IsInterLace(const char *s1,const char *s2,const char *s3)
{
    int L1 = strlen(s1);
    int L2 = strlen(s2);
    int L3 = strlen(s3);
    if(L3 != L2+L1)
        return false;

    bool p[L1+1][L2+1];
    int i,j;
    p[0][0] = true; 
    for(i = 1;i <= L1;i++)
        p[i][0] =  (p[i-1][0] && (s3[i-1] == s1[i-1]));
    for(j = 1;j <= L2;j++)
        p[0][j] = (p[0][j-1] && (s2[j-1] == s3[j-1]));
    for(i = 1;i <= L1;i++)
        for(j = 1;j <= L2;j++)
            p[i][j] = (p[i-1][j] && s3[i + j-1] == s1[i-1]) || (p[i][j-1] && s3[i + j-1] == s2[j-1]);
    return p[L1][L2]; 
}
