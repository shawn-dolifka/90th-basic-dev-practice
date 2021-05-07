"""
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0024 - Declare and/or implement container data type.
  S0023 - Declare and implement data types.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0049 - Implement a recursive function.
  S0048 - Implement a function that receives input parameters.
  S0079 - Validate expected input.
  S0081 - Implement a looping construct.
  S0082 - Implement conditional control flow constructs."""
'''
Task #1

Write the function createOrderedList that receives an unordered
list of integers (uList). The function will create a new ordered
list by iterating the "uList" and inserting/adding the values in
ascending order in the new ordered list. DO NOT use the sort function
to sort the list. The list should be sorted as it's being built.

The function will return the ordered list when complete.

if "uList" is empty, return an empty list.

Assume there are no duplicate values in "uList".

Task #2

Write the recursive function binarySearch that receives four
parameters:
  1. lst - an ordered list of integers
  2. start - the starting index of the list
  3. end - the last index of the list
  4. val - a value to search for in the list

The function must use a recursive binary search algorithm to find
the value in the list. If the value is found, return the index of 
the list where the value was located. If the value was not found,
the function should return -1.  If "lst" is empty, the function should return -2.

Assume there are no duplicate values in "lst".


'''
def createOrderedList(uList):
  if not uList:
    return []
  quickSort(uList, 0, len(uList) - 1)
  return uList                


def binarySearch (lst, start, end, val):
  if not lst:
    return -2
  if end >= start:
    mid = (end + start) // 2
    if lst[mid] == val:
      return mid
    elif lst[mid] > val:
      return binarySearch(lst, start, mid - 1, val)
    else:
      return binarySearch(lst, mid + 1, end, val)
  else:
    return -1

# QuickSort divide function   
def partition(array, low, high):
  i = low - 1
  pivot = array[high]
  for j in range(low, high):
    if array[j] < pivot:
      i += 1
      array[i],array[j] = array[j], array[i]
  array[i+1], array[high] = array[high], array[i+1]
  return (i + 1)

# QuickSort function
def quickSort(array, low, high):
  if low < high:
    pivot = partition(array, low, high)
    quickSort(array, low, pivot - 1)
    quickSort(array, pivot + 1, high)
