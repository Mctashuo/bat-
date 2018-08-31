#include<iostream>
#include<vector>
#include<algorithm>

//复杂度为nlogn的LIS算法
//开辟缓冲区,插入数据
//将要插入的数插替换比它大的值最小的数
//返回缓冲区长度
//
int LIS(const int *a,int size);
void Insert(int *a,int &size,int x,int *pre,int i,int &nIndex);
void GetLIS(const int *p,int nIndex,int *pre);
int main() {
    int a[] = {3,5,6,4,7,1,2,8};
    int size = sizeof(a)/sizeof(int);
    std::cout<<LIS(a,size)<<std::endl;
	return 0;

}


int LIS(const int *a,int size)
{
    int s=0,i;
    int *b = new int[size];
    //nIndex记录往后添加时前一个最大值的下标
    int nIndex = 0;
    int pre[size];
    for(i = 0;i < size;i++)
    {
        pre[i] = -1;
        Insert(b,s,a[i],pre,i,nIndex);
    }
    GetLIS(a,7,pre);
    delete [] b;
    return s;
}
void Insert(int *a,int &size,int x,int *pre,int i,int &nIndex) 
{
    if(size <= 0)
    {
        a[0] = x;
        size++;
        return;
    }

    if(x > a[size - 1])
    {

        pre[i] = nIndex;
        a[size] = x;
        size++;
        //更新下标
        nIndex = i;
        return;
    }

    int low=0,high=size -1;
    
    while(low <= high) 
    {
        int mid = (low + high) / 2;
        if(x >= a[mid])
            low = mid + 1;
        else if(x < a[mid])
            high = mid - 1;
    }

    if(a[low] < x)
    {
        a[low + 1] = x;
        pre[i] = pre[low + 1];
    
    }
    else
    {
        a[low] = x;
        pre[i] = pre[low];
    }

}
void GetLIS(const int *p,int nIndex,int *pre) 
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
