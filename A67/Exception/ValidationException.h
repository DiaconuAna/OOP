//
// Created by amina on 4/8/2021.
//

#ifndef A67_913_DIACONU_ANA_VALIDATIONEXCEPTION_H
#define A67_913_DIACONU_ANA_VALIDATIONEXCEPTION_H


#include <exception>
#include <string>

class ValidationException : public std::exception{
private: std::string _message;
public:
    ValidationException(const std::string& message);
    const std::string& get_message() const;
};


#endif //A67_913_DIACONU_ANA_VALIDATIONEXCEPTION_H
