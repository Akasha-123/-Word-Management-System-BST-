#include "BST.h"
#include <iostream>
#include <string>
#include <algorithm> // For std::max
using namespace std;

BST::BST() {
    root = NULL;
}

void BST::Insert(string word) {
    if (!root) {
        root = new Node(word);
        return;
    }

    Node* current = root;

    while (true) {
        if (word < current->data) {
            if (current->left == nullptr) {
                current->left = new Node(word);
                return;
            }
            else {
                current = current->left;
            }
        }
        else if (word > current->data) {
            if (current->right == nullptr) {
                current->right = new Node(word);
                return;
            }
            else {
                current = current->right;
            }
        }
        else {
            return; // No duplicates allowed
        }
    }
}

Node* BST::Search(string word) {
    if (!root) {
        return NULL;
    }

    Node* temp = root;
    while (temp != NULL) {
        if (temp->data > word) {
            temp = temp->left;
        }
        else if (temp->data < word) {
            temp = temp->right;
        }
        else {
            return temp;
        }
    }

    return NULL;
}

void BST::PreOrder(Node* node) {
    if (!node) return;
    cout << node->data << " ";
    PreOrder(node->left);
    PreOrder(node->right);
}

void BST::InOrder(Node* node) {
    if (!node) return;
    InOrder(node->left);
    cout << node->data << " ";
    InOrder(node->right);
}

void BST::PostOrder(Node* node) {
    if (!node) return;
    PostOrder(node->left);
    PostOrder(node->right);
    cout << node->data << " ";
}

int BST::Height(Node* root) {
    if (!root)
        return 0; 
    return max(Height(root->left), Height(root->right)) + 1; 
}

void BST::FindLongestWord(Node* Currentnode, string& longestword)
{
    if (!Currentnode) {
        return;
    }
    if (Currentnode->data.length() > longestword.length()) {
        longestword = Currentnode->data;
    }
    FindLongestWord(Currentnode->left, longestword);
    FindLongestWord(Currentnode->right, longestword);
}

void BST::FindShortestWord(Node* Currentnode, string& shortestword)
{
    if (!Currentnode) {
        return;
}
    if (Currentnode->data.length() < shortestword.length()) {
        shortestword = Currentnode->data;
}
    FindShortestWord(Currentnode->left, shortestword);
    FindShortestWord(Currentnode->right, shortestword);

}

void BST::Delete(string word)
{
    if (!root) return;

    Node* temp = root;
    Node* parent = NULL;

    while (temp) {
        if (temp->data == word)
            break;
        parent = temp;
        if (temp->data < word)
            temp = temp->right;
        else
            temp = temp->left;
    }

  
    if (!temp) {
        cout << "Word not found in the tree." << endl;
        return;
    }

   
    if (!temp->left && !temp->right) {
        if (temp == root) { 
            delete root;
            root = NULL;
        }
        else if (parent->left == temp) {
            parent->left = NULL;
            delete temp;
        }
        else {
            parent->right = NULL;
            delete temp;
        }
        return;
    }

 
    if (!temp->left) {  
        if (temp == root) {  
            root = temp->right;
        }
        else if (parent->left == temp) {
            parent->left = temp->right;
        }
        else {
            parent->right = temp->right;
        }
        delete temp;
        return;
    }
    if (!temp->right) {  
        if (temp == root) {  
            root = temp->left;
        }
        else if (parent->left == temp) {
            parent->left = temp->left;
        }
        else {
            parent->right = temp->left;
        }
        delete temp;
        return;
    }

   
    Node* min = temp->right;
    Node* minParent = temp;


    while (min->left) {
        minParent = min;
        min = min->left;
    }

  
    temp->data = min->data;


    if (minParent->left == min) {
        minParent->left = min->right;
    }
    else {
        minParent->right = min->right;
    }

    delete min;
}

