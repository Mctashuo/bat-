#include<iostream>
//记dp[i]为:到达a[i]时,还剩余多少步没有用
int max(int a,int b)
{
    if(a > b)
        return a;
    else 
        return b;
}
int jump(int a[],int size)
{
    if(size <=1 )
        return 0;
    int i;
    int dp[size];
    dp[0] = 0;
    for(i = 1;i < size;i++)
    {
        dp[i] = max(dp[i - 1],a[i - 1]) - 1;
    }
    return dp[size - 1] + 1;


}
int main()
{
    int A[] = {2,3,1,1,2,4,1,3,1,6,1,7};
    std::cout<<jump(A,sizeof(A)/sizeof(int))<<std::endl;
	return 0;
}
