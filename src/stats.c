/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Source file containing functions for calculating characteristic values of a sample
 *
 * The sample of values are given by an array of unsigned integer and also the size is known. 
 * The characteristic values to be calculated are median, mean, maximum and minimum.
 * There are also functionsfor printing out the array content and all characteristic values.
 * One function is used for sorting the data from biggest to smallest element.
 *
 * @author Bojan Lazic
 * @date 08.02.2022.
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

/*void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
*/
  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

/*  print_statistics(&test[0], SIZE);

}*/

void print_statistics(unsigned char* arr, unsigned long length)
{
  unsigned char minimum, maximum;
  float mean, median;

  print_array(arr, length);

  minimum = find_minimum(arr, length);
  maximum = find_maximum(arr, length);
  mean = find_mean(arr, length);
  median = find_median(arr, length);

  PRINTF("Minimum value: %u\n", minimum);
  find_minimum(arr, length);

  PRINTF("Maximum value: %u\n", maximum);
  find_maximum(arr, length);

  PRINTF("Mean value: %.2f\n", mean);
  find_maximum(arr, length);

  PRINTF("Median value: %.2f\n", median);
  find_maximum(arr, length);
}

void print_array(unsigned char* arr, unsigned long length)
{
#ifdef VERBOSE
  
  unsigned char i;
  
  for (i = 0; i < length; i++)
  {
    PRINTF("test[%u] = %u \n", i, arr[i]);
  }

  PRINTF("\n");

#endif
}

float find_median(unsigned char* arr, unsigned long length)
{
  sort_array(arr, length);

  float median;

  if(length % 2 == 0)
  {
    median = (arr[length/2] + arr[(length/2) - 1])/2;
  }
  else
  {
    median = arr[(length-1)/2];
  }

  return median;
}

float find_mean(unsigned char* arr, unsigned long length)
{
  sort_array(arr, length);

  int summ, i;

  summ = 0;

  for(i = 0; i < length; i++)
  {
    summ += arr[i];
  }

  return (summ/length);

}

unsigned char find_maximum(unsigned char* arr, unsigned long length)
{
  unsigned char maximum = 0, i;

  for(i = 0; i < length; i++)
  {
    if(arr[i] > maximum) 
    {
      maximum = arr[i];
    }
  }

  return maximum;
}

unsigned char find_minimum(unsigned char* arr, unsigned long length)
{
  unsigned char minimum = 255, i;

  for(i = 0; i < length; i++)
  {
    if(arr[i] < minimum) 
    {
      minimum = arr[i];
    }
  }

  return minimum;
}

void sort_array(unsigned char* arr, unsigned long length)
{
  int temp, i, j;

  for(i = 0; i < length-1; i++)
  {
    for(j = i + 1; j < length; j++)
    {
      if(arr[i]<arr[j])
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

}
