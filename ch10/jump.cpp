#include<iostream>
//初始步数为0;
//当前步的控制满园是[i,j],用k做遍历i到j
//计算a[k]+k的最大值记做j2
//step++,继续遍历[j+1,j2];
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
    int step = 0,i = 0,j = 0;
    int k,j2;
    while(i < size)
    {
        step++;
        for(k = i;k <= j;k++)
        {
            j2 = max(j2,k + a[k]);
            if(j2 >= size - 1)
                return step;
        }

        i = j + 1;
        j = j2;
        if(j < i)
            return -1; 
    }
    return step;

}
int main()
{
    int A[] = {2,3,1,1,2,4,1,1,6,1,7};
    std::cout<<jump(A,sizeof(A)/sizeof(int))<<std::endl;
	return 0;
}
