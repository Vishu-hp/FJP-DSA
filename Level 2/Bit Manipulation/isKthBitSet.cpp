bool checkKthBit(int n, int k)
    {
        // Your code here
        // It can be a one liner logic!! Think of it!!
        int mask = (1<<k);
        if((n&mask)!=0){
            return true;
        }
        return false;
    }
