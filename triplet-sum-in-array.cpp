#include <bits/stdc++.h>

using namespace std;

void printTriplets(vector<int> &arr, int n, int target) {

	int l=0, r=n-1;

	for(int i=0; i<n; ++i) {

		l = i+1;
		r = n-1;

		while(l < r) {

			int sum = arr[l] + arr[r] + arr[i];
			if(sum == target) {
				cout << arr[i] << ", " << arr[l] << " and " << arr[r] << endl;
				l++;
				r--;
			}
			else if(sum > target)
				r--;
			else
				l++;

		}

	}

}

int main() {
	int n, target;
	cin >> n;
	
	vector<int> arr(n);
	for(int i=0; i<n; ++i)
		cin >> arr[i];

	cin >> target;

	sort(arr.begin(), arr.end());
	printTriplets(arr, n, target);
	return 0;
}
