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
  S0052 - Implement a function that returns a single value.
  S0048 - Implement a function that receives input parameters.
  S0081 - Implement a looping construct.
  S0082 - Implement conditional control flow constructs."""
'''
Write the function findWholeWords that receives a phrase in the form of a string ("phr"), and a list containing 
one or more 'words' in the form of strings ("wordList"). The function will find all whole-word instances of each 
string in the list that is present in the phrase.

For example, two of the strings in the list may be 'cat' and 'dog'.  So, the function needs to find strings that match cat 
and dog exactly.  So, if the phrase is:

A cat is in the feline category of animals. Some cats are domesticated while others are not. The Cats About Town (CAT)
organization sponsors an initiative to free all felines. Dog is in the canine category. Some people call dogs doggy. I like my dog. 

The function should find two instance of cat in the phrase as it would not match the exact string 
with category, domesticated, or cats. It would find two instances of dog as it would not match dogs or doggy.

Strings cannot be immediately preceded by or followed by an alpha or digit to match. 
The string may or may not be preceded/followed by characters such as a space, period, commas, parenthesis etc. 

For the phrase:  "cat, horse, mouse, and dog" one instance of cat and one instance of dog exists.

Matching is case insensitive, so words like Cat, CAT, or CAt should still match.

The function should return a dictionary of all the strings in the list as a key, and the quantity found in the phrase
as a value pair. 

Example {'cat': 1,
         'dog': 1}

'''

import re

def findWholeWords(phr, wordList):
    wordDict = {}
    for word in wordList:
      # \b is for boundary in Regex.
      pattern = "\\b"+word+"\\b"
      count = len(re.findall(pattern, phr, re.IGNORECASE))
      wordDict[word] = count
    return wordDict 
