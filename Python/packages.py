"""
This question is intended to evaluate the following topics:
  S0027 - Install for a Python package using PIP.
  S0028 - Set up and replicate a Python Virtual Environment.
  S0024 - Declare and/or implement container data type.
  S0031 - Utilize logical operators to formulate boolean expressions.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0048 - Implement a function that receives input parameters.
  S0079 - Validate expected input."""
"""
For this problem you will need to create a virtual environment and install the python package astar_python inside of the virtual environment. After that is successful, you can begin writing your code.

Write a function navigate_world() that will use the A* algorithm in astar_python to traverse a multi dimensional array.
    The function will return the list of points from the start to the finish or none if there was no path to the finish

    The function needs to accept the following parameters:
     world: a 2 dimensional list containing integers
     start: a list containing the [col, row] to start
     end: a list containing the [col, row] to traverse to

Make sure the world size is at least 5x5; isn't a jagged array; and contains only 0, positive numbers, or None.
any invalid world configurations should return None.

<<<==================================================>>>

<--- How to set up venv and astar_python: --->

In Python 3.4+ venv is installed by default. Use the command:

  python -m venv [directory] 
  
to create a venv folder

For other Python versions:

  sudo pip install virtualenv

Then create a directory for the environment)

  virtualenv [directory]

Activate the environment:

  $ source myvenv/bin/activate (Linux)
  C:\> env\Scripts\activate.bat (Windows)

Install astar-python with the command:

  pip3 install astar-python

Deactivate the environment with the command:
  $ deactivate (Linux)
  C:\> edeactivate (Windows)

<<<==================================================>>>
"""

from astar_python import Astar

def navigate_world(world, start, finish):
    # Check for empty world
    if not world:
      return None
    column_count = len(world[0])
    row_count = 0
    
    # Check if world seems valid. Does not guarantee, but can save time on some runs
    if column_count < 5:
      return None

    for rows in world:
      row_count += 1
      # Check if any other rows are less than 5. Also if they differ from 1st row
      if len(rows) < 5 or len(rows) != column_count:
        return None

      for column in rows:
        if column is None:
          continue
        elif not isinstance(column, int):
          return None
        elif column < 0:
          return None
    
    # Check if rows are too few
    if row_count < 5:
      return None
    
    za_warudo = Astar(world)
    result = za_warudo.run(start, finish)
    return result
