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
vector<int> Inorder_Traversal(Node* root) {
    stack<Node*> st;
    vector<int> inorder;
    Node* node = root;
    while(true) {
        if(node != nullptr) {
            st.push(node);
            node = node->left;
        } else {
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<int> inorder = Inorder_Traversal(root);
    for(auto i : inorder) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}