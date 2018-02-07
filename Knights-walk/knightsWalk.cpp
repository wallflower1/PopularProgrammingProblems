#include <iostream>
#include <utility>
#include <queue>
using namespace std;

using Pair = pair<pair<int, int>, int>;

int dir[8][2] = { {-1,2}, {1,2}, {2,1}, {2,-1}, 
                    {-1,-2}, {1,-2}, {-2,1}, {-2,-1} };

                    
bool isCellValid(int x, int y, int R, int C){
    
    if(x <0 || x >=R || y <0 || y >= C)
        return false;
    return true;
}

int knightsWalk(int N, int M, Pair s, Pair d){
    queue<Pair> q;
    bool visit[N][M];    
    q.push(s);
    visit[s.first.first][s.first.second] = true; 
    
    while(!q.empty()){
        Pair curr = q.front();
        q.pop();
        if(curr.first.first == d.first.first
            && curr.first.second == d.first.second){
            return curr.second;
        }
        //push all adj moves to q
        for(int i=0; i<8; i++){
            Pair z;
            z.first.first = curr.first.first + dir[i][0];
            z.first.second = curr.first.second + dir[i][1];
            z.second = curr.second + 1;
            if(isCellValid(z.first.first, z.first.second, N, M) 
                && visit[z.first.first][z.first.second] == false){
                    q.push(z);
                    visit[z.first.first][z.first.second] = true;
            }
        }
    }
    return -1;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int N, M;
	    Pair s, d;
	    
	    cin>>N>>M>>s.first.first>>s.first.second;
	    cin>>d.first.first>>d.first.second;
	    s.first.first--; s.first.second--;
	    d.first.first--;d.first.second--;
	    s.second = 0; d.second = -1;
	    cout<<knightsWalk(N, M, s, d)<<"\n";
	   
	}
	return 0;
}