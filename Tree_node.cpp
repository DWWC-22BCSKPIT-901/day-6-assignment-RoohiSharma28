#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int computeDepth(TreeNode* node) {
    int depth = 0;
    while (node->left) {
        node = node->left;
        depth++;
    }
    return depth;
}

bool exists(int idx, int depth, TreeNode* node) {
    int left = 0, right = pow(2, depth) - 1;
    for (int i = 0; i < depth; i++) {
        int mid = left + (right - left) / 2;
        if (idx <= mid) {
            node = node->left;
            right = mid;
        } else {
            node = node->right;
            left = mid + 1;
        }
    }
    return node != nullptr;
}

int countNodes(TreeNode* root) {
    if (!root) return 0;
    int depth = computeDepth(root);
    if (depth == 0) return 1;
    int left = 1, right = pow(2, depth) - 1, totalNodes = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (exists(mid, depth, root)) {
            totalNodes = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return pow(2, depth) - 1 + totalNodes + 1;
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

    cout << "Number of nodes in the tree: " << countNodes(root) << endl;
    return 0;
}
