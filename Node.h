#pragma once
#include<iostream>
#include <string>
using namespace std;
class Node
{
public:
	Node* left = NULL;
	Node* right = NULL;
	string data;
	Node(string data);
};

