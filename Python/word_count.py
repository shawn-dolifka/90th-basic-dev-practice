"""
This question is intended to evaluate the following topics:
  S0033 - Utilize assignment operators to update a variable.
  S0048 - Implement a function that receives input parameters.
  S0110 - Implement error handling.
  S0037 - Open and close an existing file.
  S0038 - Read, parse, write (append, insert, modify) file data.
  S0047 - Implement a function that returns multiple values.
  S0080 - Demonstrate the skill to implement exception handling."""

"""
Create a function named word_count that takes a filename to read and counts each of the words 
in the file and keeps track of how many times each word appears

word_count must return three values: a dictionary containing each word as a key and the number of times that 
word appears in the file, the word that appears the most, and the total number of words in the file
word counts need to account for punctuation and whitespace. e.g. "ipset" and "ipset." would both count as the same word.
possible punctuation that you need to account for includes periods, commas, newlines, and tabs.

if a file contains no words, is empty, or can not be found then return None

"""
import re
import os

def word_count(fname):
  try:
    with open(fname, 'r') as reader:
      # Check if file is empty
      if os.path.getsize(fname) == 0:
        return None
      content = reader.readlines()
    word_frequency = {}
    for line in content:

      # Strip punctuation
      line = re.sub(r'[^\w ]',"",line)

      # Split words into list on space
      words = line.split()

      # Skip if the line is empty after stripping
      if not words:
        pass
      else:
        for word in words:
          word_frequency[word.lower()] = word_frequency.get(word.lower(), 0) + 1
    
    # The dictionary was empty. Happens when file is filled with only punctuation and spaces
    if not word_frequency:
      return None

    word_total = sum(word_frequency.values())
    most_word = max(word_frequency.items(), key=lambda pair: (pair[1], pair[0]))[0]

    return word_frequency, most_word, word_total

  except FileNotFoundError:
    return None
