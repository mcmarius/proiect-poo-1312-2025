//
// Created by marius on 31.03.2025.
//

#ifndef FACULTATE_H
#define FACULTATE_H
#include <string>
#include <vector>

#include "Profesor.h"
#include "Student.h"


class Facultate {
    std::string nume;
    std::vector<Student> studenti;
    std::vector<Profesor> profi;

public:
    Facultate() = default;

    explicit Facultate(const std::string &nume);

    Facultate(const std::string &nume, const std::vector<Student> &studenti,
              const std::vector<Profesor> &profi);

    friend std::ostream &operator<<(std::ostream &os, const Facultate &facultate);
};



#endif //FACULTATE_H
