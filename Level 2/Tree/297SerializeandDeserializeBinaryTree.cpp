/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void solve(TreeNode* root,string &ans){
        if(root==NULL){
            ans+="null ";
            return;
        }
        
        ans += to_string(root->val)+" ";
        solve(root->left,ans);
        solve(root->right,ans);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        solve(root,ans);
        // cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    int idx=0;
    TreeNode* solve2(vector<string>&arr){
        if(idx == arr.size()){
            return NULL;
        }
        
        if(arr[idx]=="null"){
            return NULL;
        }
        
        
        
        TreeNode* node = new TreeNode(stoi(arr[idx]));
        idx++;
        
        node->left = solve2(arr);
        idx++;
        node->right = solve2(arr);
        return node;
    }
    
    TreeNode* deserialize(string data) {
        vector<string>arr;
        // cout<<data<<endl;
        
        stringstream ss(data);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }
       
        
        
        TreeNode* root = solve2(arr);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
