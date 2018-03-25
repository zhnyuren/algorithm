#include <cstdio>
#include <cstring>
using namespace std;

int n;
int p[307];
int ans[307][307];
int s[307][307];

void printRes(int s[][307],int i,int j) {
    if(i==j) {
        printf("A%d",i);
    }
    else {
        printf("(");
        printRes(s,i,s[i][j]);
        printRes(s,s[i][j]+1,j);
        printf(")");
    }
}

int main() {
    while(~scanf("%d",&n)) {
        for(int i=0;i<=n;i++) {
            scanf("%d",&p[i]);
        }
        memset(ans,0,sizeof(ans));
        memset(s,0,sizeof(s));
        for(int l=2;l<=n;l++) {
            for(int i=1;i<=n-l+1;i++) {
                int j=i+l-1;
                ans[i][j]=0x3f3f3f3f;
                for(int k=i;k<=j-1;k++) {
                    int tmp=ans[i][k]+ans[k+1][j]+p[i-1]*p[k]*p[j];
                    if(tmp<=ans[i][j]) {
                        ans[i][j]=tmp;
                        s[i][j]=k;
                    }
                }
            }
        }
        printRes(s,1,n);
        printf("\n");
    }
}
