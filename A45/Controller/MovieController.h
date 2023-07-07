//
// Created by amina on 3/19/2021.
//

#ifndef A45_913_DIACONU_ANA_MOVIECONTROLLER_H
#define A45_913_DIACONU_ANA_MOVIECONTROLLER_H
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Controller\MovieController.h"
#include "../Repository/MovieRepository.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Domain\DynamicVectorTemplated.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Repository\WatchListRepository.h"


class MovieController {
private:

    MovieRepository movie_controller;
    WatchList user_watchlist;
    int current_index_wl;
public:
    //constructor
    explicit MovieController(MovieRepository movie_repo = MovieRepository(), WatchList watch_list = WatchList(), int index = 0);

    /**
     * Add a movie with the given attributes
     * @param title
     * @param genre
     * @param trailer
     * @param year
     * @param likes
     */
    void addMovie(char* title, char* genre, char* trailer,int year, int likes);

    /**
     * Remove a movie with the given attributes
     * Throws an exception if movie is not in the list
     * @param title
     * @param genre
     * @param trailer
     * @param year
     * @param likes
     */
    void removeMovie(char* title, char* genre, char* trailer,int year, int likes);

    /**
     * Search for the position of a movie in the list
     * @param mov
     * @return the position or -1 if it doesn't exist
     */
    int searchPosition(Movie mov);

    /**
     * Get a list of strings representing
     * the details of each movie
     * @param str
     */
    void getMovieList(char str[][256]);

    Movie getMovie(int position);

    DynamicVectorTemplated<Movie>* get_controller_list();

    /**
     * Get the number of elements the controller is working on
     * @return
     */
    int controller_size();

    /**
     * Update a movie by its title
     * Preconditions: the movie must exist in the list and the title must not be used for another movie
     * @param mov
     * @param title
     */
    void updateTitle(Movie mov, char* title);

    /**
     * Update a movie by its genre
     * Precondition: the movie must exist in the list
     * @param mov
     * @param genre
     */
    void updateGenre(Movie mov, char* genre);

    /**
     * Update a movie by its trailer
     * Precondition: the movie must exist in the list
     * @param mov
     * @param trailer
     */
    void updateTrailer(Movie mov, char* trailer);

    /**
     * Update a movie by its release year
     * Precondition: the movie must exist in the list
     * @param mov
     * @param year
     */
    void updateReleaseYear(Movie mov, int year);

    /**
     * Update a movie by its number of likes
     * Precondition: the movie must exist in the list
     * @param mov
     * @param likes
     */
    void updateLikes(Movie mov, int likes);

    /**
     * Storing 10 entities in the memory repo
     */
    void createEntries();

    /**
     * Check if a movie with a given title exists in the list
     * @param mov
     * @return -1 if the movie DOES NOT exist, else its position in the list
     */
   int getMovieStatus(char* title);

   //user-related methods
   /**
    * Add a movie to the watchlist
     * Precondition: check if the movie has been added beforehand in the watchlist
    * @param mov
    */
   void addtoWatchList(Movie mov);

    /**
     * Remove a movie from the watch list
     * Precondition: check if the movie exists in the watchlist
     * @param mov
     */
   void removefromWatchList(Movie mov);


   /**
    * Filter the movies from the watchlist based on a given genre
    * @param genre
    * @return
    */
   WatchList filterByGenre(char genre[]);


   /**
    * Returns the size of the watchlist
    * @return
    */
   int get_watchlist_size();

   /**
    * Gets the movie from the given position in the watch list
    * @param position
    * @return
    */
   Movie getWatchListMovie(int position);

   /**
    * If the user rates a movie with a like, the number
    * of likes corresponding to that movie is increased
    * @param mov
    */
   void rate_movie(Movie mov);


};


#endif //A45_913_DIACONU_ANA_MOVIECONTROLLER_H
