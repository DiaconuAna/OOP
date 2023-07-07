#pragma once
#include "Product.h"

typedef Product Telem;

typedef struct {
    Telem* elements;
    int nrElems;
    int cap;
} DynamicArray;

DynamicArray* createDA(int cap);

/**
 * Add an element(which is a product, in our case)
 * to the dynamic array
 * @param arr: the  dynamic array
 * @param product: the product we are adding to the array if it hasn't been added before
 */
void add(DynamicArray* arr, Telem product);

/**
 * Delete the element from a given position
 * @param arr
 * @param position
 */
void delete(DynamicArray*  arr, int position);

void update(DynamicArray* arr, int position, int value);
/**
 * Destroy the dynamic array
 * @param arr
 */
void destroy(DynamicArray* arr);

/**
 * Resize the Dynamic Array by doubling its
 * current size
 * @param arr
 */
void resize(DynamicArray* arr);

/**
 * Print an element from a given position
 * @param arr
 */
void print_element(DynamicArray* arr,int position, char str[]);

/**
 *
 * @param arr
 * @param position
 * @param value
 */
void reupdate(DynamicArray* arr, int position, int value);

/**
 * Update the name of a product
 * @param arr
 * @param position
 * @param name :new name
 */
void update_name(DynamicArray* arr, int position, char name[]);

/**
 * Update the category of a product
 * @param arr
 * @param position
 * @param category
 */
void update_category(DynamicArray* arr, int position, char category[]);
void update_quantity(DynamicArray* arr,int position,int value);
void update_date(DynamicArray* arr, int position, Date new_date);