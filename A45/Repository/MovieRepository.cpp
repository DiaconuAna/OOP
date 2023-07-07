//
// Created by amina on 3/19/2021.
//

#include "MovieRepository.h"
#include <string.h>

MovieRepository::MovieRepository() {

    this ->movie_repository = DynamicVectorTemplated<Movie>();
}

DynamicVectorTemplated<Movie>* MovieRepository::get_repo_list() {
    return &this->movie_repository;
}

void MovieRepository::add_movie(Movie mov) {
    this->movie_repository.add(mov);
}

void MovieRepository::remove_movie(Movie mov) {

    int movie_pos = this->search_movie(mov);
    this->movie_repository.remove(mov, movie_pos);
}

int MovieRepository::search_movie(Movie mov) {
    //return this->movie_repository.search(mov);
    int i, repo_size;
    Movie current_movie;

    repo_size = this->repo_size();

    for (i=0;i<repo_size;i++)
    {
        current_movie = this->movie_repository.getItem(i);
        if (strcmp(current_movie.getTitle(), mov.getTitle()) == 0)
            return i;
    }
    return -1;
}

void MovieRepository::update(Movie mov, Movie new_mov) {
    int movie_position;
    movie_position = this->search_movie(mov);
    this -> movie_repository.update(movie_position, new_mov);
}


void MovieRepository::getMovieList(char (*str)[256]) {
    int index = 0;
    int repo_size = this->repo_size();
    Movie current_movie;
    for (index = 0; index < repo_size; index++)
    {
        current_movie = this->movie_repository.getItem(index);
        current_movie.stringMovie(str[index]);
    }
}

int MovieRepository::repo_size() {
    return movie_repository.length();
}

int MovieRepository::getMovieStatus(char *title)  {
    return this->search_movie(Movie(title));
}

Movie MovieRepository::getMovie(int position){
    return this->movie_repository.getItem(position);
}
