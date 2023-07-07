//
// Created by amina on 3/19/2021.
//

#ifndef A45_913_DIACONU_ANA_MOVIE_H
#define A45_913_DIACONU_ANA_MOVIE_H


class Movie {
private:
    char title[256];
    char genre[256];
    int release_year;
    int number_of_likes;
    char trailer_link[256];

public:
    //constructor
    Movie(char title[] = (char*)"", char genre[] = (char*)"", int release_year = 0, int number_of_likes = 0, char trailer[] = (char*)"");

    //Title getter
    char* getTitle();

    //Title setter
    void setTitle(char title[]);

    //Genre getter
    char* getGenre();

    //Genre setter
    void setGenre(char genre[]);

    //Trailer getter
    char* getTrailer();

    //Trailer setter
    void setTrailer(char trailer[]);

    //Release Year getter
    int getReleaseYear();

    //Release Year setter
    void setReleaseYear(int year);

    //Number of likes getter
    int getLikesNumber();

    //Number of likes setter
    void setLikesNumber(int value);

    //returns the print format of a movie
    void stringMovie(char* str);

    //copy constructor
    Movie (const Movie& movie);

    //assignment operator
    Movie& operator=(const Movie& movie);

    //TODO : setters
};


#endif //A45_913_DIACONU_ANA_MOVIE_H
