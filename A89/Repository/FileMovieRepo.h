//
// Created by amina on 4/18/2021.
//

#ifndef A67_913_DIACONU_ANA_FILEMOVIEREPO_H
#define A67_913_DIACONU_ANA_FILEMOVIEREPO_H
#include "Repository\MovieRepository.h"
#include <fstream>

class FileMovieRepo : public MovieRepository {
private:
    std::string _file_name;
    void readFromFile();
    void writeToFile();

public:

    FileMovieRepo(const std::string& file_name);

    std::vector<Movie> getMovieList();

    int repo_size();

    void add_movie(const Movie& mov, int flag) override;

    Movie remove_movie(Movie mov) override;


    int search_movie(Movie mov) override;


    Movie update(Movie mov, Movie new_movie) override;

    Movie& getMovie(int position) override;

    void clear_list() override;


};


#endif //A67_913_DIACONU_ANA_FILEMOVIEREPO_H
