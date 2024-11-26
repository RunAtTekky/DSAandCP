#include <bits/stdc++.h>
using namespace std;

class Trie {

public:

	// n is number of possible characters in a string
	const static int N = 26;

	// BaseChar defines the base character for possible characters
	// Like '0' for '0','1','2'... as possible characters in string 
	const static char baseChar = 'a';

	struct TrieNode {
		int next[N];
		// If isEnd is set to true , a string ended here
		bool isEnd;
		// Freq is how many times this prefix occurs
		int freq;

		TrieNode() {
			for(int i=0;i<N;i++) next[i] = -1;
			isEnd = false;
			freq = 0;
		}
	};

	// The implementation is via vector and each position in this vector
	// Is similar as new pointer in pointer type implementation
	vector <TrieNode> tree;

	// Base Constructor
	Trie () {
		tree.push_back(TrieNode());
	}

	// Inserting a string in trie
	void insert(const string& s) {
		// p is the current node index
		int p = 0;
		tree[p].freq++;
		for(int i=0;i<s.size();i++) {
			if(tree[p].next[s[i]-baseChar] == -1) {
				tree.push_back(TrieNode());
				// We are pointing to the index of newly created node
				tree[p].next[s[i]-baseChar] = tree.size()-1;
			}

			// Point to the index of the character s[i]
			p = tree[p].next[s[i]-baseChar];
			tree[p].freq++;
		}
		tree[p].isEnd = true;
	}

	// Check if a string exists as prefix
	bool checkPrefix(const string &s) {
		int p = 0;
		for(int i=0;i<s.size();i++) {
			if(tree[p].next[s[i]-baseChar] == -1) return false;

			p = tree[p].next[s[i]-baseChar];
		}
		return true;
	}

	// Check is string exists
	bool checkString(const string &s) {
		int p = 0;
		for(int i=0;i<s.size();i++) {
			if(tree[p].next[s[i]-baseChar] == -1) return false;

			p = tree[p].next[s[i]-baseChar];
		}

		return tree[p].isEnd;
	}

	// Persistent insert
	// Returns location of new head
	int persistentInsert(int head , const string &s) {
		int old = head;

		tree.push_back(TrieNode());
		int now = tree.size()-1;
		int newHead = now;

		int i,j;

		for(i=0;i<s.size();i++) {
			if(old == -1) {
				tree.push_back(TrieNode());
				tree[now].next[s[i]-baseChar] = tree.size() - 1;
				tree[now].freq++;
				now = tree[now].next[s[i]-baseChar];
				continue;
			}

			for(j=0;j<N;j++) tree[now].next[j] = tree[old].next[j];

			tree[now].freq = tree[old].freq;
			tree[now].isEnd = tree[old].isEnd;

			tree[now].freq++;

			tree.push_back(TrieNode());
			tree[now].next[s[i]-baseChar] = tree.size()-1;

			old = tree[old].next[s[i]-baseChar];
			now = tree[now].next[s[i]-baseChar];
		}

		tree[now].freq++;
		tree[now].isEnd = true;

		return newHead;
	}

	// Persistent check prefix
	bool persistentCheckPrefix(int head, const string &s) {
		int p = head;
		for(int i=0;i<s.size();i++) {
			if(tree[p].next[s[i]-baseChar] == -1) return false;

			p = tree[p].next[s[i]-baseChar];
		}
		return true;
	}

	// Persistent check string
	bool persistentCheckString(int head, const string &s) {
		int p = head;
		for(int i=0;i<s.size();i++) {
			if(tree[p].next[s[i]-baseChar] == -1) return false;

			p = tree[p].next[s[i]-baseChar];
		}
		return tree[p].isEnd;
	}
};

string s,temp;
int main() {
	Trie trie = Trie();

	cout << trie.checkString("hello") << endl;	// Output : 0

	trie.insert("hello");

	cout << trie.checkPrefix("hell") << endl;	// Output : 1

	cout << trie.checkString("hell") << endl;	// Output : 0

	cout << trie.checkString("hello") << endl;	// Output : 1


	// Example for persistent trie 
	Trie persistentTrie = Trie();
	vector <int> heads;

	// Insert words 
	heads.push_back(0);
	heads.push_back(persistentTrie.persistentInsert(heads[heads.size()-1] , "hello"));
	heads.push_back(persistentTrie.persistentInsert(heads[heads.size()-1] , "world"));
	heads.push_back(persistentTrie.persistentInsert(heads[heads.size()-1] , "persistent"));
	heads.push_back(persistentTrie.persistentInsert(heads[heads.size()-1] , "trie"));

	cout << persistentTrie.persistentCheckString(heads[0] , "hello") << endl;	// Output : 0
	cout << persistentTrie.persistentCheckString(heads[1] , "hello") << endl;	// Output : 1

	cout << persistentTrie.persistentCheckString(heads[1] , "world") << endl;	// Output : 0
	cout << persistentTrie.persistentCheckString(heads[2] , "world") << endl;	// Output : 1

	cout << persistentTrie.persistentCheckString(heads[2] , "persistent") << endl;	// Output : 0
	cout << persistentTrie.persistentCheckString(heads[3] , "persistent") << endl;	// Output : 1

	cout << persistentTrie.persistentCheckString(heads[3] , "trie") << endl;	// Output : 0
	cout << persistentTrie.persistentCheckString(heads[4] , "trie") << endl;	// Output : 1


	return 0;
}
