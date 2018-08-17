#include<iostream>

void Merge(int a[],int low,int mid,int high);
void MergeSort(int a[],int low,int high);
void Print(const int a[],const int size);
int main() {
    int a[] = {3,56,2,7,45,8,1};
    int size = sizeof(a)/sizeof(int);
    Print(a,size); 
    MergeSort(a,0,size - 1);
    Print(a,size);
    return 0;
}

void Print(const int a[],const int size) {
    int i = 0;
    for(;i < size;i++) {
        std::cout<<a[i]<<"\t";
    }
    std::cout<<std::endl;
}

void Merge(int a[],int low,int mid,int high) {
    int * temp = new int(high - low);
    int i = low;
    int j = mid + 1; 
    int size = 0;
    for(;i <= mid && j <= high;) {
        if(a[i] < a[j])
            temp[size++] = a[i++];
        else if(a[j] < a[i])
            temp[size++] = a[j++];
    }
    while(i <= mid) 
        temp[size++] = a[i++];
    while(j <= high)
        temp[size++] = a[j++];

    for(i = 0;i < size;i++) 
        a[low + i] = temp[i];

    delete [] temp;
    
}

void MergeSort(int a[],int low,int high) {
    if(low >= high)
        return;
    int mid = (low + high) /2;
    MergeSort(a,low,mid);
    MergeSort(a,mid+1,high);
    Merge(a,low,mid,high);
}


