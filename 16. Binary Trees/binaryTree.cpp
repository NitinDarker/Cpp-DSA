#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class TreeNode {
  public:
    int data;
    TreeNode *left, *right;

    TreeNode(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// With Queue
void create_tree(TreeNode *root, vector<int> &arr) {
    // In-order creation of binary tree
    queue<TreeNode *> q;
    int i = 0;
    q.push(root);
    while (i < arr.size()) {
        TreeNode *currNode = q.front();
        q.pop();
        currNode->left = new TreeNode(arr[i++]);
        currNode->right = new TreeNode(arr[i++]);
        q.push(currNode->left);
        q.push(currNode->right);
    }
}

// Without Queue (but uses an extra array)
void create_new_tree(TreeNode *root, vector<int> &arr) {
    // In-order creation of binary tree
    int n = arr.size();
    vector<TreeNode *> nodes(n);
    nodes[0] = root;

    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n) {
            nodes[2 * i + 1] = new TreeNode(arr[2 * i + 1]);
            nodes[i]->left = nodes[2 * i + 1];
        }
        if (2 * i + 2 < n) {
            nodes[2 * i + 2] = new TreeNode(arr[2 * i + 2]);
            nodes[i]->right = nodes[2 * i + 2];
        }
    }
}

void inOrder(TreeNode *root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    TreeNode *root = new TreeNode(0);
    create_new_tree(root, arr);
    inOrder(root);
}