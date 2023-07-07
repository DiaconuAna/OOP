#include "Product.h"
#include <string.h>
#include <stdio.h>

int validateMonth(int month)
{
    if (month < 1 || month > 12)
        return 0;
    else return 1;
}

int validateDay(int year, int month, int day)
{
    if (day < 0 || day > 31)
        return 0;

    switch(month) {
        case 1:
            if (day > 31) return 0;
            break;
        case 2:
            if(year%4 == 0 && day > 29) return 0;
            else if (day>28) return 0;
            break;
        case 3:
            if (day > 31) return 0;
            break;
        case 4:
            if (day > 30) return 0;
            break;
        case 5:
            if (day > 31) return 0;
            break;
        case 6:
            if (day > 30) return 0;
            break;
        case 7:
            if (day > 31) return 0;
            break;
        case 8:
            if (day > 31) return 0;
            break;
        case 9:
            if (day > 30) return 0;
            break;
        case 10:
            if (day > 31) return 0;
            break;
        case 11:
            if (day > 30) return 0;
            break;
        case 12:
            if (day > 31) return 0;
            break;
        default: return 0;
    }
    return 1;

}

int validateDate(int year, int month, int day)
{
    return validateMonth(month) && validateDay(year, month, day);
}

Date createDate(int day, int month,  int year)
{
    if(validateDate(year, month, day))
    {
        Date d;
        d.day = day;
        d.month = month;
        d.year = year;
        return d;
    }
    else
    {
        Date d;
        d.day = 0;
        d.month = 0;
        d.year = 0;
        return d;
    }

}

Product createProduct(char name[], char category[], int quantity, Date expiration_date)
{
 Product p;
 strcpy(p.name, name);
 strcpy(p.category, category);
 p.quantity = quantity;
 p.expiration_date = expiration_date;

 return p;
}

char* getName(Product* p)
{
    return p->name;
}

char* getCategory(Product* p)
{
    return p->category;
}

int getQuantity(Product* p)
{
    return p->quantity;
}

Date getExpirationDate(Product* p)
{
    return p->expiration_date;
}


void setQuantity(Product* p, int value)
{
    p->quantity = value;
}

void setName(Product* p, char name[])
{
    strcpy(p->name, name);
}

void setCategory(Product *p, char category[])
{
    strcpy(p->category, category);
}

void setDate(Product *p, Date date)
{
    p->expiration_date.day = date.day;
    p->expiration_date.month = date.month;
    p->expiration_date.year = date.year;
}

void updateQuantity(Product *p, int value)
{
    p->quantity += value;
}

void toString(Product p, char str[])
{
    sprintf(str, "\n Name: %s \n Category: %s \n Quantity: %d \n Expiration date(D/M/Y): %d-%d-%d\n", p.name, p.category, p.quantity, p.expiration_date.day, p.expiration_date.month, p.expiration_date.year);

}