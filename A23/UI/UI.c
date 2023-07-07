//
// Created by amina on 3/4/2021.
//
#include "RefrigeratorController.h"
#include "ProductRepository.h"
#include "Product.h"
#include "UndoService.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a23-913-Diaconu-Ana\Tests\Refrigerator_tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <crtdbg.h>

Date read_date()
{
    int day,  month,  year;
    Date exp_date;
    printf("\n Please enter an expiration date: ");
    printf("\n Day: ");
    scanf("%d", &day);
    printf("\n Month: ");
    scanf("%d", &month);
    printf("\n Year: ");
    scanf("%d", &year);

    exp_date = createDate(day, month, year);
    return exp_date;
}

int product_input(char name[], char category[], int* quantity, Date* expiration_date)
{
    char temp;
    char quant[100];
    //scanf("%c",&temp);
 printf("\n Please name your product: ");
 //scanf("%[^\n]%*c",name);
 scanf("%s",name);
// printf("%s", name);
 //fgets(name,100,stdin);
// scanf("%c",&temp);

 do
     {
 printf("\n Please choose a category: ");
 printf("\n >>dairy \n >>meat \n >>sweets \n >>fruit \n");
 scanf("%s",category);}

 while (strcmp(category, "dairy")!=0 && strcmp(category, "meat")!=0 && strcmp(category, "sweets")!=0 && strcmp(category, "fruit")!=0);

 printf("\n Please enter a quantity: ");
    scanf("%s", quant);
    *quantity = atoi(quant);
    if (*quantity == 0)
    {printf("Invalid value.");
    return 0;}

        //tmp = scanf("%d", &quantity);



 *expiration_date = read_date();
    return 1;
}

int addProductUI(DynamicArray* arr, UndoRedo* undoredo)
{
    char name[100],str[100];
    char category[100];
    int quantity;
    Date exp_date;
    if (product_input(name, category, &quantity, &exp_date) == 0){
        printf("Wrong input. Try again?>");
        return 0;}

    if (exp_date.day == 0){
        perror("Invalid date");
        return 0;}
    addProduct(undoredo, arr, name,  category,   quantity, exp_date, 1);
}

void deleteProductUI(DynamicArray*  arr, UndoRedo* undoredo)
{
    char name[100], category[100], c;
    printf("\n Please enter name of the product you want to delete: ");
    scanf("%s",name);
    scanf("%c",&c);

    do
    {
        printf("\n Please choose a category: ");
        printf("\n >>dairy \n >>meat \n >>sweets \n >>fruit \n");
        scanf("%s", category);}

    while (strcmp(category, "dairy")!=0 && strcmp(category, "meat")!=0 && strcmp(category, "sweets")!=0 && strcmp(category, "fruit")!=0);

    deleteProduct(undoredo, arr, name, category, 1);
}

void updateProductUI(DynamicArray *arr, UndoRedo* undoredo)
{
    char name[100], category[100],c, update[100], quant[100];
    int quantity, year, day, month;

    do{
    printf("Input the field which you would like to update: >>name >>category >>quantity >>date");
    scanf("%s",update);
    }
    while (strcmp(update, "name")!=0 && strcmp(update, "quantity")!=0 && strcmp(update, "category")!=0 && strcmp(update,"date")!=0);

    printf("\n Please enter name of the product you want to update: ");
    scanf("%s",name);

        scanf("%c",&c);
    do
    {
        printf("\n Please choose a category: ");
        printf("\n >>dairy \n >>meat \n >>sweets \n >>fruit \n");
        scanf("%s", category);}

    while (strcmp(category, "dairy")!=0 && strcmp(category, "meat")!=0 && strcmp(category, "sweets")!=0 && strcmp(category, "fruit")!=0);

    if (strcmp(update, "name") == 0){
        printf("Input the new name: ");
        scanf("%s", update);
        updateProduct1(undoredo, arr, name, category,update, 1, 1);}
    else if (strcmp(update, "category") == 0){
        printf("Input the new category: ");
        scanf("%s", update);
        updateProduct1(undoredo, arr, name, category,update, 2 ,1);}
    else if (strcmp(update,"quantity") == 0){
        printf("Input the new quantity: ");
        scanf("%s", quant);
        quantity = atoi(quant);
        if (quantity == 0)
        {printf("Invalid value.");
            return ;}

        updateProduct2(undoredo, arr, name, category, quantity, 1);}
    else if (strcmp(update, "date") == 0){
        printf("\n Please enter an expiration date: ");
        printf("\n Day: ");
        scanf("%d", &day);
        printf("\n Month: ");
        scanf("%d", &month);
        printf("\n Year: ");
        scanf("%d", &year);
        Date new_date = createDate(day, month, year);
        updateProduct3(undoredo, arr, name, category, new_date, 1);}

}


void menu()
{
    printf("\n***********");
    printf("\n1  >> Add a product");
    printf("\n2  >> Delete a product");
    printf("\n3  >> Update a product");
    printf("\n4  >> Display list of products");
    printf("\n5  >> Display all products whose name contains a given string and show them sorted by the existing quantity.");
    printf("\n6  >> Display all products which expire in a given year (Bonus for b.).");
    printf("\n7  >> Display all products whose name contains a given string and show them sorted descending by their name.");
    printf("\n8  >> Display all products of a given category whose expiration dates are close.");
    printf("\n9  >> Undo.");
    printf("\n10 >> Redo.");
    printf("\n11 >> Run tests.");
    printf("\n0  >> Exit");
    printf("\n***********\n");
}


