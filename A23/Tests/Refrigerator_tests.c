//
// Created by amina on 3/13/2021.
//

#include "Refrigerator_tests.h"
#include "ProductRepository.h"
#include "RefrigeratorController.h"
#include "UndoService.h"
#include "Product.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void testDomain()
{
    //try to create a date containing an invalid month
    Date d1, d2;
    char product_name[100], product_category[100];
    int product_quantity;

    d1 = createDate(1,13,2021);
    assert(d1.month == 0);

    //try to create a date containing an invalid day
    d1 = createDate(31,2,2021);
    assert(d1.day == 0);
    d1 = createDate(29,2,2021);
    assert(d1.day == 0);

    //create a product, then get/set its attributes using the corresponding functions
    Product p;
    d1 = createDate(10,3,2022);
    p = createProduct("Milka","sweets",5,d1);
    strcpy(product_name, getName(&p));
    assert(strcmp(product_name, "Milka") == 0);

    strcpy(product_category, getCategory(&p));
    assert(strcmp(product_category, "sweets") == 0);

    product_quantity = getQuantity(&p);
    assert(product_quantity  == 5);

    d1 = getExpirationDate(&p);
    assert(d1.day == 10);
    assert(d1.month == 3);
    assert(d1.year == 2022);

    //modify  the name, category,  quantity and date

    setName(&p, "Choco");
    strcpy(product_name, getName(&p));
    assert(strcmp(product_name, "Choco") == 0);

    setCategory(&p, "dairy");
    strcpy(product_category, getCategory(&p));
    assert(strcmp(product_category, "dairy") == 0);

    setQuantity(&p, 13);
    product_quantity = getQuantity(&p);
    assert(product_quantity  == 13);

    d2 = createDate(13,7,2021);
    setDate(&p, d2);
    d1 = getExpirationDate(&p);
    assert(d1.day == 13);
    assert(d1.month == 7);
    assert(d1.year == 2021);

    //update the quantity of a product
    updateQuantity(&p, 13);
    product_quantity = getQuantity(&p);
    assert(product_quantity  == 26);

    printf("\nDomain tests ran successfully");
}

void testRepository()
{
    //create a dynamic array and perform operations on it
    DynamicArray* arr;
    Product product;
    Date date1;

    arr  = createDA(2);
    assert(arr->cap == 2);
    assert(arr->nrElems == 0);

    //add elements to the array and check if it has been resized properly
    date1 = createDate(3,12,2022);
    product = createProduct("Milka","sweets",4, date1);
    add(arr, product);

    assert(arr->nrElems == 1);
    assert(strcmp(getName(&arr->elements[0]), "Milka") == 0);

    date1 = createDate(5,6,2021);
    product = createProduct("Salad","fruit",10, date1);
    add(arr, product);

    assert(arr->cap == 2);
    assert(arr->nrElems == 2);

    date1 = createDate(10,9,2023);
    product = createProduct("Biscuits","sweets",2, date1);
    add(arr, product);

    assert(arr->cap == 4);
    assert(arr->nrElems == 3);

    //delete an element from the array
    delete(arr, 2);
    assert(arr->nrElems == 2);

    //update the attributes of a product
    update_name(arr, 0, "choco");
    assert(strcmp(getName(&arr->elements[0]), "choco") == 0);
    update_category(arr, 0, "dairy");
    assert(strcmp(getCategory(&arr->elements[0]), "dairy") == 0);
    update_quantity(arr, 0, 24);
    assert(getQuantity(&arr->elements[0]) == 24);
    update_date(arr,0, createDate(2,4,2021));
    assert(getExpirationDate(&arr->elements[0]).day == 2);
    assert(getExpirationDate(&arr->elements[0]).month == 4);
    assert(getExpirationDate(&arr->elements[0]).year == 2021);

    //destroy the dynamic array in order not to leak memory
    destroy(arr);

    printf("\nRepository tests ran successfully");
}

