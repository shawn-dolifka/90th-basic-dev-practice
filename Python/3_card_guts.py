"""
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0024 - Declare and/or implement container data type.
  S0023 - Declare and implement data types.
  S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
  S0031 - Utilize logical operators to formulate boolean expressions.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0048 - Implement a function that receives input parameters.
  S0079 - Validate expected input.
  S0081 - Implement a looping construct.
  S0082 - Implement conditional control flow constructs."""
'''
In the poker game of guts, the highest card is an Ace and lowest is a 2. In guts each player is given
three cards and you go head to head with your opponents.  The highest hand wins.  The ranking of hands is in 
this order:
1. Highest three of a kind (if any)     Winner: 6,6,6        Not winner: 5,5,5
2. Highest two of a kind (if any)     Winner: 7,7,5    Not winner: 5,5,6
3. High card (person with highest card)   Winner: 11,7,5     Not winner: 10,4,2

This game of guts will only have two players to keep it simple.  Assume no two players will ever have
the same pair (if there is a pair).  And no two players will ever have the same high card.

The findGutsWinner function will receive two lists that represent two guts hands.  Each list will contain three numbers
from 2 to 14.  Where 14 represents an Ace, 13 a King etc.

For example hand1 may contain [14,2,7] and hand2 may contain [3,3,14] in which hand2 would be highest because it had two of a kind.

Determine which of the two hands is the highest, and return the list containing that hand.

Assume there are no invalid numbers in each list.

If any list is more or less than three elements, return an empty list.

'''
THREE_OF_KIND = 3
TWO_OF_KIND = 2

def findGutsWinner(hand1, hand2):
  if len(hand1) != 3 or len(hand2) != 3:
    return []

  cards_p1 = {}
  cards_p2 = {}
  
  # Find 2 and 3 of a kinds in hands with dictionary matches
  for i in range(3):
    p1_card = hand1[i]
    p2_card = hand2[i]
    cards_p1[p1_card] = cards_p1.get(p1_card, 0) + 1
    cards_p2[p2_card] = cards_p2.get(p2_card, 0) + 1
  
  # Player 1 has 3 of a kind and Player 2 doesn't
  if THREE_OF_KIND in cards_p1.values() and THREE_OF_KIND not in cards_p2.values():
    return hand1
  # Player 2 has 3 of a kind and Player 1 doesn't
  if THREE_OF_KIND in cards_p2.values() and THREE_OF_KIND not in cards_p1.values():
    return hand2
  # Both players have 3 of a kind
  if THREE_OF_KIND in cards_p1.values() and THREE_OF_KIND in cards_p2.values():
    p1_high = p2_high = 0

    # Find the highest card for Player 1
    for key, value in cards_p1.items():
      if value == THREE_OF_KIND:
        p1_high = key

    # Find the highest card for Player 2
    for key, value in cards_p2.items():
      if value == THREE_OF_KIND:
        p2_high = key

    # Player with the higher card wins
    if p1_high > p2_high:
      return hand1
    else:
      return hand2


  # Player 1 has a pair and Player 2 doesn't
  if TWO_OF_KIND in cards_p1.values() and TWO_OF_KIND not in cards_p2.values():
    return hand1
  # Player 2 has a pair and Player 1 doesn't
  if TWO_OF_KIND in cards_p2.values() and TWO_OF_KIND not in cards_p1.values():
    return hand2
  # Both players have a pair
  if TWO_OF_KIND in cards_p1.values() and TWO_OF_KIND in cards_p2.values():
    p1_high = p2_high = 0

    # Find the highest card for Player 1
    for key, value in cards_p1.items():
      if value == TWO_OF_KIND:
        p1_high = key

    # Find the highest card for Player 2
    for key, value in cards_p2.items():
      if value == TWO_OF_KIND:
        p2_high = key
    
    # Player with the higher card wins
    if p1_high > p2_high:
      return hand1
    else:
      return hand2

  # No one has matches. Highest card wins
  if max(cards_p1) > max(cards_p2):
    return hand1
  else:
    return hand2
