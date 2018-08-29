#include<iostream>
#include<algorithm>
void TwoSum(int *a,int size,int sum);
void Print(const int *a);

int main() {

    int a[] = {17,14,16,7,3,11,9,0};
    int size = sizeof(a)/sizeof(int);
    std::sort(a,a + size);
    TwoSum(a,size,20); 
    return 0;
}


void TwoSum(int *a,int size,int sum) {
    int i =0,j = size -1;
    
    while(i < j) {
        if(a[i] + a[j] > sum) {
            j--;
        }else if (a[i] + a[j] < sum) {
            i++;
        }else {
            std::cout<<a[i]<<"\t"<<a[j]<<std::endl;
            i++;
            j--; 
        }
    }

     
}
