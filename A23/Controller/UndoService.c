//
// Created by amina on 3/12/2021.
//

#include "UndoService.h"
#include "Product.h"
#include "ProductRepository.h"
#include "RefrigeratorController.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

UndoRedo* createUndoRedoArray(int capacity)
{

     UndoRedo* arr = (UndoRedo*)malloc(sizeof(UndoRedo));
     if (arr == NULL)
         return NULL;

     arr->capacity = capacity;
     arr->currentCapacity = 0;
     arr->currentIndex = -1;

    arr->elements = (UndoRedoElement*)malloc(capacity*sizeof(UndoRedoElement));
    if (arr->elements == NULL)
        return NULL;

    return arr;
}

UndoRedoElement createOperation(int UndoRedoId, Product prod, Product prev_prod)
{
    UndoRedoElement elem;
    elem.undo_redo_id = UndoRedoId;
    elem.current_product = prod;
    elem.prev_product = prev_prod;

    return elem;
}

void addOperation(UndoRedo* arr,int UndoRedoId, Product prod, Product prev_prod)
{
//    self._history = self._history[0:self._index + 1]
//    self._history.append(operation)
//    self._index = len(self._history) - 1

    UndoRedoElement arr_elem;

    arr->currentIndex ++;
    if (arr->currentIndex + 1 == arr->capacity)
        resizeUndoRedo(arr);

    arr_elem = createOperation(UndoRedoId, prod, prev_prod);

    //When recording a new operation, discard all previous undos

    arr->currentCapacity = arr->currentIndex + 1;
    arr->elements[arr->currentIndex] = arr_elem;

}

void resizeUndoRedo(UndoRedo* arr)
{
    arr -> capacity *=2;
    arr -> elements = (UndoRedoElement*)realloc(arr->elements, sizeof(UndoRedoElement)*arr->capacity);
}

void undo(UndoRedo* arr, DynamicArray* da)
{
    char name[100], category[100], update_data[100];
    int update_quantity, quantity;
    Date update_date, date;

   // printf("\n%d %d\n", arr->currentIndex, arr->currentCapacity);

 if (arr->currentIndex == -1) {
     perror("\n No more undos! \n");
     return;
 }

 switch (arr->elements[arr->currentIndex].undo_redo_id){
     case 1: deleteProduct(arr, da, arr->elements[arr->currentIndex].current_product.name, arr->elements[arr->currentIndex].current_product.category,2);
             break;
     case 2: strcpy(name, getName(&arr->elements[arr->currentIndex].current_product));
             strcpy(category, getCategory(&arr->elements[arr->currentIndex].current_product));
             quantity = getQuantity(&arr->elements[arr->currentIndex].current_product);
             date = getExpirationDate(&arr->elements[arr->currentIndex].current_product);
             addProduct(arr, da, name, category, quantity, date, 2);
             break;
     case 3: strcpy(name, getName(&arr->elements[arr->currentIndex].current_product));
             strcpy(category, getCategory(&arr->elements[arr->currentIndex].current_product));
             strcpy(update_data, getName(&arr->elements[arr->currentIndex].prev_product));
             updateProduct1(arr, da ,name, category, update_data, 1, 2);
             break;
     case 4: strcpy(name, getName(&arr->elements[arr->currentIndex].current_product));
             strcpy(category, getCategory(&arr->elements[arr->currentIndex].current_product));
             strcpy(update_data, getCategory(&arr->elements[arr->currentIndex].prev_product));
             updateProduct1(arr, da, name, category, update_data, 2, 2);
             break;
     case 5: strcpy(name, getName(&arr->elements[arr->currentIndex].current_product));
             strcpy(category, getCategory(&arr->elements[arr->currentIndex].current_product));
             update_quantity = getQuantity(&arr->elements[arr->currentIndex].prev_product);
             updateProduct2(arr, da, name, category,  update_quantity, 2);
             break;
     case 6: strcpy(name, getName(&arr->elements[arr->currentIndex].current_product));
             strcpy(category, getCategory(&arr->elements[arr->currentIndex].current_product));
             update_date = getExpirationDate(&arr->elements[arr->currentIndex].prev_product);
             updateProduct3(arr, da, name, category,  update_date, 2);
             break;
 }
 arr->currentIndex -=1;

}

void redo(UndoRedo* arr, DynamicArray* da)
{
    char name[100], category[100], update_data[100];
    int update_quantity, quantity;
    Date update_date, date;

    //printf("\n%d %d\n", arr->currentIndex, arr->currentCapacity);

    if (arr->currentCapacity - 1 == arr->currentIndex ) {
        perror("\n No more redos! \n");
        return;
    }


    arr->currentIndex +=1;

    switch (arr->elements[arr->currentIndex].undo_redo_id){
        case 1:
            strcpy(name, getName(&arr->elements[arr->currentIndex].current_product));
            strcpy(category, getCategory(&arr->elements[arr->currentIndex].current_product));
            quantity = getQuantity(&arr->elements[arr->currentIndex].current_product);
            date = getExpirationDate(&arr->elements[arr->currentIndex].current_product);
            addProduct(arr, da, name, category, quantity, date, 2);
            break;
        case 2: deleteProduct(arr, da, arr->elements[arr->currentIndex].current_product.name, arr->elements[arr->currentIndex].current_product.category, 2);
            break;
        case 3: strcpy(name, getName(&arr->elements[arr->currentIndex].prev_product));
            strcpy(category, getCategory(&arr->elements[arr->currentIndex].prev_product));
            strcpy(update_data, getName(&arr->elements[arr->currentIndex].current_product));
            updateProduct1(arr, da,name, category, update_data, 1, 2);
            break;
        case 4: strcpy(name, getName(&arr->elements[arr->currentIndex].prev_product));
            strcpy(category, getCategory(&arr->elements[arr->currentIndex].prev_product));
            strcpy(update_data, getCategory(&arr->elements[arr->currentIndex].current_product));
            updateProduct1(arr, da,name, category, update_data, 2, 2);
            break;
        case 5: strcpy(name, getName(&arr->elements[arr->currentIndex].prev_product));
            strcpy(category, getCategory(&arr->elements[arr->currentIndex].prev_product));
            update_quantity = getQuantity(&arr->elements[arr->currentIndex].current_product);
            updateProduct2(arr, da,name, category,  update_quantity, 2);
            break;
        case 6: strcpy(name, getName(&arr->elements[arr->currentIndex].prev_product));
            strcpy(category, getCategory(&arr->elements[arr->currentIndex].prev_product));
            update_date = getExpirationDate(&arr->elements[arr->currentIndex].current_product);
            updateProduct3(arr, da,name, category,  update_date, 2);
            break;
    }

}

void destroyUndoRedo(UndoRedo* arr)
{

 if (arr == NULL)
     return;

 free(arr->elements);
 arr->elements = NULL;

 free(arr);
}