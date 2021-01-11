#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<memory>
#include<cstring>

// using namespace std;

// const int maxn = 100005;

// struct Cnode{
//     int l;
//     int r;
//     int lazy;
//     long long sum;
// }tree[maxn * 4];

// // start from 1
// void build(int i, int l, int r){
//     tree[i].l = l;
//     tree[i].r = r;
//     if(l == r){
//         cin >> tree[i].sum;
//         return;
//     }
//     int mid = (l+r) >> 1;
//     build(2*i, l, mid);
//     build(2*i+1, mid+1,r);
//     tree[i].sum = tree[2*i].sum + tree[2*i + 1].sum;
// }

// void add(int i, int l, int r, int k){
//     if(tree[i].r == tree[i].l){
//         tree[i].sum += k;
//         return;
//     }
//     int mid = (tree[i].l + tree[i].r) >> 1;
//     if(l <= mid) add(2*i, l, r, k);
//     if(r > mid) add(2*i + 1, l, r, k);
//     tree[i].sum = tree[2*i].sum + tree[2*i+1].sum;
// }

// long long query(int i, int l, int r){
//     if(tree[i].l == l && tree[i].r == r){
//         return tree[i].sum;
//     }
//     int mid = tree[i].l + tree[i].r >> 1;
//     if(r <= mid) return query(2*i, l, r);
//     else if(l > mid) return query(2*i + 1, l, r);
//     else return query(2 * i, l, mid) + query(2*i+1, mid+1, r);
// }
// int main(){
//     int n,m,op;
//     cin >> n >> m;
//     build(1,1,n);
//     int l,r,v;
//     for(int j = 1; j <= m; j++){
//         cin >> op;
//         if(op == 1){
//             cin >> l >> r >> v;
//             add(1, l, r, v);
//         }
//         if(op == 2){
//             cin >> l >> r;
//             cout << query(1, l, r) << endl;
//         }
//     }
//     return 0;
// }

using namespace std;
typedef long long LL;
const int MAXN = 100010;
struct Node {
    int l, r;
    LL lazy;
    LL sum;
} segTree[MAXN * 4];

void build(int i, int l, int r){
    segTree[i].l = l;
    segTree[i].r = r;
    if(l == r){
        cin >> segTree[i].sum;
        return;
    }
    int mid = (l+r) >> 1;
    build(2*i, l, mid);
    build(2*i + 1, mid+1, r);
    segTree[i].sum = segTree[2*i].sum + segTree[2*i + 1].sum;
}

void push_up(int i, LL v){
    segTree[i].sum += (segTree[i].r - segTree[i].l + 1) * v;
    segTree[i].lazy += v;
}
void push_down(int i){
    if(segTree[i].l == segTree[i].r) return;
    push_up(2*i, segTree[i].lazy);
    push_up(2*i+1, segTree[i].lazy);
    segTree[i].lazy = 0;
}

void add(int i, int l, int r, int v){
    if(segTree[i].l >= l && segTree[i].r <= r){
        push_up(i, v);
        return;
    }
    push_down(i);
    int mid = segTree[i].l + segTree[i].r >> 1;
    if(mid >= l){
        add(2*i, l, r, v);
    }
    if(r > mid){
        add(2*i + 1, l, r, v);
    }
    segTree[i].sum = segTree[2*i].sum + segTree[2*i + 1].sum;
}

LL query(int i, int l, int r){
    if(segTree[i].l == l && segTree[i].r == r){
        return segTree[i].sum;
    }
    push_down(i);
    int mid = segTree[i].l + segTree[i].r >> 1;
    if(r <= mid) return query(2*i, l, r);
    else if(l > mid) return query(2*i+1, l, r);
    else{
        return query(2*i, l, mid) + query(2*i+1, mid+1, r);
    }
}

int main() {
    int n, m, op;
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    int l, r; LL v;
    while (m--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%lld", &l, &r, &v);
            add(1, l, r, v);
        } else {
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(1, l, r));
        }
    }
    return 0;
}