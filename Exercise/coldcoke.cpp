// solution for 冰阔落
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
int father[50005];

int GetRoot(int n){
    if (father[n] != n){
        father[n] = GetRoot(father[n]);
    }
    return father[n];
}

void Union(int x, int y){
    int p1 = GetRoot(x);
    int p2 = GetRoot(y);
    if(p1 == p2) return;
    father[p2] = p1;
}

void init(){
    for(int i = 0; i <= N; i++){
        father[i] = i;
    }
}
int main(){
    while(cin >> N >> M){
        init();
        for(int i = 0; i < M; i++){
            int x,y;
            cin >> x >> y;
            if(GetRoot(x) == GetRoot(y)){
                cout << "Yes" << endl;
            }
            else{
                cout <<"No" << endl;
                Union(x, y);
            }
        }
        vector<int> ve;
        ve.clear();
        for(int i = 1; i <= N; i++){
            if(father[i] == i){
                ve.push_back(i);
            }
        }
        cout << ve.size() << endl;
        for(int i = 0; i < ve.size(); i++){
            cout <<ve[i] << " ";
        }
        cout << endl;
    }
    
}