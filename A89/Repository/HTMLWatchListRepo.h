//
// Created by amina on 4/18/2021.
//

#ifndef A67_913_DIACONU_ANA_HTMLWATCHLISTREPO_H
#define A67_913_DIACONU_ANA_HTMLWATCHLISTREPO_H
#include "Repository\WatchListRepository.h"


class HTMLWatchListRepo : public WatchList {
private:
    void readFromFile() override;
    void writeToFile() override;
    std::string _filename;

public:
    HTMLWatchListRepo(const std::string& repo_file_name, const std::string& html_file_name);
    void addMovie(Movie mov, int flag) override;
    void deleteMovie(Movie mov) override;
    ~HTMLWatchListRepo();
};


#endif //A67_913_DIACONU_ANA_HTMLWATCHLISTREPO_H
