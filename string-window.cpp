#include <bits/stdc++.h>

using namespace std;

void findWindow(string &text, string &pattern, string &ans, int &minLen) {
	int left = 0, right = 0, count = 0;
	unordered_map<char, int> map;
	for(char c: pattern) {
		map[c]++;
	}
	
	while(right < text.length()) {
		char ch = text[right];
		
		if(map.count(ch) and map[ch] > 0) {
			count++;
			map[ch]--;		
		}

		while(count >= pattern.length()) {
			int len = right - left + 1;
			if(len < minLen) {
				minLen = len;
				ans = text.substr(left, len);
			}

			char c = text[left];

			if(map.count(c)) 
			{
				map[c]++;
				count--;
			}

			left++;
		}
		// cout << "left :- " << left << " , right :- " << right << endl;
		right++;
	} 
}

int main() {
	string text, pattern;
	getline(cin , text);
	getline(cin, pattern);
	
	if(text.length() < pattern.length()) {
		cout << "No String";
		return 0;
	} 

	string ans = "";
	int minLength = INT_MAX;

	findWindow(text, pattern, ans, minLength);

	cout << ans;
	return 0;
}
