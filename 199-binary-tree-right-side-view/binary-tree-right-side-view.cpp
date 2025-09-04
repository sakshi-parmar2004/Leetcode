/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int data;
        while(!q.empty())
        {
            TreeNode* top = q.front();
            q.pop();
            if(!top)
            {
                ans.push_back(data);
                if (!q.empty()) {
                    q.push(NULL);  // only add marker if more nodes exist
                }
            }
            else
            {
                data= top->val;
                if(top->left)
                {
                    q.push(top->left);
                }
                if(top->right)
                {
                    q.push(top->right);
                }
            }

        }
        return ans;
    }
};