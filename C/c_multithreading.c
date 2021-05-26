/*
A prime number is any positive integer that has two factors, 1, and the number itself. e.g.: 2, 3, 5, 7, 11,...

Create a function, FindPrimes, that takes the name of a file and a pointer to an array that you will output prime numbers to, and the size of that array
    Using multithreading, create 10 threads that will share the work of calculating which numbers in the file specified are prime.
    Properly protect resources shared by threads
    After all prime numbers are found, return the prime numbers via the primes parameter passed to FindPrimes

You may modify the header file if needed.
*/
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "TestCode.h"
#include <stdlib.h>

#define MAX_THREADS 10
#define PRIME_CAPACITY 10000

enum{FALSE = 0, TRUE};

// Struct to hold arguments to threads
typedef struct thread_args
{
    //int index;
    int numbers[PRIME_CAPACITY/MAX_THREADS];
} thread_args, *thread_args_ptr;

// Function to determine if number is prime
void *isPrime(void* thread_args)
{
    thread_args_ptr args = thread_args; 

    // Loop from 0 to 999 to check 1000 numbers per thread
    for (int i = 0; i < (PRIME_CAPACITY/MAX_THREADS); i++)
    {
        int number = args->numbers[i];
        // 1 is special case. Not prime
        if (number <= 1)
        {
            // Non-prime numbers are set to FALSE (0)
            args->numbers[i] = FALSE;
            continue;
        }
        for (int ii = 2; ii <= (number/2); ii++)
        {
            if (number % ii == 0)
            {
                // Non-prime numbers are set to FALSE (0)
                args->numbers[i] = FALSE;
                break;
            }
        }
    }
}

int FindPrimes(const char *fname, int* primes, int numSize)
{
    FILE *fp = fopen(fname, "r");
    if (fp == NULL)
    {
        exit(1);
    }

    // To be used to go through the indexes of the list of numbers
    static int index = 0;

    pthread_t threads[MAX_THREADS];  
    int all_numbers[PRIME_CAPACITY] = {};
    char line[20] = {};

    // Get all numbers from the file and store it in array
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        all_numbers[index] = atoi(line);
        index++;
    }
    fclose(fp);
    // Array to 10 sets of arguments to pass to threads
    thread_args_ptr args_array[MAX_THREADS] = {};

    // All 10,000 numbers are divided into chunks of 1,000. Each thread will process 1,000 numbers. 
    // 1,000 numbers * 10 threads = 10,000
    for (int i = 0; i < MAX_THREADS; i++)
    {
        args_array[i] = (thread_args_ptr)malloc(sizeof(thread_args));
        int start = i * (PRIME_CAPACITY/MAX_THREADS);
        int end = start + ( (PRIME_CAPACITY/MAX_THREADS) - 1 );
        index = 0;
        // Give each set of arguments 1,000 numbers to check if prime
        for (int j = start; j <= end; j++)
        {
            args_array[i]->numbers[index] = all_numbers[j];
            index++;
        }
        if (pthread_create(threads + i, NULL, isPrime, args_array[i]) != 0)
        {
            perror("Failed to create thread.\n");
            exit(1);
        }
    }
    
    /* Join 10 threads
    Create and join threads in different loops or threads will execute sequentially. */
    for (int i = 0; i < MAX_THREADS; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("Failed to join thread.\n");
            exit(1);
        }
    }

    index = 0;
    for (int args_index = 0; args_index < MAX_THREADS; args_index++)
    {
        for (int j = 0; j < (PRIME_CAPACITY/MAX_THREADS); j++)
        {
            int number = args_array[args_index]->numbers[j];
            if (number != FALSE)
            {
                primes[index] = number;
                index++;
            }
        }
        free(args_array[args_index]);
    }
    return primes;
}
