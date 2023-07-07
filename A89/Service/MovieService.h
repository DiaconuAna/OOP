//
// Created by amina on 4/3/2021.
//

#ifndef A67_913_DIACONU_ANA_MOVIESERVICE_H
#define A67_913_DIACONU_ANA_MOVIESERVICE_H
#include "Domain\Movie.h"
#include "Repository\MovieRepository.h"
#include "Repository\WatchListRepository.h"
#include "Exception\ValidationException.h"
#include "Exception\RepositoryException.h"

class MovieService {
private:
    MovieRepository* _movie_repo;
    WatchList* _user_watchlist;
public:
    //constructor
    explicit MovieService(MovieRepository& movie_repo, WatchList& watch_list);

    std::vector<Movie> getMovieList();

    /**
     * Add a movie with the given attributes
     * @param title
     * @param genre
     * @param trailer
     * @param year
     * @param likes
     */
    void addMovie(const std::string& title,const std::string& genre,const std::string& trailer, int year, int likes, int flag);

    /**
     * Remove a movie with the given attributes
     * Throws an exception if movie is not in the list
     * @param title
     * @param genre
     * @param trailer
     * @param year
     * @param likes
     */
    void removeMovie(const std::string& title,const std::string& genre,const std::string& trailer,int year, int likes);

    /**
     * Search for the position of a movie in the list
     * @param mov
     * @return the position or -1 if it doesn't exist
     */
    int searchPosition(Movie mov);


    Movie getMovie(int position);

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
    void updateTitle(Movie mov, const std::string& title);

    /**
     * Update a movie by its genre
     * Precondition: the movie must exist in the list
     * @param mov
     * @param genre
     */
    void updateGenre(Movie mov, const std::string& genre);

    /**
     * Update a movie by its trailer
     * Precondition: the movie must exist in the list
     * @param mov
     * @param trailer
     */
    void updateTrailer(Movie mov, const std::string& trailer);

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


    //user-related methods
    /**
     * Add a movie to the watchlist
      * Precondition: check if the movie has been added beforehand in the watchlist
     * @param mov
     */
    void addtoWatchList(Movie mov, int flag);

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
    std::vector<Movie> filterByGenre(const std::string& genre);


    /**
     * Returns the size of the watchlist
     * @return
     */
    int get_watchlist_size();


    /**
     * If the user rates a movie with a like, the number
     * of likes corresponding to that movie is increased
     * @param mov
     */
    void rate_movie(Movie mov);

    std::vector<Movie> getWatchList();

    void clearMovieList();
    void clearWatchList();

    void see_watchlist();

};


#endif //A67_913_DIACONU_ANA_MOVIESERVICE_H
