
#include "Movie.h"
#include <string.h>
#include <stdlib.h>
#include <cstdio>


Movie::Movie():_title{""},_genre{""},_release_year{0},_number_of_likes{-1},_trailer_link{""}{}

Movie::Movie(const std::string &title, const std::string &genre, int release_year, int like_number, const std::string &trailer):_title{title},_genre{genre},_release_year{release_year},_number_of_likes{like_number},_trailer_link{trailer}
{}

const std::string &Movie::getTitle() const {
    return this->_title;
}

const std::string &Movie::getGenre() const {
    return this->_genre;
}

const std::string &Movie::getTrailer() const {
    return this->_trailer_link;
}

int Movie::getReleaseYear() const {
    return this->_release_year;
}

int Movie::getLikesNumber() const {
    return this->_number_of_likes;
}

Movie::Movie(const Movie &m):_title{m._title}, _genre{m._genre}, _release_year{m._release_year}, _number_of_likes{m._number_of_likes}, _trailer_link{m._trailer_link} {

}

void Movie::setGenre(const std::string &genre) {
    this->_genre = genre;
}

void Movie::setTrailer(const std::string &trailer) {
    this->_trailer_link = trailer;
}

void Movie::setReleaseYear(int year) {
    this->_release_year = year;
}

void Movie::setLikesNumber(int value) {
    this->_number_of_likes = value;
}

void Movie::setTitle(const std::string &title) {
    this->_title = title;
}

Movie &Movie::operator=(const Movie &movie) {
    this->_title = movie._title;
    this->_genre = movie._genre;
    this->_trailer_link = movie._trailer_link;
    this->_number_of_likes = movie._number_of_likes;
    this->_release_year = movie._release_year;

    return *this;
}

//std::ostream &operator<<(std::ostream &os, const Movie &movie) {
//    os<<"\nTitle: "<<movie._title<<"\nGenre: "<<movie._genre<<"\nRelease Year: ";
//    os<<movie._release_year<<"\nNumber of likes: "<<movie._number_of_likes;
//    os<<"\nTrailer Link: "<<movie._trailer_link;
//    return os;
//}
std::ostream &operator<<(std::ostream &os, const Movie &movie) {
    os<<movie._title<<"\n"<<movie._genre<<"\n";
    os<<movie._trailer_link<<"\n";
    os<<movie._release_year<<"\n"<<movie._number_of_likes<<"\n";
    return os;
}

std::istream &operator>>(std::istream &is, Movie &movie) {

    //is.clear();is.sync();
    std::string aux;
    std::getline(is, movie._title);
    is.clear();is.sync();
    std::getline(is, movie._genre);
    is.clear();is.sync();
    std::getline(is, movie._trailer_link);
    is.clear();is.sync();
    is>>movie._release_year>>movie._number_of_likes;
    std::getline(is,aux);
    //is.clear();is.sync();
    return is;
}

bool Movie::operator==(const Movie &movie) const {
    if (this->_title.compare(movie._title) == 0) {
        return true;
    }
    else return false;
}

Movie::~Movie() {

}



