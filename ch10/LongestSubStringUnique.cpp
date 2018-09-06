#include<iostream>
const int CHARATER_MAX = 26;
int max(int a,int b)
{
    if(a > b)
        return a;
    else
        return b;
}
int LongestSubStringUnique(char *a,int size)
{
    int exsit[CHARATER_MAX];
    int i;
    for(i = 0;i < CHARATER_MAX;i++)
        exsit[i] = -1;
    int start = 0;
    int nMax = 0;
    for(i = 0;i < size;i++)
    {
        if(exsit[a[i] - 'a'] >= start)
        {
            nMax = max(nMax,i - start);
            start = exsit[a[i] - 'a'] + 1; 
        }
        exsit[a[i] - 'a'] = i;
    }

    return nMax;

}
int main()
{
    char a[] = "abcabcbb";
    std::cout<<LongestSubStringUnique(a,sizeof(a)/sizeof(char) - 1)<<std::endl;
	return 0;
}
