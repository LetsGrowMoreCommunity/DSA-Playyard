
Time Complexity:- O(n)
Space Complexity:- O(n)
//done using bfs
#include<iostream>
using namespace std;
   int deepestLeavesSum(TreeNode *root)
  {
    int sum = 0;
    int n;
    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty())
    {
      sum = 0;
      n = que.size();

      for (int i = 0; i < n; i++)
      {
        TreeNode *t = que.front();
        if (t->left)
          que.push(t->left);
        if (t->right)
          que.push(t->right);

        int sum += t->val;
        que.pop();
      }
    }

    return sum;
   }
int main()
{
    vector<int>root;
    cin>>root;
    cout<< deepestLeavesSum(TreeNode *root)<<endl;
}
/*Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
 /*
