#include <iostream>
#include <queue>
using namespace std;
/*
 * 拓扑排序的方法
 * 从有向图中选择一个入度为0的顶点并且输出它,
 * 从网中删去该顶点,并且删去从该顶点发出的全部有向边
 * 重复上述两步,直到没有入度为0的顶点为止
 */

//结点数为n,用邻接矩阵gragh[n][n]存储边权,
//用indegree[n]存储每个结点的入度

void topologic(int * toposort) {
    int cnt = 0;
    queue<int> q;
    int i = 0;
    for(i = 0;i < n;i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        toposort[cur++] = cur;
        for(i = 0;i < n;i++) {
            if(graph[cur][i]) {
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
    }

}
int main() {
    return 0; 
}
