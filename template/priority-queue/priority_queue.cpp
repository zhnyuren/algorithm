#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

struct Node1 {
    int a;
    bool operator< (const Node1& d) const {
        return d.a>a;
    }
};

priority_queue<Node1> Q1;

//struct Node2 {
//    int a;
//};
//
//struct cmp {
//    bool operator() (Node2 x,Node2 y) {
//        return x.a<y.a;
//    }
//};

//priority_queue<Node2,vector<Node2>,cmp> Q2;

int main() {
    for(int i=0;i<6;i++) {
        int s;
        Node1 x;
//        Node2 y;
        scanf("%d",&s);
        x.a=s;
//        y.a=s;
        Q1.push(x);
//        Q2.push(y);
    }
    while(!Q1.empty()) {
        printf("%d\n",Q1.top());
        Q1.pop();
    }
//    while(!Q2.empty()) {
//        printf("%d\n",Q2.top());
//        Q2.pop();
//    }
}
