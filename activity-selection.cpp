#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	int t, n, s, e;
	vector<pair<int, int>> arr;	
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; ++i) {
			cin >> s >> e;
			arr.push_back(make_pair(s, e));
		}

		sort(arr.begin(), arr.end(), compare);

		int ans = 1;
		int finishTime = arr[0].second;

		for(int i=1; i<n; ++i) {
			if(arr[i].first > finishTime) {
				finishTime = arr[i].second;
				ans++;
			}
		}
		cout << ans << endl;
		arr.clear();
	} 
	return 0;
}
