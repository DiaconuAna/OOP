//
// Created by amina on 3/20/2021.
//

#include "UI.h"
#include <iostream>
#include <string>
#include <utility>
#include <cstring>
#include <windows.h>
#include <fstream>
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Tests\Tests.h"

UI::UI(MovieService& service):_service{service} {}

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
    std::cout<<"9. See the movie watchlist.\n";
    std::cout<<std::endl;
}

void UI::updateTitle() {
    std::string title, new_title;
    std::cout << "Input a title: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, title);
    std::cout << "\n Input the new title: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, new_title);
    this->_service.updateTitle(Movie(title, "", 0, -1, ""), new_title);

}

void UI::updateGenre() {
    std::string title, new_genre;

    std::cout << "Input a title: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, title);

    std::cout << "\n Input the new genre: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, new_genre);

    this->_service.updateGenre(Movie(title, "",0, -1, ""), new_genre);

}

void UI::updateTrailer() {
    std::string title, new_trailer;

    std::cout << "Input a title: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, title);

    std::cout << "\n Input the new trailer: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, new_trailer);

    this->_service.updateTrailer(Movie(title, "", 0, -1, ""), new_trailer);

}

void UI::updateYear() {
     int newyear;
     char new_year[100];
     std::string title;

     std::cout << "Input a title: ";


     std::cin.clear(); std::cin.sync();
     std::getline(std::cin, title);

    do {
        std::cout << "New year of release: ";
        std::cin.clear(); std::cin.sync();
        std::cin.get(new_year, 99);
        //std::cin.get();
        newyear = atoi(new_year);
    }
    while (newyear == 0);

    this->_service.updateReleaseYear(Movie(title,"", 0, -1, ""), newyear);

}

void UI::updateLikes() {
    char new_likes[100];
    std::string title;
    int newlikes;

    std::cout << "Input a title: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, title);

    do{
        std::cout<<"New number of likes: ";
        std::cin.clear(); std::cin.sync();
        std::cin.get(new_likes, 99);

        if(strcmp(new_likes,"0") == 0){
            newlikes = 0;
            break;
        }
        else{
            newlikes = atoi(new_likes);
        }
    }
    while(newlikes==0);

    this->_service.updateLikes(Movie(title,"", 0,-1, ""), newlikes);
}

void UI::listMovies() {

    std::vector<Movie> movieList = this->_service.getMovieList();
    for (const auto&mov: movieList){
        std::cout<<mov<<std::endl;
    }
}

void UI::addMovie() {
    char stryear[100], strlikes[100];
    std::string title, genre, trailer;
    int year, likes;
    std::cout << "Input a title: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, title);

    std::cout << "Choose a genre: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, genre);

    std::cout<<"Link to a trailer: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, trailer);

    do {
        std::cout << "Year of release: ";
        std::cin.clear(); std::cin.sync();
        std::cin.get(stryear, 99);
        std::cin.clear(); std::cin.sync();
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
    this->_service.addMovie(title, genre, trailer, year, likes,0);
}

void UI::removeMovie() {
    std::string title;
    std::cout << "Input a title: ";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, title);

    this->_service.removeMovie(title, "","",0,-1);
}

void UI::seeWatchlist() {
    this->_service.see_watchlist();
}

void UI::admin_menu() {
    int command, over = 0;
    std::string file_name;
    std::cout << "You have entered administrator mode!\n";

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
                catch (const ValidationException &ve) {
                    std::cout<<ve.get_message()<<std::endl;
                }
                catch (const RepositoryException &re){
                    std::cout<<re.get_message()<<std::endl;
                }
                break;
            case 3:
                try{this->removeMovie();}
                catch (const RepositoryException &re){
                    std::cout<<re.get_message()<<std::endl;
                }
                break;
            case 4:
                try{this->updateTitle();}
                catch (const ValidationException &ve) {
                    std::cout<<ve.get_message()<<std::endl;
                }
                catch (const RepositoryException &re){
                    std::cout<<re.get_message()<<std::endl;
                }
                break;
            case 5:
                try{this->updateGenre();}
                catch (const ValidationException &ve) {
                    std::cout<<ve.get_message()<<std::endl;
                }
                catch (const RepositoryException &re){
                    std::cout<<re.get_message()<<std::endl;
                }
                break;
            case 6:
                try{this->updateTrailer();}
                catch (const ValidationException &ve) {
                    std::cout<<ve.get_message()<<std::endl;
                }
                catch (const RepositoryException &re){
                    std::cout<<re.get_message()<<std::endl;
                }
                break;
            case 7:
                try{this->updateYear();}
                catch (const ValidationException &ve) {
                    std::cout<<ve.get_message()<<std::endl;
                }
                catch (const RepositoryException &re){
                    std::cout<<re.get_message()<<std::endl;
                }
                break;
            case 8:
                try{this->updateLikes();}
                catch (const ValidationException &ve) {
                    std::cout<<ve.get_message()<<std::endl;
                }
                catch (const RepositoryException &re){
                    std::cout<<re.get_message()<<std::endl;
                }
                break;
            case 9:
                this->seeWatchlist();
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
    std::cout<<"3. See the watch list\n";
    std::cout<<"4. See the watch list csv/html.";
    std::cout<<std::endl;
}

