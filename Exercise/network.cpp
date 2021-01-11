// solution for 网络连通性测试
#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<set>

using namespace std;

const int maxN = 100010;
const int maxM = 400010;

int dfn[maxN] = {};
int visited[maxN] = {};
int low[maxN] = {};
int N, M;
int color[maxN];
int colornum = 0;
int idx = 0;
// 每个node的相邻node
vector<int> ve[maxN];
stack<int> S;
set<int> indegree[maxN];
set<int> outdegree[maxN];
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
		else{
			low[u] = min(low[u], low[t]);
		}
	}
	if (dfn[u] == low[u]){
		colornum ++;
		int v;
		do{
			v = S.top();
			S.pop();
			visited[v] = 0; 
			color[v] = colornum;
		}while(v != u);
		// cout << endl << endl;
	}
}
void DFS(){
    for(int i = 1; i <= N; i++){
        if(!dfn[i]) Tarjan(i);
    }
}
int main(){
    int T;
    cin >> T;
    while(T--){
        while(!S.empty()) S.pop();
        for(int i = 0; i < maxN; i++){
            indegree[i].clear();
            outdegree[i].clear();
            ve[i].clear();
        }
        colornum = 0;
        idx = 1;
        memset(dfn, 0 ,sizeof(dfn));
        memset(visited, 0, sizeof(visited));
        memset(low, 0, sizeof(low));
        memset(color, 0, sizeof(-1));
        cin >> N >> M;
        int a, b;
        for(int i = 0; i < M; i++){
            // cout <<1 << endl;
            cin >> a >>b;
            ve[a].push_back(b);
        }
        
        DFS();
        bool flag = 0;
        // cout << colornum << endl;
        // for(int i = 1; i<=N; i++){
        //     cout << color[i] <<" ";
        // }
        // cout << endl;
        if (colornum == 1){
            cout << "Strong" << endl;
            flag = 1;
            continue;
        }
        

        for(int i = 1; i<=N; i++){
            for(int j = 0; j < ve[i].size(); j++){
                if(color[ve[i][j]] == color[i]) continue;
                indegree[color[ve[i][j]]].insert(color[i]);
                outdegree[color[i]].insert(color[ve[i][j]]);
            }
        }
        // for(int i = 1; i<=colornum; i++){
        //     cout <<i <<" ";
        //     cout << indegree[i].size() << " ";
        //     cout << outdegree[i].size() << endl;
        // }
        queue<int> que;
        int rudu[maxN] = {};
        for(int i = 1; i <= colornum; i++){
            rudu[i] = indegree[i].size();
            if(rudu[i]== 0) que.push(i);
        }
        while(!que.empty()){
            if(que.size() > 1) {
                cout << "Error" << endl;flag =1; 
                // while(!que.empty()) {
                //     cout << que.front() <<" ";
                //     que.pop();
                    
                // }
                // cout << endl;
                break;
            }
            int x = que.front();
            que.pop();
            for(set<int>::iterator it = outdegree[x].begin(); it != outdegree[x].end(); it++){
                int y = *it;
                rudu[y] --;
                if(rudu[y] == 0) que.push(y);
            }
        }
        if(flag == 0) cout << "Weak" << endl;
    }
    return 0;
}