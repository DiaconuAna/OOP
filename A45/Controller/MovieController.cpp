//
// Created by amina on 3/19/2021.
//

#include "MovieController.h"
#include <exception>
#include <string.h>
#include <utility>
#include <windows.h>
#include "../Repository/MovieRepository.h"
#include <iostream>

MovieController::MovieController(MovieRepository movie_repo, WatchList watch_list, int index) {
  //this->movie_controller = std::move(movie_repo);
  this -> movie_controller = movie_repo;
  this -> user_watchlist = watch_list;
  this ->current_index_wl = index;
  //this -> createEntries();
}

void MovieController::createEntries() {
    movie_controller.add_movie(Movie((char*)"Ghosts", (char*)"Comedy", 2019, 10, (char*)"https://www.youtube.com/watch?v=5e0nB1mSd9Q"));
    movie_controller.add_movie(Movie((char*)"Beauty and the Beast",(char*)"Fantasy",2017,14,(char*)"https://www.youtube.com/watch?v=e3Nl_TCQXuw"));
    movie_controller.add_movie(Movie((char*)"Inglorious Basterds",(char*)"War",2009,12,(char*)"https://www.youtube.com/watch?v=KnrRy6kSFF0"));
    movie_controller.add_movie(Movie((char*)"Ophelia",(char*)"Romance",2019,17,(char*)"https://www.youtube.com/watch?v=gIA2Fn2q7zY"));
    movie_controller.add_movie(Movie((char*)"W.E.",(char*)"Romance",2011,20,(char*)"https://www.youtube.com/watch?v=4lNg0cm69xU"));
    movie_controller.add_movie(Movie((char*)"Anthropoid",(char*)"War",2016,25,(char*)"https://www.youtube.com/watch?v=blAKCJcXC5c"));
    movie_controller.add_movie(Movie((char*)"Jojo Rabbit",(char*)"War",2019,15,(char*)"https://www.youtube.com/watch?v=ZkKaDXapi1o"));
    movie_controller.add_movie(Movie((char*)"303 Squadron",(char*)"War",2018,13,(char*)"https://www.youtube.com/watch?v=vSHeKwLnp8o"));
    movie_controller.add_movie(Movie((char*)"Mulan",(char*)"Animation",2020,21,(char*)"https://www.youtube.com/watch?v=R-eFm--k21c"));
    movie_controller.add_movie(Movie((char*)"Aladdin",(char*)"Fantasy",2019,24,(char*)"https://www.youtube.com/watch?v=foyufD52aog"));

}

DynamicVectorTemplated<Movie>* MovieController::get_controller_list() {
    return this->movie_controller.get_repo_list();
}

int MovieController::getMovieStatus(char *title) {
    return movie_controller.getMovieStatus(title);
}

void MovieController::addMovie(char *title, char *genre, char *trailer, int year, int likes) {
     Movie m1, m2;
     m1 = Movie(title, genre, year, likes, trailer);
     if (this->getMovieStatus(title) != -1)
         throw "Movie title must be unique! Please try again!";
     else
         this -> movie_controller.add_movie(m1);
}

void MovieController::removeMovie(char *title, char *genre, char *trailer, int year, int likes) {

    Movie m1;
    m1 = Movie(title, genre, year, likes, trailer);

    int position = this -> searchPosition(m1);

    if (position == -1)
        throw "Movie not found in the list!";
    else{
        this->movie_controller.remove_movie(m1);
    }
}

int MovieController::searchPosition(Movie mov) {
    return this->movie_controller.search_movie(mov);
}

void MovieController::getMovieList(char (*str)[256]) {
    this->movie_controller.getMovieList(str);
}


int MovieController::controller_size() {
    return this->movie_controller.repo_size();
}

