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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == NULL || root == p || root == q)
        return root;

    int rootVal = root->val;
    int pVal = p->val;
    int qVal = q->val;

    if (rootVal < pVal && rootVal < qVal) {
        // both p and q are right of root
        return lowestCommonAncestor(root->right, p, q);
    } else if (rootVal > pVal && rootVal > qVal) {
        // both p and q are left of root
        return lowestCommonAncestor(root->left, p, q);
    } else {
        return root;
    }
}
