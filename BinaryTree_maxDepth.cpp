#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
}

TreeNode* insertLevelOrder(const vector<int>& arr, TreeNode* root, int i, int n) {
    if (i < n) {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;

        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<int> values(n);
    cout << "Enter the values of the nodes (level order): ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    TreeNode* root = nullptr;
    root = insertLevelOrder(values, root, 0, n);

    cout << "Maximum Depth of Binary Tree: " << maxDepth(root) << endl;
    return 0;
}