void testController()
{
    DynamicArray* arr;
    DynamicArray* filter;
    DynamicArray* aux;
    UndoRedo* undoredo;
    Product product;
    Date date1, date2;

    arr  = createDA(2);
    filter = createDA(2);
    aux = createDA(2);
    undoredo = createUndoRedoArray(2);

    //add a new product to the array
    addProduct(undoredo, arr, "Milka", "sweets", 4, createDate(2,4,2021), 1);
    assert(arr->nrElems == 1);
    assert(strcmp(getName(&arr->elements[arr->nrElems - 1]), "Milka") == 0);

    //try to add the same product to the array so that its quantity its updated
    addProduct(undoredo, arr, "Milka", "sweets", 4, createDate(2,4,2021), 1);
    assert(arr->nrElems == 1);
    assert(getQuantity(&arr->elements[arr->nrElems - 1]) == 8);

    addProduct(undoredo, arr, "OatMilk", "dairy", 6, createDate(4,5,2021), 1);
    addProduct(undoredo, arr, "Avocado", "fruit", 3, createDate(10,8,2021), 1);

    assert(arr->nrElems == 3);

    //delete an element
    deleteProduct(undoredo, arr, "OatMilk", "dairy", 1);
    assert(arr->nrElems == 2);

    //update a product's name, category, quantity and date and also find its position in the list
    int product_position = searchProduct(arr, "Avocado", "fruit");
    assert(product_position == 1);

    updateProduct1(undoredo, arr, "Avocado", "fruit", "Mango", 1, 1);
    assert(strcmp(getName(&arr->elements[product_position]), "Mango") == 0);

    updateProduct1(undoredo, arr, "Mango", "fruit", "sweets", 2, 1);
    assert(strcmp(getCategory(&arr->elements[product_position]), "sweets") == 0);

    updateProduct2(undoredo, arr, "Mango", "sweets",5, 1);
    assert(getQuantity(&arr->elements[product_position]) == 5);

    updateProduct3(undoredo, arr, "Mango", "sweets", createDate(1,1,2022), 1);
    assert(getExpirationDate(&arr->elements[product_position]).day == 1);
    assert(getExpirationDate(&arr->elements[product_position]).month == 1);
    assert(getExpirationDate(&arr->elements[product_position]).year == 2022);

    //try searching for a product that is not in the list
    product_position = searchProduct(arr, "SweetPotato", "sweets");
    assert(product_position == -1);

    //filter the elements in the array by a given string
    filter = filterString(arr, "an");
    assert(filter->nrElems == 1);
    assert(strcmp(getName(&filter->elements[0]),"Mango") == 0);

    //the given string is an empty array (in our case "-")
    filter = filterString(arr, "-");
    assert(filter->nrElems == 2);
    assert(strcmp(getName(&filter->elements[0]),"Milka") == 0);
    assert(strcmp(getName(&filter->elements[1]),"Mango") == 0);

    //sort the array in ascending, then descending order by quantity
    // Milka has quantity 8, Mango has quantity 5
    sortDescendingByQuantity(filter);
    assert(strcmp(getName(&filter->elements[0]),"Milka") == 0);
    assert(strcmp(getName(&filter->elements[1]),"Mango") == 0);

    sortAscendingByQuantity(filter);
    assert(strcmp(getName(&filter->elements[1]),"Milka") == 0);
    assert(strcmp(getName(&filter->elements[0]),"Mango") == 0);

    //filter by year
    filter = filterByYear(arr, 2021);
    assert(filter->nrElems == 1);
    assert(strcmp(getName(&filter->elements[0]),"Milka") == 0);

    //compute the number of days between 2 dates
    date1 = createDate(12,3,2002);
    date2 = createDate(13,7,2002);

    assert(numberOfDaysBetweenDates(date1, date2) == 123);

    //filter products by category
    addProduct(undoredo, arr, "Tomato", "fruits", 7, createDate(20,3,2021), 1);
    filter = filterbyCategory(arr,"sweets");
    assert(filter->nrElems == 2);
    assert(strcmp(getName(&filter->elements[0]),"Milka") == 0);
    assert(strcmp(getName(&filter->elements[1]),"Mango") == 0);

    filter = filterbyCategory(arr, "fruits");
    assert(filter->nrElems == 1);
    assert(strcmp(getName(&filter->elements[0]),"Tomato") == 0);

    filter = filterbyCategory(arr,"-");
    assert(filter->nrElems == 3);
    assert(strcmp(getName(&filter->elements[0]),"Milka") == 0);
    assert(strcmp(getName(&filter->elements[1]),"Mango") == 0);
    assert(strcmp(getName(&filter->elements[2]),"Tomato") == 0);

    //array of products from aby category who expire in less than 20 days
    filter = filterbyCategory(arr,"-");
    aux = getProductsExp(filter, 21);

    assert(aux->nrElems == 2);
    assert(strcmp(getName(&aux->elements[0]),"Milka") == 0);
    assert(strcmp(getName(&aux->elements[1]),"Tomato") == 0);

    //destroy the dynamic arrays in order not to leak memory
    destroyDynamicArray(arr);
    destroyDynamicArray(filter);
    destroyDynamicArray(aux);
    destroyUndoRedo(undoredo);
    printf("\nController tests ran successfully");
}

