//
// Created by amina on 3/19/2021.
//

#include "Movie.h"
#include <string.h>
#include <stdlib.h>
#include <cstdio>

Movie::Movie(char title[] , char genre[] , int release_year, int number_of_likes, char trailer[]){
    strcpy(this->title, title);
    strcpy(this->genre, genre);
    strcpy(this->trailer_link, trailer);
    this->release_year = release_year;
    this->number_of_likes = number_of_likes;

}

char* Movie::getTitle()
{
 return this->title;
}

char* Movie::getGenre()
{
return this->genre;
}

char* Movie::getTrailer()
{
return this->trailer_link;
}

int Movie::getReleaseYear()
{
return this->release_year;
}

int Movie::getLikesNumber()
{
return this->number_of_likes;
}

void Movie::setTitle(char *title) {
    strcpy(this->title, title);
}

void Movie::setGenre(char *genre) {
    strcpy(this->genre, genre);
}

void Movie::setTrailer(char *trailer) {
    strcpy(this->trailer_link, trailer);
}

void Movie::setLikesNumber(int value) {
    this->number_of_likes = value;
}

void Movie::setReleaseYear(int year) {
    this->release_year = year;
}

Movie& Movie::operator=(const Movie &movie) {
    strcpy(this->title, movie.title);
    strcpy(this->genre, movie.genre);
    strcpy(this->trailer_link, movie.trailer_link);
    this->number_of_likes = movie.number_of_likes;
    this->release_year = movie.release_year;

    return *this;
}


void Movie::stringMovie(char *str) {
sprintf(str, "\n Title: %s \n Genre: %s \n Year of Release: %d \n Number of likes: %d \n Trailer link: %s \n", this->title, this->genre, this->release_year, this->number_of_likes, this->trailer_link);
}

Movie::Movie(const Movie& movie){
    strcpy(this->title, movie.title);
    strcpy(this->genre, movie.genre);
    strcpy(this->trailer_link, movie.trailer_link);
    this->number_of_likes = movie.number_of_likes;
    this->release_year = movie.release_year;
}