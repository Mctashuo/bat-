#include<algorithm>
#include<iostream>

typedef struct tagSItem {
    int t;
    int nIndex;
    bool bFirst;

    bool operator < (struct tagSItem & Item) const {
        return t < Item.t;
    }
}SItem;

void GanttChart(const int *a,const int *b,int *c,int size);
void Print(const int *a,int size);
int main() {
    int a[] = {8,6,2,4};
    int b[] = {3,1,3,12};

    int n = sizeof(a) / sizeof(int);

    int *c = new int[n];

    GanttChart(a,b,c,n);
    Print(c,n);
    delete []c;
}

void Print(const int *a,int size) {
    for(int i = 0;i < size;i++) {
        std::cout<<a[i]<<"\t";
    } 
    std::cout<<std::endl;
}

void GanttChart(const int *a,const int *b,int *c,int size) {
    int s2 = 2 * size;
    SItem *pItem = new SItem[s2];
    int i;
    for(i = 0; i < size;i++) {
        pItem[i].t = a[i];
        pItem[i].nIndex = i;
        pItem[i].bFirst = true;

        pItem[size + i].t = b[i];
        pItem[size + i].nIndex = i;
        pItem[size + i].bFirst = false;
    }

    std::sort(pItem,pItem+s2);

    bool *pArrage = new bool[size];

    for(i = 0;i < size;i++)
        pArrage[i] = false;
    int from = 0;
    int to = size - 1;
    for(i = 0; i < s2;i++) {
        if(pArrage[pItem[i].nIndex]) 
            continue;
        pArrage[pItem[i].nIndex] = true;
        
        if(pItem[i].bFirst)
            c[from++] = pItem[i].nIndex;
        else
            c[to--] = pItem[i].nIndex;
        if(to < from)
            break;
    }
    delete [] pArrage;
    delete [] pItem;
     
}