void printProductList(DynamicArray* arr)
{
    char str[100][100];
    int index;

    getProductList(arr, str);
    //printf("%d", arr->nrElems);
    if (arr->nrElems == 0)
        printf("There are no elements in this list!");
    else{
    for (index = 0;index < arr->nrElems;index++)
        printf("\n%s", str[index]);}
}

void display_filter_name(DynamicArray* arr)
{
    //first filter the list
    char str[100],c,sorting_type[100];
    DynamicArray* FilteredArray;

    printf("Input the string you want to filter after: ");
    scanf("%s", str);
    scanf("%c",&c);

    do {
        printf("Do you want to sort it in descending or ascending order?\n");
        printf(">> ascending >>descending \n");
        scanf("%s", sorting_type);
    }
    while (strcmp(sorting_type, "ascending") != 0 && strcmp(sorting_type, "descending") != 0);

    //scanf("%[^\n]s", str);
    //fgets(str,99,stdin);
    FilteredArray = filterString(arr, str);
    if (strcmp(sorting_type, "ascending") == 0)
        sortAscendingByQuantity(FilteredArray);
    else
        sortDescendingByQuantity(FilteredArray);
    printProductList(FilteredArray);
    destroyDynamicArray(FilteredArray);
}

void display_filter_name_2(DynamicArray* arr)
{
    char str[100],c;
    DynamicArray* FilteredArray;

    printf("Input the string you want to filter after: ");
    scanf("%s", str);
    scanf("%c",&c);

    FilteredArray = filterString(arr, str);
    sortDescendingByName(FilteredArray);
    printProductList(FilteredArray);
    destroyDynamicArray(FilteredArray);

}

void display_filter_year1(DynamicArray* arr)
{
    int year, x;
    char c;
    DynamicArray *FilteredArray;
    DynamicArray *FinalArray;

    printf("Enter a number of days: ");
    scanf("%d",&x);
    scanf("%c",&c);

    printf("Choose a year: ");
    scanf("%d", &year);

    FilteredArray = filterByYear(arr, year);
    FinalArray = getProductsExp(FilteredArray, x);
    printProductList(FinalArray);
    destroyDynamicArray(FilteredArray);
    destroyDynamicArray(FinalArray);

}

void display_filter_year(DynamicArray* arr)
{
    int year;
    char c, answer[100];
    DynamicArray *FilteredArray;
    DynamicArray *FinalArray;
    printf("Choose a year: ");
    scanf("%d", &year);

    FilteredArray = filterByYear(arr, year);

    printf("Would you like to display the array sorted in ascending order by quantity? \n >>Yes >>No \n");
    scanf("%s", answer);

    if(strcmp(answer,"No")==0)
        printProductList(FilteredArray);
    else{
        sortAscendingByQuantity(FilteredArray);
        printProductList(FilteredArray);
    }
    destroyDynamicArray(FilteredArray);

}

void display_expiration_date(DynamicArray* arr)
{
    char category[100],c,answer[100];
    int x;
    DynamicArray* filteredArray;
    DynamicArray* finalArray;

    printf("Enter a number of days: ");
    scanf("%d",&x);
    scanf("%c",&c);


    do
    {
        printf("\n Please choose a category: ");
        printf("\n >>dairy \n >>meat \n >>sweets \n >>fruit \n >> - (empty)\n");
        scanf("%s", category);}

    while (strcmp(category, "dairy")!=0 && strcmp(category, "meat")!=0 && strcmp(category, "sweets")!=0 && strcmp(category, "fruit")!=0 && strcmp(category, "-")!=0);


    filteredArray = filterbyCategory(arr, category);
    finalArray = getProductsExp(filteredArray, x);

    printf("Would you like the array to be sorted in descending order by date?(Bonus requirement)?\n >>Yes >>No\n");
    scanf("%s", answer);

    if(strcmp(answer,"No")==0)
        printProductList(finalArray);
    else
    {
        sortDescendingByDate(finalArray);
        printProductList(finalArray);
    }
    destroyDynamicArray(filteredArray);
    destroyDynamicArray(finalArray);
}

void entries(DynamicArray* arr)
{
createEntries(arr);
}

void undoUI(UndoRedo* arr, DynamicArray* da)
{
    undo(arr, da);
}

void redoUI(UndoRedo* arr, DynamicArray* da)
{
    redo(arr, da);
}

void runTestsUI()
{
    testAll();
}


int main()
{
 int is_it_over_yet =  0;
 int command;
 DynamicArray* da, filter_list;
 UndoRedo* undoredo;

 da = createDA(2);
 undoredo = createUndoRedoArray(2);
 entries(da);
 while (!is_it_over_yet){
     menu();
     printf("Pick an option: ");
     scanf("%d", &command);

     switch(command){
         case 1:if(addProductUI(da, undoredo) == 0)
                //printf("Maybe next time?\n");
                break;
         case 2:deleteProductUI(da, undoredo);
                break;
         case 3:updateProductUI(da, undoredo);
                break;
         case 4:printProductList(da);
                break;
         case 5:display_filter_name(da);
                break;
         case 6:display_filter_year(da);
                break;
         case 7:display_filter_name_2(da);
                break;
         case 8:display_expiration_date(da);
                break;
         case 9:undoUI(undoredo, da);
                break;
         case 10: redoUI(undoredo, da);
                  break;
         case 11: runTestsUI();
                  break;
         case 0:is_it_over_yet = 1;
                printf("Come back soon!");
                break;
         default: printf("Incorrect command. Please try again!");
     }

 }

 destroyUndoRedo(undoredo);
 destroyDynamicArray(da);

    int r = _CrtDumpMemoryLeaks();

    printf("\n Memory leaks: %d",r);
    return 0;
}