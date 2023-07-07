#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Controller\MovieController.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Repository\MovieRepository.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Domain\Movie.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Domain\DynamicVectorTemplated.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Repository\WatchListRepository.h"
#include <iostream>
#include <assert.h>
#include <string.h>

void testAdmin(){

    //std::cout<<"Hello";
    MovieRepository movie_repo;
    //std::cout<<"Hello";
    MovieController movie_controller(movie_repo);


    Movie m1;
    DynamicVectorTemplated<Movie> v1, v2;
    char str[100][256];
    int position;
    //add movies
    movie_controller.addMovie((char*)"Witcher",(char*)"Fantasy",(char*)"trailer1",2000,15);
    movie_controller.addMovie((char*)"Fury",(char*)"War",(char*)"trailer2",2010,19);
    movie_controller.addMovie((char*)"Ophelia",(char*)"Drama",(char*)"trailer3",2019,10);
    assert(movie_controller.controller_size()==3);
    //try to add a movie that already exists
    try{
        movie_controller.addMovie((char*)"Witcher",(char*)"Fantasy",(char*)"trailer1",2000,15);}
    catch (char const msg[100])
    { // std::cout<<"Bonjour\n";
        assert(strcmp(msg,"Movie title must be unique! Please try again!") == 0);
    }
    //remove a movie
    movie_controller.removeMovie((char*)"Witcher",(char*)"Fantasy",(char*)"trailer1",2000,15);
    assert(movie_controller.controller_size()==2);

    v1 = *movie_controller.get_controller_list();
    v2 = v1;
    assert(strcmp(v1[0].getTitle(),"Ophelia") == 0);

    //try to remove a movie that is not in the list
    try {
        movie_controller.removeMovie((char*)"Witcher",(char*)"Fantasy",(char*)"trailer1",2000,15);
    }
    catch (char const msg[100]) {
        assert(strcmp(msg,"Movie not found in the list!") == 0);
    }

    //try to access a movie whose index is invalid
    try{
        strcmp(v1[56].getTitle(),"Ophelia");
    }
    catch (char const msg[100]){
        assert(strcmp(msg,"\n Invalid index - out of bounds! \n") == 0);
    }

    //update a movie
    //update the title of an already existing movie
    movie_controller.updateTitle(Movie((char*)"Ophelia",(char*)"Drama",2019,10,(char*)"trailer3"), (char*)"Hamlet");
    position = movie_controller.searchPosition(Movie((char*)"Hamlet",(char*)"Drama",2019,10,(char*)"trailer3"));
    v1 = *movie_controller.get_controller_list();
    assert(strcmp(v1[position].getTitle(),"Hamlet") == 0);

    //update a movie with a title that already exists in the list
    try{
        movie_controller.updateTitle(Movie((char*)"Hamlet",(char*)"Drama",2019,10,(char*)"trailer3"), (char*)"Fury");
    }
    catch (char const msg[100])
    {
        assert(strcmp(msg,"Movie title must be unique! Please try again!") == 0);
    }
    //update the title of a movie that is not in the list
    try{
        movie_controller.updateTitle(Movie((char*)"Oph",(char*)"Drama",2019,10,(char*)"trailer3"), (char*)"Fury");
    }
    catch (char const msg[100])
    {
        assert(strcmp(msg,"Movie not found in the list!") == 0);
    }

    //update the genre of a movie
    movie_controller.updateGenre(Movie((char*)"Hamlet",(char*)"Drama",2019,10,(char*)"trailer3"), (char*)"History");
    position = movie_controller.searchPosition(Movie((char*)"Hamlet",(char*)"History",2019,10,(char*)"trailer3"));
    v1 = *movie_controller.get_controller_list();
    assert(strcmp(v1[position].getGenre(),"History") == 0);

    //update the genre of a movie that is not in the list
    try{
        movie_controller.updateGenre(Movie((char*)"Oph",(char*)"Drama",2019,10,(char*)"trailer3"), (char*)"Romance");
    }
    catch (char const msg[100])
    {
        assert(strcmp(msg,"Movie not found in the list!") == 0);
    }

    //update the trailer of a movie
    movie_controller.updateTrailer(Movie((char*)"Hamlet",(char*)"Drama",2019,10,(char*)"trailer3"), (char*)"trailer");
    position = movie_controller.searchPosition(Movie((char*)"Hamlet",(char*)"History",2019,10,(char*)"trailer3"));
    v1 = *movie_controller.get_controller_list();
    assert(strcmp(v1[position].getTrailer(),"trailer") == 0);


    //update the trailer of a movie that is not in the list
    try{
        movie_controller.updateTrailer(Movie((char*)"Oph",(char*)"Drama",2019,10,(char*)"trailer3"), (char*)"trailer");
    }
    catch (char const msg[100])
    {
        assert(strcmp(msg,"Movie not found in the list!") == 0);
    }

    //update the release year of a movie
    movie_controller.updateReleaseYear(Movie((char*)"Hamlet",(char*)"Drama",2019,10,(char*)"trailer3"), 2004);
    position = movie_controller.searchPosition(Movie((char*)"Hamlet",(char*)"History",2019,10,(char*)"trailer3"));
    v1 = *movie_controller.get_controller_list();
    assert(v1[position].getReleaseYear() == 2004);


    //update the release year of a movie that is not in the list
    try{
        movie_controller.updateReleaseYear(Movie((char*)"Oph",(char*)"Drama",2019,10,(char*)"trailer3"), 2091);
    }
    catch (char const msg[100])
    {
        assert(strcmp(msg,"Movie not found in the list!") == 0);
    }

    //update the number of likes of a movie
    movie_controller.updateLikes(Movie((char*)"Hamlet",(char*)"Drama",2019,10,(char*)"trailer3"), 24);
    position = movie_controller.searchPosition(Movie((char*)"Hamlet",(char*)"History",2019,10,(char*)"trailer3"));
    v1 = *movie_controller.get_controller_list();
    assert(v1[position].getLikesNumber() == 24);
   DynamicVectorTemplated<Movie>v5 = v1;

    //update the number of likes of a movie that is not in the list
    try{
        movie_controller.updateLikes(Movie((char*)"Oph",(char*)"Drama",2019,10,(char*)"trailer3"), 7);
    }
    catch (char const msg[100])
    {
        assert(strcmp(msg,"Movie not found in the list!") == 0);
    }

    movie_controller.createEntries();
    assert(movie_controller.controller_size() == 12);

    movie_controller.getMovieList(str);
    std::cout << "Admin tests ran successfully!\n";
}

