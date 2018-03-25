#include <cstdio>
#include <cstring>
using namespace std;

struct BigNum {
    int num[100];
    int len;
};

BigNum BigMul(BigNum a,BigNum b) {
    BigNum tmp;
    memset(tmp.num,0,sizeof(tmp.num));
    tmp.len=0;
    int n1=a.len;
    int n2=b.len;
    for(int i=0;i<n2;i++) {
        for(int j=0;j<n1;j++) {
            tmp.num[i+j]+=(a.num[j]*b.num[i]);
        }
    }
    int c=0;
    for(int i=0;i<n1+n2;i++) {
        int k=tmp.num[i];
        tmp.num[i]=(k+c)%10;
        c=(k+c)/10;
    }
    for(int i=n1+n2;i>=0;i--) {
        if(tmp.num[i]!=0) {
            tmp.len=i+1;
            break;
        }
    }
    if(tmp.len==0) {// important
        tmp.num[0]=0;
        tmp.len=1;
    }
    return tmp;
}

int BigCmp(BigNum a,BigNum b) {
    //a>b -> return 1
    //a<b -> return -1
    //a=b -> return 0;
    int n1=a.len;
    int n2=b.len;
    if(n1>n2) return 1;
    else if(n1<n2) return -1;
    for(int i=n1-1;i>=0;i--) {
        if(a.num[i]>b.num[i]) return 1;
        else if(a.num[i]<b.num[i]) return -1;
    }
    return 0;
}

int main() {
    BigNum a;
    scanf("%d",&a.len);
    for(int i=0;i<a.len;i++) scanf("%d",&a.num[i]);
    BigNum b;
    scanf("%d",&b.len);
    for(int i=0;i<b.len;i++) scanf("%d",&b.num[i]);
    BigNum c;
    c=BigMul(a,b);
    printf("%d\n",BigCmp(a,c));
}
