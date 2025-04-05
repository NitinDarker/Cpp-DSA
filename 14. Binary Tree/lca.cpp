#include <bits/stdc++.h>
using namespace std;

// “The lowest common ancestor is defined between two nodes p and q as
// the lowest node in T that has both p and q as descendants
// (where we allow a node to be a descendant of itself).”

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *findLCA(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == NULL) {
        return NULL;
    }
    if (root == p) {
        return p;
    }
    if (root == q) {
        return q;
    }
    TreeNode *leftVal = findLCA(root->left, p, q);
    TreeNode *rightVal = findLCA(root->right, p, q);
    if (leftVal && rightVal) {
        return root;
    } else if (leftVal == NULL) {
        return rightVal;
    } else {
        return leftVal;
    }
}
