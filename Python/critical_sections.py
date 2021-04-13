"""
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  A0564 - Multi-threading
  S0382 - Create a class constructor or destructor
  S0026 - Utilize standard library modules.
  S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++)."""
"""
** NOTE: THE SOLUTION FOR THIS PROBLEM IS BASED ON A SPECIFICALLY DEFINED ALGORITHM EXPLAINED BELOW. ALTHOUGH THE AUTOMATED TESTS
** MAY BE SUCCESSFUL, YOUR SOLUTION WILL RECEIVE A MANUAL REVIEW FOR FINAL DETERMINATION OF PASS/FAIL

Write a multi-threaded program that demonstrates ***RLock***.

Create two thread classes: AddThread and MultiplyThread.

Class AddThread should increment a global variable by 1,
sleep for a random time (one to 3 seconds) and increment the variable again.

Class MultiplyThread should double the
global variable, sleep for a random time (one to 3 seconds) and double the variable again.

Protect these critical sections with a lock.

After both threads terminate, print the final value of the shared variable.
"""

import threading, time, random

number = 1

class AddThread( threading.Thread ):
    def __init__(self, name, lock):
        threading.Thread.__init__(self)
        self.name = name
        self.lock = lock

    def run(self):
        global number
        self.lock.acquire()
        number += 1
        time.sleep(random.randrange(1,3))
        number += 1
        self.lock.release()

        


class MultiplyThread( threading.Thread ):
    def __init__(self, name, lock):
        threading.Thread.__init__(self)
        self.name = name
        self.lock = lock

    def run(self):
        global number
        self.lock.acquire()
        number *= 2
        time.sleep(random.randrange(1,3))
        number *= 2
        self.lock.release()

if __name__ == "__main__":

    lock = threading.RLock()

    thread1 = AddThread("thread1", lock)
    thread2 = MultiplyThread("thread2", lock)

    thread1.start()
    thread2.start()

    thread1.join()
    thread2.join()

    print("Number is: {}".format(number))

'''
 Test cases pass, but there's no info on if it's really correct. I keep getting the same number as a return when I run the script,
 so locking is working properly as far as I know. I don't know what this question expects as the "right" answer. All I can say is
 the lock and release on the critical section is working properly.
'''
