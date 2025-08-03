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
private : 
    int max_sum = INT_MIN; 
    int summing(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftSum = max(summing(root->left),0);
        int rightSum = max(summing(root->right),0);
        int currSum = rightSum + leftSum + root->val;
        max_sum = max(currSum,max_sum);
        return max(leftSum,rightSum) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        summing(root);
        return max_sum; 
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl;
    return 0;
}