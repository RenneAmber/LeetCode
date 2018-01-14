#include<iostream>
#include<vector>
#include<string>
using namespace std;

// time limitation error!!
//struct Node {
//	Node** node;
//	int nodeNum;
//	string word;
//	Node* parent;
//};
//class Tree {
//	Node* root;
//	void printHelper(Node* n,vector<string> vs) {
//		if (n && n->nodeNum!=0) {
//			int sz = n->nodeNum;
//			for (int i = 0; i < sz; i++) {
//				vector<string> vt(vs);
//				vt.push_back(n->node[i]->word);
//				printHelper(n->node[i], vt);
//			}
//			
//		}
//		else {
//			for (int i = 0; i < vs.size(); i++) {
//				cout << vs[i] << ' ';
//			}
//			cout << endl;
//		}
//	}
//
//public:
//	Tree(string word) {
//		root = new Node();
//		root->parent = NULL;
//		root->word = word;
//	}
//
//	void addTree(Node* n, vector<Node*> words) {
//		int sz = words.size();
//		n->node = new Node*[sz];
//		n->nodeNum = sz;
//		for (int i = 0; i < sz; i++) {
//		/*	words[i]->parent = new Node();
//			words[i]->parent = n;*/
//			n->node[i] = words[i];
//		}
//	}
//
//	Node* getRoot() {
//		return root;
//	}
//
//	Node* makeNodeFromWord(string word,Node* node) {
//		Node* n = new Node();
//		n->node = new Node*();
//		n->word = word;
//		n->parent = node;
//		return n;
//	}
//
//	void printTree() {
//		Node * n = root;
//		vector<string> vs;
//		vs.push_back(root->word);
//		printHelper(root, vs);
//	}
//
//};
//
//int diffLetter(string word1, string word2) {
//	if (word1.size() != word2.size()) {
//		return -1;
//	}
//	int sz = word1.size();
//	int count = 0;
//	for (int i = 0; i < sz; i++) {
//		if (word1[i] != word2[i]) {
//			count++;
//		}
//	}
//	return count;
//}
//
//
//
//
//vector<string> makeLadder(Node* node, string beginWord, string endWord) {
//	vector<string> ladder;
//	Node* n = node;
//	ladder.push_back(endWord);
//	while (n->word != beginWord) {
//		ladder.push_back(n->word);
//		n = n->parent;
//	}
//	ladder.push_back(beginWord);
//	reverse(ladder.begin(),ladder.end());
//	return ladder;
//
//}
//
//vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//	int sz = wordList.size();
//	string currWord = beginWord;
//	vector<Node*>currList;
//	vector<vector<string>>results;
//
//	Tree* tree = new Tree(beginWord); 
//	
//
//	// first cycle
//	for (int i = 0; i < sz; i++) {
//		string word = wordList[i];
//		if (diffLetter(currWord, word) == 1) {
//			currList.push_back(tree->makeNodeFromWord(word,tree->getRoot()));
//			if (word == endWord) {
//				vector<string>result;
//				result.push_back(beginWord);
//				result.push_back(endWord);
//				results.push_back(result);
//				return results;			// the only result
//			}
//		}
//		
//		tree->addTree(tree->getRoot(), currList);
//	}
//
//	// following cycles
//	vector<Node*> temp;
//	vector<Node*> currWords;
//	bool stop = false;
//	for (int i = 0; i < currList.size(); i++) {
//		currWord = currList[i]->word;
//		
//		for (int j = 0; j < sz; j++) {
//			string word = wordList[j];
//			if (diffLetter(currWord, word) == 1) {
//				if (word == endWord) {
//					stop = true;
//					results.push_back(makeLadder(currList[i], beginWord,endWord));
//				}
//				Node* n = tree->makeNodeFromWord(word,currList[i]);
//				temp.push_back(n);
//				currWords.push_back(n);
//			}
//		}
//		currWords.clear();
//		tree->addTree(currList[i], currWords);
//		
//
//		if (i == currList.size() - 1) {
//			i = -1;		// i will be 0 at the beginning!!
//			if (stop == true) {
//				break;
//			}
//			currList =  vector<Node*>(temp);
//			temp.clear();
//		
//		}
//	}
//
//	//tree->printTree();
//	return results;
//}




int main() {
	string b = "hit";
	string e = "cog";
	vector<string> l;
	l.push_back("hot");
	l.push_back("dot");
	l.push_back("dog");
	l.push_back("lot");
	l.push_back("log");
	l.push_back("cog");

	vector<vector<string>> r = findLadders(b, e, l);
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < r[i].size(); j++) {
			cout << r[i][j] << ' ';
		}
		cout << endl;
	}

	system("pause");
}