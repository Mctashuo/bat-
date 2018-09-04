#include<iostream>
#include<vector>
using std::vector;
int PathNumber(vector<vector<bool> >& chess);
int main()
{
    const int M = 4;
    const int N = 5;
    vector<vector<bool> > chess(M,vector<bool>(N));
    int i,j;
    for(i = 0;i < M;i++)
    {
    
        for(j = 0;j < N;j++)
        {
            chess[i][j] = (rand() % 5 != 0);
            if(chess[i][j])
                std::cout<<1<<"\t";
            else
                std::cout<<0<<"\t";
        }
        std::cout<<std::endl;
    }
    std::cout<<PathNumber(chess)<<std::endl;
	return 0;
}
int PathNumber(vector<vector<bool> >& chess) 
{
    const int M = chess.size();
    const int N = chess[0].size();
    int path[N];
    path[0] = chess[0][0]?1:0;
    int i,j;
    for(j = 1;j < N;j++)
        if(chess[0][j] && path[j-1]!=0)
            path[j] = 1;
        else
            path[j] = 0;
    for(i = 1;i < M;i++)
    {
        if(!chess[i][0])
            path[0] = 0;
        for(j = 1;j < N;j++)
        {
            if(chess[i][j])
                path[j] += path[j-1];
            else
                path[j] = 0;
            
        }
        
    }

    return path[N-1];
}   
