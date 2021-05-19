"""
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0023 - Declare and implement data types.
  S0031 - Utilize logical operators to formulate boolean expressions.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0074 - Find an item in a Binary Search Tree.
  S0075 - Add and remove nodes from a Binary Search Tree.
  S0052 - Implement a function that returns a single value.
  S0060 - Create and destroy a Binary Search Tree.
  S0048 - Implement a function that receives input parameters.
  S0081 - Implement a looping construct.
  S0082 - Implement conditional control flow constructs."""
'''

A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties:
        The left sub-tree of a node has a value less than its parent node's value.
        The right sub-tree of a node has a value greater than to its parent node's value.
        In this scenario, no duplicate values are allowed.
        
Task #1

Write the function buildBST that receives a list of integers. The function will build The
BST by:
    1. Iterating the list
    2. Using the provided Node class and creating Nodes for each value
    3. Inserting each Node into the BST.
If a value in the list is already in the BST, ignore the value and continue processing the rest of the list.

When complete, the function will return a reference to the root node of the BST.

Task #2

Write the function findLevel that receives the root of a BST (root) and a integer 
value (findVal). The function will search the BST and find and return level of the
BST where the value resides.  If the value is not found, the function returns None.

'''

class Node:
    def __init__(self, val):
        self.val = val
        self.right = None
        self.left = None

    def insert(self, value):
        if self.val == value:
            return
        elif value < self.val:
            if self.left:
                return self.left.insert(value)
            else:
                self.left = Node(value)
        else:
            if self.right:
                return self.right.insert(value)
            else:
                self.right = Node(value)
                return
    
    def find(self, value, level):
        if self.val == value:
            return level
        elif value < self.val and self.left:
            return self.left.find(value, level+1)
        elif value > self.val and self.right:
            return self.right.find(value, level+1)
        return None

def buildBST(nums):
    root = Node(nums[0])
    size = len(nums)
    for i in range(1, size):
        root.insert(nums[i])
    return root

def findLevel(root, findVal):
    level = 0
    level = root.find(findVal, level)
    return level
