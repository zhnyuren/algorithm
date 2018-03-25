#include <cstdio>
using namespace std;

int n,t,x,y,ans;
int data[10010];
int mat[1003][10010];

void merge_process(int arr[],int l,int mid,int r) {
    int i=l,j=mid+1,s=r-l+1,k=0;
    int *tmpArr;
    tmpArr=new int[s];
    while(i<=mid && j<=r) {
        if(arr[i]<=arr[j]) tmpArr[k++]=arr[i++];
        else {
            ans+=(j-k-l);
            tmpArr[k++]=arr[j++];
        }
    }
    while(i<=mid) tmpArr[k++]=arr[i++];
    while(j<=r) tmpArr[k++]=arr[j++];
    for(i=0;i<s;i++) arr[l+i]=tmpArr[i];
    delete []tmpArr;
}

void merge_sort(int arr[],int l,int r) {
    if(l<r) {
        int mid=(r+l)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge_process(arr,l,mid,r);
    }
}

int main() {
    while(~scanf("%d",&n)) {
        for(int i=0;i<n;i++) {
            scanf("%d",&data[i]);
        }
        scanf("%d",&t);
        // t´ÎÑ¯ÎÊ
        for(int i=0;i<t;i++) {
            for(int j=0;j<n;j++) {
                mat[i][j]=data[j];
            }
        }
        for(int i=0;i<t;i++) {
            ans=0;
            scanf("%d%d",&x,&y);
            merge_sort(mat[i],x,y);
            printf("%d\n",ans);
        }
    }
}
