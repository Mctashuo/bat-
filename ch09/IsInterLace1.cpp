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

    bool p[L1+1];
    int i,j;
    p[L1] = true;
    for(j = 1;j <= L2;j++)
        p[j] = (p[j-1] && s2[j-1] == s3[j - 1]);
    for(i = 1;i <= L1;i++)
        for(j = 1;j <= L2;j++)
            p[j] = (p[j] && s1[i - 1] == s3[i + j -1]) || (p[j-1] && s2[j-1] == s3[i + j -1]);
    return p[L2];

}
