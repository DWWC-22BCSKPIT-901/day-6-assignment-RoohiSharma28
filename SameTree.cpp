#include <iostream>
#include <vector> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;
    }
    if (!p || !q) {
        return false;
    }
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
    cout << "Enter the number of nodes in the first tree: ";
    cin >> n;
    
    vector<int> values1(n);
    cout << "Enter the values of the nodes for the first tree (level order): ";
    for (int i = 0; i < n; i++) {
        cin >> values1[i];
    }

    TreeNode* root1 = nullptr;
    root1 = insertLevelOrder(values1, root1, 0, n);

    cout << "Enter the number of nodes in the second tree: ";
    cin >> n;

    vector<int> values2(n);
    cout << "Enter the values of the nodes for the second tree (level order): ";
    for (int i = 0; i < n; i++) {
        cin >> values2[i];
    }

    TreeNode* root2 = nullptr;
    root2 = insertLevelOrder(values2, root2, 0, n);

    if (isSameTree(root1, root2)) {
        cout << "The two trees are the same." << endl;
    } else {
        cout << "The two trees are not the same." << endl;
    }

    return 0;
}
