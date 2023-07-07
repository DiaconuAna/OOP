#pragma once
#include "ProductRepository.h"
#include "Product.h"
#include "UndoService.h"

/**
 * Adds a product to the product  list
 * If the product  already exists, its quantity is updated
 * @param arr
 * @param name
 * @param category
 * @param quantity
 * @param expiration_date
 */
void addProduct(UndoRedo* arr1, DynamicArray* arr, char name[], char category[], int quantity, Date expiration_date, int id);

/**
 * Delete a product if it exists in the list
 * Throw an exception otherwise
 * @param arr
 * @param name
 * @param category
 */
void deleteProduct(UndoRedo* arr1, DynamicArray* arr, char name[], char category[], int id);

/**
 * Update the quantity of an already  existing product
 * Throw an exception if product is  not in the list
 * @param arr
 * @param name
 * @param category
 * @param value
 */
void updateProduct1(UndoRedo* arr1, DynamicArray* arr, char name[], char category[], char update_data[], int value, int id);
void updateProduct2(UndoRedo* arr1, DynamicArray* arr, char name[], char category[], int update, int id);
void updateProduct3(UndoRedo* arr1, DynamicArray* arr, char name[], char category[], Date new_date, int id);

/**
 * Search for product p in the list
 * @param arr
 * @param name
 * @param category
 * @return its position if  the element exists,  else -1
 */
int searchProduct(DynamicArray* arr, char name[],char category[]);

/**
 * Prepare the list for display
 * @param arr
 * @param str
 */
void getProductList(DynamicArray *arr, char str[][100]);

/**
 * Adds 10 entries to the dynamic array
 * @param arr
 */
void createEntries(DynamicArray* arr);

/**
 * Display all products whose name contains a given string
 * (if the string is empty, all products from the refrigerator are considered)
 * @param arr
 * @param str
 * @return A Dynamic Array containing the said elements
 */
DynamicArray* filterString(DynamicArray* arr, char str[]);

/**
 * Sort a list of products in ascending order by Quantity
 * @param arr
 */
void sortAscendingByQuantity(DynamicArray* arr);

/**
 * Sort a list of products in descending order by quantity
 * @param arr
 */
void sortDescendingByQuantity(DynamicArray* arr);

/**
 * Filter all products by the year in which they expire
 * @param arr
 * @param year
 * @return
 */
DynamicArray* filterByYear(DynamicArray* arr, int year);

/**
 * Sort a list of products in descending order by their year of expiration
 * @param arr
 */
void sortDescendingByDate(DynamicArray* arr);

/**
 * Sort a list of products in descending order by name
 * @param arr
 */
void sortDescendingByName(DynamicArray* arr);
void destroyDynamicArray(DynamicArray* arr);

/**
 * Computes the number of days between two days
 * and returns it
 * @param d1
 * @param d2
 * @return
 */
int numberOfDaysBetweenDates(Date d1, Date d2);

/**
 * Get the current day, month and year
 * @return
 */
Date getCurrentDate();

/**
 * Computes the number of days left before an expiration date
 * @param x
 * @param number_of_days
 * @return
 */
int ExpirationTime(int x,int number_of_days);

/**
 * Filter a list of products by their category
 * @param arr
 * @param str
 * @return
 */
DynamicArray* filterbyCategory(DynamicArray *arr, char str[]);

/**
 * Get all products of a given category (if the category is empty, all types of food will be considered)
 * whose expiration dates are close (expire in the following X days, where the value of X is user-provided).
 * @param arr
 * @param x
 * @return
 */
DynamicArray* getProductsExp(DynamicArray *arr, int x);