#include <bits/stdc++.h>

using namespace std;

char maze[11][11];

bool ratChasesItsCheese(int n, int m, int sr = 0, int sc = 0) {
	if(maze[sr][sc] == 'X')
		return false;

	if(sr == n and sc == m) {
		maze[sr][sc] = '1';

		for(int i=0; i<=n; ++i) {
			for(int j=0; j<=m; ++j) {
				if(maze[i][j] == '1')
					cout << '1';
				else
					cout << '0';
				cout << " ";
			}	
			cout << endl;
		}

		return true;
	}

	maze[sr][sc] = '1';

	bool up = false, left = false, right = false, down = false;


	//call right
	if(sc+1 <= m and maze[sr][sc+1] != 'X' and maze[sr][sc+1] != '1') {
		// cout << "RIGHT\n";
		right = ratChasesItsCheese(n, m, sr, sc+1);
	}
	
	//call down
	if(!right and sr+1 <= n and maze[sr+1][sc] != 'X' and maze[sr+1][sc] != '1') {
		// cout << "DOWN\n";
		down = ratChasesItsCheese(n, m, sr+1, sc);
	}

	//call left
	if(!right and !down and sc-1 >= 0 and maze[sr][sc-1] != 'X' and maze[sr][sc-1] != '1') {
		// cout << "LEFT\n";
		left = ratChasesItsCheese(n, m, sr, sc-1);
	}

	//call up
	if(!right and !down and !left and sr-1 >= 0 and maze[sr-1][sc] != 'X' and maze[sr-1][sc] != '1') {
		// cout << "UP\n";
		up = ratChasesItsCheese(n, m, sr-1, sc);
	}

	if(right or down or left or up)
		return true;

	maze[sr][sc] = '0';

	return false;
}

int main() {
	int n, m;
	cin >> n >> m;

	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cin >> maze[i][j];
		}	
	}

	bool ans = ratChasesItsCheese(n-1, m-1);
	if(!ans) 
		cout << "NO PATH FOUND";

	return 0;
}
