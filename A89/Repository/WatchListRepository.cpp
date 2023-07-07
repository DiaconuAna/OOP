//
// Created by amina on 4/3/2021.
//

#include "WatchListRepository.h"
#include <fstream>

WatchList::WatchList(const std::string &file_name): _file_name{file_name}{
    this->readFromFile();
}


int WatchList::list_size() {
    return this->watchlist.size();
}

int WatchList::searchMovie(Movie mov) {

    int i=0;
    for (const auto& movie: this->watchlist){
        if (mov.getTitle() == movie.getTitle())
            return i;
        i++;
    }
    return -1;
}

void WatchList::deleteMovie(Movie mov) {
    int movie_position;
    movie_position = this->searchMovie(mov);
    if (movie_position == -1)
        throw RepositoryException("Movie does not exist in the watch list!");
    else{
        this->watchlist.erase(watchlist.begin()+movie_position);
    }
}

void WatchList::addMovie(Movie mov, int flag) {
    int movie_position;
    movie_position = this->searchMovie(mov);
    if (movie_position!=-1)
        //throw RepositoryException("Movie already exists in the watch list!");
        throw RepositoryException("Movie already exists in the watch list!");
    else{
        this->watchlist.push_back(mov);
    }
    if (flag!=1)
        this->writeToFile();
}

Movie WatchList::getMovie(int position) {
    return this->watchlist[position];
}

std::vector<Movie> WatchList::getWatchList() {
    return this->watchlist;
}

void WatchList::clear_watchlist() {
    this->watchlist.clear();
}

void WatchList::writeToFile() {
    std::string file_name;
    file_name = this->_file_name;
    std::fstream file(file_name.c_str(), std::ios::out|std::ios::trunc);

    if (file.is_open()){
        std::vector<Movie> list = this->getWatchList();
        for (const auto& movie: list) {
            file << movie;
        }
        file.close();}

    else
    {
        throw RepositoryException("Unable to open the file!\n");
    }
}

const std::string &WatchList::getFileName() const {
    return this->_file_name;
}

void WatchList::setFileName(const std::string &fileName) {
    this->_file_name = fileName;
}


void WatchList::readFromFile()
{
    std::string file_name;
    file_name = this->_file_name;
    std::ifstream file(file_name.c_str());

    if (file.is_open()){
        this->clear_watchlist();
        while (!file.eof()){
            Movie m;
            file>>m;
            this->addMovie(m,1);
        }
        file.close();
        this->watchlist.erase(this->watchlist.end());
    }
    else{
        throw RepositoryException("Unable to open the file!\n");
    }

}

WatchList::~WatchList() {

}


