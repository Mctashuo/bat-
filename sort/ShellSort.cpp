#include<iostream>
void ShellSort(int a[],int size)
{
    int i,j;
    int gap = 1;
    while(gap < size / 3)
        gap = gap * 3 + 1;
    while(gap > 0)
    {
        for(i = gap;i < size;i++)
        {
            j = i - gap;
            int tmp = a[i];
            while(j >= 0 && tmp < a[j])
            {
                a[j + gap] = a[j];
                j -= gap; 
            }
            a[j + gap] = tmp;
        }
        gap = gap / 3;
    }
}
void Print(int a[],int size)
{
    for(int i = 0;i < size;i++)
        std::cout<<a[i]<<"\t";
    std::cout<<std::endl;
}
int main()
{
    int a[] = {5,2,3,1,7,8,3,4,3,1};
    int size = sizeof(a)/sizeof(int);
    Print(a,size);
    ShellSort(a,size);
    Print(a,size);

	return 0;
}
