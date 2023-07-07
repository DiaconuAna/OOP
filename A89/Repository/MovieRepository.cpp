//
// Created by amina on 4/3/2021.
//

#include "MovieRepository.h"
#include <string.h>
#include <iostream>
#include <fstream>

MovieRepository::MovieRepository() {
}


void MovieRepository::add_movie(const Movie& mov, int flag) {
    RepositoryValidator::validate_add(this->movie_repository, mov);
    this->movie_repository.push_back(mov);

}

Movie MovieRepository::remove_movie(Movie mov) {

    RepositoryValidator::validate_remove(this->movie_repository, mov);
    int movie_pos = this->search_movie(mov);
    this->movie_repository.erase(movie_repository.begin()+movie_pos);
    return mov;
}

int MovieRepository::search_movie(Movie mov) {
    int i=0;

    for(const auto& movie: this->movie_repository)
    {
        if (mov.getTitle() == movie.getTitle())
            return i;
        i++;
    }
    return -1;
}

Movie MovieRepository::update(Movie mov, Movie new_mov) {
    int flag;
    if (mov.getTitle() == new_mov.getTitle())
        flag = 0;
    else flag = 1;
    RepositoryValidator::validate_update(this->movie_repository, mov, new_mov, flag);
    MovieValidator::validate(new_mov);
    int position = this->search_movie(mov);
    if(position == -1)
        throw RepositoryException("Movie not in the list!");
    else{
    this->movie_repository[position] = new_mov;
    return mov;}
}

int MovieRepository::repo_size() {
    return movie_repository.size();
}

Movie& MovieRepository::getMovie(int position){
    return this->movie_repository[position];
}

std::vector<Movie> MovieRepository::getMovieList() {
    return this->movie_repository;
}

void MovieRepository::clear_list() {
    this->movie_repository.clear();
}
