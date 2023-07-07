//
// Created by amina on 4/3/2021.
//

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\UI\UI.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Service\MovieService.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Exception\RepositoryException.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Repository\FileMovieRepo.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Tests\Tests.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Repository\CSVWatchListRepo.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Repository\HTMLWatchListRepo.h"
#include <crtdbg.h>
#include <fstream>

int main()
{
   // Tests t;
   // t.testAll();
    std::string file_name1, file_name2;
    int ok = 0;

//    do{
//    std::cout<<"Input a file name for the movie list: ";
//    std::cin.clear(); std::cin.sync();
//    std::getline(std::cin, file_name1);
//    std::ifstream file(file_name1.c_str());
//    if (file.is_open()){
//        ok=1;
//        file.close();}
//    }
//    while(ok==0);
//
//    ok=0;
//    do {
//        std::cout << "Input a file name for the watch list: ";
//        std::cin.clear();
//        std::cin.sync();
//        std::getline(std::cin, file_name2);
//        std::ifstream file(file_name2.c_str());
//        if (file.is_open()){
//            ok=1;
//            file.close();}
//    }
//    while(ok==0);

    char strchoice[20];
    int choice;
    ok=0;

    /*
     *  do{
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
     */

    do{
        std::cout<<"\n 1. CSV \n 2.HTML \n";
        std::cin.clear();
        std::cin.sync();
        std::cin.get(strchoice, 19);
        std::cin.get();
        choice = atoi(strchoice);
        if (choice == 1 || choice == 2)
            ok=1;
    }
    while(ok==0);

    if (choice == 1){
        ok=0;
        do{
            std::cout<<"Input a file name for the CSV watch list: ";
            std::cin.clear(); std::cin.sync();
            std::getline(std::cin, file_name1);
            std::ifstream file(file_name1.c_str());
            if (file.is_open()){
                ok=1;
                file.close();}
        }
        while(ok==0);

        FileMovieRepo movie_repo{"movies.txt"};
        CSVWatchListRepo watch_list{"watchlist.txt",file_name1.c_str()};
        MovieService service{movie_repo, watch_list};
        UI ui{service};
        ui.menu();
    }
    else {
        ok=0;
        do{
            std::cout<<"Input a file name for the HTML watch list: ";
            std::cin.clear(); std::cin.sync();
            std::getline(std::cin, file_name1);
            std::ifstream file(file_name1.c_str());
            if (file.is_open()){
                ok=1;
                file.close();}
        }
        while(ok==0);

        FileMovieRepo movie_repo{"movies.txt"};
        HTMLWatchListRepo watch_list{"watchlist.txt",file_name1};
        MovieService service{movie_repo, watch_list};
        UI ui{service};
        ui.menu();
    }


    int r = _CrtDumpMemoryLeaks();
    printf("\n Memory leaks: %d",r);
    return 0;

}