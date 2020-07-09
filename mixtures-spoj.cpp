#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> dp;

ll csum(vector<int> arr, int s, int e) {
	ll ans = 0;
	for(int i=s; i<=e; ++i) {
		ans += arr[i];
		ans %= 100;
	}

	return ans;
}

ll findMinSmoke(vector<int> arr, int i, int j) {
	if(i>=j)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	dp[i][j] = INT_MAX;
	for(int k=i; k<=j; ++k) {

		ll result = findMinSmoke(arr, i, k) + findMinSmoke(arr, k+1, j) + csum(arr, i, k)*csum(arr, k+1, j);
		dp[i][j] = min(dp[i][j], result);

	}

	return dp[i][j];
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i=0; i<n; ++i) {
		cin >> arr[i];
	}

	dp.resize(n+1, vector<ll> (n+1, -1));
	cout << findMinSmoke(arr, 0, n-1);
	return 0;
}
