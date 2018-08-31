#include<iostream>
int MaxProfit(int *prices,int size);
int min(int a,int b);
int max(int a,int b);
int main() {
    int prices[] = {7,1,5,3,6,4};
    std::cout<<MaxProfit(prices,sizeof(prices)/sizeof(int))<<std::endl;
	return 0;
}
int MaxProfit(int *prices,int size)
{
    int mn = prices[0],p=0;
    for(int i = 1;i < size;i++) 
    {
        mn = min(mn,prices[i - 1]);
        p = max(p,prices[i] - mn);

    }
    return p;


}

int min(int a,int b)
{
    if(a < b)
        return a;
    return b;
}

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
