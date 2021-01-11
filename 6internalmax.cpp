// 树状数组求最大值
// 一个小练习，可以仿照interval.cpp中的push_down和push_up函数优化

#include <iostream>
#include <queue>

using namespace std;
const int maxN = 100000;
const int INF = 0x3fffffff;
struct node{
    int l;
    int r;
    int max;
}tree[maxN * 4];

void build(int i, int l, int r){
    tree[i].l = l;
    tree[i].r = r;
    tree[i].max = -INF;
    if(l == r) return;
    int mid = l + r >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
}
void Modify(int i, int pos, int v){
    cout << i <<endl;
    if(pos >= tree[i].l && pos <= tree[i].r){
        tree[i].max = max(tree[i].max, v);
    }
    if(tree[i].l == tree[i].r) {
        return;
    }
    int mid = tree[i].l + tree[i].r >> 1;
    if(pos <= mid){
        Modify(2*i, pos, v);
    }
    else if(pos > mid){
        Modify(2*i+1, pos, v);
    }
}
int maxres = -INF;
void Query(int i, int l, int r){
    // cout << i <<" "<< l <<" "<< r <<endl;
    if(l == tree[i].l && r == tree[i].r){
        maxres = max(maxres, tree[i].max);
        return;
    }
    int mid = tree[i].l + tree[i].r >> 1;
    if(mid < l) {Query(2*i+1, l, r); return;}
    else if(mid >= r) {Query(2*i, l, r); return;}
    else {Query(2*i, l, mid); Query(2*i+1, mid+1, r); return;}
}
int main(){
    int M, N;
    cin >> N >> M;
    build(1, 1, N);
    for(int i = 1; i<=N; i++){
        int v;
        cin >> v;
        Modify(1, i, v);
    }
    for(int i = 1; i<=M; i++){
        int a,b;
        cin >> a >>b;
        cout <<Query(1, a, b);
    }
}