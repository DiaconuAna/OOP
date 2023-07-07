//
// Created by amina on 4/8/2021.
//

#include "MovieValidator.h"

void MovieValidator::validate(const Movie &mov) {

    std::string errors="";
    if (mov.getLikesNumber()<0)
        errors+="\n Likes number should be positive...";
    if (mov.getReleaseYear()<1850)
        errors+="\n Movies didn't exist back then. Better luck next time!";
    if(mov.getTitle()=="")
        errors+="\n A movie cannot have an empty title!";
    if(mov.getGenre()=="")
        errors+="\n Your movie should belong to a genre!";
    if(mov.getTrailer()=="")
        errors+="\n Your movie should have a trailer!";
    if (errors.size()!=0)
        throw ValidationException(errors);
}
