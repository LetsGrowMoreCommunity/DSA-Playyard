""" Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
problem statement: https://leetcode.com/problems/excel-sheet-column-title/
For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...

Solution: A simple iterative solution to continously divide base-10 number and generate a
pseudo-base-26 character corresponding to the column title
"""

class Solution:
    def convertToTitle(self, columnNumber: int) -> str: # function give Column Name
        columnName = ''
        while (columnNumber > 0):
            columnName += chr((columnNumber - 1) % 26 + 65)     # add number with remainder and generate column name using ASCII value.
            columnNumber = (columnNumber - 1) // 26        # split the number and give integer value
        return columnName[::-1]            # reverse the name

n = input("ColumnNumber = ")     # asking the user to enter the input number
print('\"'+Solution.convertToTitle(Solution,int(n))+'\"')   # calling to above function and print column name in between double quote.

#Example 1:
#Input: ColumnNumber = 1
#Output: "A"

#Example 2:
#Input: ColumnNumber = 28
#Output: "AB"

#Example 3:
#Input: ColumnNumber = 702
#Output: "ZZ"

#Example 4:
#Input: ColumnNumber = 18279
#Output: "AAAA"

#Example 5:
#Input: ColumnNumber = 2147483647
#Output: "FXSHRXW"