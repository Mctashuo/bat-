#include<iostream>
#include<vector>
#include<algorithm>

//最长递增子序列
//找出给定数组最长肯单调递增的子序列的长度,和子序列
//

int LIS(const int *p,int length,int &nIndex,int *pre);
void GetLIS(const int *p,int &nIndex,int *pre);
int main() 
{
    int array[] = {1,4,5,6,2,3,8,9,10,11,12,12,1};

    //int array[] = {1,4,6,2,8,9,7};
    int size = sizeof(array)/sizeof(int);
    int nIndex;
    int * pre = new int[size];
    std::cout<<LIS(array,size,nIndex,pre)<<std::endl;
    GetLIS(array,nIndex,pre);


    return 0;
}
int LIS(const int *p,int length,int &nIndex,int *pre) 
{
    int LS = 1;
    int i,j;
    int *b = new int[length];
    nIndex = 0;
    for(i = 0;i < length;i++)
    {
        b[i] = 1;
        pre[i] = -1; 
    }

    for(i = 1;i < length;i++)
    {
        for(j = 0;j < i;j++) 
        {
            if(p[j] <= p[i]) 
            {
                if(b[i] < b[j]+1)
                {
                    b[i] = b[j] + 1;
                    pre[i] = j;
                }
            }
        }    
        if(b[i] > LS)
        {
            LS=b[i];
            nIndex = i;
        }

    }

    delete [] b;
    return LS;
}
void GetLIS(const int *p,int &nIndex,int *pre) 
{
    std::vector<int> lis;
    while(nIndex>=0) 
    {
        lis.push_back(p[nIndex]);
        nIndex = pre[nIndex];
    }
    reverse(lis.begin(),lis.end());
    for(auto i:lis){
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;
}
