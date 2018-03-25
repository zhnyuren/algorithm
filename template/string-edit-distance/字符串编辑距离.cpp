#include <bits/stdc++.h>
#define LL long long
using namespace std;

char s1[1007];
char s2[1007];
int ans[1007][1007];
int n1,n2;

int solve(char s1[],char s2[]) {
    memset(ans,0,sizeof(ans));
    int i=0,j=0;
    for(j=0;j<=n2;j++) ans[0][j]=j;
    for(i=0;i<=n1;i++) ans[i][0]=i;
    for(i=1;i<=n1;i++) {
        for(j=1;j<=n2;j++) {
            if(s1[i-1]==s2[j-1]) ans[i][j]=ans[i-1][j-1];
            else {
               ans[i][j]=min(ans[i][j-1],
                         min(ans[i-1][j],
                             ans[i-1][j-1]))+1;
            }
        }
    }
    return ans[i-1][j-1];
}


int main() {
    while(~scanf("%s%s",s1,s2)) {
        n1=strlen(s1);
        n2=strlen(s2);
        printf("%d\n",solve(s1,s2));
    }
}
