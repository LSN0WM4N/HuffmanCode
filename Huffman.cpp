#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include"Huffman.h"
using namespace std;

string text, actualCode;
vector<pair<string, char>> dict; // TODO: Imporve this
map<char, string> dictMap;
map<string, char> reverseDict;

void setText(string input) {
	text = input;
}

// TODO: Make the dictionary only allowed for none special character
// TODO: Compress all and decompress 

// HuffmanTreeGenerator(string text) -> HuffmanNode
// 	takes a text and generates one of the corresponding HuffmanTrees
// 	Returns the result as the root of the tree
HuffmanNode* HuffmanTreeGenerator() {
	vector<int> frecuencies(256);

	for (char c : text) 
		frecuencies[int(c)] ++;

	priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareHuffmanNode> pq;
	for (int i = 0; i < 256; i ++) {
		if (frecuencies[i] == 0)
			continue;

		HuffmanNode* node = new HuffmanNode();
		node->val = frecuencies[i];
		node->character = i;

		pq.push(node);
	}

	while (pq.size() > 1) {	
		HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* parent = new HuffmanNode(left->val + right->val, 5);
        parent->L = left;
        parent->R = right;

        pq.push(parent);
	}

	return pq.top();
}

// HuffmanDictionaryHenerator(HuffmanNode *actual, string &actualCode, 
//                                    vector<pair<string, char>> &dict) -> void
// 	This is and DFS who generates the code for all the characters, the result 
// 	is storaged in dict parameter as a pair
void HuffmanDictionaryGenerator(HuffmanNode *actual) {
	if (actual->L != nullptr && actual->R != nullptr) {
		dict.push_back({actualCode, actual->character});
		dictMap[actual->character] = actualCode;
		reverseDict[actualCode] = actual->character;
		return;
	}

	actualCode.push_back('0');
	HuffmanDictionaryGenerator(actual->L);
	actualCode.pop_back();
	actualCode.push_back('1');
	HuffmanDictionaryGenerator(actual->R);
	actualCode.pop_back();
}

string HuffmanCodeOutput(string input) {
	setText(input);
	HuffmanNode* Root = HuffmanTreeGenerator();

	HuffmanDictionaryGenerator(Root);

	string result = "";
	for (char c : text) 
		result += dictMap[c];
	return result;
}

void PrintDictionary() {
	cout << "{\n";
	for (auto &x : dict)
		cout << "\t" << x.first << ":" << x.second << "\n";
	cout << "}\n";
}
