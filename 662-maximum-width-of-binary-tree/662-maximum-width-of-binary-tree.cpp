class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long ans=1;
        deque<pair<unsigned long long,TreeNode*>> q;
        q.push_back({1,root});
        while(!q.empty()){
            int sz=q.size();
            ans = max(ans,q.back().first-q.front().first+1);
            while(sz--){
                auto [num,now]=q.front();
                q.pop_front();
                if(now->left) q.push_back({2*num,now->left});
                if(now->right) q.push_back({2*num+1,now->right}); 
            }
        }
        return ans;
    }
};