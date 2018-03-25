#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1007;
int r[maxn][maxn];
int visit[maxn];
int match[maxn];
int n;

int DFS(int u) {
    int v;
    for(v=1;v<=1000;v++) {
        if(r[u][v] && !visit[v]) {
            visit[v]=1;
            if(match[v]==-1 || DFS(match[v])) {
                match[v]=u;
                printf("from %d to %d\n",u,v);
                return 1;
            }
        }
    }
    return 0;
}

int Hungarian() {
    int cnt=0;
    for(int i=1;i<=1000;i++) {
        memset(visit,0,sizeof(visit));
        if(DFS(i)) cnt++,printf("cnt:%d\n",cnt);
    }
    return cnt;
}

int main() {
    int a,b;
    while(~scanf("%d",&n)) {
        memset(r,0,sizeof(r));
        memset(match,-1,sizeof(match));
        for(int i=1;i<=n;i++) {
           scanf("%d%d",&a,&b);
           r[a][b]=1;
        }
        printf("%d\n",Hungarian());
    }
}
/*
13
1 1
1 2
1 4
2 2
2 5
3 1
3 4
3 7
4 3
4 4
4 6
5 4
6 4
*/

