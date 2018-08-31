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
    int mx;
    for(int k = 1;k <= K;k++)
    {
        mx = dp[k-1][0]-prices[0];
        for(int i = 1;i < size;i++)
        {
            dp[k][i] = max(mx+prices[i],dp[k][i-1]);
            mx = max(dp[k-1][i] - prices[i],mx);
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
