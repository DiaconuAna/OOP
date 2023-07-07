//
// Created by amina on 3/4/2021.
//

#include "ProductRepository.h"
#include "Product.h"
#include <stdlib.h>
#include <string.h>

DynamicArray* createDA(int cap)
{
    DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (da == NULL)
        return NULL;

    da->cap = cap;
    da->nrElems = 0;

    da -> elements = (Telem*)malloc(cap * sizeof(Telem));
    if (da->elements == NULL)
        return NULL;

    return da;
}

void add(DynamicArray* arr, Telem product)
{
    if (arr == NULL)
        return;
    if (arr->elements == NULL)
        return;

    // resize the array, if necessary
    if (arr->nrElems == arr->cap)
        resize(arr);
    arr->elements[arr->nrElems] = product;
    arr->nrElems++;
}


void delete(DynamicArray*  arr, int position)
{
    arr->elements[position] = arr->elements[arr->nrElems - 1];
    arr -> nrElems -= 1;
}


void update(DynamicArray* arr, int position, int value)
{
    setQuantity(&arr->elements[position], value);
}

void reupdate(DynamicArray* arr, int position, int value)
{
    updateQuantity(&arr->elements[position], value);
}

void destroy(DynamicArray* arr)
{
    if (arr == NULL)
        return;

    free(arr->elements);
    arr->elements = NULL;

    free(arr);
}


void resize(DynamicArray* arr)
{

    arr->cap *=2;
    arr->elements = (Telem*)realloc(arr->elements, sizeof(Telem)*arr->cap);

}


void print_element(DynamicArray* arr, int position, char str[])
{

    toString(arr->elements[position], str);
}

void update_name(DynamicArray* arr, int position, char name[])
{
    //strcpy(arr->elements[position].name, name);
    setName(&arr->elements[position], name);
}

void update_category(DynamicArray* arr, int position, char category[])
{
   // strcpy(arr->elements[position].category, category);
   setCategory(&arr->elements[position], category);
}

void update_quantity(DynamicArray* arr,int position,int value)
{
    setQuantity(&arr->elements[position], value);
}

void update_date(DynamicArray* arr, int position, Date new_date)
{
//    arr->elements[position].expiration_date.day = new_date.day;
//    arr->elements[position].expiration_date.month = new_date.month;
//    arr->elements[position].expiration_date.year = new_date.year;
      setDate(&arr->elements[position], new_date);

}