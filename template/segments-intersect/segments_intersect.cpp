#include <cstdio>
#include <algorithm>
using namespace std;

struct L {
    double x;
    double y;
}p[1000];

double direction(L p1,L p2,L p3) {
    //(p3-p1)x(p2-p1)
    return (p3.x-p1.x)*(p2.y-p1.y)-(p2.x-p1.x)*(p3.y-p1.y);
}

bool on_segment(L p1,L p2,L p3) {
    if(p3.x>=min(p1.x,p2.x) &&
       p3.x<=max(p1.x,p2.x) &&
       p3.y>=min(p1.y,p2.y) &&
       p3.y<=max(p1.y,p2.y)) return true;
    else return false;
}

bool segment_intersect(L p1,L p2,L p3,L p4) {
    double d1=direction(p3,p4,p1);
    double d2=direction(p3,p4,p2);
    double d3=direction(p1,p2,p3);
    double d4=direction(p1,p2,p4);
    if(d1*d2<0 &&d3*d4<0) return true;
    else if(d1==0 && on_segment(p3,p4,p1)) return true;
    else if(d2==0 && on_segment(p3,p4,p2)) return true;
    else if(d3==0 && on_segment(p1,p2,p3)) return true;
    else if(d4==0 && on_segment(p1,p2,p4)) return true;
    else return false;
}

int main() {
    for(int i=0;i<=3;i++) {
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    printf("%d\n",segment_intersect(p[0],p[1],p[2],p[3]));
}
