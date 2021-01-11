// solution for 最短路
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int T;
int M, N, V;
const int INF = 0x7fffffff;
const int maxN = 10010;
const int maxM = 20010;
struct edge{
    int s, e, len;
    edge(int s = 0, int e = 0, int len = 0):s(s), e(e), len(len){};
};
vector<edge> ve;
int dist[maxN] = {};

bool bellman_ford(int v){
    for(int i = 1; i <= N; i++){
        dist[i] = INF;
    }
    dist[v] = 0;
    int size = ve.size();
    for(int i = 0; i < N -1; i++){
        bool updateFlag = 0;
        for(int j = 0; j < size; j++){
            int x = ve[j].s;
            int y = ve[j].e;
            int len = ve[j].len;
            if(dist[x] == INF) continue;
            if(dist[y] > dist[x] + len){
                dist[y] = dist[x] + len;
                updateFlag = true;
            }
        }
        if(!updateFlag){
            break;
        }
    }
    // panduan
    for(int j = 0; j < size; j++){
        int x = ve[j].s;
        int y = ve[j].e;
        int len = ve[j].len;
        if(dist[x] == INF) continue;
        if(dist[y] > dist[x] + len){
            dist[y] = dist[x] + len;
            return true;
            // updateFlag = true;
        }
    }
    return 0;
}

int main(){
    // cout << 0x7FFFFFFF << endl;
    // cout << 10000 * 10000;
    cin >> T;
    int a, b, c;
    while(T--){
        memset(dist, 0, sizeof(dist));
        ve.clear();
        cin >> N >> M;
        cin >> V;
        for(int i = 0; i < M; i++){
            cin >> a >> b >> c;
            ve.push_back(edge(a,b,c));
        }
        if(bellman_ford(V)){
            cout << "Error" << endl;
        }
        else{
            for(int i = 1; i <= N; i++){
                if(dist[i] == INF){
                    cout << "null "; 
                }
                else    cout << dist[i] <<" ";
            }
            cout << endl;
        }
    }
}