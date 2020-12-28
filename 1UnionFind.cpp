/*
 *UnionFindSet 
 *树状数组(一维)
 *线段树(一维)
 *Trie图
 *有向图求强连通分量
 *BF算法求最短路
 */

#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<memory>
#include<string>

using namespace std;

const int MAXN = 100010;
int father[MAXN] = {};
void initial(){
    for(int i = 0; i < MAXN; i++){
        father[i] = i;
    }
}
int GetRoot(int n){
    if(father[n] == n){
        return n;
    }
    else{
        father[n] = GetRoot(father[n]);
        return father[n];
    }
}
void Union(int m, int n){
    int r1 = GetRoot(m);
    int r2 = GetRoot(n);
    if(r1 != r2){
        father[r1] = r2;
    }
    return;
}
bool Query(int m, int n){
    int r1 = GetRoot(m);
    int r2 = GetRoot(n);
    if(r1 != r2){
        return false;
    }
    return true;
}
int main(){
    initial();
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m;i++){
        int z, x, y;
        cin >> z >> x >> y;
        if(z == 1){
            Union(x, y);
        }
        else{
            if(Query(x, y)){
                cout << "Y" << endl;
            }
            else{
                cout <<"N" << endl;
            }
        }
    }
    return 0;
}