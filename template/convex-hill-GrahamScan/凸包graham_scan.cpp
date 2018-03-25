#include <cstdio>
using namespace std;
/**
 * One important thing:
 * special judge when N==2
**/
struct Node {
    int x;
    int y;
};

Node nd[10000];
Node s[10000];
int top=-1;
int N;

int dis(Node a,Node b) {
    return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
}

int crossProduct(Node p1,Node p2,Node p3,Node p4) {
    return (p2.x-p1.x)*(p4.y-p3.y)-(p2.y-p1.y)*(p4.x-p3.x);
}

bool cmpSortPolarAngle(Node a,Node b) {
    if(crossProduct(nd[0],a,nd[0],b)>0) return true;
    if(crossProduct(nd[0],a,nd[0],b)==0 &&
       dis(a,nd[0])<dis(b,nd[0])) return true;
    return false;
}

void GrahamScan() {
    int k=0;
    for(int i=1;i<N;i++) {
        if(nd[k].y>nd[i].y) k=i;
        else if(nd[k].y==nd[i].y) {
            if(nd[k].x>nd[i].x) k=i;
        }
    }
    swap(nd[0],nd[k]);
    sort(nd+1,nd+N,cmpSortPolarAngle);
    top=-1;
    s[++top]=nd[0];
    s[++top]=nd[1];
    s[++top]=nd[2];
    for(int i=3;i<N;i++) {
        while(top>=1 && crossProduct(s[top-1],s[top],s[top-1],nd[i])<0)
            top--;
        s[++top]=nd[i];
    }
}

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d%d",&nd[i].x,&nd[i].y);
    }
    GrahamScan();
    if(N==2) {}
    else {}
}
