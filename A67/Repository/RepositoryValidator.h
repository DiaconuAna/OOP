//
// Created by amina on 4/9/2021.
//

#ifndef A67_913_DIACONU_ANA_REPOSITORYVALIDATOR_H
#define A67_913_DIACONU_ANA_REPOSITORYVALIDATOR_H

#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Domain\Movie.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Exception\RepositoryException.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Repository\MovieRepository.h"
#include <vector>

class RepositoryValidator {
public:
    static void validate_add(std::vector<Movie> list, Movie mov);
    static void validate_remove(std::vector<Movie> list, Movie mov);
    static void validate_update(std::vector<Movie> list, Movie mov, Movie new_mov, int flag);
};


#endif //A67_913_DIACONU_ANA_REPOSITORYVALIDATOR_H
