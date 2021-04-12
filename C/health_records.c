/*
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
  S0034 - Declare and implement appropriate data types for program requirements.
  S0035 - Declare and/or implement of arrays and multi-dimensional arrays.
  S0033 - Utilize assignment operators to update a variable.
  S0042 - Open and close an existing file.
  S0043 - Read, parse, write (append, insert, modify) file data.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0048 - Implement a function that receives input parameters.
  S0079 - Validate expected input.
  S0090 - Allocate memory on the heap (malloc).
  S0097 - Create and use pointers.
  S0081 - Implement a looping construct.
  S0108 - Utilize post and pre increment/decrement operators.
  S0082 - Implement conditional control flow constructs.
  S0156 - Utilize a struct composite data type.
  S0160 - Utilize the standard library.*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include"TestCode.h"
/*
In this program, you’ll design two structures for a person called BirthDate and HealthProfile. 

The BirthDate structure will include three integer members for the month, day and year of the birth.

The HealthProfile structure’s members will include: 
   - two character arrays for the person’s firstName and lastName, allowing for 14 characters each;
   - a character for the person's gender;
   - a BirthDate structure for the person's dateOfBirth;
   - three integers representing the person's height (in inches), weight (in pounds) and maxHeartRate; and
   - three doubles representing the person's maxTargetRate, minTargetRate and BMI (Body Mass Index).

The HealthProfile needs to be defined before your program will compile.

Your program should have a function that reads the data (firstName, lastName, gender, dateOfBirth, height, weight) 
of 5 persons from a given file (PersonsData.txt) 
and uses it to set the members of a HealthProfile variable. 

The program also should include functions that calculate: 
   - the user’s age in years
   - maximum heart rate and target-heart-rate range, 
   - and body mass index (BMI). 

The formula for calculating your maximum heart rate in beats per minute is:
    maxHeartRate = 220 - your age in years. 

Your target heart rate is a range that’s 50–85% of your maximum heart rate:
     maxTargetRate = 0.85 * maxHeartRate;  
    minTargetRate = 0.50 * maxHeartRate;  

The formulas for calculating BMI is 
   BMI = (weightInPounds × 703)/ (heightInInches × heightInInches)

 NOTES:
  - Round maxTargetRate to 2 decimal numbers
  - Round minTargetRate to 2 decimal numbers
  - Round BMI to 1 decimal number

The program will include a function: HealthProfile* computeHealthProfiles(int*& agesInYears)
The function will return the health profiles of all persons after the calculations of maximum heart rate,  maxTargetRate, minTargetRate, and BMI
The function also will receive an array of integers to return the ages of all users in years. 
Note that the ages of the persons will depend on the current date, so the array agesInYears will return the current ages of the persons. 

*/


HealthProfile healthDatabase[NUMBER_OF_PERSONS];

void readData()
{
   FILE *the_file = fopen("PersonsData.txt", "r");
   if (the_file == NULL)
   {
      exit(1);
   }
   char line[100];
   // Person counter for healthDatabase
   int person = 0;

   // Read file line by line
   while (fgets(line, sizeof(line), the_file))
   {
      // Create token for split strings
      char *token;
      // Counter for strtok 
      int i = 0;

      /* Create array to store patient info
         [0] First Name
         [1] Last Name
         [2] Gender
         [3] Birthday Year-Month-Day
         [4] Height
         [5] Weight
      */
      char info[6][20];

      HealthProfile new_profile;
      BirthDate new_birthday;
      token = strtok(line, " ;");
      
      // Copy person's data into an array
      while (token != NULL)
      {
         strcpy(info[i], token);
         token = strtok(NULL, " ;");
         i++;
      }

      strcpy(new_profile.firstName, info[0]);
      strcpy(new_profile.lastName, info[1]);
      new_profile.gender = info[2][0];

      // Split the birthday info on the dash
      token = strtok(info[3], "-");
      
      /*
         [0] Year
         [1] Month
         [2] Day
      */
      char year_mon_day[3][5];

      // Reset strtok counter
      i = 0;
      while (token != NULL)
      {
         strcpy(year_mon_day[i], token);
         token = strtok(NULL, "-");
         i++;
      }
      new_birthday.year = atoi(year_mon_day[0]);
      new_birthday.month = atoi(year_mon_day[1]);
      new_birthday.day = atoi(year_mon_day[2]);
      new_profile.dateOfBirth = new_birthday;
      new_profile.height = atoi(info[4]);
      new_profile.weight = atoi(info[5]);

      healthDatabase[person] = new_profile;
      person++;
   }
}

int calculateAgeInYears(HealthProfile hp)
{
   int current_year = 0, current_month = 0, current_day = 0;
   int user_year = hp.dateOfBirth.year,
       user_month = hp.dateOfBirth.month,
       user_day = hp.dateOfBirth.day;
   int age = 0;
   time_t current_time;
   time(&current_time);
   struct tm *time_struct = localtime(&current_time);

   // Year is given in years from 1900, so add 1900 for current year
   current_year = time_struct->tm_year + 1900;

   // Month is indexed at 0, so add 1 for current month
   current_month =  time_struct->tm_mon + 1;
   current_day = time_struct->tm_mday;
   age = current_year - user_year;
   if (current_month <= user_month && current_day < user_day)
   {
      age--;
   }

   return age;
}

double calculateBMI(HealthProfile hp)
{
   double BMI = (hp.weight * 703) / (pow(hp.height, 2));
   return round(BMI * 10)/10;
}

// Get Minimum Target Heart Rate
double calculateMinTarget(HealthProfile hp)
{
   int max_heart = 220 - calculateAgeInYears(hp);
   double min_target = round(max_heart * 0.5 * 100)/100;
   return min_target;
}

// Get Maximum Target Heart Rate
double calculateMaxTarget(HealthProfile hp)
{
   int max_heart = 220 - calculateAgeInYears(hp);
   double max_target = round(max_heart * 0.85 * 100)/100;
   return max_target;
}

HealthProfile* computeHealthProfiles(int** agesInYears)
{
   readData();
   int *ages = (int*)malloc(sizeof(int) * 5);
   for (int i = 0; i < sizeof(healthDatabase)/sizeof(healthDatabase[0]); i++)
   {
      healthDatabase[i].BMI = calculateBMI(healthDatabase[i]);
      healthDatabase[i].maxHeartRate = 220 - calculateAgeInYears(healthDatabase[i]);
      healthDatabase[i].maxTargetRate = calculateMaxTarget(healthDatabase[i]);
      healthDatabase[i].minTargetRate = calculateMinTarget(healthDatabase[i]);
      ages[i] = calculateAgeInYears(healthDatabase[i]);
   }
   *agesInYears = ages;
   return healthDatabase;
}
