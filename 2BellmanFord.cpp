/*
 *UnionFindSet 
 *树状数组(一维)
 *线段树(一维)
 *Trie图
 *有向图求强连通分量
 *BF算法求最短路
 */
// BF算法可以处理负权边，但不适用于负权回路，算法复杂度为O(N*E)
// code is for 洛谷P3385
#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<memory>
#include<string>

using namespace std;
const int INF = 0x7fffffff;
const int MAXN = 2010;

struct edge{
    int s;
    int e;
    int len;
    edge(int s, int e, int len):s(s), e(e), len(len){}
    edge(){}
};
// N为节点数, M为边数
int N, M;
vector<edge> Edges;
int dist[MAXN] = {};

/*
 *Bellman-Ford算法不一定要循环n-1次，n为顶点个数
 *只要在某次循环过程中，考虑每条边后，源点到所有顶点的最短路径长度都没有变，
 *那么Bellman-Ford算法就可以提前结束了
 *v是源点，返回值表示是否有负权回路
 */
bool bellman_ford(int v){
    for(int i = 1; i <= N; i++){
        dist[i] = INF;
    }
    dist[v] = 0;
    int size = Edges.size();
    bool updateFlag = 0;
    for(int k = 0; k < N - 1; k++){
        updateFlag = 0;
        for(int i = 0; i < size; i++){
            int s = Edges[i].s;
            int e = Edges[i].e;
            int len = Edges[i].len;
            if(dist[s] != INF){
                if(dist[s] + len < dist[e]){
                    dist[e] = dist[s] + len;
                    updateFlag = 1;
                }
            }
        }
        if(!updateFlag) break;
    }
    for(int i = 0; i < size; i++){
        int s = Edges[i].s;
        int e = Edges[i].e;
        int len = Edges[i].len;
        if(dist[s] != INF && dist[s] + len < dist[e]) return true;
    }
    return false;
}

int main(){
    int testcase = 0;
    cin >> testcase;
    for(int k = 0; k < testcase; k++){
        cin >> N >> M;
        Edges.clear();
		for (int i = 0; i < M; i++){
			int a,b,c;
			cin >> a >> b >> c;
            if(c >= 0){
                Edges.push_back(edge(b,a,c));
            }
			Edges.push_back(edge(a,b,c));
		}
		if(bellman_ford(1))
			cout << "YES\n";
		else cout << "NO\n";
	}
}