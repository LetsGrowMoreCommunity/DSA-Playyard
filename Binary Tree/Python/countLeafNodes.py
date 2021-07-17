#Dummy BT Class
class bstNode:
	def __init__(self,val=0,left=None,right=None):
		self.val = val
		self.left = left
		self.right = right
		
class countLeafNodes:
	def __init__(self):
		self.curLeafNodes = 0
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

