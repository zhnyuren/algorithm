#include<bits/stdc++.h>

const int N=203;
const int mod=1000007;
using namespace std;

int n,s[N];

int main() {
    while(~scanf("%d",&n)) {
        int ans=0,x;
        for(int i=1;i<=n;i++) {
            scanf("%d",&x);
            int l=1,r=ans+1,mid;
            while(l!=r) {
                mid=(l+r)/2;
                if(x<=s[mid]) l=mid + 1;
                else r=mid;
            }
            s[l]=x;
            if(ans<l) ans=l;
            printf("ans:%d\n",ans);
        }
        printf("%d\n",ans);
    }
}
