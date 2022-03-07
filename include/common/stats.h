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
 * @file stats.h
 * @brief Contains functions for calculating characteristic values of a sample
 *
 * The sample of values are given by an array of unsigned integer and also the size is known. 
 * The characteristic values to be calculated are median, mean, maximum and minimum.
 * There are also functionsfor printing out the array content and all characteristic values.
 * One function is used for sorting the data from biggest to smallest element.
 *
 * @author Bojan Lazic
 * @date 08.02.2022
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median
 *
 * The function takes the (pointer to)array and array length and makes multiple function calls to functions sort_array, print_array, find_median, find_mean, find_maximum, find_minimum.
 * In the end it prints out data and characteristic values of the data.
 *
 * @param *arr pointer to the first element of array, which contains statistic data
 * @param length size of the array containing statistic data
 */
void print_statistics(unsigned char* arr, unsigned long length);



/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * @param *arr pointer to the first element of array, which contains statistic data
 * @param length size of the array containing statistic data
 */
void print_array(unsigned char* arr, unsigned long length);



/**
 * @brief Given an array of data and a length, returns the median value
 *
 * The function takes the (pointer to)array and array length, goes through all the elements of the array to calculate the median then returns that value back from the function.
 *
 * @param *arr pointer to the first element of array, which contains statistic data
 * @param length size of the array containing statistic data
 *
 * @return Median for the sample data
 */
float find_median(unsigned char* arr, unsigned long length);


/**
 * @brief Given an array of data and a length, returns the mean.
 *
 * The function takes the (pointer to)array and array length, goes through all the elements of the array to calculate the mean then returns that value back from the function.
 *
 * @param *arr pointer to the first element of array, which contains statistic data
 * @param length size of the array containing statistic data
 *
 * @return Mean for the sample data
 */
float find_mean(unsigned char* arr, unsigned long length);



/**
 * @brief Given an array of data and a length, returns the maximum
 *
 * The function takes the (pointer to)array and array length, goes through all the elements of the array to find the maximum value then returns that value back from the function.
 *
 * @param *arr pointer to the first element of array, which contains statistic data
 * @param length size of the array containing statistic data
 *
 * @return Maximum for the sample data
 */
unsigned char find_maximum(unsigned char* arr, unsigned long length);



/**
 * @brief Given an array of data and a length, returns the minimum
 *
 * The function takes the (pointer to)array and array length, goes through all the elements of the array to find the minimum value then returns that value back from the function.
 *
 * @param *arr pointer to the first element of array, which contains statistic data
 * @param length size of the array containing statistic data
 *
 * @return Minimum for the sample data
 */
unsigned char find_minimum(unsigned char* arr, unsigned long length);



/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest.  
 *
 * The function takes the (pointer to)array and array length and sorts the array from biggest to smallest. After calling this function the zeroth 
 * element should be the largest value, and the last element (n-1) should be the smallest value.
 *
 * @param *arr pointer to the first element of array, which contains statistic data
 * @param length size of the array containing statistic data
 */
void sort_array(unsigned char* arr, unsigned long length);


#endif /* __STATS_H__ */
