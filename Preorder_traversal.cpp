#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    stack<TreeNode*> stack;
    stack.push(root);

    while (!stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();
        result.push_back(node->val);  

        if (node->right) {
            stack.push(node->right);  
        }
        if (node->left) {
            stack.push(node->left);   
        }
    }

    return result;
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

    vector<int> result = preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
