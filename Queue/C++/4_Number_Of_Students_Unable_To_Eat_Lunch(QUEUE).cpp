/*
Problem: Number of Students Unable to Eat Lunch on LeetCode
Solution by AtrikGit6174

The stud vector for the preference of students is converted into a queue, 
while the sand vector for the shape of the sandwiches is effectively 
treated as a stack using iterators.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution 
{
public:
    int countStudents(vector<int>& stud, vector<int>& sand) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int n= stud.size();
        int flag= 0;
        queue<int> line;
        
        for (int i=0; i<stud.size(); i++)
            line.push(stud[i]);
        
        auto sandptr= sand.begin();
        
        /*
        flag will be equal to line.size() when the line has been 
        iterated once over but no student could pick a sandwich, 
        which is trivially solved for zero remaining students.
        However, once a student picks up a sandwich, flag is reset to 0.
        */
        
        for (int i=0; flag!=line.size(); i++)
        {
            if (line.front()==*sandptr)
            {
                line.pop();
                sandptr++;
                flag= 0;
            }
            
            else
            {
                line.push(line.front());
                line.pop();
                flag++;
            }
        }
        
        return line.size();   
    }
};

int main() 
{
	int t; cin>>t;  //no. of test cases
	
	/*
	Constraints:

    || 1 <= students.length, sandwiches.length <= 100
    || students.length == sandwiches.length
    || sandwiches[i] is 0 or 1.
    || students[i] is 0 or 1.
    */
	
	while (t--)
	{
	    cout<<"\nEnter the number of students/sandwiches: ";
	    int n; cin>>n;
	    
	    vector<int> stud (n);
	    vector<int> sand (n);
	    
	    cout<<"\nEnter students array: ";
	    for (int i=0; i<n; i++)
	        cin>>stud[i];
	        
	    cout<<"\nEnter sandwiches array: ";
	    for (int i=0; i<n; i++)
	        cin>>sand[i];
	   
	    Solution *ob;
	    cout<<"\nRequired number= "<<ob->countStudents(stud, sand)<<"\n";
	    
	}
	return 0;
}

/*
SAMPLE INPUT
2				<-- NUMBER OF TEST CASES
4				<-- NUMBER OF STUDENTS/SANDWICHES FOR THE TEST CASE 1
1 1 0 0				<-- STUDENTS VECTOR FOR TEST CASE 1
0 1 0 1				<-- SANDWICHES VECTOR FOR TEST CASE 1
6				<-- NUMBER OF STUDENTS/SANDWICHES FOR THE TEST CASE 2
1 1 1 0 0 1			<-- STUDENTS VECTOR FOR TEST CASE 2
1 0 0 0 1 1			<-- SANDWICHES VECTOR FOR TEST CASE 2

SAMPLE OUTPUT (excluding interactive instructions)
0
3

COMPLEXITY ANALYSIS n= no. of students/sandwiches
Time: O(n) to re-create queue and O(n) to iterate. 
      Even if the queue is rolling over, it cannot 
      exceed n more iterations after the required count is reached.
      Hence, total O(n).
Space: O(n) for inputs and aux space: O(n) to re-create a queue.
       Hence, O(n) overall.
*/
