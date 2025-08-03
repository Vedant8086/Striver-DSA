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
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int d = 0;
    int height(TreeNode* root) {
        if(root == nullptr) return 0;
        int l = height(root->left);
        int r = height(root->right);
        d = max(l+r,d);
        return 1 + max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);

        return d;
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Diameter of the binary tree is: " << sol.diameterOfBinaryTree(root) << endl;
    return 0;
}