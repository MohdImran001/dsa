#include <bits/stdc++.h>

using namespace std;

int findMinSquares(vector<vector<int>> &board, vector<vector<int>> &visited, int row = 0, int col = 0) {
	int x[] = {-2, -2, -1, -1,  1, 1,  2, 2};
	int y[] = {-1,  1, -2,  2, -2, 2, -1, 1};

	queue<pair<int, int>> q;
	q.push(make_pair(row, col));

	while(!q.empty()) {
		auto p = q.front();
		q.pop();

		for(int i=0; i<8; ++i) {
			int r = row + x[i];
			int c = col + y[i];

			if(r < board.size() and r >= 0 and c < board[0].size() and c >= 0 and board[r][c] == 1) {
				visited[r][c] = 1;
				q.push(make_pair(r, c));
			}
		}
	}

	cout << "\n*********************\n";
	for(auto v: visited) {
		for(auto el: v) {
			cout << el << "\t";
		}
		cout << endl;
	}

	return 0;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> board(n, vector<int> (n, 0));
	vector<vector<int>> visited(n, vector<int> (n, -1));

	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			cin >> board[i][j];
			if(board[i][j] == 1)
				visited[i][j] = 0;
		}
	}

	// cout << findMinSquares(board, visited) << endl;




	for(auto v: board) {
		for(auto el: v) {
			cout << el << "\t";
		}
		cout << endl;
	}

	cout << "\n*********************\n";
	for(auto v: visited) {
		for(auto el: v) {
			cout << el << "\t";
		}
		cout << endl;
	}
	return 0;
}
