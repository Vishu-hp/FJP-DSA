Node* buildTree(int inorder[], int levelOrder[], int is, int ie,int n)
{
//add code here.
    if(is>ie){
        return NULL;
    }
    
    Node* root = new Node(levelOrder[0]);
    
    if(is==ie){
        return root;
    }
    
    int idx=is;
    while(inorder[idx] != root->key){
        idx++;
    }
    
    unordered_set<int>ust;
    for(int i=is;i<idx;i++){
        ust.insert(inorder[i]);
    }
    
    int lofls[idx-is];
    int lofrs[ie-idx];
    
    int li=0,ri=0;
    
    
    for(int i=1;i<n;i++){
        int v=levelOrder[i];
        
        if(ust.size()>0 && ust.find(v) != ust.end()){
            lofls[li++] = v;
            ust.erase(v);
        }
        else{
            lofrs[ri++]=v;
        }
    }
    
    root->left = buildTree(inorder,lofls,is,idx-1,idx-1-is+1);
    root->right = buildTree(inorder,lofrs,idx+1,ie,ie-idx-1+1);
    
    return root;
}
