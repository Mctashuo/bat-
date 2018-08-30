#include<iostream>

//复杂度为nlogn的LIS算法
//开辟缓冲区,插入数据
//将要插入的数插替换比它大的值最小的数
//返回缓冲区长度
//
int LIS(const int *a,int size);
void Insert(int *a,int &size,int x);
int main() {
    int a[] = {3,5,6,4,7,1,2,8};
    std::cout<<LIS(a,sizeof(a)/sizeof(int))<<std::endl;
	return 0;

}


int LIS(const int *a,int size) 
{
    int s=0,i;
    int *b = new int[size];
    for(i = 0;i < size;i++)
        Insert(b,s,a[i]);
    delete [] b;
    return s;
}
void Insert(int *a,int &size,int x) 
{
    if(size <= 0)
    {
        a[0] = x;
        size++;
        return;
    }

    if(x > a[size - 1])
    {
        a[size] = x;
        size++;
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
        a[low + 1] = x;
    else
        a[low] = x;

}
