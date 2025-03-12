# Huffman coding project

This is a simple project about [Huffman Coding](https://en.wikipedia.org/wiki/Huffman_coding). The Huffman code is a lossless compression algorithm.


To compile it use the command
    g++ Huffman.cpp main.cpp -o huffman
and 
    ./huffman 
to execute

## Usage 

You pass a string with no spaces and the program will calculate one of the Huffman codes for the given string. Actually just shows the size in bits 
of the result but you can change it easly...

## Todos

* Add the dictionary to the result
* Create a function to restore the original data from a given code
* Error handling
