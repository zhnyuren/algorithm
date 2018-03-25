#define maxn 10//表示x集合和y集合中顶点的最大个数！

int nx,ny;//x集合和y集合中顶点的个数
int edge[maxn][maxn];//edge[i][j]为1表示ij可以匹配
int cx[maxn],cy[maxn];//用来记录x集合中匹配的y元素是哪个！
int visited[maxn];//用来记录该顶点是否被访问过！

int path(int u) {
    int v;
    for(v=0;v<ny;v++) {
        if(edge[u][v] && !visited[v]) {
            visited[v]=1;
            if(cy[v]==-1 || path(cy[v])) {//如果y集合中的v元素没有匹配或者是v已经匹配，但是从cy[v]中能够找到一条增广路
                cx[u]=v;
                cy[v]=u;
                return 1;
            }
        }
    }
    return 0;
}

int maxmatch() {
    int res=0;
    memset(cx,0xff,sizeof(cx));//初始值为-1表示两个集合中都没有匹配的元素！
    memset(cy,0xff,sizeof(cy));
    for(int i=0;i<=nx;i++) {
        if(cx[i]==-1) {
            memset(visited,0,sizeof(visited));
            res+=path(i);
        }
    }
    return res;
}
