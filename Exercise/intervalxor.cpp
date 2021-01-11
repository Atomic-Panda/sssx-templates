// solution for 区间异或和
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

const int maxN = 100010;
using namespace std;
int A[maxN] = {};
int C[maxN] = {};
int N, Q;

inline int lowbit(int x){
    return x&(-x);
}

// set to v, instead of add v;
void update(int i, int v){
    while(i <= N){
        C[i] ^= v;
        i+=lowbit(i);
    }
    return;
}

int query(int i){
    int res = 0;
    while(i>=1){
        res ^= C[i];
        i -= lowbit(i);
    }    
    return res;
}

int main(){
    // cout << ((0^3)^6) << endl;
    while(cin >> N >> Q){
        memset(A, 0, sizeof(A));
        memset(C, 0 ,sizeof(C));
        for(int i = 1; i <= N; i ++){
            update(i, i);
            A[i] = i;
        }
        int ans = 0;
        for(int i = 1; i <= Q; i++){
            int a, b, c;
            cin >> a >> b >> c;
            if(a == 1){
                update(b, c^A[b]);
                A[b] = c;
            }
            else{
                // ans = 0;
                ans ^= query(b-1);
                ans ^= query(c);
                // cout << ans << endl;
            }
        }
        cout << ans <<endl;
    }
}