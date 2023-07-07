#pragma once

typedef struct
{
    int day,month,year;
} Date;

typedef struct {
    char name[50];
    char category[50];
    int quantity;
    Date expiration_date;
}  Product;

/**
 * Create a product with the given attributes
 * @param name
 * @param category
 * @param quantity
 * @param expiration_date
 * @return
 */
Product createProduct(char name[], char category[], int quantity, Date expiration_date);

/**
 * Create a date with the given attributes
 * @param day
 * @param month
 * @param year
 * @return
 */
Date createDate(int day, int month,  int year);

/**
 * Get the name of a product
 */
char*  getName(Product* p);

/**
 * Get the category of a product
 * @param p
 * @return
 */
char* getCategory(Product* p);

int getQuantity(Product* p);
Date getExpirationDate(Product* p);

/**
 * Modify the quantity of a certain product
 * @param p
 * @param value
 */
void setQuantity(Product* p, int value);
void toString(Product p, char str[]);
void updateQuantity(Product *p, int value);
void setName(Product* p, char name[]);
void setCategory(Product *p, char category[]);
void setDate(Product *p, Date date);

int validateMonth(int month);
int validateDay(int year, int month, int day);
int validateDate(int year, int month, int day);