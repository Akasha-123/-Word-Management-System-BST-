#pragma once
#include"Node.h"
class BST
{
public:
	Node* root;
	BST();
	void Insert(string word);
	Node* Search(string word);
	void PreOrder(Node* root);
	void InOrder(Node* root);
	void PostOrder(Node* root);
	void Delete(string word);
	int Height(Node* root);
	void FindLongestWord(Node* Currentnode, string& longestword);
	void FindShortestWord(Node* Currentnode, string& shortestword);
};

