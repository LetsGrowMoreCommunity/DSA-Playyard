/*
-> Problem Statement
You are given an array of points having x and y co-ordinates (vector of vectors) and an integer k, 
You need to return k closest points to origin according to euclidean distance.

-> Approach Explanation:
- First for all points (vector having x and y) , we will map value of x^2 + y^2 with its key as point's index.
  ( since we will be using int while comparing distance we are not taking square root of distance, 
    since taking square root can not make comparision exact for int , and not taking sqrt will not affect while comparing
- We need K closest points i.e. K points having shortest distance which can be found using priority_queue as minheap. )
- Priority queue is considered as vector of vectors (each having distance and index taken from map),
  priority_queue will keep vectors in assending order of distance as per given comparision function.
  And we can get first k closest points from index inside first k priority_queue vectors. 
*/

#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    
    bool operator()(vector<int> const& a, vector<int> const& b )     //comparision function to sort according to distance 
    {
        return a[0] > b[0];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        map<int,int>mp;
        for(int i=0;i<points.size();i++)
        {
            mp[i] = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]); //mapping distances and index for points
        }
        
        priority_queue<vector<int>, vector<vector<int>>, Solution> pq;             // priority_queue as minheap(for distances)
        
        for(auto i : mp)
        {
            vector<int>v;
            v.push_back(i.second);
            v.push_back(i.first);
            pq.push(v);                                             // pushing distances and indexes from maps to priority_queue
        }
        
        vector<vector<int>>ans;
        
        while(k--)
        {
            vector<int>top = pq.top();                              // getting first k vectors having shortest distances
            vector<int>xy = points[top[1]];                         // getting corrsponding points from index
            ans.push_back(xy);                                      
            pq.pop();
        }
        
        return ans;                                                 // returning final vector having k closest points from origin
        
    }
};

// It can also be easily solved with similar logic just by using vector of vectors or map having distances and indices in sorted manner.

int main() 
{
    cout<<"\nEnter number of test cases: ";
	int t; cin>>t;  //no. of test cases

	/*
	Constraints:
    1 <= k <= points array length <= 10^4
   -10^4 < x,y values < 10^4
    */

	while (t--)
	{
	    cout<<"\n\nEnter number of points you have: ";
	    int n; cin>>n;

	    vector<vector<int>> points (n);

	    cout<<"\nEnter points as x and y co-ordinates in array : ";
	    for (int i=0; i<n; i++)
           {
                cout<<"\nPoint :"<<i + 1<<endl;
                cout<<"\nx :";
                cin>>points[i][0];
                cout<<"\ny :";
                cin>>points[i][1];
           }
        
        cout<<"\nEnter value of K (No of Closest points you want): ";
        int k;cin>>k;

	    Solution *ob;
        cout<<"\nK Closest Poits to Origin are :";
	    vector<vector<int>> closestpoints =  ob-> kClosest(points,k);
        for (int i=0; i<k; i++)
           {
                cout<<"\nPoint :"<<i + 1<<endl;
                cout<<"\nx :";
                cin>>points[i][0];
                cout<<"\ny :";
                cin>>points[i][1];
           }
	    
	}
	return 0;
}

/*
SAMPLE INPUT
2				         // number of test cases 
3				         // no.of points for test case:1
4 3 	                 // points as x and y in vector for test case:1
-1 2
-5 3
2                        // value of k
5				         // no.of pointsfor test case:2
-2 5                     // points as x and y in vector for test case:2
0 0 
1 -6
7 -4  
3                        // value of k
 
SAMPLE OUTPUT (excluding interactive instructions)
-1 2    ( 2 clost points to origin for test case-1 )
4 3
0 0    ( 3 closest points to origin for test case-2 )
-2 5 
1 -6  
COMPLEXITY ANALYSIS : N= no.of points in array
Time : O(N) to iterate array/vector and insert in map  . 
       O(NLogN) for creating minheap or inserting elements in priority_que
       Hence, O(NlogN) overall.
Space: O(N) for inputs and aux space: O(N) to create a priority_queue.
       Hence, O(N) overall.
*/