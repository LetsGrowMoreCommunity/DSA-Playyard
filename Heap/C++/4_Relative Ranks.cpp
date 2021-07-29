//time complexity )(NLOGN)
#include<bits/stdc++.h>
using namespace std;
    
vector<string> findRelativeRanks(vector<int>& nums) {//take the vector of scores
	int n = nums.size();//counting the size 
	priority_queue<pair<int,int>> pq;//taking a priority queqe
	vector<string> ans(n);
	string s;
	for(int i=0;i<n;++i)  pq.push({nums[i],i});//storing the num and its index in the priority queqe
	for(int i=0;i<n;++i){
	  if(i<3){//taking 3 cases 
		switch(i){
		  case 0: s="Gold Medal"; break;
		  case 1: s="Silver Medal"; break;
		  case 2: s="Bronze Medal"; break;
		}
	  }else s = to_string(i+1);//if it does not fall under the three cases then convert that integer to string
	  ans[pq.top().second] = s;
	  pq.pop();//for printingthe elements in the output
	}
	return ans;//returning the ans
}

int main()
{

    int nums[n];
    for (i = 0; i < n; i++) {

     cin >> nums[i]; 
    }

    cout <<  findRelativeRanks(nums);

    return 0;
	
	
}




/*Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].

Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th]./*
