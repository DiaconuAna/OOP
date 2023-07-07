//
// Created by amina on 3/20/2021.
//

#include "UI.h"
#include <iostream>
#include <utility>
#include <string.h>
#include <windows.h>
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Tests\MovieDatabaseTests.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Domain\DynamicVectorTemplated.h"


UI::UI(MovieRepository movie_repo, WatchList watch_list) {
    this->movie_controller = MovieController(std::move(movie_repo), std::move(watch_list));
    this->movie_controller.createEntries();
    std::cout << "You have entered administrator mode!";
}

void UI::printAdminMenu() {

    std::cout<< std::endl;
    std::cout<<"0. Exit administrator mode.\n";
    std::cout<<"1. List all the movies in the database.\n";
    std::cout<<"2. Add a movie.\n";
    std::cout<<"3. Remove a movie from the list.\n";
    std::cout<<"4. Update the title of a movie.\n";
    std::cout<<"5. Update the genre of a movie.\n";
    std::cout<<"6. Update the trailer of a movie.\n";
    std::cout<<"7. Update the release year of a movie.\n";
    std::cout<<"8. Update the number of likes of a movie.\n";
    std::cout<<"9. Run the tests.\n";
    std::cout<<std::endl;
}

void UI::updateTitle() {
    char title[100]="\0", genre[100]="\0", trailer[100], stryear[100], strlikes[100], new_title[100];
    int year, likes;
    //std::cout<<"\nInput the movie data\n";
    //std::cin.get();
    std::cout << "Input a title: ";
    std::cin.clear(); std::cin.sync();
    std::cin.get(title, 99);

    std::cout << "\n Input the new title: ";
    //std::cin.get();
    std::cin.clear(); std::cin.sync();
    std::cin.get(new_title, 99);
    std::cin.get();
    //std::cout<<title<<std::endl;
    this->movie_controller.updateTitle(Movie(title, genre, year, likes, trailer), new_title);

}

void UI::updateGenre() {
    char title[100]="\0", genre[100]="\0", trailer[100], stryear[100], strlikes[100], new_genre[100];
    int year, likes;
    //std::cout<<"\nInput the movie data\n";
    //std::cin.get();
    std::cout << "Input a title: ";
    std::cin.clear(); std::cin.sync();
    std::cin.get(title, 99);

    std::cout << "\n Input the new genre: ";
    //std::cin.get();

    std::cin.clear(); std::cin.sync();
    std::cin.get(new_genre, 99);
    std::cin.get();
    //std::cout<<title<<std::endl;
    this->movie_controller.updateGenre(Movie(title, genre, year, likes, trailer), new_genre);

}

void UI::updateTrailer() {
    char title[100]="\0", genre[100]="\0", trailer[100], stryear[100], strlikes[100], new_trailer[100];
    int year, likes;
    //std::cout<<"\nInput the movie data\n";
    //std::cin.get();
    std::cout << "Input a title: ";
    std::cin.clear(); std::cin.sync();
    std::cin.get(title, 99);

    std::cout << "\n Input the new trailer: ";
    std::cin.clear(); std::cin.sync();
    std::cin.get(new_trailer, 99);
    std::cin.get();
    //std::cout<<title<<std::endl;
    this->movie_controller.updateTrailer(Movie(title, genre, year, likes, trailer), new_trailer);

}

void UI::updateYear() {
    char title[100]="\0", genre[100]="\0", trailer[100], stryear[100], strlikes[100], new_year[100];
    int year, likes, newyear;
    //std::cout<<"\nInput the movie data\n";
    //std::cin.get();
    std::cout << "Input a title: ";

    std::cin.clear(); std::cin.sync();
    std::cin.get(title, 99);

    do {
        std::cout << "New year of release: ";
        std::cin.clear(); std::cin.sync();
        std::cin.get(new_year, 99);
        //std::cin.get();
        newyear = atoi(new_year);
    }
    while (newyear == 0);

    this->movie_controller.updateReleaseYear(Movie(title, genre, year, likes, trailer), newyear);

}

