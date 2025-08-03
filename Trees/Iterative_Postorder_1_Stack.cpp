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
vector<int> Postorder_Traversal(Node* root) {
    vector<int> postorder;
    if(root == nullptr) return postorder;
    stack<Node*> st;
    st.push(root);
    Node* temp = nullptr;
    while(root != nullptr || !st.empty()) {
        if(root != nullptr) {
            st.push(root);
            root = root->left;
        } else {
            temp = st.top()->right;
            if(temp == nullptr) {
                temp =st.top();st.pop();
                postorder.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            } else {
                root = temp;
            }
        }
    }
    return postorder;
}
int main() {    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    for(auto i : Postorder_Traversal(root)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}