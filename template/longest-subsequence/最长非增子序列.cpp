
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int inf=0x3f3f3f3f;
int n;
int data[10007];
int last[10007];
int res;

int main() {
    while(~scanf("%d",&n)) {
        for(int i=n-1;i>=0;i--) {
            scanf("%d",&data[i]);
        }
        fill(last,last+n,inf);
        res=0;
        for(int i=0;i<n;i++) {
            int j=upper_bound(last,last+n,data[i])-last;
            if(res<j+1) res=j+1;
            last[j]=data[i];
            printf("last[%d]=%d\n",j,last[j]);
            printf("res:%d\n",res);
        }
        printf("%d\n",res);
    }
}
/*
10
5 4 3 6 1 1 7 8 9 0
*/

