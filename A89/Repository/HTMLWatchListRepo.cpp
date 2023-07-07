//
// Created by amina on 4/18/2021.
//

#include "HTMLWatchListRepo.h"
#include <windows.h>
#include <fstream>

HTMLWatchListRepo::HTMLWatchListRepo(const std::string &repo_file_name, const std::string &html_file_name): WatchList(repo_file_name), _filename{html_file_name}{
    this->writeToFile();
}


void HTMLWatchListRepo::readFromFile() {
    ShellExecute(nullptr, "open", this->_filename.c_str(), nullptr, nullptr, SW_SHOWNORMAL);

}

void HTMLWatchListRepo::writeToFile() {
    std::fstream file(this->_filename.c_str(), std::ios::out|std::ios::trunc);

    if (file.is_open()){
        file<<"<!DOCTYPE html>\n<html>\n<head>\n<title>WATCHLIST</title>\n";
        file<<"</head>\n<body>\n<table border=\"1\">\n";

        file<<"<tr>\n";
        file<<"<td>Title</td>\n";
        file<<"<td>Genre</td>\n";
        file<<"<td>Trailer link</td>\n";
        file<<"<td>Release year</td>\n";
        file<<"<td>Number of likes</td>\n";
        file<<"</tr>\n";

        std::vector<Movie> list=this->getWatchList();
        for(const auto& movie: list){
            file<<"<tr>\n";
            file<<"<td>"<<movie.getTitle()<<"</td>\n";
            file<<"<td>"<<movie.getGenre()<<"</td>\n";
            file<<"<td>"<<movie.getTrailer()<<"</td>\n";
            file<<"<td>"<<movie.getReleaseYear()<<"</td>\n";
            file<<"<td>"<<movie.getLikesNumber()<<"</td>\n";
            file<<"</tr>\n";
        }
        file<<"</table>\n</body>\n</html>";
    }
    else {
        throw RepositoryException("Unable to open the file!\n");
    }
}

void HTMLWatchListRepo::addMovie(Movie mov, int flag) {
    WatchList::addMovie(mov, flag);
    this->writeToFile();
}

void HTMLWatchListRepo::deleteMovie(Movie mov) {
    WatchList::deleteMovie(mov);
    this->writeToFile();
}

HTMLWatchListRepo::~HTMLWatchListRepo() {

}

