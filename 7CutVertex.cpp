#include <iostream>
#include <vector>
#include<cstring>
using namespace std;

#define MyMax 80050
typedef vector<int> Edge;
vector<Edge> G(MyMax);
bool Visited[MyMax] ;
int dfn[MyMax] ;
int low[MyMax] ;
int Father[MyMax]; //DFS树中每个点的父节点
bool bIsCutVetext[MyMax]; //每个点是不是割点
int nTime; //Dfs时间戳
int n,m; //n是点数，m是边数
void Tarjan(int u, int father) //father 是u的父节点
{	
	Father[u] = father;
	int i,j,k;
	low[u] = dfn[u] = nTime ++;
	for( i = 0;i < G[u].size() ;i ++ ) {
		int v = G[u][i];
		if( ! dfn[v]) {
			Tarjan(v,u);
			low[u] = min(low[u],low[v]);
		}
		else if( father != v ) //连到父节点的回边不考虑，否则求不出桥
			low[u] = min(low[u],dfn[v]);
	}
}
void Count()
{ //计算割点和桥
	int i,nRootSons = 0;
	Tarjan(1,0);
	for( i = 2;i <= n;i ++ ) {
		int v = Father[i];
		if( v == 1 )
			nRootSons ++; //DFS树中根节点有几个子树
		else if( dfn[v] <= low[i])
			bIsCutVetext[v] = true;
	}
	if( nRootSons > 1)
		bIsCutVetext[1] = true;
	bool isnull = false;
    for( i = 1;i <= n;i ++ )
		if( bIsCutVetext[i] ){
            cout << i << " ";
            isnull = true;
        }
    if(!isnull) cout <<"null" << endl;
    else cout << endl;
			
	for( i = 1;i <= n;i ++) {
		int v = Father[i];
		if(v >0 &&  dfn[v] < low[i])
			cout << v << "," << i <<endl;
	}
}
int main()
{
	int M;
    cin >> M;
    while(M--){
        int u,v;
        int i;
       
        nTime = 1;
        cin >> n >> m ; //n是点数，m是边数
         for(int i = 1; i <= MyMax; i++){
            G[i].clear();
        }
        for(  i = 1;i <= m;i ++ ) {
            cin >> u >> v; //点编号从1开始
            G[v].push_back(u);
            G[u].push_back(v);
        }
        memset(Visited, 0, sizeof(Visited));
        memset( dfn,0,sizeof(dfn));
        memset( low, 0, sizeof(low));
        memset( Father,0,sizeof(Father));
        memset( bIsCutVetext,0,sizeof(bIsCutVetext));
        Count();
    }
    
	return 0;
}
