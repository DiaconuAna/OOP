//
// Created by amina on 4/18/2021.
//

#include "CSVWatchListRepo.h"
#include <windows.h>
#include <fstream>

CSVWatchListRepo::CSVWatchListRepo(const std::string& repo_file_name, const std::string& csv_file_name) : WatchList(repo_file_name), _filename{csv_file_name} {
    this->writeToFile();
}

CSVWatchListRepo::~CSVWatchListRepo() {

}

void CSVWatchListRepo::writeToFile() {
    std::fstream file(this->_filename.c_str(), std::ios::out|std::ios::trunc);

    if (file.is_open()){
        std::vector<Movie> list = this->getWatchList();
        for(const auto& movie: list){
            file<<movie.getTitle()<<","<<movie.getGenre()<<","<<movie.getTrailer()<<","<<movie.getReleaseYear()<<","<<movie.getLikesNumber()<<"\n";
        }
    }
    else {
        throw RepositoryException("Unable to open the file!\n");
    }

}

void CSVWatchListRepo::readFromFile() {
  ShellExecute(nullptr, "open", this->_filename.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

void CSVWatchListRepo::addMovie(Movie mov, int flag) {
    WatchList::addMovie(mov, flag);
    this->writeToFile();
}

void CSVWatchListRepo::deleteMovie(Movie mov) {
    WatchList::deleteMovie(mov);
    this->writeToFile();
}



