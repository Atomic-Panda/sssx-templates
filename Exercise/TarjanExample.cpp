// P7251 [JSOI2014]强连通图
/*
 *UnionFindSet 
 *树状数组(一维)
 *线段树(一维)
 *Trie图
 *有向图求强连通分量
 *BF算法求最短路
 */
// Tarjan算法可以用来求强联通分量
#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<memory>
#include<cstring>
#include<set>
// #define DEBUG
using namespace std;
const int MAXN = 100050;
vector<int> ve[MAXN];
stack<int> S;
int N;
int E;
bool visited[MAXN];
int dfn[MAXN];
int low[MAXN];
int color[MAXN];
int idx = 0;
int num = 0;
set<int> colorin[MAXN];
set<int> colorout[MAXN];

void Tarjan(int u){
	dfn[u] = low[u] = idx++;
	S.push(u);
	visited[u] = 1;
	int size = ve[u].size();
	#ifdef DEBUG
	// cout << "Tarjan:" << u << "; size:"<<size << endl;
	#endif
	for (int i = 0; i < size; i++){
		if (size == 0) break;
		int t = ve[u][i];
		#ifdef DEBUG
		cout << "Accessing node "<< t << endl;
		#endif
		if(dfn[t] == 0){
			Tarjan(t);
			low[u] = min(low[u], low[t]);
		}
		else if(visited[t] == 1){
			low[u] = min(low[u], low[t]);
		}
	}
	if (dfn[u] == low[u]){
		num ++;
		int v;
		#ifdef DEBUG	
		cout << "SCC Index: "<<num <<endl;
		#endif
		do{
			v = S.top();
			S.pop();
			visited[v] = 0; 
			color[v] = num;
			#ifdef DEBUG
			printf("%d ", v);
			#endif
		}while(v != u);
		// cout << endl << endl;
	}
}
void DFS(){
	/*cout << in_degree.size() <<endl;
	if (in_degree.size() == 0) Tarjan(1);
	else for (int i = 0; i < in_degree.size(); i++){
		cout << in_degree[i] << "lingdu" <<endl;
		Tarjan(in_degree[i]);
	}*/
	for (int i= 1; i<=N;i++){
		if(!dfn[i]) Tarjan(i);
	}
}
int main(){
	idx = 1;
	memset(dfn, 0, sizeof(dfn));
	memset(visited, 0, sizeof(visited));
	memset(low, 0, sizeof(low));
	memset(color, 0 ,sizeof(color));
	cin >> N;
	cin >> E;
	int a,b;
	for (int i = 1; i <= E; i++){
		cin >> a >> b;
		ve[a].push_back(b);
	}
	DFS();
	int cnt[MAXN] = {};
	for(int i = 1; i <= N; i++){
		// cout << color[i] << endl;
		cnt[color[i]]++;
	}
	int maxcnt = 0;
	for(int i = 1; i <= num; i++){
		maxcnt = max(maxcnt, cnt[i]);
	}
	cout << maxcnt << endl;
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < ve[i].size(); j++){
			colorin[color[i]].insert(color[ve[i][j]]);
			colorout[color[ve[i][j]]].insert(color[i]);
		}
	}
	int indeg = 0, outdeg = 0;
	for(int i = 1; i <= num; i++){
		if(colorin[i].size() == 0) indeg++;
		if(colorout[i].size() == 0) outdeg++;
	}
	cout << max(indeg, outdeg) << endl;
	return 0;
}
