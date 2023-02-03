#include <stdio.h>
#include <stdlib.h>


/* Function declarations */
int isEven(const int NUM);
int isPrime(const int NUM);


int main()
{
    /* File pointer to hold reference to different files */
    FILE * fPtrIn,
         * fPtrEven, 
         * fPtrOdd, 
         * fPtrPrime;

    
    int num, success;

    /* 
     * Open all files to perform read/write.
     */
    fPtrIn   = fopen("C:/Atharav Documents/Sem 4/Software Lab 2/Data/Numbers.txt", "r");
    fPtrEven = fopen("C:/Atharav Documents/Sem 4/Software Lab 2/Data/even.txt" , "w");
    fPtrOdd  = fopen("C:/Atharav Documents/Sem 4/Software Lab 2/Data/odd.txt"  , "w");
    fPtrPrime= fopen("C:/Atharav Documents/Sem 4/Software Lab 2/Data/prime.txt", "w");


    /* fopen() return NULL if unable to open file in given mode. */
    if(fPtrIn == NULL || fPtrEven == NULL || fPtrOdd == NULL || fPtrPrime == NULL)
    {
        /* Unable to open file hence exit */
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_FAILURE);
    }


    /* File open success message */
    printf("File opened successfully. Reading integers from file. \n\n");

    // Read an integer and store read status in success.
    while (fscanf(fPtrIn, "%d", &num) != -1)
    {
        /*
         * Write prime, even and odd numbers to different files.
         */
        if (isPrime(num))
            fprintf(fPtrPrime, "%d\n", num);
        else if (isEven(num))
            fprintf(fPtrEven, "%d\n", num);
        else
            fprintf(fPtrOdd, "%d\n", num);

    }


    /* Done with all files, hence close all. */
    fclose(fPtrIn);
    fclose(fPtrEven);
    fclose(fPtrOdd);
    fclose(fPtrPrime);

    printf("Data written to files successfully.");


    return 0;
}

int isEven(const int NUM)
{
    return !(NUM & 1);
}


/* 
 * Returns 1 if the number is prime otherwise 0. 
 */
int isPrime(const int NUM)
{
    int i;  
    if (NUM < 0)
        return 0;
      
    for ( i=2; i<=NUM/2; i++ )    
    {       
        if (NUM % i == 0)    
        {  
            return 0;  
        }    
    }   
      
    return 1;  
}