// 114. Flatten Binary Tree to Linked List
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode *prev = NULL;
  public:
    void flatten(TreeNode *root) {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};


class Solution2 {
    public:
      void flatten(TreeNode *root) {
          stack<TreeNode *> st;
          if (root) st.push(root);
          while (!st.empty()) {
              TreeNode *curr = st.top();
              st.pop();
              if (curr->right) st.push(curr->right);
              if (curr->left) st.push(curr->left);
              if (!st.empty()) curr->right = st.top();
              curr->left = NULL;
          }
      }
  };