class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        q.push({NULL, 1});   // ✅ level delimiter

        int maxi = INT_MIN;
        int ans = 1;
        int sum = 0;
       

        while (!q.empty()) {
            TreeNode* front = q.front().first;
            int level = q.front().second;
            q.pop();

            if (front == NULL) {
            
                if (sum > maxi) {
                    maxi = sum;
                    ans = level;
                }
                sum = 0;
                // currLevel++;

                if (!q.empty()) {
                    q.push({NULL, level+1});
                }
            } else {
                sum += front->val;

                if (front->left) q.push({front->left, level + 1});
                if (front->right) q.push({front->right, level + 1});
            }
        }

        return ans;
    }
};
