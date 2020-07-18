#include <bits/stdc++.h>

using namespace std;

bool myCompare(string a, string b) {
	string ab = a.append(b);
	string ba = b.append(a);

	return ab.compare(ba) > 0 ? 1: 0;
}

int main() {
	int t, n;
	vector<string> arr;
	cin >> t;
	while(t--) {
		cin >> n;
		arr.resize(n);
		for(int i=0; i<n; ++i)
			cin >> arr[i];

		sort(arr.begin(), arr.end(), myCompare);

		for(string el: arr)
			cout << el;

		cout << endl;
		arr.clear();
	}
	return 0;
}
