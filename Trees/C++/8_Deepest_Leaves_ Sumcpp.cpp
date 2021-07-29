
//done using bfs
class Solution { 
public:
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<TreeNode*>> levels;
        queue<TreeNode*> toDo;//preservr the tree in a queqe since doing bfs
        toDo.push(root);
        
        while(!toDo.empty()){
            vector<TreeNode*> level;
            while(!toDo.empty()) { level.push_back(toDo.front()); toDo.pop(); }
            levels.push_back(level);
            
            for(TreeNode* l: level){
                if(l->left) toDo.push(l->left);//if left then push left
                if(l->right) toDo.push(l->right);
            }
        }
        
        int deepestSum(0);
        for(int i(0); i<levels[levels.size()-1].size(); i++)
            deepestSum+=(levels[levels.size()-1][i])->val;//addding all the nodes of the last level throuh leve order traversal
        
        return deepestSum;//returning the ans
    }
};
int main()
{
    vector<int>root;
    cin>>root;
    cout<< deepestLeavesSum(TreeNode* root)<<endl;
}
/*Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
 /*
