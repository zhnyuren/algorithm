#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int top;

struct Node {
    int num;
    int x;
    int y;
}nd[10000],s[10000];

int dis(Node a,Node b) {
    return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
}

int crossProduct(Node p1,Node p2,Node p3,Node p4) {
    return (p2.x-p1.x)*(p4.y-p3.y)-(p2.y-p1.y)*(p4.x-p3.x);
}

void jarvis() {
    int k=0;
    top=-1;
    for(int i=1;i<N;i++) {
        if(nd[i].y<nd[k].y) k=i;
        else if(nd[i].y==nd[k].y) {
            if(nd[i].x<nd[k].x) k=i;
        }
    }
    swap(nd[k].num,nd[0].num);
    swap(nd[k],nd[0]);
    s[++top]=nd[0];
    k=0;//out
    while(top==0 || (top!=0 && s[0].x!=s[top].x && s[0].y!=s[top].y)) {
        for(int j=0;j<N;j++) {
            if(s[top].num!=j) {
                if(crossProduct(nd[s[top].num],nd[k],nd[s[top].num],nd[j])<0) {
                    k=j;
                }
                else if(crossProduct(nd[s[top].num],nd[k],nd[s[top].num],nd[j])==0) {
                    if(dis(nd[s[top].num],nd[k])<dis(nd[s[top].num],nd[j])) {
                        k=j;
                    }
                }
            }
        }
        s[++top]=nd[k];
    }
}

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d%d",&nd[i].x,&nd[i].y);
        nd[i].num=i;
    }
    jarvis();
}
