'''
This question is intended to evaluate the following topics:
  - A0019 - Integrate functionality between multiple software components.
  - A0018 - Analyze a problem to formulate a software solution.
  - S0024 - Declare and/or implement container data type.
  - S0023 - Declare and implement data types.
  - S0037 - Open and close an existing file.
  - S0032 - Utilize relational operators to formulate boolean expressions.
  - S0038 - Read, parse, write (append, insert, modify) file data.
  - S0033 - Utilize assignment operators to update a variable.
  - S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  - S0052 - Implement a function that returns a single value.
  - S0048 - Implement a function that receives input parameters.
  - S0080 - Demonstrate the skill to implement exception handling.
  - S0079 - Validate expected input.
  - S0081 - Implement a looping construct.
  - S0110 - Implement error handling.
  - S0082 - Implement conditional control flow constructs.

Write the function find_culprits that receives the name of a file.
The function will open and read the file.
The file contains a list of user ids and number of minutes their
login session has been idle. The file can contain multiple session entries
of the same user id.  The format of the file is:  userid, mins

Example:

jschmo, 22
haaron, 12
haaron, 7
jschmo, 17

The function should find the (up to) top five users with the most total idle time and 
save them in order (highest to lowest) in a list of lists.  Each list item in the list will contain a userid
and number of mins as an integer in that order.

Example  [["jschmo",39],["haaron",19]]

Write no more than the top five users to the list handling the case where there may not be five total
users. If there is a tie between values any order between the ties is valid.

If the file cannot be opened, return None

For this exercise all data in the file has valid format/content.

If the file process successfully, return the list of lists of users
'''

import os
from collections import Counter

def find_culprits(fileName):
    try:
        with open(fileName, 'r') as reader:
            # Account for empty file
            if os.path.getsize(fileName) == 0:
                return []
            content = reader.readlines()
    except FileNotFoundError:
        return None
    
    culprits = {}
    top_5 = []

    for line in content:
        # Remove white space
        line = line.replace(" ", "")
        # Remove newline
        line = line.replace("\n", "")
        # index 0 is username, index 1 is idle time
        user_info = line.split(',')

        username = user_info[0]
        idle_time = int(user_info[1])
        
        if username in culprits:
            culprits[username] = culprits.get(username) + idle_time
        else:
            culprits[username] = idle_time
    
    # Create a collection to use most_common function
    collection = Counter(culprits)
    
    # most_common will get the top number of whatever is passed as an argument
    # By default most_common will handle where there isn't five users
    for key, value in collection.most_common(5):
        top_5.append([key,value])

    return top_5
