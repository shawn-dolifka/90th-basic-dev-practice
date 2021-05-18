"""
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0024 - Declare and/or implement container data type.
  S0023 - Declare and implement data types.
  S0031 - Utilize logical operators to formulate boolean expressions.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0069 - Find an item in a Circularly Linked List.
  S0070 - Add and remove nodes from a Circularly Linked List.
  S0052 - Implement a function that returns a single value.
  S0057 - Create and destroy a Circularly Linked List.
  S0048 - Implement a function that receives input parameters.
  S0079 - Validate expected input.
  S0081 - Implement a looping construct.
  S0110 - Implement error handling.
  S0082 - Implement conditional control flow constructs."""
'''
Write the function buildList that receives a list of integers (nums).
The buildList function should create a circularly linked list using 
the Node class defined below.

The buildList function should iterate the "nums" list and insert the numbers into nodes. 
Each new node will be inserted at the head of the circularly linked list.

if a number in "nums" is already in the circularly linked list or if an item in "nums" is
not an integer, do not insert it into the circularly linked list and continue iterating the "nums" list

The buildList function should return a reference to the head node of the link list once processed.

if "nums" is an empty list, the function should return None.




'''
class Node:
    def __init__(self, num):
        self.num = num
        self.next = None

def buildList(nums):
  head = None
  if not nums:
    return None
  num_dict = {}
  for num in nums:
    # Skip non-Integers
    if not isinstance(num, int):
      continue
    # Skip items already in linked list
    if num in num_dict:
      continue

    num_dict[num] = True
    if head == None:
      head = Node(num)
      head.next = head
      last = head
    else:
      new_node = Node(num)
      new_node.next = head
      head = new_node
      last.next = head
      
  return head