void UI::user_menu() {
    int command, over = 0;

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
                catch (const RepositoryException &re) {
                    std::cout<<re.get_message()<<std::endl;
                }
                break;
            case 2:
                try{
                    this->removeFromWatchList();
                }
                catch (const RepositoryException &re) {
                    std::cout<<re.get_message()<<std::endl;
                }
                break;
            case 3:
                this->display_watch_list();
                break;
            case 4:
                this->seeWatchlist();
                break;
            default: std::cout << "Please input a valid command! ";
        }
    }
}


void UI::display_watch_list() {
    int list_size;
    list_size = this->_service.get_watchlist_size();
    std::vector<Movie> watch_list = this->_service.getWatchList();

    if (list_size == 0){
        std::cout <<"\n Watch list is empty- add some movies to it!\n";
        return;}

    for (auto const& movie: watch_list){
        std::cout<<movie<<std::endl;
    }

}



void UI::display_movies_by_genre() {
    std::string genre;
    int watch_list_length, current_position;
    bool over = false;

    std::cout<<"Which genre would you like to see?";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, genre);
    std::vector<Movie> genre_watch_list = this->_service.filterByGenre(genre);

    watch_list_length = genre_watch_list.size();
    std::cout<<watch_list_length;
    current_position = 0;


    while (!over){
     if(current_position == watch_list_length)
            current_position = 0;

        Movie current_movie;
        current_movie = genre_watch_list[current_position];
        std::cout<<current_movie<<std::endl;

        ShellExecute(NULL,"open",current_movie.getTrailer().c_str(),NULL, NULL, SW_SHOWNORMAL);
        std::cout << "Would you like to add the movie to the watch list? \n1.Yes 2.No\n";
        int cmd1;
        std::cin>>cmd1;
        if (cmd1 == 1)
            try{
                this->_service.addtoWatchList(current_movie,0);}
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


void UI::removeFromWatchList() {
    Movie mov;
    std::string title;
    std::cout << "What is the title of the movie you want to remove from the watch list?\n";
    std::cin.clear(); std::cin.sync();
    std::getline(std::cin, title);
    mov = Movie(title,"",0,-1,"");

    this->_service.removefromWatchList(mov);

    std::cout << "Would you like to rate a movie with a like? \n 1.Yes \n 2.No \n";

    int cmd;
    std::cin >> cmd;
    if (cmd == 1)
        this->_service.rate_movie(mov);

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

void UI::runTests() {
    Tests t;
    t.testAll();
}


//
//void UI::readFromFile(int flag, const std::string& file_name) {
//
//    std::ifstream file(file_name.c_str());
//
//    if (file.is_open()){
//        if (flag == 1){
//        int size = this->_service.controller_size();
//        this->_service.clearMovieList();
//        while (!file.eof()){
//        Movie m;
//        file>>m;
//        //std::cout<<m<<std::endl;
//        this->_service.addMovie(m.getTitle(), m.getGenre(), m.getTrailer(), m.getReleaseYear(), m.getLikesNumber(),1);
//        //TODO : get rid of the trash read at the end
//        }
//        file.close();}
//        else
//        {
//            this->_service.clearWatchList();
//            while (!file.eof()){
//                Movie m;
//                file>>m;
//                this->_service.addtoWatchList(m,1);
//            }
//            file.close();
//        }
//    }
//    else
//    {
//        std::cout<<"Unable to open the file!\n";
//    }
//
//}