void testUser(){


    MovieRepository movie_repo;
    WatchList watch_list;
    MovieController controller(movie_repo, watch_list);
    controller.createEntries();
    assert(controller.controller_size() == 10);
    assert(controller.get_watchlist_size() == 0);

    WatchList genre_list1 = controller.filterByGenre((char*)"War");
    assert(genre_list1.list_size() == 4);

    WatchList genre_list2 = controller.filterByGenre((char*)"-");
    assert(genre_list2.list_size() == 10);

    //try to find movies of a bogus genre
    try{
        WatchList genre_list3 = controller.filterByGenre((char*)"ihjh");
    }
    catch (char const msg[100])
    {
        assert(strcmp(msg,"No movie has the given genre!") == 0);
    }


    controller.addtoWatchList(Movie((char*)"Inglorious Basterds",(char*)"War",2009,12,(char*)"https://www.youtube.com/watch?v=KnrRy6kSFF0"));
    assert(controller.get_watchlist_size() == 1);

    //try to add a movie that has already been added before
    try{
        controller.addtoWatchList(Movie((char*)"Inglorious Basterds",(char*)"War",2009,12,(char*)"https://www.youtube.com/watch?v=KnrRy6kSFF0"));
    }
    catch (char const msg[100])
    {
        assert(strcmp(msg,"Movie already exists in the watch list!") == 0);
    }
    assert(controller.get_watchlist_size() == 1);

    Movie mov1;
    mov1 = controller.getMovie(0);
    assert(strcmp(mov1.getTitle(),"Ghosts") == 0);

    mov1 = controller.getWatchListMovie(0);
    assert(strcmp(mov1.getTitle(),"Inglorious Basterds") == 0);

    //remove a movie from the watch list and also rate it with a like
    controller.removefromWatchList(Movie((char*)"Inglorious Basterds"));
    controller.rate_movie(Movie((char*)"Inglorious Basterds"));

    //try to remove a movie that does not exist in the watch list
    try{
        controller.removefromWatchList(Movie((char*)"djdjd"));
    }
    catch (char const msg[100])
    {
        assert(strcmp(msg,"Movie does not exist in the watch list!") == 0);
    }


    std::cout << "User tests have ran successfully!\n";
}

void testAll(){
    testAdmin();
    testUser();
}