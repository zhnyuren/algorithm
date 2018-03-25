#include <bits/stdc++.h>
using namespace std;

int n,k;
int data[10000];

int Partition(int A[],int l,int r) {
    int pivot=A[l];
    int i=l;
    for(int j=l+1;j<=r;++j) {
        if(A[j]<=pivot) {
            ++i;
            swap(A[i],A[j]);
        }
    }
    swap(A[i],A[l]);
    return i;
}

int Randomized_Partition(int A[],int l,int r) {
    srand(time(NULL));
    int i=rand()%(r+1);
    swap(A[l],A[i]);
    return Partition(A,l,r);
}

int Randomized_Select(int A[],int p,int q,int i) {
    if(p==q) return A[p];
    int t=Randomized_Partition(A,p,q);
    int k=t-p+1;
    if(i==k) return A[t];
    if(i<k) return Randomized_Select(A,p,t-1,i);
    else return Randomized_Select(A,t+1,q,i-k);
}


int main() {
    while(~scanf("%d%d",&n,&k)) {
        for(int i=0;i<n;i++) {
            scanf("%d",&data[i]);
        }
        printf("%d\n",Randomized_Select(data,0,n-1,k));
    }
}
