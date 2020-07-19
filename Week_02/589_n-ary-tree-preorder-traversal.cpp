/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    /*
    vector<int> result;
    vector<int> preorder(Node* root) {
        if (root == nullptr)
        {
            return result;
        }

        result.push_back(root->val);
        for (auto i : root->children)
        {
            preorder(i);
        }
            
        return result;    
    }
    */
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }
        stack<Node *> helper;
        helper.push(root);
        while (!helper.empty())
        {
            Node *tmp = helper.top();
            helper.pop();
            result.push_back(tmp->val);
            int len = tmp->children.size();
            for(int i = len - 1; i >= 0; i--)
            {
                helper.push(tmp->children[i]);
            }
        }

        return result;  
    }
};