"""
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0382 - Create a class constructor or destructor
  S0024 - Declare and/or implement container data type.
  S0023 - Declare and implement data types.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0058 - Create and destroy a Queue.
  S0071 - Enqueue and dequeue a Queue.
  S0052 - Implement a function that returns a single value.
  S0048 - Implement a function that receives input parameters.
  S0081 - Implement a looping construct.
  S0082 - Implement conditional control flow constructs."""
'''
This task will implement a simple queue class using a  list. Each node in the queue
contains an integer.

Write the class queue with the following attributes, functions and functionality:

Attributes:
   qList = a list representing the queue

Functions:

enqueue - This function receives one parameter. A list of numbers
            to add to the queue. The function should iterate the list
            and add each number on to the queue as it's iterated.

dequeue  - This function receives one parameter. An integer indicating
           how many items to remove from the queue. If the integer
           passed is greater than the number of items in the queue
           the function will not modify the queue.
           Otherwise, the function will remove the number of items from
           the queue.

emptyQueue - This function has no parameters and removes all items in the
             queue.
             
peek - This function has no parameters and returns the front value
       in the queue without modifying the queue. If there is no front value
       the function returns None.
       
isEmpty - This function has no parameters and returns a boolean on whether
          the queue is empty.

size - returns the size of the queue.
'''

class queue:
    def __init__(self):
        self.qList = []

    def enqueue(self, items):
        for item in items:
            self.qList.append(item)

    def dequeue(self, numRemove):
        if numRemove > len(self.qList):
            return
        for i in range(numRemove):
            self.qList.pop(0)

    def emptyQueue(self):
        if self.isEmpty():
            return
        while not self.isEmpty():
            self.qList.pop()

    def peek(self):
        if self.isEmpty():
            return None
        return self.qList[0]

    def isEmpty(self):
        if not self.qList:
            return True
        return False

    def size(self):
        return len(self.qList)
