//
// Created by amina on 3/20/2021.
//
#pragma once
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Controller\MovieController.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Repository\MovieRepository.h"

class UI {
private:
    MovieController movie_controller;

public:
    //constructor
    explicit UI(MovieRepository movie_repo, WatchList watch_list);

    static void printAdminMenu();
    static void printUserMenu();

    void menu();
    void admin_menu();
    void user_menu();

    void listMovies();
    void addMovie();
    void removeMovie();

    static void runTests();


    void updateTitle();
    void updateGenre();
    void updateTrailer();
    void updateYear();
    void updateLikes();


    /**
   * Display a movie's data
   */
    void display_movie(Movie mov);

    /**See the movies in the database having a given genre
     * (if the genre is empty, see all the movies), one by one.
     */
    void display_movies_by_genre();

    /**
     * See the watch list.
     */
    void display_watch_list();

    /**
     * Delete a movie from the watch list, after the user watched the movie. When deleting a movie from the watch list,
     * the user can also rate the movie (with a like), and in this case, the number of likes
     * the movie has in the repository will be increased.
     * @param mov
     */
    void removeFromWatchList();

};


