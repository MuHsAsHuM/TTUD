#include <bits/stdc++.h> 
using namespace std;
#define pii pair<int,int>

const int MAXN = 1e3 +5;
int maze[MAXN][MAXN] = {0};
int dist[MAXN][MAXN];
int n,m,r,c;

void input(){
    cin>>n>>m>>r>>c;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>maze[i][j];
        }
    }
}

void find_path(){
    queue<pair<int,int>> q;
    
    q.push({r,c});
    int dx[] = {0,1,0,-1}; //W,S,D,A
    int dy[] = {-1,0,1,0};
    
    while(!q.empty()){
        pii u = q.front();
        q.pop();
        
        maze[u.first][u.second] = 1;
        
        for(int i=0; i<4; i++){
            int y = u.first + dy[i];
            int x = u.second + dx[i];
            
            if(x < 1 || x>n || y<1 || y>m){
                cout<<dist[u.first][u.second] + 1;
            }
            
            if(maze[y][x] !=1){
                q.push({y,x});
                dist[y][x] = dist[u.first][u.second] +1;
                maze[y][x] = 1; 
            }
        }
    }
}
int main() { 
    input();
    find_path();
    return 0;
}
    
