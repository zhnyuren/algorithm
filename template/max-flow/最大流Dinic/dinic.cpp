#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int inf=0x7fffffff;
int M,N;
int level[1007];
int a,b,c;

struct Dinic {
    int c;
    int f;
}edge[1007][1007];

bool dinic_bfs() {
    queue<int> q;
    memset(level,0,sizeof(level));
    q.push(1);
    level[1]=1;
    int u,v;
    while(!q.empty()) {
        u=q.front();
        q.pop();
        for(v=1;v<=N;v++) {
            if(!level[v] && edge[u][v].c>edge[u][v].f) {
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
    return level[N]!=0;
}

int dinic_dfs(int u,int cnt) {
    int rt=cnt;
    int v,t;
    if(u==N) return cnt;
    for(v=1;v<=N && rt;v++) {
        if(level[u]+1==level[v]) {
            if(edge[u][v].c>edge[u][v].f) {
                t=dinic_dfs(v,min(rt,edge[u][v].c-edge[u][v].f));
                edge[u][v].f+=t;
                edge[v][u].f-=t;
                rt-=t;
            }
        }
    }
    return cnt-rt;
}

int dinic() {
    int sum=0;
    int cnt=0;
    while(dinic_bfs()) {
        while(cnt=dinic_dfs(1,inf)) sum+=cnt;
    }
    return sum;
}

int main() {
    while(~scanf("%d%d",&N,&M)) {
        memset(edge,0,sizeof(edge));
        while(M--) {
            scanf("%d%d%d",&a,&b,&c);
            edge[a][b].c+=c;
        }
        printf("%d\n",dinic());
    }
}
