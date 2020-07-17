#include <bits/stdc++.h>
#define ll long long int 

using namespace std;

ll maxSubarraySum(vector<ll> &a, ll size) {
   ll max_so_far = a[0]; 
   ll curr_max = a[0]; 
  
   for (ll i = 1; i < size; i++) 
   { 
        curr_max = max(a[i], curr_max+a[i]); 
        max_so_far = max(max_so_far, curr_max); 
   } 
   return max_so_far; 
}

int main() {
	ll t, n;
	vector<ll> arr;

	cin >> t;
	while(t--) {
		cin >> n;
		arr.resize(n);

		for(int i=0; i<n; ++i) {
			cin >> arr[i];
		}

		cout << maxSubarraySum(arr, n) << endl;

		arr.clear();
	}

	return 0;
}