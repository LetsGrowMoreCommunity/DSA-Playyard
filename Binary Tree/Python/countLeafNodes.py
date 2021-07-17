from collections import defaultdict
class bstNode:
	def __init__(self,val=0,left=None,right=None):
		self.val = val
		self.left = left
		self.right = right

class countLeafNodes:
	def __init__(self):
		self.curLeafNodes = 0
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
	def recurse(self,bst):
		if(not bst):
			return
		if(not bst.left and not bst.right):
			self.curLeafNodes += 1
			return
		else:
			self.recurse(bst.left)
			self.recurse(bst.right)
	def countLeafNodes(self,bst):
		self.curLeafNodes = 0
		self.recurse(bst)
		return self.curLeafNodes

### Testing code ###
if __name__ == '__main__':
	#[3,9,20,null,null,15,7]
	tester = bstNode(3)
	tester.left = bstNode(9)
	testingStation = countLeafNodes()
	print(str(testingStation.levelOrder(tester)).replace("None","null"))
	print(testingStation.countLeafNodes(tester))
	tester.right = bstNode(20)
	tester.right.left = bstNode(15)
	tester.right.right = bstNode(7)
	tester.right.right.right = bstNode(20)
	tester.left.left = bstNode(100)
	print(str(testingStation.levelOrder(tester)).replace("None","null"))
	print(testingStation.countLeafNodes(tester))
	#[null, 100, null, 9, null, 3, null, 15, null, 20, null, 7, null, 20, null]