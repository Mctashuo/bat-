#include<iostream>
//逆序数问题
int Merge(int a[],int low,int mid,int high,int &count);
void MergeSort(int a[],int low,int high,int &count);
void Print(const int a[],const int size);
int main() {
    int a[] = {3,56,2,7,45,8,1};
    int size = sizeof(a)/sizeof(int);
    Print(a,size); 
    int count = 0;
    MergeSort(a,0,size - 1,count);
    Print(a,size);
    std::cout<<count<<std::endl;
    return 0;
}

void Print(const int a[],const int size) {
    int i = 0;
    for(;i < size;i++) {
        std::cout<<a[i]<<"\t";
    }
    std::cout<<std::endl;
}

int Merge(int a[],int low,int mid,int high,int &count) {
    int * temp = new int(high - low);
    int i = low;
    int j = mid + 1; 
    int size = 0;
    for(;i <= mid && j <= high;) {
        if(a[i] < a[j])
            temp[size++] = a[i++];
        else if(a[j] < a[i]) { 
            temp[size++] = a[j++];
            count += mid - i + 1;
        
        }
    }
    while(i <= mid) 
        temp[size++] = a[i++];
    while(j <= high)
        temp[size++] = a[j++];

    for(i = 0;i < size;i++) 
        a[low + i] = temp[i];

    delete [] temp;
    
}

void MergeSort(int a[],int low,int high,int &count) {
    if(low >= high)
        return;
    int mid = (low + high) /2;
    MergeSort(a,low,mid,count);
    MergeSort(a,mid+1,high,count);
    Merge(a,low,mid,high,count);
}


