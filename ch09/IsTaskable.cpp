#include<iostream>
#include<algorithm>
typedef struct tagTask 
{
    int taskID;
    int RO;
    static bool Compare(const tagTask &task1,const tagTask & task2)
    {
        return task1.RO>task2.RO;
    }
}STask;
bool IsTaskable(int N,int M,int R[],int O[]);
int main() 
{
    using std::cout;
    using std::endl;
    const int N=2;
    const int M = 14;
    int R[N] =  {10,8};
    int O[N] = {5,6};
    bool b = IsTaskable(N,M,R,O);
    cout<<(b?"Yes":"No")<<endl;
	return 0;
}
bool IsTaskable(int N,int M,int R[],int O[])
{
    STask * st = new STask[N];
    int i;
    for(i = 0;i < N;i++)
    {
        st->taskID = i;
        st->RO = R[i]-O[i];
    }
 
    std::sort(st,st+N,STask::Compare);

    int k = R[0];
    bool flag = true;

    for(i = 1;i < N;i++)
    {
        if(k > M)
        {
            return false;
        }
        k = O[i-1] + R [i];
    }
    delete [] st;
    return flag;
}
