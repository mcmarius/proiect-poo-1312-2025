//
// Created by marius on 31.03.2025.
//

#ifndef PROFESOR_H
#define PROFESOR_H
#include <string>
#include <vector>


class Profesor {
    std::string nume;
    std::vector<std::string> materii;
public:
    Profesor(const std::string &nume, const std::vector<std::string> &materii);
    friend std::ostream &operator<<(std::ostream &os, const Profesor &prof);
};



#endif //PROFESOR_H
