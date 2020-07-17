#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

	vector<vector<int>> mat(n, vector<int> (n));

	for(int j = 0; j < n; ++j) {

		for(int i = n-1; i >= 0; --i) {

			cin >> mat[i][j];

        }

    }
    // cout << endl;
	for(auto v: mat) {
        for(auto el: v) {
            cout << el << " ";
        }
        cout << endl;
    }

	return 0;
}
