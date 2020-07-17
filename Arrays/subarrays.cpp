#include <bits/stdc++.h>

using namespace std;

int findSubarrays(vector<int> arr, int n) {
	int sum = 0;

	for(int i=0; i<n; ++i) {
		unordered_set<int> set;

		for(int j=i; j<n; ++j) {
			if(set.count(arr[j])) {
				break;
			}
			set.insert(arr[j]);
			sum += j-i+1;
		}
	}

	return sum;
}

int findSubarraysOptimized(vector<int> arr, int n) {
    // For maintaining distinct elements. 
    unordered_set<int> s; 
  
    // Initialize ending point and result 
    int j = 0, ans = 0; 
  
    // Fix starting point 
    for (int i=0; i<n; i++) 
    { 
        // Find ending point for current subarray with 
        // distinct elements. 
        while (j < n && s.find(arr[j]) == s.end()) 
        { 
            s.insert(arr[j]); 
            j++; 
        } 
  
        // Calculating and adding all possible length 
        // subarrays in arr[i..j] 
        ans += ((j - i) * (j - i + 1))/2; 
  
        // Remove arr[i] as we pick new stating point 
        // from next 
        s.erase(arr[i]); 
    } 

	return ans;
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i=0; i<n; ++i) {
		cin >> arr[i];
	}

	cout << findSubarraysOptimized(arr, n);	
	return 0;
}