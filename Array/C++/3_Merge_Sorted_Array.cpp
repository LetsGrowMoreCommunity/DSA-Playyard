/*
Problem: Merge Sorted Arrays on LeetCode
Solution by AtrikGit6174

The solution contains both O(1) and O(m+n) aux space methods
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    void merge_space (vector<int>& vec1, int m, vector<int>& vec2, int n)
    //uses O(m+n) aux space
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        vector<int> copy;
        
        for (int i=0,j=0; i!=m or j!=n; )
        {
            if (i<m and j<n)
            {
                if (vec1[i]<=vec2[j])
                {
                    copy.push_back(vec1[i]);
                    i++;
                }
                
                else
                {
                    copy.push_back(vec2[j]);
                    j++;
                }
            }
            
            else if (i<m and j==n)
            {
                copy.push_back(vec1[i]);
                i++;
            }
            
            else if (j<n and i==m)
            {
                copy.push_back(vec2[j]);
                j++;
            }
        }
        
        vec1= copy;
    }
    
    void merge_nospace(vector<int>& vec1, int m, vector<int>& vec2, int n) 
    //uses O(1) aux space
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if (m==0)
        {
            vec1= vec2;
            return;
        }
        
        if (n==0)
            return;
        
        int ptr1=0, ptr2=0;
        
        while (n)
        {
            while (m and vec1[ptr1]<=vec2[ptr2])
            {
                ptr1++;
                m--;
            }
            
            //vec1.insert(vec1.begin()+ptr1, vec2[ptr2]);
            //vec1.erase(vec1.end()-1);
            
            for (int i=vec1.size()-1; i>=ptr1+1; i--)
                vec1[i]=vec1[i-1];
            
            vec1[ptr1]=vec2[ptr2];
            ptr1++;
            ptr2++;
            n--;      
        }
    }
    
    void display (vector<int> &vec)
    {
        for (int i=0; i<vec.size(); i++)
            cout<<vec[i]<<" ";
        
        cout<<"\n";
    }
};

int main() 
{
	cout<<"\nEnter the number of test cases: ";
	int t; cin>>t;
	
	for (int count=1; count<=t; count++)
	{
	    cout<<"\nTEST CASE "<<count;
	    cout<<"\nEnter the size of the vectors: ";
	    int m,n; cin>>m>>n;
	    
	    vector<int> vec1(m+n), vec2(n);
	    
	    cout<<"\nEnter vec1: ";
	    for (int i=0; i<m+n; i++)
	    {
	        if (i<m) 
	            cin>>vec1[i];
	        else
	            vec1[i]=0;
	    }
	    
	    cout<<"\nEnter vec2: ";
	    for (int i=0; i<n; i++)
	        cin>>vec2[i];
	   
	    auto vec1_copy= vec1;
	    Solution *ob;
	    ob->merge_space (vec1, m, vec2, n);
	    cout<<"\nWith space: "; ob->display(vec1);
	    
	    ob->merge_nospace (vec1_copy,m, vec2, n);
	    cout<<"\nWithout space: "; ob->display(vec1_copy);
	}
	return 0;
}

/*
SAMPLE INPUT
3               <-- NUMBER OF TEST CASES
3 3             <-- CASE 1 m=3, n=3
1 2 3           <-- CASE 1 VECTOR 1
2 5 6           <-- CASE 1 VECTOR 2
1 0             <-- CASE 2 m=1 n=0
1               <-- CASE 2 VECTOR 1, NO VECTOR 2
0 1             <-- CASE 3 m=0 n=1
1               <-- CASE 3 VECTOR 2, NO VECTOR 1

SAMPLE OUTPUT (excluding interactive instructions)
With space: 1 2 2 3 5 6
Without space: 1 2 2 3 5 6

With space: 1
Without space: 1

With space: 1
Without space: 1

COMPLEXITY ANALYSIS m+n is the total number of elements in the final array
Time:- With space: O(m+n) to compare and insert in a new array
       Without space: O(mn) for the worst case where the vec2's last element 
                     is less than vec1's first element.
                     This will require m` shifts for all n elements.
                     
Aux Space:- With space: O(m+n)
            Without space O(1)
*/
