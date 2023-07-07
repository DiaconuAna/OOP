//
// Created by amina on 4/8/2021.
//

#ifndef A67_913_DIACONU_ANA_REPOSITORYEXCEPTION_H
#define A67_913_DIACONU_ANA_REPOSITORYEXCEPTION_H


#include <exception>
#include <string>

class RepositoryException : public std::exception{
private: std::string _message;
public:
    RepositoryException(const std::string& message);
    const std::string& get_message() const;

};


#endif //A67_913_DIACONU_ANA_REPOSITORYEXCEPTION_H
