#include<iostream>
using namespace std;
int Partition(int a[],int low,int high)
{
    int i = low,j = high;
    int tmp = a[i];
    while(i < j)
    {
        while(i < j && a[j] >= tmp)
            j--;
        a[i] = a[j];

        while(i < j && a[i] <= tmp)
            i++;
        a[j] = a[i];
    }
    a[i] = tmp;
    return i;
}
void QuickSort(int a[],int low,int high)
{
    if(low > high)
        return;
    int pivot = Partition(a,low,high);
    QuickSort(a,low,pivot -1);
    QuickSort(a,pivot + 1,high);
}
void Print(int a[],int size)
{
    for(int i = 0;i < size;i++)
        cout<<a[i]<<"\t";
    cout<<endl;
}
int main()
{
    int a[] = {
        4,2,5,4,3,1
    };
    int size = sizeof(a)/sizeof(int);
    Print(a,size);
    QuickSort(a,0,size-1);
    Print(a,size);
	return 0;
}
