#include <cstdio>
#include <algorithm>
using namespace std;

const int inf=0x3f3f3f3f;
int N,ans;

struct Node {
    int x;
    int y;
}nd[10000];

bool cmpMostLeft(Node a,Node b) {
    return a.x<b.x;
}

int dis(Node a,Node b) {
    return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
}

void FindCloeset(int l,int r) {
    if(l<r) {
        int mid=(l+r)/2;
        FindCloeset(l,mid);
        FindCloeset(mid+1,r);
        for(int i=l;i<=mid;i++) {
            for(int j=mid+1;j<=min(mid+5,r);j++) {
                int tmp=dis(nd[i],nd[j]);
                if(tmp<ans) ans=tmp;
            }
        }
    }
}

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d%d",&nd[i].x,&nd[i].y);
    }
    ans=inf;
    sort(nd,nd+N,cmpMostLeft);
    FindCloeset(0,N-1);
    printf("%d\n",ans);
}