void UI::updateLikes() {
    char title[100]="\0", genre[100]="\0", trailer[100], stryear[100], strlikes[100], new_likes[100];
    int year, likes, newlikes;
    //std::cout<<"\nInput the movie data\n";
    //std::cin.get();
    std::cout << "Input a title: ";
    std::cin.clear(); std::cin.sync();
    std::cin.get(title, 99);

    do{
        std::cout<<"New number of likes: ";
        std::cin.clear(); std::cin.sync();
        std::cin.get(new_likes, 99);
        //std::cin.get();
        if(strcmp(new_likes,"0") == 0){
            likes = 0;
            break;
        }
        else{
            newlikes = atoi(new_likes);
        }
    }
    while(newlikes==0);

    this->movie_controller.updateLikes(Movie(title, genre, year, likes, trailer), newlikes);
}

void UI::listMovies() {
    char str[100][256];
    this->movie_controller.getMovieList(str);

    for (int i=0;i<this->movie_controller.controller_size(); i++){
        std::cout << str[i];
    }
}

void UI::addMovie() {
    char title[100], genre[100], trailer[100], stryear[100], strlikes[100];
    int year, likes;
    std::cout << "Input a title: ";
    std::cin.get();
    std::cin.get(title, 99);
    //std::cout<<title<<std::endl;
    std::cin.get();
    std::cout << "Choose a genre: ";
    std::cin.get(genre, 99);
    std::cin.get();
    std::cout<<"Link to a trailer: ";
    std::cin.get(trailer, 99);
    std::cin.get();
    do {
        std::cout << "Year of release: ";
        std::cin.get(stryear, 99);
        std::cin.get();
        year = atoi(stryear);
    }
    while (year == 0);

    do{
        std::cout<<"Number of likes: ";
        std::cin.get(strlikes, 99);
        std::cin.get();
        if(strcmp(strlikes,"0") == 0){
            likes = 0;
            break;
        }
        else{
            likes = atoi(strlikes);
        }
    }
    while(likes == 0);
    this->movie_controller.addMovie(title, genre, trailer, year, likes);
}

void UI::removeMovie() {
    char title[100], genre[100], trailer[100], stryear[100], strlikes[100];
    int year, likes;
    std::cout << "Input a title: ";
    std::cin.clear(); std::cin.sync();
    std::cin.get(title, 99);

    this->movie_controller.removeMovie(title, genre, trailer, year, likes);
}

void UI::runTests() {
    testAll();
}


void UI::admin_menu() {
    int command, over = 0;
    std::cout << "You have entered administrator mode!";
    //std::cout << "Hello";
    while (over == 0)
    {
        printAdminMenu();
        std::cin >> command;
        command = int(command);
        switch(command)
        {
            case 0: over = 1;
                std::cout << "Goodbye \n";
                break;
            case 1: this->listMovies();
                break;
            case 2:
                try{this->addMovie();}
                catch (const char msg[256]) {
                    std::cout<<msg<<std::endl;
                }
                break;
            case 3:
                try{this->removeMovie();}
                catch (const char msg[256]){
                    std::cout<<msg<<std::endl;
                }
                break;
            case 4:
                try{this->updateTitle();}
                catch (const char msg[256]) {
                    std::cout<<msg<<std::endl;
                }
                break;
            case 5:
                try{this->updateGenre();}
                catch (const char msg[256]) {
                    std::cout<<msg<<std::endl;
                }
                break;
            case 6:
                try{this->updateTrailer();}
                catch (const char msg[256]) {
                    std::cout<<msg<<std::endl;
                }
                break;
            case 7:
                try{this->updateYear();}
                catch (const char msg[256]) {
                    std::cout<<msg<<std::endl;
                }
                break;
            case 8:
                try{this->updateLikes();}
                catch (const char msg[256]) {
                    std::cout<<msg<<std::endl;
                }
                break;
            case 9: this->runTests();
                break;
            default: std::cout << "Please input a valid command! ";
        }
    }

}

