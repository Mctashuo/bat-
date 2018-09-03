#include<iostream>
#include<vector>
using std::vector;
int MinPath(vector<vector<int> > & chess,int M,int N);
int main()
{
    const int M = 10;
    const int N = 8;
    vector<vector<int> > chess(M,vector<int>(N));
    int i,j;
    for(i = 0;i < M;i++)
        for(j = 0;j < N;j++)
        {
            chess[i][j] = rand()%100;
        }
    std::cout<<MinPath(chess,M,N)<<std::endl;
	return 0;
}
int MinPath(vector<vector<int> > & chess,int M,int N)
{
    int path[N];
    int i,j;
    vector<int> p;
    path[0] = chess[0][0];
    for(i = 1;i < N;i++)
    {
        path[i] = path[i-1] + chess[0][i];
    }
    for(i = 1;i < M;i++)
    {
        path[0] = chess[i][0];
        for(j = 1;j < N;j++)
        {
            if(path[j] < path[j-1])
                path[j] += chess[i][j];
            else
                path[j] = path[j-1] + chess[i][j];
        }
    }
    return path[N-1];


}
