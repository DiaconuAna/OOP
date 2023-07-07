//
// Created by amina on 4/3/2021.
//
#pragma once
#ifndef A67_913_DIACONU_ANA_UI_H
#define A67_913_DIACONU_ANA_UI_H

#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Service\MovieService.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Domain\Movie.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Exception\ValidationException.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Exception\RepositoryException.h"

class UI {
private:
    MovieService& _service;

public:
    //constructor
    UI(MovieService& service);

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
    void seeWatchlist();


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





#endif //A67_913_DIACONU_ANA_UI_H
