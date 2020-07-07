#include <bits/stdc++.h>

using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string searchIn [] = { 
	"prateek", 
	"sneha", 
	"deepak", 
	"arnav", 
	"shikha", 
	"palak", 
	"utkarsh", 
	"divyam", 
	"vidhi", 
	"sparsh", 
	"akku"
};

void smartKeypad2(string str, string ans = "") {
	if(str.length() == 0) {
		for(int i=0; i<11; ++i) {
			string s = searchIn[i];
			if(s.find(ans) != string::npos) {
				cout << s << endl;
			}
		}
		return;
	}

	char ch = str[0];
	int index = ch - '0';

	string ros = str.substr(1);
	string s = table[index];
	
	for(int i=0; i<s.length(); ++i) {
		smartKeypad2(ros, ans + s[i]);
	}
}

int main() {
	string n;
	cin >> n;
	smartKeypad2(n);
	// cout << endl;
	return 0;
}
