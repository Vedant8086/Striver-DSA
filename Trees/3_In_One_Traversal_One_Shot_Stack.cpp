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
vector<vector<int>> preInPostTraversal(Node* root) {
    stack<pair<Node*,int>> st;
    vector<int> pre,in,post;
    st.push({root,1});
    while(!st.empty()) {
        auto it = st.top();
        st.pop();

        if(it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != nullptr) {
                st.push({it.first->left,1});
            }
        } else  if(it.second == 2) {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right != nullptr) {
                st.push({it.first->right,1});
            }
        } else {
            post.push_back(it.first->data);
        }
    }
    
    return {pre,in,post};
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<vector<int>> traversals = preInPostTraversal(root);

    cout << "Preorder Traversal: ";
    for (int val : traversals[0]) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder Traversal: ";
    for (int val : traversals[1]) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder Traversal: ";
    for (int val : traversals[2]) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}