void MovieController::updateTitle(Movie mov, char *title) {
    int position;
    position = this->searchPosition(mov);
    if (position == -1){
        //std::cout<<mov.getTitle();
        throw "Movie not found in the list!";}

    else{
        //std::cout<<"Hello";
        if (getMovieStatus(title) != -1)
            throw "Movie title must be unique! Please try again!";
        else {
            Movie newMovie, currentMovie;
            currentMovie = this->movie_controller.getMovie(position);
            newMovie = currentMovie;
            newMovie.setTitle(title);
            this->movie_controller.update(mov, newMovie);
        }
    }
}

void MovieController::updateGenre(Movie mov, char *genre) {
    int position;
    position = this->searchPosition(mov);
    if (position == -1)
        throw "Movie not found in the list!";
    else{
        Movie newMovie, currentMovie;
        currentMovie = this->movie_controller.getMovie(position);
        newMovie = currentMovie;
        newMovie.setGenre(genre);
        this->movie_controller.update(mov, newMovie);
    }
}

void MovieController::updateTrailer(Movie mov, char *trailer) {
    int position;
    position = this->searchPosition(mov);
    if (position == -1)
        throw "Movie not found in the list!";
    else{
        Movie newMovie, currentMovie;
        currentMovie = this->movie_controller.getMovie(position);
        newMovie = currentMovie;
        newMovie.setTrailer(trailer);
        this->movie_controller.update(mov, newMovie);
    }
}

void MovieController::updateReleaseYear(Movie mov, int year) {
    int position;
    position = this->searchPosition(mov);
    if (position == -1)
        throw "Movie not found in the list!";
    else{
        Movie newMovie, currentMovie;
        currentMovie = this->movie_controller.getMovie(position);
        newMovie = currentMovie;
        newMovie.setReleaseYear(year);
        this->movie_controller.update(mov, newMovie);
    }
}

void MovieController::updateLikes(Movie mov, int likes) {
    int position;
    position = this->searchPosition(mov);
    if (position == -1)
        throw "Movie not found in the list!";
    else{
        Movie newMovie, currentMovie;
        currentMovie = this->movie_controller.getMovie(position);
        newMovie = currentMovie;
        newMovie.setLikesNumber(likes);
        this->movie_controller.update(mov, newMovie);
    }
}

void MovieController::addtoWatchList(Movie mov) {
   this->user_watchlist.addMovie(mov);
}

void MovieController::removefromWatchList(Movie mov) {
  this->user_watchlist.deleteMovie(mov);
}

WatchList MovieController::filterByGenre(char *genre) {
    WatchList genre_watch_list;
    //std::cout << genre<<std::endl;
    if(strcmp(genre, "-") == 0)
    {
       //std::cout<<"Bonjour\n";
        for (int index = 0;index < this->controller_size();index ++)
        {
            Movie current_movie;
            current_movie = this->movie_controller.getMovie(index);
            genre_watch_list.addMovie(current_movie);
    }
        return genre_watch_list;
    }

    else
    {
        for (int index = 0;index < this->controller_size();index ++)
        {
            Movie current_movie;
            current_movie = this->movie_controller.getMovie(index);
            if (strcmp(current_movie.getGenre(), genre) == 0){
                //std::cout<<current_movie.getGenre()<<std::endl;
                genre_watch_list.addMovie(current_movie);
            }
        }
        if (genre_watch_list.list_size() != 0)
            return genre_watch_list;
        else throw "No movie has the given genre!";
    }
   // genre_array.~DynamicVectorTemplated();
}

void MovieController::rate_movie(Movie mov) {
    int movie_position;
    movie_position = this->getMovieStatus(mov.getTitle());
    mov = this->getMovie(movie_position);
    this->updateLikes(mov, mov.getLikesNumber()+1);
}

Movie MovieController::getMovie(int position) {
    return this->movie_controller.getMovie(position);
}

int MovieController::get_watchlist_size() {
    return this->user_watchlist.list_size();
}

Movie MovieController::getWatchListMovie(int position) {
    return this->user_watchlist.getMovie(position);
}


