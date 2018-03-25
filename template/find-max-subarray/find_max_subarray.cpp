#include <cstdio>
using namespace std;

int n;
int data[10000];
const int inf=0x3f3f3f3f;

/**
* method:
* recursion.
* Three situation: in left sub-array, in right sub-array, cross left and right.
* Choose the largest one.
* Divide to sub problems in first two.
* As for the third one, traverse from mid to two sides of the array. time complexity: O(n)
*/

int findCross(int arr[],int l,int mid,int r) {
    int lsum=-inf;
    int sum=0;
    for(int i=mid;i>=l;i--) {
        sum+=arr[i];
        if(sum>lsum) lsum=sum;
    }
    int rsum=-inf;
    sum=0;
    for(int i=mid+1;i<=r;i++) {
        sum+=arr[i];
        if(sum>rsum) rsum=sum;
    }
    return lsum+rsum;
}

int findMaxSubArr(int arr[],int l,int r) {
    if(l==r) return arr[l];
    else {
        int mid=(l+r)/2;
        int lsum=findMaxSubArr(arr,l,mid);
        int rsum=findMaxSubArr(arr,mid+1,r);
        int csum=findCross(arr,l,mid,r);
        if(lsum>rsum && lsum>csum) return lsum;
        else if(rsum>lsum && rsum>csum) return rsum;
        else if(csum>lsum && csum>rsum) return csum;
    }
}

int main() {
    while(~scanf("%d",&n)) {
        for(int i=0;i<n;i++) {
            scanf("%d",&data[i]);
        }
        printf("%d\n",findMaxSubArr(data,0,n-1));
    }
}

/*
16
13 -3 -25 20 -3 -16 -23 18 20 -7 12 -5 -22 15 -4 7
*/
