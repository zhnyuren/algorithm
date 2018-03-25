#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define ll long long
using namespace std;
const int maxn=1007;
const int inf=0x3f3f3f3f;
int N,M;
int r[maxn][maxn];
int pre[maxn];
bool vis[maxn];
bool BFS(int s,int t) {
    queue<int> que;
    memset(pre,-1,sizeof(pre));
    memset(vis,false,sizeof(vis));
    pre[s]=s;
    vis[s]=true;
    que.push(s);
    int p;
    while(!que.empty()) {
        p=que.front();
        que.pop();
        for(int i=1;i<=M;++i) {
            if(r[p][i]>0 && !vis[i]) {
                pre[i]=p;
                vis[i]=true;
                if(i==t) return true;
                que.push(i);
            }
        }
    }
    return false;
}
int EK(int s,int t) {
    int maxflow=0,d;
    while(BFS(s,t)) {//O(VE)
        d=inf;
        for(int i=t;i!=s;i=pre[i]) {
            d=min(d,r[pre[i]][i]);
        }
        for(int i=t;i!=s;i=pre[i]) {
            r[pre[i]][i]-=d;
            r[i][pre[i]]+=d;
        }
        maxflow+=d;
    }
    return maxflow;
}
int main() {
    while(~scanf("%d%d",&M,&N)) {
        memset(r,0,sizeof(r));
        int s,e,c;
        for(int i=0;i<N;++i) {
            scanf("%d%d%d",&s,&e,&c);
            r[s][e]+=c;
        }
        printf("%d\n",EK(1,M));
    }
    return 0;
}
