#include "RefrigeratorController.h"
#include "Product.h"
#include "ProductRepository.h"
#include "UndoService.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

void addProduct(UndoRedo* arr1, DynamicArray* arr, char name[], char category[], int quantity, Date expiration_date, int id)
{
 int position;
 Product p;

 position = searchProduct(arr, name, category);

 if (position != -1){
     reupdate(arr, position, quantity);}
 else{
     p = createProduct(name, category, quantity, expiration_date);
     if (id == 1)
     {
         addOperation(arr1,1,p,p);

     }
     add(arr,p);
      }

}


void deleteProduct(UndoRedo* arr1, DynamicArray* arr, char name[], char category[], int id)
{
    int position;
    Product p;

    position = searchProduct(arr, name, category);

    if (position == -1)
        perror("Product does not exist in the list!");
    else {
        if (id == 1)
        {
            p = arr->elements[position];
            addOperation(arr1,2,p,p);
        }
        delete(arr, position);
    }

}


void updateProduct1(UndoRedo* arr1, DynamicArray* arr, char name[], char category[],char update_data[], int value, int id)
{
    int position;
    Product current_product, prev_product;

    position = searchProduct(arr, name, category);

    if(position == -1)
        perror("Product does not exist in the list!");
    else
    {
        if (value == 1){
            if (id == 1)
            {
                prev_product = arr->elements[position];
                current_product = prev_product;
                strcpy(current_product.name, update_data);
                addOperation(arr1,3,current_product, prev_product);
            }
            update_name(arr, position, update_data);}
        else if (value == 2){
            if (id == 1)
            {
                prev_product = arr->elements[position];
                current_product = arr->elements[position];
                strcpy(current_product.category, update_data);
                addOperation(arr1,4,current_product, prev_product);
            }
            update_category(arr, position, update_data);}
    }
}

void updateProduct2(UndoRedo* arr1, DynamicArray* arr, char name[], char category[], int update, int id)
{
    int position;
    Product prev_product, current_product;
    position = searchProduct(arr, name, category);

    if(position == -1)
        perror("Product does not exist in the list!");
    else
    {   if (id == 1)
        {
            prev_product = arr->elements[position];
            current_product = prev_product;
            current_product.quantity = update;
            addOperation(arr1,5,current_product, prev_product);
        }
        update_quantity(arr, position, update);
    }
}

void updateProduct3(UndoRedo* arr1, DynamicArray* arr, char name[], char category[], Date new_date, int id)
{
    int position;
    Product prev_product, current_product;

    position = searchProduct(arr, name, category);

    if(position == -1)
        perror("Product does not exist in the list!");
    else
    {   if (id == 1)
        {
            prev_product = arr->elements[position];
            current_product = prev_product;
            current_product.expiration_date = new_date;
            addOperation(arr1,6,current_product, prev_product);
        }
        update_date(arr, position, new_date);
    }
}



int searchProduct(DynamicArray* arr,char name[],char category[])
{

    Product current_element;
    int index;

    for (index = 0; index < arr->nrElems; index++){
        current_element = arr->elements[index];
        if ((strcmp(name, current_element.name) == 0) && (strcmp(category, current_element.category) == 0))
            return index;
    }
    return -1;
}

void getProductList(DynamicArray *arr, char str[][100])
{
    int index = 0;
    for (index = 0;index < arr->nrElems;index++)
        toString(arr->elements[index], str[index]);
}

void createEntries(DynamicArray* arr)
{
    Product prod;
    prod = createProduct("MilkaOreo","sweets",4,createDate(10,3,2021));
    add(arr, prod);
    prod = createProduct("KinderMaxKing","sweets",3,createDate(13,4,2022));
    add(arr, prod);
    prod = createProduct("OatMilk","dairy",2,createDate(5,6,2022));
    add(arr, prod);
    prod = createProduct("CoconutMilk","dairy",5,createDate(8,5,2021));
    add(arr, prod);
    prod = createProduct("Lasagna","meat",3,createDate(7,8,2021));
    add(arr, prod);
    prod = createProduct("SmoothieMix","fruit",6,createDate(10,3,2021));
    add(arr, prod);
    prod = createProduct("AppleJuice","fruit",4,createDate(30,7,2021));
    add(arr, prod);
    prod = createProduct("FruitSaladMix","fruit",2,createDate(15,9,2021));
    add(arr, prod);
    prod = createProduct("GreekYoghurt2%","dairy",6,createDate(23,8,2021));
    add(arr, prod);
    prod = createProduct("MilkaWaffle","sweets",4,createDate(16,3,2021));
    add(arr, prod);
}

DynamicArray* filterString(DynamicArray* arr, char str[])
{
    DynamicArray* da;
    int i;
    char product_name[100];

    if (str[0] == '-')
    {
        da = createDA(arr->cap);
        for (i = 0;i < arr->nrElems; i++)
            add(da, arr->elements[i]);
        return da;
    }

    else {
        da = createDA(arr->cap);
        for (i = 0; i < arr->nrElems; i++) {

            strcpy(product_name, arr->elements[i].name);
            if (strstr(product_name, str)) {
                add(da, arr->elements[i]);
            }
        }
        return da;
    }
}

