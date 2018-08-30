#include<iostream>
//最长递增子序列
//找出给定数组最长肯单调递增的子序列的长度
//
int max(int,int);

int LIS(const int *p,int length);
int main() 
{
    int array[] = {1,4,5,6,2,3,8,9,10,11,12,12,1};

    //int array[] = {1,4,6,2,8,9,7};
    int size = sizeof(array)/sizeof(int);
    std::cout<<LIS(array,size)<<std::endl;
    return 0;
}
int LIS(const int *p,int length) 
{
    int LS = 1;
    int i,j;
    int *b = new int[length];

    for(i = 0;i < length;i++)
        b[i] = 1;
    for(i = 1;i < length;i++)
    {
        for(j = 0;j < i;j++) 
        {
            if(p[j] <= p[i]) 
            {
                b[i] = max(b[i],b[j] + 1); 
            }
        }    
        LS = max(b[i],LS);

    }

    delete [] b;
    return LS;
}
int max(int a,int b) 
{
    if(a > b)
        return a;
    return b;
}
