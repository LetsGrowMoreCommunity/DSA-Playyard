# vchsi - Count Leaf Nodes from a Binary Tree
# github.com/vchsi
#
# Time Complexity: O(m+n) where M=Nodes and N=Paths
# Space Complexity: O(1) Where 1=Single Int used to store leaves
#
# Explanation:
# Do preorder traversal on Binary Tree
# Store LeafCount as a Instance Variable and reset to 0 every time the function
# is ran
# Count the node as a leaf if node.left is None and node.right is None

from collections import defaultdict

#Initalize Binary Tree Node Class
class btNode:
	def __init__(self,val=0,left=None,right=None):
		self.val = val
		self.left = left
		self.right = right

class countLeafNodes:
	#Initialize Leaf Node Counter
	def __init__(self):
		self.curLeafNodes = 0
	#Function to see testcase
	def levelOrder(self, root):
		di = defaultdict(list)
		def dfs(root,lvl):
			nonlocal di
			if(not root):
				di[lvl].append(None)
				return
			di[lvl].append(root.val)
			dfs(root.left,lvl+1)
			dfs(root.right,lvl+1)
		dfs(root,0)
		li = []
		for v in di.values():
			li+=list(v)
		return li
	#Preorder Traversal Function called by main function
	def recurse(self,bst):
		if(not bst):
			return
		#Checks if current node is a leaf node
		if(not bst.left and not bst.right):
			self.curLeafNodes += 1
			return
		else:
			#Else continue the Preorder Traversal
			self.recurse(bst.left)
			self.recurse(bst.right)
	#Main function called that calls recurse()
	def countLeafNodes(self,bst):
		#Set Counter back to 0
		self.curLeafNodes = 0
		self.recurse(bst)
		#Return Counter
		return self.curLeafNodes


#### Testing code ####
if __name__ == '__main__':
	#[3, 9, null, null, null]
	#answer: 1
	tester = btNode(3)
	tester.left = btNode(9)
	testingStation = countLeafNodes()
	#print(str(testingStation.levelOrder(tester)).replace("None","null"))
	print(testingStation.countLeafNodes(tester))
	#[3, 9, 20, 100, null, 15, 7, null, null, null, null, null, 20, null, null]
	#Answer: 3
	tester.right = btNode(20)
	tester.right.left = btNode(15)
	tester.right.right = btNode(7)
	tester.right.right.right = btNode(20)
	tester.left.left = btNode(100)
	#print(str(testingStation.levelOrder(tester)).replace("None","null"))
	print(testingStation.countLeafNodes(tester))
	#[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
	#Answer: 5
	tester = btNode(6)
	tester.left = btNode(7)
	tester.right = btNode(8)
	tester.left.left = btNode(2)
	tester.left.left.left = btNode(9)
	tester.left.right = btNode(7)
	tester.left.right.left = btNode(1)
	tester.left.right.right = btNode(4)
	tester.right.left = btNode(1)
	tester.right.right = btNode(1)
	tester.right.right.right = btNode(5)
	print(testingStation.countLeafNodes(tester))