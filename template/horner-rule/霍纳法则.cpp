#include <bits/stdc++.h>
using namespace std;

int T,n,m,c;
int a[100007];
int b[100007];

int HornerRule(int x,int len,int num[]) {
    int fx=0;
    for(int i=len;i>=0;i--) {
        fx=(fx*x)+num[i];
    }
    return fx;
}

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=0;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        for(int i=0;i<=m;i++) {
            scanf("%d",&b[i]);
        }
        scanf("%d",&c);
        while(c--) {
            int x,y;
            scanf("%d%d",&x,&y);
            int fx=HornerRule(x,n,a);
            int fy=HornerRule(y,m,b);
            int ans=fx*fy;
            printf("%d\n",ans);
        }
    }
}

