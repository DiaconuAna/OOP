//
// Created by amina on 3/26/2021.
//
#pragma once
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Domain\DynamicVectorTemplated.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Domain\Movie.h"

class WatchList {
private:
    DynamicVectorTemplated<Movie> watchlist;

public:
    //default constructor
    WatchList();

    /**
     * Add a movie to the watchlist
     * Precondition: check if the movie has been added beforehand in the watchlist
     * @param mov
     */
    void addMovie(Movie mov);

    /**
     * Remove a movie from the watch list
     * Precondition: check if the movie exists in the watchlist
     * @param mov
     */
    void deleteMovie(Movie mov);

    /**
     * Look for a movie in the watchlist and return its position
     * @param mov
     * @return -1 if the movie does not exist in the watchlist, else its position
     */
    int searchMovie(Movie mov);

    /**
     * Return the current size of the watchlist
     * @return
     */
    int list_size();

    Movie getMovie(int position);





};
