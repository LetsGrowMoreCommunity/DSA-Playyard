//Adding the solution to same tree

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)//taking the parameters
    {
       if(p==NULL && q==NULL)
           return true;// if p and q both are empty then true because both are same in thatcase
       
       if((p==NULL && q!=NULL) || (p!=NULL && q==NULL))
           return false;//if one of then not equal to NULL then also return false
       
       if(p->val!=q->val)
           return false;//if the values of their nodes dies not match then false
        
       return isSameTree(p->left,q->left) && isSameTree(p->right,q->right); //if pleft and qleft same as well as pright and q right then return true else false
       
    }
};
//INPUT [1,2,3]
//[1,2,3]
//Output
//true
//Expected
//true
