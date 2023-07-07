//
// Created by amina on 3/19/2021.
//

#ifndef A45_913_DIACONU_ANA_MOVIEREPOSITORY_H
#define A45_913_DIACONU_ANA_MOVIEREPOSITORY_H
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Domain\Movie.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Domain\DynamicVectorTemplated.h"
class MovieRepository {
private:
   DynamicVectorTemplated<Movie> movie_repository;
public:
    /**
     * Constructor of the repository
     * @param movie_repository
     */
    //explicit MovieRepository(DynamicVector* movie_repository);
    MovieRepository();

    /**
     * Return the number of elements currently stored in the repo
     * @return
     */
    int repo_size();

    DynamicVectorTemplated<Movie>* get_repo_list();

    /**
     * Add a movie to the repository
     * @param mov
     */
    void add_movie(Movie mov);

    /**
     * Remove a movie from the repository
     * @param mov
     */
    void remove_movie(Movie mov);

    /**
     * Search a movie in the list and return its position
     * @param mov
     * @return position, else -1 if not in the list
     */
    int search_movie(Movie mov);

    /**
     * Update the title of a movie
     * @param mov
     * @param title
     */
    void update(Movie mov, Movie new_movie);


    /**
    * Get a list of strings representing
    * the details of each movie
    * @param str
    */
    void getMovieList(char str[][256]);

    /**
     * Check if a movie with a given title exists in the list
     * @param mov
     * @return
     */
    int getMovieStatus(char* title);

    /**
     * Get a movie instance from a given position
     * @param position
     * @return
     */
    Movie getMovie(int position);

};


#endif //A45_913_DIACONU_ANA_MOVIEREPOSITORY_H
