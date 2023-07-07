#pragma once
#ifndef A45_913_DIACONU_ANA_MOVIE_H
#define A45_913_DIACONU_ANA_MOVIE_H

#include <string>
#include <iostream>

class Movie {
private:
    std::string _title;
    std::string _genre;
    int _release_year;
    int _number_of_likes;
    std::string _trailer_link;

public:
    //constructor
    Movie();
    Movie(const std::string&, const std::string&, int, int, const std::string&);

    Movie(const Movie&m);


    //Title getter
    const std::string& getTitle() const;

    //Title setter
    void setTitle(const std::string& title);

    //Genre getter
    const std::string& getGenre() const;

    //Genre setter
    void setGenre(const std::string& genre);

    //Trailer getter
    const std::string& getTrailer() const;

    //Trailer setter
    void setTrailer(const std::string& trailer);

    //Release Year getter
    int getReleaseYear() const;

    //Release Year setter
    void setReleaseYear(int year);

    //Number of likes getter
    int getLikesNumber() const;

    //Number of likes setter
    void setLikesNumber(int value);

    //assignment operator
    Movie& operator=(const Movie& movie);

    bool operator==(const Movie&) const;
    friend std::ostream& operator<<(std::ostream&, const Movie&);
    friend std::istream& operator>>(std::istream&, Movie&);

    ~Movie();

};


#endif //A45_913_DIACONU_ANA_MOVIE_H