DynamicArray* filterByYear(DynamicArray* arr, int year)
{
    DynamicArray* da;

    int i;

    if (year == 0){

        da = createDA(arr->cap);
        for (i = 0;i < arr->nrElems; i++)
            add(da, arr->elements[i]);
        return da;
    }
    else {

        da = createDA(arr->cap);
        for (i = 0; i < arr->nrElems; i++) {

            if (arr->elements[i].expiration_date.year == year)
                add(da, arr->elements[i]);
        }
        printf("%d\n", da->nrElems);
        return da;
    }
}

void sortAscendingByQuantity(DynamicArray* arr)
{
    Product temp;
    int i,j,q1,q2;

    for (i=0;i<arr->nrElems-1;i++)
        for(j=i+1;j<arr->nrElems;j++){
            q1 = arr->elements[i].quantity;
            q2 = arr->elements[j].quantity;
            if (q1>q2)
            {
                temp = arr->elements[i];
                arr->elements[i] = arr->elements[j];
                arr->elements[j] = temp;
            }
        }
}

void sortDescendingByQuantity(DynamicArray* arr)
{
    Product temp;
    int i,j,q1,q2;

    for (i=0;i<arr->nrElems-1;i++)
        for(j=i+1;j<arr->nrElems;j++){
            q1 = arr->elements[i].quantity;
            q2 = arr->elements[j].quantity;
            if (q1<q2)
            {
                temp = arr->elements[i];
                arr->elements[i] = arr->elements[j];
                arr->elements[j] = temp;
            }
        }
}

void sortDescendingByDate(DynamicArray* arr)
{
    Product temp;
    int i,j,q1,q2,d1,d2;

    for (i=0;i<arr->nrElems-1;i++)
        for(j=i+1;j<arr->nrElems;j++){
            q1 = arr->elements[i].expiration_date.month;
            q2 = arr->elements[j].expiration_date.month;
            d1 = arr->elements[i].expiration_date.day;
            d2 = arr->elements[j].expiration_date.day;
            if (q1<q2 || (q1 == q2 && d1<d2))
            {
                temp = arr->elements[i];
                arr->elements[i] = arr->elements[j];
                arr->elements[j] = temp;
            }
        }
}

void sortDescendingByName(DynamicArray* arr)
{
    Product temp;
    int i,j,q1,q2;
    char name1[100], name2[100];

    for (i=0;i<arr->nrElems-1;i++)
        for(j=i+1;j<arr->nrElems;j++){
            strcpy(name1, arr->elements[j].name);
            strcpy(name2, arr->elements[i].name);
            if (strcmp(name1, name2) >= 0)
            {
                temp = arr->elements[i];
                arr->elements[i] = arr->elements[j];
                arr->elements[j] = temp;
            }
        }
}

void destroyDynamicArray(DynamicArray* arr)
{
    destroy(arr);
}

int numberOfDaysBetweenDates(Date d1, Date d2)
{
    int DaysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int leapYearCount = 0;
    int year1, year2;

    //compute the number of days for year represented in d1
    year1 = 365 * d1.year + d1.day;

    for (int i=0;i<d1.month - 1;i++)
        year1 += DaysPerMonth[i];

    //count the number of leap years before a given date
    int aux = d1.year;

    //check if the current year needs to be
    //considered for the count of leap years
    //or not
    if (d1.month <= 2)
        aux --;

    leapYearCount = aux/4 - aux/100 + aux/400;
    year1 += leapYearCount;

    //do the same for year 2
    year2 = 365*d2.year + d2.day;

    for (int i=0;i<d2.month-1;i++)
        year2 += DaysPerMonth[i];

    aux = d2.year;
    if(d2.month <= 2)
        aux --;

    leapYearCount = aux/4-aux/100+aux/400;
    year2 += leapYearCount;

    return (year2 - year1);
}

Date getCurrentDate()
{
    time_t t = time(NULL);
    Date current_date;

    struct tm tm = *localtime(&t);
    current_date = createDate(tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);

    return current_date;
}

int ExpirationTime(int x,int number_of_days)
{
    if (number_of_days < 0 || (number_of_days - x< 0))
        return 1;
    return 0;
}

DynamicArray* filterbyCategory(DynamicArray *arr, char str[])
{
    int i;
    DynamicArray* da;

    if (strcmp(str,"-") == 0)
    {

        da = createDA(arr->cap);
        for (i = 0;i < arr->nrElems; i++)
            add(da, arr->elements[i]);
        return da;
    }
    else{

        da = createDA(arr->cap);
        for (i = 0;i< arr->nrElems;i++)
            if (strcmp(getCategory(&arr->elements[i]),str) == 0)
                add(da, arr->elements[i]);
        return da;
    }
}

DynamicArray* getProductsExp(DynamicArray *arr, int x)
{
    int i, days_btw_years;
    Date d1,d2;
    DynamicArray* FilteredArray;
    FilteredArray = createDA(arr->cap);

    for (i = 0; i< arr->nrElems;i++)
    {
        d1 = getExpirationDate(&arr->elements[i]);
        d2 = getCurrentDate();
        days_btw_years = numberOfDaysBetweenDates(d2,d1);
       // printf("%d\n", days_btw_years);
        if (ExpirationTime(x, days_btw_years) != 0)
            add(FilteredArray, arr->elements[i]);
    }
    return FilteredArray;
}