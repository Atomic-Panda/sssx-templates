// solution for 树状数组过线段树不过
#include<iostream>
using namespace std;

int nextRand(int num){
    return (num*199+666)% 9875321;
}
int C[300050] = {};
int A[300050] = {};
int m,n;
inline int lowbit(int x){
    return x&(-x);
}
void Update(int x){
    while(x <= n){
        C[x] += 1;
        x += lowbit(x);
    }
}
long long GetSum(int x){
    long long sum =0;
    while(x != 0){
        sum += C[x];
        x-=lowbit(x);
    }
    return sum;
}
int main(){
    // int m;
    cin >> m >> n;
    int num = 0;
    int x;
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        num = nextRand(num);
        x = num % m + 1;
        ans += GetSum(x-1);
        Update(x);
    }
    cout << ans;
    return 0;
}