void UI::printUserMenu() {
    std::cout<< std::endl;
    std::cout<<"0. Exit user mode.\n";
    std::cout<<"1. See the movies in the database having a given genre one by one.\n";
    std::cout<<"2. Remove a movie from the watch list\n";
    std::cout<<"3. See the watch list";
    std::cout<<std::endl;
}

void UI::user_menu() {
    int command, over = 0;
    std::cout << "You have entered user mode!";

    while (over == 0)
    {
        printUserMenu();
        std::cin >> command;
        command = int(command);
        switch(command)
        {
            case 0: over = 1;
                std::cout << "Goodbye \n";
                break;
            case 1:
                try{
                this->display_movies_by_genre();}
                catch (const char msg[256]) {
                    std::cout<<msg<<std::endl;
                }
                break;
            case 2:
                try{
                    this->removeFromWatchList();
                }
                catch (const char msg[256]) {
                    std::cout<<msg<<std::endl;
                }
                break;
            case 3:
                this->display_watch_list();
                break;
            default: std::cout << "Please input a valid command! ";
        }
    }
}


void UI::display_watch_list() {
    int list_size;
    list_size = this->movie_controller.get_watchlist_size();

    if (list_size == 0){
        std::cout <<"\n Watch list is empty- add some movies to it!\n";
        return;}


    for (int index=0;index<list_size;index++){
        Movie mov1;
        mov1 = this->movie_controller.getWatchListMovie(index);
        this->display_movie(mov1);
        std::cout<<std::endl;
    }
}


void UI::display_movie(Movie mov) {
   char str[256];
   mov.stringMovie(str);
   std::cout<<str<<std::endl;
}

void UI::display_movies_by_genre() {
   char genre[100];
   int watch_list_length, current_position;
   bool over = false;

   //WatchList genre_watch_list;
   std::cout<<"Which genre would you like to see?";
   std::cin.clear(); std::cin.sync();
   std::cin.get(genre,99);
   std::cin.clear(); std::cin.sync();
   WatchList genre_watch_list = this->movie_controller.filterByGenre(genre);
   watch_list_length = genre_watch_list.list_size();
   current_position = 0;

   while (!over){
       if(current_position == watch_list_length)
           current_position = 0;
       char str[256];
       Movie current_movie;
       current_movie = genre_watch_list.getMovie(current_position);
       current_movie.stringMovie(str);
       std::cout << str << std::endl;
       ShellExecute(NULL,"open",current_movie.getTrailer(),NULL, NULL, SW_SHOWNORMAL);
       std::cout << "Would you like to add the movie to the watch list? \n1.Yes 2.No\n";
       int cmd1;
       std::cin>>cmd1;
       if (cmd1 == 1)
           try{
           this->movie_controller.addtoWatchList(current_movie);}
           catch (const char msg[256]) {
               std::cout<<msg<<std::endl;
           }

       int cmd2;
       std::cout<<"Would you like to see the next movie in the list?\n1.Yes 2.No\n";
       std::cin>>cmd2;
       if (cmd2 == 2)
           over = true;
       else
           current_position ++;

   }

}

void UI::menu() {
   int command, over;
   do{
       std::cout<<"\n1. Administrator Mode\n2. User Mode\n";
       std::cin>>command;

       if(command == 1)
           this->admin_menu();
       else if (command == 2)
           this->user_menu();
       else std::cout<<"\nInvalid option. Try again!\n";

       std::cout<<" 1. Exit \n 2. Continue\n";
       std::cin>>over;
   }
   while(over !=1);

}

void UI::removeFromWatchList() {
    Movie mov;
    char title[100];
    std::cout << "What is the title of the movie you want to remove from the watch list?\n";
    std::cin.clear(); std::cin.sync();
    std::cin.get(title, 99);
    mov = Movie(title);

    this->movie_controller.removefromWatchList(mov);

    std::cout << "Would you like to rate a movie with a like? \n 1.Yes \n 2.No \n";

   int cmd;
   std::cin >> cmd;
   if (cmd == 1)
       this->movie_controller.rate_movie(mov);

}
