#include<iostream>
void InsertionSort(int a[],int size)
{
    int i,j;
    for(i = 1;i < size;i++)
    {
        int j = i;
        int tmp = a[i];
        while(j > 0 && tmp < a[j - 1])
        {
            a[j] = a[j - 1]; 
            j--;
        }
        if(i != j)
            a[j] = tmp;
        
    }
}
void Print(int a[],int size)
{
    for(int i = 0;i < size;i++)
    {
        std::cout<<a[i]<<"\t";
    }
    std::cout<<std::endl;
}
int main()
{
    int a[] = {5,3,2,6,1,4,9};
    Print(a,sizeof(a)/sizeof(int));
    InsertionSort(a,sizeof(a)/sizeof(int));
    Print(a,sizeof(a)/sizeof(int));
	return 0;
}
