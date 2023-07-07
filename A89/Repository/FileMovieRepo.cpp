//
// Created by amina on 4/18/2021.
//

#include "FileMovieRepo.h"


FileMovieRepo::FileMovieRepo(const std::string &file_name): MovieRepository(), _file_name{file_name}{
    this->readFromFile();
}



void FileMovieRepo::writeToFile() {
    std::string filename;
    filename = this->_file_name;
    std::fstream file(filename.c_str(), std::ios::out|std::ios::trunc);

    if (file.is_open()){
        file<<this->repo_size();
        std::vector<Movie> list = this->getMovieList();
        for (const auto& movie: list) {
            file << movie;
        }

        file.close();
    }
    else
    {
        throw RepositoryException("Unable to open the file!\n");
    }
}


void FileMovieRepo::readFromFile() {

    //std::cout<<"Before opening\n";
    std::ifstream file(this->_file_name.c_str());
    int number;
    //std::cout<<"Before opening\n";

    if (file.is_open()){
        //std::cout<<"After opening\n";
        //file>>number;
        //std::cout<<number<<std::endl;
        this->clear_list();
        while(!file.eof()){
            Movie m;
            file>>m;
            //std::cout<<m;

            this->add_movie(Movie(m.getTitle(), m.getGenre(), m.getReleaseYear(), m.getLikesNumber(),m.getTrailer()),1);
            //std::cout<<m;

            //TODO : get rid of the trash read at the end
        }
        this->movie_repository.erase(movie_repository.end());
        file.close();}
    else
    {
        throw RepositoryException("Unable to open the file!\n");
    }

}

std::vector<Movie> FileMovieRepo::getMovieList() {
    //this->readFromFile();
    return MovieRepository::getMovieList();
}

int FileMovieRepo::repo_size() {
    return MovieRepository::repo_size();
}

void FileMovieRepo::add_movie(const Movie& mov, int flag) {
    //this->readFromFile();
    //std::cout<<"File repo here\n";
    MovieRepository::add_movie(mov,1);
    if (flag != 1){
        this->writeToFile();
    }
}

Movie FileMovieRepo::remove_movie(Movie mov) {
    Movie m;
    // this->readFromFile();
    //std::cout<<"File repo here\n";
    m=MovieRepository::remove_movie(mov);
    this->writeToFile();
    return m;
}

int FileMovieRepo::search_movie(Movie mov) {
    // this->readFromFile();
    return MovieRepository::search_movie(mov);
}

Movie FileMovieRepo::update(Movie mov, Movie new_movie) {
    Movie m;
    // this->readFromFile();
    m=MovieRepository::update(mov, new_movie);
    this->writeToFile();
    return m;
}

Movie &FileMovieRepo::getMovie(int position) {
    // this->readFromFile();
    return MovieRepository::getMovie(position);
}

void FileMovieRepo::clear_list() {
    MovieRepository::clear_list();
}
