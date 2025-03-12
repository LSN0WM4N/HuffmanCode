#include<bits/stdc++.h>
#include"Huffman.h"
using namespace std;

int main() {

	string input;
	cin >> input;

	cout << "Input size before processing: " << input.size() * 8 << " bits\n";
	string result = HuffmanCodeOutput(input);
	cout << "Output code size after processing: " << result.size() << " bits\n";

	return 0;
}
