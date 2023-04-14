class Pair{
    public:
    Node* par;
    int lr;
    int rr;
    
    Pair(){}
    
    Pair(Node* n,int a,int b){
        par=n;
        lr=a;
        rr=b;
    }
};

Node* constructBst(int arr[], int n)
{
    // Code here
    queue<Pair>q;
    q.push(Pair(NULL,INT_MIN,INT_MAX));
    int idx=0;
    Node* root;
    
    while(q.size() > 0 && idx<n){
        Pair rem = q.front();
        q.pop();
        
        int ele = arr[idx];
        
        
        if(ele < rem.lr || ele>rem.rr){
            continue;
        }   
        
        Node* node= new Node(ele);
        idx++;
        
        if(rem.par == NULL){
            root = node;
        }
        else{
            Node* par = rem.par;
            if(ele < par->data){
                par->left = node;
            }
            else{
                par->right = node;
            }
        }
        
        q.push(Pair(node,rem.lr,ele));
        q.push(Pair(node,ele,rem.rr));
    }
    
    return root;
}
