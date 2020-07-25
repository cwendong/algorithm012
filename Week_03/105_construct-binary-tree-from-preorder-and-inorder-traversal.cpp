/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
public:
    /*
    // recursive solution
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if (preorder.empty() || inorder.empty())
        {
            return nullptr;
        }
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);
        vector<int>::iterator findIndex = find(inorder.begin(), inorder.end(), rootVal);
        vector<int> inorderLeft(inorder.begin(), findIndex);
        vector<int> inorderRight(++findIndex, inorder.end());

        findIndex = ++preorder.begin() + inorderLeft.size();
        vector<int> preorderLeft(++preorder.begin(), findIndex);
        vector<int> preorderRight(findIndex, preorder.end());
        

        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);

        return root;     
    }
    */

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stackHelper;
        stackHelper.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); ++i) {
            int preorderVal = preorder[i];
            TreeNode* node = stackHelper.top();
            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorderVal);
                stackHelper.push(node->left);
            }
            else {
                while (!stackHelper.empty() && stackHelper.top()->val == inorder[inorderIndex]) {
                    node = stackHelper.top();
                    stackHelper.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                stackHelper.push(node->right);
            }
        }
        return root;
    }
};