//
// Created by amina on 4/9/2021.
//

#include "RepositoryValidator.h"

void RepositoryValidator::validate_add(std::vector<Movie> list, Movie mov) {
    std::string errors="";
    int i=0,position=-1;

    for(const auto&movie: list){
        if(mov.getTitle() == movie.getTitle()){
            position = i;
            break;}
        i++;}
    if (position!=-1)
        errors+="\nMovie title must be unique! Please try again!";
//    if(position == -1)
//        errors+="\nMovie not found in the list!";
    if(errors.size()!=0)
        throw RepositoryException(errors);
}

void RepositoryValidator::validate_remove(std::vector<Movie> list, Movie mov) {
    std::string errors="";
    int i=0,position=-1;

    for(const auto&movie: list){
        if(mov.getTitle() == movie.getTitle()){
            position = i;
            break;}
        i++;}
//    if (position!=-1)
//        errors+="\nMovie title must be unique! Please try again!";
    if(position == -1)
        errors+="\nMovie not found in the list!";
    if(errors.size()!=0)
        throw RepositoryException(errors);

}

void RepositoryValidator::validate_update(std::vector<Movie> list, Movie mov, Movie new_mov, int flag) {
    std::string errors="";
    int i=0,position=-1;

    for(const auto&movie: list){
        if(mov.getTitle() == movie.getTitle()){
            position = i;
            break;}
        i++;}

    if(position == -1)
        errors+="\nMovie not found in the list!";

    position = -1;
    i=0;

    for(const auto&movie: list){
        if(new_mov.getTitle() == movie.getTitle()){
            position = i;
            break;}
        i++;}

    if (position!=-1 && flag == 1)
        errors+="\nMovie title must be unique! Please try again!";
    if(errors.size()!=0)
        throw RepositoryException(errors);

}

