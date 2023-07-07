//
// Created by amina on 4/8/2021.
//

#include "ValidationException.h"

ValidationException::ValidationException(const std::string &message): std::exception(), _message{message} {
}

const std::string &ValidationException::get_message() const {
    return this->_message;
}
