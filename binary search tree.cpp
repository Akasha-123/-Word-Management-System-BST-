#include <iostream>
#include <cstring>
#include <string>
#include "Node.h"
#include "BST.h"

#define MAX_WORDS 100

using namespace std;

int main() {
    int choice;
    string word;
    char ans = 'y';
    BST tree;

    do {
        cout << "Press 1. for insertion" << endl;
        cout << "Press 2. for search" << endl;
        cout << "Press 3. for deletion" << endl;
        cout << "Press 4. for height" << endl;
        cout << "Press 5. for in order traversal" << endl;
        cout << "Press 6. for post order traversal" << endl;
        cout << "Press 7. for pre order traversal" << endl;
        cout << "Press 8. for longest word" << endl;
        cout << "Press 9. for shortest word" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            char paragraph[500];
            string Words[MAX_WORDS];
            int wordCount = 0;

            cout << "Enter the paragraph to insert:" << endl;
            cin.ignore();
            cin.getline(paragraph, 500);

            char* context = nullptr;
            char* token = strtok_s(paragraph, " ", &context);
            while (token != nullptr && wordCount < MAX_WORDS) {
                Words[wordCount++] = string(token);
                token = strtok_s(nullptr, " ", &context);
            }

            for (int i = 0; i < wordCount; i++) {
                tree.Insert(Words[i]);
            }
            cout << "Inserted words from the paragraph into the tree." << endl;
            cout << "Do you want to insert more (y/n)? ";
            cin >> ans;
            break;
        }
        case 2: {
            cout << "Enter the word to search:" << endl;
            cin >> word;
            bool found = tree.Search(word);
            if (found)
                cout << "Word found in the tree." << endl;
            else
                cout << "Word not found in the tree." << endl;
            cout << "Do you want to search more (y/n)? ";
            cin >> ans;
            break;
        }
        case 3: {
            cout << "Enter the word to delete:" << endl;
            cin >> word;
            tree.Delete(word);
            cout << "Word deleted (if it existed)." << endl;
            cout << "Do you want to delete more (y/n)? ";
            cin >> ans;
            break;
        }
        case 4: {
            int height = tree.Height(tree.root);
            cout << "Height of the tree: " << height << endl;
            cout << "Do you want to perform another operation (y/n)? ";
            cin >> ans;
            break;
        }
        case 5: {
            cout << "In-order traversal: ";
            tree.InOrder(tree.root);
            cout << endl;
            break;
        }
        case 6: {
            cout << "Post-order traversal: ";
            tree.PostOrder(tree.root);
            cout << endl;
            break;
        }
        case 7: {
            cout << "Pre-order traversal: ";
            tree.PreOrder(tree.root);
            cout << endl;
            break;
        }
        case 8: {
            string longestword = tree.root->data;
            tree.FindLongestWord(tree.root, longestword);
            cout << "Longest word in the tree: " << longestword << endl;
            break;
        }
        case 9: {
            string shortestword = tree.root->data;
            tree.FindShortestWord(tree.root, shortestword);
            cout << "Shortest word in the tree: " << shortestword << endl;
            break;
        }
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (true);

    return 0;
}