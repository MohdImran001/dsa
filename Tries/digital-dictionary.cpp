#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Node {
public:
	char data;
	int count;
	map<char, Node*> children;
	bool terminal;

	Node(char d) {
		data = d;
		count = 1;
		terminal = false;
	}
};

class Trie {
	Node *root;
	int cnt;

public:
	Trie() {
		root = new Node('\0');
		cnt = 0;
	}

	void insert(string w) {
		Node *temp = root;

		for(int i=0; i < w.length(); ++i) {

			char ch = w[i];

			if(temp->children.count(ch)) {

				temp = temp->children[ch];
				temp->count++;				//increasing frequency of character
			
			}
			else {
			
				Node *n = new Node(ch);
				temp->children[ch] = n;
				temp = n; 
			
			}

		}

		temp->terminal = true;
		cnt++;
	}



	void traverse(Node *temp, vector<string> &res, string ans) {
		ans.push_back(temp->data);

		if(temp->terminal)
			res.push_back(ans);

		for(auto p: temp->children) {
			traverse(p.second, res, ans);
		}
	}

	bool searchEngine(string w, vector<string> &res) {
		Node *temp = root;
 
		for(int i=0; i < w.length() ; ++i) {
 
			char ch = w[i];
			if(temp->children.count(ch) == 0)
				return false;

			temp = temp->children[ch];

		}

		if(temp->terminal)
			res.push_back(w);

		//travere remaining strings
		for(auto p: temp->children) {
			traverse(p.second, res, w);
		}

		return true;
	} 

};

int main() {
	Trie t;
	string word;
	vector<string> res;

	ll n;
	cin >> n;

	while(n--) {
		string data;
		cin >> data;
		t.insert(data);
	}

	ll q;
	cin >> q;

	while(q--) {
		cin >> word;

		bool result = t.searchEngine(word, res);
		if(result) {

			for(auto s: res)
				cout << s << endl;

		}
		else {

			cout << "No suggestions\n";
			t.insert(word);

		}

		res.clear();
	}
	return 0;
}