// 树状数组 Fenwick Tree
// 更新过程是每次加了个二进制的低位1，比如我们更新5(101+1 ->110, 110 + 10 -> 1000, 1000 + 1000 -> 10000)
// 查询过程每次就是去掉了二进制中的低位1，比如我们查询sum(16)(1111 - 1 -> 1110, 1110 - 10 -> 1100, 1100 - 100 -> 1000)
// https://www.luogu.com.cn/problem/P3374

#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<memory>
#include<cstring>
using namespace std;

int N;
int a[500005];
int c[500005];
int lowbit(int x) {return x&(-x);}
int getsum(int x){
    int res = 0;
    for(int i = x; i > 0; i-=lowbit(i)){
        res += c[i];
    }
    return res;
}
void update(int x, int k){
    for(int i = x; i <= N; i += lowbit(i)){
        c[i] += k;
    }
}
int main(){
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    // int m;
    // cin >> N >> m;
    // for(int i = 0; i < N; i++){
    //     int t;
    //     cin >> t;
    //     update(i+1, t);
    // }
    // for(int j = 0; j < m; j++){
    //     int a, b, c;
    //     cin >> a >> b >> c;
    //     if(a == 1){
    //         update(b, c);
    //     }
    //     else{
    //         cout << getsum(c) - getsum(b-1) << endl;
    //     }
    // }
    // P3368
    int m;
    cin >> N >> m;
    int a = 0, b;
    for(int i = 0; i < N; i++){
        cin >> b;
        update(i + 1, b-a);
        a = b;
    }
    int c, d;
    for(int j = 1; j <= m; j++){
        cin >> a;
        if(a == 1){
            cin >> b >> c >> d;
            update(b, d);
            update(c + 1, -d);
        }
        else if(a == 2){
            cin >> b;
            cout << getsum(b) << endl;
        }
    }
    return 0;
    return 0;
}