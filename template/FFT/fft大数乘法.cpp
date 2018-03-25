//https://buaacoding.cn/problem/240/index
#include <cstdio>
#include <cmath>
#include <cstring>
#define N 205050

using namespace std;
const double PI=acos(-1.0);

/**
 * big number multiply
 **/

struct Complex {
    double real,image;
    Complex(double _real=0.0,double _image=0.0):real(_real),image(_image) {}
    Complex operator*(Complex c) {
        return Complex(real*c.real-image*c.image,real*c.image+image*c.real);
    }
    Complex operator+(Complex c) {
        return Complex(real+c.real,image+c.image);
    }
    Complex operator-(Complex c) {
        return Complex(real-c.real,image-c.image);
    }
};

void bit_rev(Complex *a,int loglen,int len) {
    for(int i=0;i<len;++i) {
        int t=i,p=0;
        for(int j=0;j<loglen;++j) {
            p<<=1;
            p=p | (t & 1);
            t>>=1;
        }
        if(p<i) {
            Complex temp=a[p];
            a[p]=a[i];
            a[i]=temp;
        }
    }
}

void FFT(Complex *a,int loglen,int len,int on) {
    bit_rev(a,loglen,len);
    for(int s=1,m=2;s<=loglen;++s,m<<=1) {
        Complex wn=Complex(cos(2*PI*on/m),sin(2*PI*on/m));
        for(int i=0;i<len;i+=m) {
            Complex w=Complex(1.0,0.0);
            for(int j=0;j<m/2;++j) {
                Complex u=a[i+j];
                Complex v=w*a[i+j+m/2];
                a[i+j]=u+v;
                a[i+j+m/2]=u-v;
                w=w*wn;
            }
        }
    }
    if(on==-1) {
        for(int i=0;i<len;++i)
            a[i].real/=len,a[i].image/=len;
    }
}

char a[N*2],b[N*2];
Complex pa[N*2],pb[N*2];
int ans[N*2];

int main () {
    while(~scanf("%s%s",a,b)) {
        int lena=strlen(a);
        int lenb=strlen(b);
        int n=1,loglen=0;
        while(n<lena+lenb) n<<=1,loglen++;
        for(int i=0,j=lena-1;i<n;++i,--j)
            pa[i]=Complex(j>=0?a[j]-'0':0.0,0.0);
        for(int i=0,j=lenb-1;i<n; ++i,--j)
            pb[i]=Complex(j>=0?b[j]-'0':0.0,0.0);
        for(int i=0;i<=n;++i) ans[i]=0;
        FFT(pa,loglen,n,1);
        FFT(pb,loglen,n,1);
        for(int i=0;i<n;++i) pa[i]=pa[i]*pb[i];
        FFT(pa,loglen,n,-1);
        for(int i=0;i<n;++i) ans[i]=pa[i].real+0.5;
        for(int i=0;i<n;++i) ans[i+1]+=ans[i]/10,ans[i]%=10; //8 jin zhi
        int pos=lena+lenb-1;
        for(;pos>0 && ans[pos]<=0;--pos) ;
        for(;pos>=0;--pos) printf("%d",ans[pos]);
        printf("\n");
    }
    return 0;
}
