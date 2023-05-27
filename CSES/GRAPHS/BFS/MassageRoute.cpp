#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
 
#define  psb(v) push_back(v)
 
int n, m; //nós, arestas
vii gr; ; // lista de adj
vb visited; // marcador de visitados
vi dist; // distancia dos nós e pais dos nós
vi pai;
queue<int> q; // fila de execução  
 
void bfs(int s){
    visited[s] = true;
    dist[s] = 0;
    pai[s] = -1;
    q.push(s);
 
    while(!q.empty()){
        int u = q.front(); q.pop();
    
        for(int to : gr[u]){

            if(!visited[to]){
                pai[to] = u;
                visited[to] = true;
                
                dist[to] = dist[u] + 1; 

                q.push(to);
            }
        }
    }
}

void print(int filho){
    if(filho == -1){
        return;
    }
    print(pai[filho]);
    cout << filho << " ";
}
 
 
int main(){
    cin >> n >> m;
 
    gr.assign(n + 1, vi());
    visited.assign(n + 1, false);
    dist.assign(n + 1, 1e9);
    pai.assign(n + 1, 0);
 
    for (int i {1}; i <= m; ++i){
        int a, b; cin >> a >> b;
 
        gr[a].psb(b);
        gr[b].psb(a);
    }
 
    bfs(1);
   
    if(dist[n] == 1e9){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    cout << dist[n] + 1 << endl;
    print(n);
    cout << endl;
    return  0;
}