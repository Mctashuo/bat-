#include<iostream>
#include<vector>
int MaxProfitK(const int *prices,int size,int K);
int max(int a,int b);
int main() {
    int prices[] = {7,1,5,3,6,4};
    int K=3;
    std::cout<<MaxProfitK(prices,sizeof(prices)/sizeof(int),K)<<std::endl;
	return 0;
}
int MaxProfitK(const int *prices,int size,int K)
{
    using std::vector;
    vector<vector<int>> dp(K+1,vector<int>(size,0));
    for(int k = 1;k <= K;k++)
    {
        for(int i = 0;i < size;i++)
        {
            dp[k][i] = dp[k][i-1];
            for(int j = 0;j < i;j++)
            {
                dp[k][i] = max(dp[k-1][j]+prices[i]-prices[j],dp[k][i]);
            }
        }
    }
    return dp[K][size-1];
    
}

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
