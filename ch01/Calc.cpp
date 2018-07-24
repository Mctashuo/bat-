#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
/*
 * 最短路径问题权值相同的最短路径问题,退化为BFS广度优先搜索
 * 结点步数step[0...N-1]初始化为0
 * 路径数目pathNum[0...N-1]初始化为0
 * pathNum[0] = 1;
 * 路径数目依次入栈
 */
const int N = 16;
int Calc(int G[N][N]) {
    int step[N];
    int pathNum[N];
    memset(step,0,sizeof(int) * N);
    memset(pathNum,0,sizeof(int) * N);
    pathNum[0] = 1;
    queue<int> s;
    s.push(0);
    int cur = 0;
    int i,from;
    while(!s.empty()) {
        from = s.front();
        s.pop(); 
        cur = step[from] + 1;
        for(i = 1;i < N;i++) {
            //连通
            if(G[from][i] == 1) {
                //未到达,或有更短路径
                if(step[i] == 0 || step[i] > cur) {
                    step[i] = cur;
                    pathNum[i] = pathNum[from];
                    s.push(i);
                }else if(step[i] == cur) {
                    pathNum[i] += pathNum[from];
                }
            
            }
        }
    }
    return pathNum[N-1];

}

int main() {
    int G[N][N];
    memset(G,0,sizeof(int) * N * N);

    G[0][1] = G[0][4] = 1;
    G[1][0] = G[1][5] = G[1][2] = 1;
    G[2][1] = G[2][6] = G[2][3] = 1;
    G[3][2] = G[3][7] = 1;
    G[4][5] = G[4][0] = 1;
    G[5][4] = G[5][9] = G[5][6] = G[5][1] = 1;
    G[6][5] = G[6][10] = G[6][7] = G[6][2] = 1;
    G[7][6] = G[7][3] = 1;
    G[8][12] = G[8][9] = 1;
    G[9][8] = G[9][13] = G[9][10] = G[9][5] = 1;
    G[10][9] = G[10][14] = G[10][11] = G[10][6] = 1;
    G[11][10] = G[11][15] = 1;
    G[12][13] = G[12][8] = 1;
    G[13][12] = G[13][14] = G[13][9] = 1;
    G[14][13] = G[14][15] = G[14][10] = 1;
    G[15][14] = G[15][11] = 1;
    cout<<Calc(G)<<endl;
    return 0;
} 
