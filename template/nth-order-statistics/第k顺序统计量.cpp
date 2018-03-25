#include <bits/stdc++.h>
using namespace std;

int n,k;
int data[100005];

int main() {
    while(~scanf("%d%d",&n,&k)) {
        for(int i=0;i<n;i++) scanf("%d",&data[i]);
        nth_element(data,data+k-1,data+n);
        printf("%d\n",data[k-1]);
    }
}
