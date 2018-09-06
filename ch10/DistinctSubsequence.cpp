#include<iostream>
#include<cstring>
int DistinctSubsequence(const char *pText,const char * pPattern)
{
    int size1 = strlen(pText);
    int size2 = strlen(pPattern);
    if(size2 > size1)
        return 0;
    int dp[size2 + 1];
    int i,j;
    dp[0] = 1;
    for(j = 1;j <= size2;j++)
        dp[j] = 0;
    for(i = 0; i < size1;i++)
        for(j = 0;j < size2;j++)
        {
            if(pText[i] == pPattern[j])
                dp[j + 1] += dp[j];
        }
    return dp[size2];
}
int main()
{
    char text[] = "abacab";
    char pattern[] =  "ab";
    std::cout<<DistinctSubsequence(text,pattern)<<std::endl;
	return 0;
}
