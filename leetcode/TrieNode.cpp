#include <iostream>
#include <string>
using namespace std;

const int R = 26;
class TrieNode{
private:
	TrieNode *links[R];
	bool endFlag;
public:
	TrieNode(){
		for(int i = 0; i < R; ++i){
			links[i] = NULL; 
		}
	}
	bool containsKey(char ch){
		return links[ch - 'a'] != NULL;
	}
	TrieNode *get(char ch){
		return links[ch - 'a'];
	}
	void put(char ch, TrieNode *node){
		links[ch - 'a'] = node;
	}
	void setEnd(){
		endFlag = true;
	}
	bool isEnd(){
		return endFlag;
	}
};

class Trie{
private:
	TrieNode *root;

	TrieNode *searchPrefix(string word){
		TrieNode *node = root;
		for(int i = 0; i < word.size(); ++i){
			char curLetter = word.at(i);
			if(node->containsKey(curLetter)){
				node = node->get(curLetter);
			}else{
				return NULL;
			}
		}
		return node;
	}

public:
	Trie(){
		root = new TrieNode();
	}
	void insert(string word){
		TrieNode *node = root;
		for(int i = 0; i < word.size(); ++i){
			char currentChar = word.at(i);
			if(!node->containsKey(currentChar)){
				node->put(currentChar, new TrieNode());
			}
			node = node->get(currentChar);
		}
		node->setEnd();
	}

	bool search(string word){
		if(searchPrefix(word) == NULL){
			return false;
		}else{
			TrieNode *node = searchPrefix(word);
			return node != NULL && node->isEnd();
		}
	}

	bool startwith(string prefix){
		TrieNode *node = searchPrefix(prefix);
		return node != NULL;
	}
};

int main(){
	Trie T;
	T.insert("abc");
	//int *p = new int(NULL));
	cout << T.search("ab") << endl;
	cout << T.startwith("a") << endl;
	return 0;
}