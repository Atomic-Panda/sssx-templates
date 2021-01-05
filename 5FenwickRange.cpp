// 树状数组 Fenwick Tree
// 更新过程是每次加了个二进制的低位1，比如我们更新5(101+1 ->110, 110 + 10 -> 1000, 1000 + 1000 -> 10000)
// 查询过程每次就是去掉了二进制中的低位1，比如我们查询sum(16)(1111 - 1 -> 1110, 1110 - 10 -> 1100, 1100 - 100 -> 1000)
// https://www.luogu.com.cn/problem/P3374

// 区间更新 区间求和 依旧采用差分的方法 维护新的数组c2[i] = (i-1)*c[i];
#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<memory>
#include<cstring>
using namespace std;
typedef long long ll;

int N;
ll a[1000005];
ll c[1000005];
ll c2[1000005];

int lowbit(int x) {return x&(-x);}

int getsum(int x){
    int res = 0;
    for(int i = x; i > 0; i-=lowbit(i)){
        res += x * c[i];
        res -= c2[i];
    }
    return res;
}

void update(int x, int k){
    for(int i = x; i <= N; i += lowbit(i)){
        c[i] += k;
        c2[i] += k*(x-1);
    }
}

int main(){
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    memset(c2, 0, sizeof(c2));
    int m;
    cin >> N >> m;
    int a = 0, b;
    for(int i = 0; i < N; i++){
        cin >> b;
        update(i + 1, b-a);
        a = b;
    }
    char op;
    int c, d;
    for(int j = 1; j <= m; j++){
        cin >> op;
        if(op == 'C'){
            cin >> b >> c >> d;
            update(b, d);
            update(c + 1, -d);
        }
        else if(op == 'Q'){
            cin >> b >> c;
            cout << getsum(c) - getsum(b-1) << endl;
        }
    }
    return 0;
    return 0;
}