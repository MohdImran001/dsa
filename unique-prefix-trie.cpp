#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	char data;
	int count;
	unordered_map<char, Node*> children;
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

	void insert(char *w) {
		Node *temp = root;
		for(int i=0; w[i] != '\0'; ++i) {
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

	bool find(char *w) {
		Node *temp = root;
		for(int i=0; w[i] != '\0'; ++i) {
			char ch = w[i];
			if(temp->children.count(ch) == 0) {
				return false;
			}

			temp = temp->children[ch];
		}

		return temp->terminal;
	}

	string findPrefix(char *w) {
		Node *temp = root;
		string ans = "";
		for(int i=0; w[i]!='\0'; ++i) {

			char ch = w[i];
			temp = temp->children[ch];
			ans.push_back(ch);
			if(temp->count == 1) {
				return ans;
			}

		}
		return "";
	}

};

int main() {
	Trie t;
	char words[][10] = { "cobra", "dog", "dove", "duck", "cobras" };

	for(int i=0; i<5; ++i) {
		t.insert(words[i]);
	}

	string ans;
	for(int i=0; i<5; ++i) {
		ans = t.findPrefix(words[i]);
		if(ans.length() > 0)
			cout << ans << " ";
		else
			cout << "-1" << " ";
	}

	return 0;
}