void testUndo()
{
    DynamicArray* arr;
    UndoRedo* undoredo;
    Product product;
    Date date1, date2;

    arr  = createDA(2);
    undoredo = createUndoRedoArray(2);

    //there are no undos
    assert(undoredo->currentIndex == -1);

    //there are no redos
    assert(undoredo->currentCapacity - 1 == undoredo -> currentIndex);

    //perform three operations that modify the initial array so that
    //undoredo array would have to be resized

    addProduct(undoredo, arr, "Milka","sweets",4,createDate(2,4,2021),1);
    addProduct(undoredo, arr, "Avocado", "fruits", 7, createDate(31,3,2021), 1);
    addProduct(undoredo, arr, "CoconutMilk","dairy",3,createDate(5,5,2021), 1);

    assert(undoredo->currentCapacity == 3);

    deleteProduct(undoredo, arr, "Avocado", "fruits", 1);
    updateProduct1(undoredo, arr, "Milka", "sweets", "dairy", 2,1);
    assert(strcmp(getCategory(&arr->elements[0]), "dairy") == 0);

    //undo - update of category
    undo(undoredo,arr);
    assert(strcmp(getCategory(&arr->elements[0]), "sweets") == 0);

    //undo - delete of Avocado
    undo(undoredo, arr);
    assert(arr->nrElems == 3);
    assert(strcmp(getName(&arr->elements[2]),"Avocado") == 0);

    //undo - add of CoconutMilk
    undo(undoredo, arr);
    assert(arr->nrElems == 2);
    assert(strcmp(getName(&arr->elements[0]),"Milka") == 0);
    assert(strcmp(getName(&arr->elements[1]),"Avocado") == 0);

    //redo - add of CoconutMilk
    redo(undoredo, arr);
    assert(arr->nrElems == 3);
    assert(strcmp(getName(&arr->elements[2]),"CoconutMilk") == 0);

    //redo - delete of Avocado
    redo(undoredo, arr);
    assert(arr->nrElems == 2);
    assert(strcmp(getName(&arr->elements[0]),"Milka") == 0);
    assert(strcmp(getName(&arr->elements[1]),"CoconutMilk") == 0);

    //redo - update of Milka
    redo(undoredo, arr);
    assert(strcmp(getCategory(&arr->elements[0]), "dairy") == 0);

    //update name- undo and redo
    updateProduct1(undoredo, arr, "CoconutMilk", "dairy", "Mango",1,1);
    assert(strcmp(getName(&arr->elements[1]),"Mango") == 0);
    undo(undoredo, arr);
    assert(strcmp(getName(&arr->elements[1]),"CoconutMilk") == 0);
    redo(undoredo, arr);
    assert(strcmp(getName(&arr->elements[1]),"Mango") == 0);

    //update quantity -undo and redo
    updateProduct2(undoredo, arr, "Milka", "dairy", 10, 1);
    assert(getQuantity(&arr->elements[0]) == 10);
    undo(undoredo, arr);
    assert(getQuantity(&arr->elements[0]) == 4);
    redo(undoredo, arr);
    assert(getQuantity(&arr->elements[0]) == 10);

    //update date- undo and redo
    updateProduct3(undoredo, arr, "Milka", "dairy", createDate(13,7,2022), 1);
    date1 = createDate(13,7,2022);
    date2 = getExpirationDate(&arr->elements[0]);
    assert(getExpirationDate(&arr->elements[0]).day == date1.day);
    assert(getExpirationDate(&arr->elements[0]).month == date1.month);
    assert(getExpirationDate(&arr->elements[0]).year == date1.year);
    undo(undoredo, arr);
    date1 = createDate(2,4,2021);
    assert(getExpirationDate(&arr->elements[0]).day == date1.day);
    assert(getExpirationDate(&arr->elements[0]).month == date1.month);
    assert(getExpirationDate(&arr->elements[0]).year == date1.year);
    redo(undoredo, arr);
    date1 = createDate(13,7,2022);
    assert(getExpirationDate(&arr->elements[0]).day == date1.day);
    assert(getExpirationDate(&arr->elements[0]).month == date1.month);
    assert(getExpirationDate(&arr->elements[0]).year == date1.year);

    //destroy the dynamic arrays in order not to leak memory
    destroyUndoRedo(undoredo);
    destroyDynamicArray(arr);
    printf("\nUndo/Redo tests ran successfully\n");
}

void testAll()
{
    testDomain();
    testRepository();
    testController();
    testUndo();
}