//
// Created by amina on 3/26/2021.
//

#include "WatchListRepository.h"
#include <string.h>

WatchList::WatchList() {
    this -> watchlist = DynamicVectorTemplated<Movie>();
}

int WatchList::list_size() {
    return this->watchlist.length();
}

int WatchList::searchMovie(Movie mov) {
    int list_length = this->list_size();
    int i;

    for (i = 0;i<list_length;i++)
    {
        Movie current_movie;
        current_movie = this->watchlist.getItem(i);
        if (strcmp(current_movie.getTitle(), mov.getTitle()) == 0)
            return i;
    }
    return -1;
}

void WatchList::deleteMovie(Movie mov) {
   int movie_position;
   movie_position = this->searchMovie(mov);
   if (movie_position == -1)
       throw "Movie does not exist in the watch list!";
   else{
       this->watchlist.remove(mov, movie_position);
   }
}

void WatchList::addMovie(Movie mov) {
    int movie_position;
    movie_position = this->searchMovie(mov);
    if (movie_position!=-1)
        throw "Movie already exists in the watch list!";
    else{
        this->watchlist.add(mov);
    }
}

Movie WatchList::getMovie(int position) {
    return this->watchlist.getItem(position);
}
