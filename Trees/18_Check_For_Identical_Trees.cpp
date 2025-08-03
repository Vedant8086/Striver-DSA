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
    bool trees(TreeNode* p,TreeNode* q) {
        if(!p && !q) {
            return true;
        }
        
        if(p && q && p->val == q->val) {
            return (trees(p->left,q->left) && trees(p->right,q->right));
        }

        return false;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return trees(p,q);
    }
};
int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution sol;
    if (sol.isSameTree(p, q)) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }
    return 0;
}