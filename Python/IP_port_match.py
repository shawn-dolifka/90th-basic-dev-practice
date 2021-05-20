"""
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0026 - Utilize standard library modules.
  S0024 - Declare and/or implement container data type.
  S0023 - Declare and implement data types.
  S0031 - Utilize logical operators to formulate boolean expressions.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0048 - Implement a function that receives input parameters.
  S0081 - Implement a looping construct.
  S0082 - Implement conditional control flow constructs.
  S0161 - Write and utilize regular expressions in a program."""
"""

** NOTE: THE SOLUTION FOR THIS PROBLEM IS BASED ON A SPECIFICALLY DEFINED ALGORITHM EXPLAINED BELOW. ALTHOUGH THE AUTOMATED TESTS
** MAY BE SUCCESSFUL, YOUR SOLUTION WILL RECEIVE A MANUAL REVIEW FOR FINAL DETERMINATION OF PASS/FAIL

Write a program that uses a regular expression to extract all strings 
of the form <ip_address>:<port> from the input string, where `ip_address` is
an IPv4 style address and `port` is an integer in the range 50000-62000 (inclusive).

@param inputString An input string containing some text that should be searched 
                   for the pattern described above


Your function should return a list of tuples containing the address and port
of the form (str, int)

"""
import re

# \b[5-6](?:(?<=5)[0-9]|(?<=6)[0-2])

def find_matches(inputString):
  ip_regex = re.compile(r'\b(?:[0-9]{1,3}\.){3}[0-9]{1,3}\b')
  port_regex = re.compile(r'(?:\b620{3})|(?:\b6[0-1][0-9]{3})|(?:5[0-9]{4})')
  ip_addresses = re.findall(ip_regex, inputString)
  ports = re.findall(port_regex, inputString)

  ip_and_port = []
  size = len(ip_addresses)
  for i in range(size):
    temp = (ip_addresses[i], int(ports[i]))
    ip_and_port.append(temp)
  return ip_and_port
