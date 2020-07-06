#include <bits/stdc++.h>

using namespace std;

// vector<int> dp;
// int findMinJumps(vector<int> arr, int n, int si = 0) {
// 	if(si == 0 and arr[si] == 0) {
// 		return INT_MAX;
// 	}
	
// 	if(si >= n or arr[si] == 0) {
// 		return 0;
// 	} 

// 	if(dp[si] != -1) {
// 		return dp[si];
// 	}

// 	int minSteps = INT_MAX;
// 	for(int i=1; i<=arr[si]; ++i) {

// 			int steps = 1 + findMinJumps(arr, n, si+i);
// 			minSteps = min(minSteps, steps);

// 	}

// 	dp[si] = minSteps;

// 	for(auto el: dp) {
// 		cout << el << "\t";
// 	}
// 	cout << endl << "********************************" << endl;

// 	return minSteps;
// }

int findMinJumpsDP(vector<int> arr, int n) {
	if(n == 0) {
		return INT_MAX;
	}

	vector<int> dp(n+1);
	dp[n] = 0;				//BASE CASE

	for(int i = n-1; i >= 0; --i) {

		int minSteps = INT_MAX;
		for(int j=1; j<=arr[i]; ++j) {

			if(i+j <= n) {
				int steps;

				if(dp[i+j] == INT_MAX) 
					steps = dp[i+j];
				else
					steps = 1 + dp[i+j];

				minSteps = min(minSteps, steps);
			}
		}
		

		dp[i] = minSteps;
	}


	// cout << endl << "DP -> " ;
	// for(auto el: dp) {
	// 	cout << el << "\t";
	// }

	return dp[0];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		vector<int> arr(n);
		for(int i=0; i<n; ++i) {
			cin >> arr[i];
		}

		// dp.resize(n, -1);
		cout << findMinJumpsDP(arr, n);
		cout << endl;
	}
	return 0;
}
