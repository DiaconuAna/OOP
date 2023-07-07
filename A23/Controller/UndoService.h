#pragma once
#include "Product.h"
#include "ProductRepository.h"

typedef struct
{
    int undo_redo_id;
    Product current_product;
    Product prev_product;
} UndoRedoElement;

typedef struct{
    UndoRedoElement* elements;
    int currentCapacity;
    int currentIndex;
    int capacity;

}UndoRedo;

UndoRedo* createUndoRedoArray(int capacity);

/**
 * Create an element of the undo-redo list
 * @param UndoRedoId : Id of the undo operation: 1 for add, 2 for delete, 3 for update name, 4 for update category
 *                 5 for update quantity, 6 for update date
 * @param prod
 * @return
 */
UndoRedoElement createOperation(int UndoRedoId, Product prod, Product prev_prod);

/**
 * @param arr
 * @param UndoId
 * @param prod
 */
void addOperation(UndoRedo* arr,int UndoRedoId, Product prod, Product prev_prod);

void resizeUndoRedo(UndoRedo* arr);

void destroyUndoRedo(UndoRedo* arr);

void undo(UndoRedo* arr, DynamicArray* da);
void redo(UndoRedo* arr, DynamicArray* da);