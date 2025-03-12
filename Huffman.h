#ifndef HUFFMAN_CODE_H
#define HUFFMAN_CODE_H

#include<string>
#include<vector>
#include<queue>
using namespace std;

struct HuffmanNode {
    int val;
    char character;
    HuffmanNode *L;
    HuffmanNode *R;

    HuffmanNode() : val(0), character('\0'), L(nullptr), R(nullptr) {}
    HuffmanNode(int v, char c) : val(v), character(c), L(nullptr), R(nullptr) {}
};

struct CompareHuffmanNode {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->val > b->val;
    }
};

void setText(string);
HuffmanNode* HuffmanTreeGenerator();
void HuffmanDictionaryGenerator(HuffmanNode*);	
string HuffmanCodeOutput(string); 
void PrintDictionary();

//TODO:
string RecoveryTextFrom(string);


#endif
