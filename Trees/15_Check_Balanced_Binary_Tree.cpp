#include<iostream>
#include<iomanip>
#include<thread>
#include<typeinfo>
#include<cstring>
#include<bits/stdc++.h>
#include<string>
#include<math.h>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<exception>
#include<stdexcept>
#include<fstream>
using namespace std;
class Node {
    public :
        int data;
        Node* left;
        Node* right;
        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
};
class Solution {
private : 
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;

        int left = maxDepth(root->left);
        if(left == -1) return -1;
        int right = maxDepth(root->right);
        if(right == -1) return -1;

        if(abs(left - right) > 1) return -1;
        return 1 + max(left,right);
    }
public:
    bool isBalanced(Node* root) {
        return maxDepth(root) != -1;
    }
};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);

    Solution sol;
    if (sol.isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
    return 0;
}