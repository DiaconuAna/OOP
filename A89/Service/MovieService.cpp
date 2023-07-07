//
// Created by amina on 4/3/2021.
//

#include "MovieService.h"
#include <algorithm>
#include <Domain/MovieValidator.h>


MovieService::MovieService(MovieRepository& movie_repo, WatchList &watch_list): _movie_repo{&movie_repo}, _user_watchlist{&watch_list}
{}
//
//void MovieService::createEntries() {
//    this->_movie_repo.add_movie(Movie("Ghosts", "Comedy", 2019, 10, "https://www.youtube.com/watch?v=5e0nB1mSd9Q"));
//    this->_movie_repo.add_movie(Movie("Beauty and the Beast","Fantasy",2017,14,"https://www.youtube.com/watch?v=e3Nl_TCQXuw"));
//    this->_movie_repo.add_movie(Movie("Inglorious Basterds","War",2009,12,"https://www.youtube.com/watch?v=KnrRy6kSFF0"));
//    this->_movie_repo.add_movie(Movie("Ophelia","Romance",2019,17,"https://www.youtube.com/watch?v=gIA2Fn2q7zY"));
//    this->_movie_repo.add_movie(Movie("W.E.","Romance",2011,20,"https://www.youtube.com/watch?v=4lNg0cm69xU"));
//    this->_movie_repo.add_movie(Movie("Anthropoid","War",2016,25,"https://www.youtube.com/watch?v=blAKCJcXC5c"));
//    this->_movie_repo.add_movie(Movie("Jojo Rabbit","War",2019,15,"https://www.youtube.com/watch?v=ZkKaDXapi1o"));
//    this->_movie_repo.add_movie(Movie("303 Squadron","War",2018,13,"https://www.youtube.com/watch?v=vSHeKwLnp8o"));
//    this->_movie_repo.add_movie(Movie("Mulan","Animation",2020,21,"https://www.youtube.com/watch?v=R-eFm--k21c"));
//    this->_movie_repo.add_movie(Movie("Aladdin","Fantasy",2019,24,"https://www.youtube.com/watch?v=foyufD52aog"));
//
//}


void MovieService::addMovie(const std::string& title,const std::string& genre,const std::string& trailer, int year, int likes, int flag) {
    Movie m1, m2;
    m1 = Movie(title, genre, year, likes, trailer);
    MovieValidator::validate(m1);
    this -> _movie_repo -> add_movie(m1, flag);
}

void MovieService::removeMovie(const std::string& title,const std::string& genre,const std::string& trailer, int year, int likes) {

    Movie m1;
    m1 = Movie(title, genre, year, likes, trailer);
    this->_movie_repo -> remove_movie(m1);
}

int MovieService::searchPosition(Movie mov) {
    return this->_movie_repo -> search_movie(mov);
}


int MovieService::controller_size() {
    return this->_movie_repo-> repo_size();
}

void MovieService::updateTitle(Movie mov, const std::string& title) {
    int position;
    position = this->searchPosition(mov);

    Movie newMovie, currentMovie;
    if(position == -1)
        throw RepositoryException("Movie not in the list!");
    currentMovie = this->_movie_repo->getMovie(position);
    newMovie = currentMovie;
    newMovie.setTitle(title);
    this->_movie_repo->update(mov, newMovie);
}

void MovieService::updateGenre(Movie mov, const std::string& genre) {
    int position;
    position = this->searchPosition(mov);
    if(position == -1)
        throw RepositoryException("Movie not in the list!");
    Movie newMovie, currentMovie;
    currentMovie = this->_movie_repo->getMovie(position);
    newMovie = currentMovie;
    newMovie.setGenre(genre);
    this->_movie_repo->update(mov, newMovie);
}

void MovieService::updateTrailer(Movie mov, const std::string& trailer) {
    int position;
    position = this->searchPosition(mov);
    if(position == -1)
        throw RepositoryException("Movie not in the list!");
    Movie newMovie, currentMovie;
    currentMovie = this->_movie_repo->getMovie(position);
    newMovie = currentMovie;
    newMovie.setTrailer(trailer);

    this->_movie_repo->update(mov, newMovie);

}

void MovieService::updateReleaseYear(Movie mov, int year) {
    int position;
    position = this->searchPosition(mov);
    if(position == -1)
        throw RepositoryException("Movie not in the list!");
    Movie newMovie, currentMovie;
    currentMovie = this->_movie_repo->getMovie(position);
    newMovie = currentMovie;
    newMovie.setReleaseYear(year);

    this->_movie_repo->update(mov, newMovie);

}

void MovieService::updateLikes(Movie mov, int likes) {
    int position;
    position = this->searchPosition(mov);
    if(position == -1)
        throw RepositoryException("Movie not in the list!");
    Movie newMovie, currentMovie;
    currentMovie = this->_movie_repo->getMovie(position);
    newMovie = currentMovie;
    newMovie.setLikesNumber(likes);

    this->_movie_repo->update(mov, newMovie);
}

void MovieService::addtoWatchList(Movie mov, int flag) {
    this->_user_watchlist->addMovie(mov, flag);
}

void MovieService::removefromWatchList(Movie mov) {
    this->_user_watchlist->deleteMovie(mov);
}

std::vector<Movie> MovieService::filterByGenre(const std::string& genre) {
    if (genre== "-"){
        std::vector<Movie> watch_list = this->_movie_repo->getMovieList();
        std::vector<Movie> genre_list(watch_list.size());
        //auto it =
        std::copy(watch_list.begin(),watch_list.end(), genre_list.begin());
        //std::cout<<genre_list.size()<<" ";
//     for (auto it = genre_list.begin(); it != genre_list.end(); ++it)
//         std::cout << *it <<std:: endl;
        //genre_list.resize(std::distance(genre_list.begin(), it));

        return genre_list;
    }
    else{
        std::vector<Movie> watch_list = this->_movie_repo->getMovieList();
        std::vector<Movie> genre_list(watch_list.size());
        auto it = std::copy_if(watch_list.begin(), watch_list.end(), genre_list.begin(),[&genre](const auto&x){return x.getGenre()==genre;});
        genre_list.resize(std::distance(genre_list.begin(), it));
        return genre_list;
    }
}


void MovieService::rate_movie(Movie mov) {
    int movie_position;
    movie_position = this->_movie_repo->search_movie(mov);
    mov = this->getMovie(movie_position);
    this->updateLikes(mov, mov.getLikesNumber()+1);
}

Movie MovieService::getMovie(int position) {
    return this->_movie_repo->getMovie(position);
}

int MovieService::get_watchlist_size() {
    return this->_user_watchlist->list_size();
}

std::vector<Movie> MovieService::getMovieList() {
    return _movie_repo->getMovieList();
}

std::vector<Movie> MovieService::getWatchList() {
    return _user_watchlist->getWatchList();
}

void MovieService::clearMovieList() {
    this->_movie_repo->clear_list();
}

void MovieService::clearWatchList() {
    this->_user_watchlist->clear_watchlist();
}

void MovieService::see_watchlist() {
    this->_user_watchlist->readFromFile();
}

//
//void MovieService::setMovieFileName(const std::string &file_name) {
//    this->_movie_repo.setFileName(file_name);
//}
//
//void MovieService::setWatchListFileName(const std::string &file_name) {
//  this->_user_watchlist.setFileName(file_name);
//}




