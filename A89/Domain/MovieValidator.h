//
// Created by amina on 4/8/2021.
//

#ifndef A67_913_DIACONU_ANA_MOVIEVALIDATOR_H
#define A67_913_DIACONU_ANA_MOVIEVALIDATOR_H
#include "Movie.h"
#include "Exception/ValidationException.h"

class MovieValidator {
public:
    static void validate(const Movie&);
};


#endif //A67_913_DIACONU_ANA_MOVIEVALIDATOR_H
