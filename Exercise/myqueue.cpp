// solution for 2019 final 排队
#include<iostream>
#include<queue>
using namespace std;
int father[20] = {};

void init(){
    for(int i = 1; i<20; i++) father[i]=i;
}
int GetRoot(int x){
    if(father[x] == x){
        return x;
    }
    father[x] = GetRoot(father[x]);
    return father[x];
}
void Union(int x, int y){
    int px = GetRoot(x);
    int py = GetRoot(y);
    if(px == py) return;
    father[px] = py;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        init();
int N, M;
    cin >> N>>M;
    for(int i = 1; i<=M;i++){
        int a,b;
        cin >> a >> b;
        Union(a,b);
    }
    for(int i = 1; i<=N; i++){
        cout <<GetRoot(i) <<" ";
    }
    cout << endl;
    }
    
}