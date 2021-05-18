/*
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
  S0034 - Declare and implement appropriate data types for program requirements.
  S0031 - Utilize logical operators to formulate boolean expressions.
  S0035 - Declare and/or implement of arrays and multi-dimensional arrays.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0036 - Declare and implement a char * array (string).
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0053 - Implement a function that returns a memory reference.
  S0079 - Validate expected input.
  S0090 - Allocate memory on the heap (malloc).
  S0097 - Create and use pointers.
  S0081 - Implement a looping construct.
  S0108 - Utilize post and pre increment/decrement operators.
  S0110 - Implement error handling.
  S0082 - Implement conditional control flow constructs.
  S0160 - Utilize the standard library.*/
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include "TestCode.h"

/*
The Vigenere cipher
--------------------
The Vigenere cipher is a method of encrypting alphabetic text. To encrypt a message, a key is needed that is as long as the message.
Usually, the key is a ***repeating*** keyword.

The encryption is done by adding a letter from the plain text to a letter of the key.
You must convert all uppercase letters to lowercase letters.
Each letter in the alphabet is given an index:
a = 0, b = 1, c = 2, d = 3, e = 4,........, w = 22, x = 23, y = 24, and z = 25

For example, if the keyword is "deceptive", the message “we are discovered save yourself” is encrypted as:

plaintext:    we are discovered save yourself
key:          de cep tivedecept ived eceptive
ciphertext:   zi cvt wqngrzgvtw avzh cqyglmgj

The cipher letter 'z' is the result of 'w' + 'd', which is 22 + 3 = 25

***Note*** that 'y' + 'e' = 'c' because (24 + 4) mod 26 = 2, which is c

In general, the encryption is done as follows:
Plaintext  P = (p0, p1, ...,pn-1)
Key        K = (k0, k1, ...,km-1)   ----> The original key length is m and the key will be repeated to match length af the plaintext
Ciphertext C = (c0, c1, ...,cn-1)

ENCRYPTION FORMULA: ci = [pi + k(i mod m)] mod 26

The function encryptVigenere takes two parameters: the input plain text and the key.
It returns a char pointer to the cipher text.
If the input or the key is NULL/EMPTY, the function returns NULL

*/

/*
  Important information lacking. It should be stated in the question that
  a non-alphabetic character should not increment i in the encryption formula.
  It took a lot of looking around in the debugger to figure that out. This
  question lacks the full information needed to solve this question in a timely
  manner. I don't know if leaving that out was intended or not, but I don't think
  it's a fair assessment when the challenge stems from leaving out vital information.
*/

#define ASCII_OFFSET 97
#define ALPHA 26
enum {FALSE = 0, TRUE};

const char* encryptVigenere(const char* input, const char* key)
{
  // Check for NULL or empty input
  if (input == NULL || key == NULL || input[0] == '\0')
  {
    return NULL;
  }

  int size = strlen(input);
  int key_size = strlen(key);
  char alphabet[ALPHA] = {};
  char *cipherText = (char*)calloc(size, sizeof(char));

  // Populate a list with all lowercase letters from a-z
  for (int i = 0; i < ALPHA; i++)
  {
    alphabet[i] = (char)(ASCII_OFFSET + i);
  }

  // Count non-alpha characters. The key index should not increment when they're found.
  int non_alpha = 0;
  for (int i = 0; i < size; i++)
  {
    // Check if character is a letter
    if (isalpha(input[i]))
    {
      // Convert character to a number between 0-26
      int num_letter = tolower(input[i]) - ASCII_OFFSET;
      // Convert the key to a number between 0-26
      int num_key = ( tolower(key[(i - non_alpha) % key_size]) - ASCII_OFFSET );
      int chiper_index = (num_letter + num_key) % ALPHA ;
      char chipher_letter[2] = {alphabet[chiper_index]};
      strcat(cipherText, chipher_letter);
    }
    // Non-alpha characters are appended as-is. Subtract their count from i or the cipher is thrown off.
    else
    {
      char non_cipher[2] = {input[i]};
      strcat(cipherText, non_cipher);
      non_alpha++;
    }
  }
  return cipherText;
}
