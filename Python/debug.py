'''
A school coverts each test score grade to a GPA using the scale below.  When the term is over
they compute the average of all GPAs to determine an overall GPA and grade for the course.

Grade   Score   GPA  
A       93-100  4
A-      90-92   3.7
B+      87-89   3.3
B       83-86   3
B-      80-82   2.7
C+      77-79   2.3
C       73-76   2
C-      70-72   1.7
D+      67-69   1.3
D       65-66   1
F       < 65    0

The computeGPA function receives a list of test scores and should:
    1. Compute a GPA for each test
    2. Throw out the two lowest GPAs
    3  Find the overall average GPA for all the GPAs.  
    4. Then, based on the overall GPA average, compute a final grade.
    5. Return the average GPA rounded to two decimal positions along with the final grade.
    6. If any score in the list is less than 0 or greater than 100, the function returns "INVALID SCORE"

However there are several syntax and logical errors in the code below that neeed to be identified and
corrected before this function executes properly.

'''

'''
The 'runtests.py' file had indentation errors. Not sure if that
was a part of the question, but it's not worded as if it is. If there
aren't supposed to be errors in the tests file, then someone needs to 
fix it in the repo.
'''
def computeGPA(scoreList):
    GPAs = []
    avg = 0
    # scorelist case sensitive. Corrected to scoreList
    for score in scoreList:
        # Indentation was off on if-else statements
        # Needs to use 'or' instead of 'and' to check invalid scores       
        if score < 0 or score > 100:
            # Test case checks for "INVALID_SCORE", not "INVALID SCORE"
            return "INVALID_SCORE"
        # Scores >= 93 are a 4
        if score >= 93:                
            GPAs.append(4)
        elif score >= 90:
            GPAs.append(3.7)
        elif score >= 87:
            GPAs.append(3.3)
        elif score >= 83:
            GPAs.append(3)
        elif score >= 80:
            GPAs.append(2.7)
        elif score >= 77:
            # Should be 2.3, not 2
            GPAs.append(2.3)        
        elif score >= 73:
            # Should be 2, not 2.3
            GPAs.append(2)      
        elif score >= 70:
            GPAs.append(1.7)
        elif score >= 67:
            GPAs.append(1.3)
        elif score >= 65:
            GPAs.append(1)
        else:                    
            GPAs.append(0)
        
    GPAs.sort()
    # Pop needs to remove from index 0 to drop lowest GPAs
    # By default, pop removes index -1, which would be the 
    # highest GPAs, not lowest.
    GPAs.pop(0)                  
    GPAs.pop(0)

    # Average was calulated incorrectly.
    # Use sum() on GPAs and round final value to 2 decimal places.
    avg = round(sum(GPAs)/len(GPAs), 2)       
    
    finalGrade = ' '
    
    if avg == 4:              
        finalGrade = 'A'
    elif avg >= 3.7:             
        finalGrade = 'A-'
    elif avg >= 3.3:
        finalGrade = 'B+'
    elif avg >= 3:
        finalGrade = 'B'
    elif avg >= 2.7:
        finalGrade = 'B-'
    elif avg >= 2.3:
        finalGrade = 'C+'
    elif avg >=2.0:
        finalGrade = 'C'
    elif avg >= 1.7:
        finalGrade = 'C-'
    elif avg >= 1.3:
        finalGrade = 'D+'
    elif avg >= 1.0:
        finalGrade = 'D'
    else:
        finalGrade = 'F'
    
    return float(avg), finalGrade   


