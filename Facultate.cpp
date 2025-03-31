//
// Created by marius on 31.03.2025.
//

#include "Facultate.h"
#include <iostream>

Facultate::Facultate(const std::string &nume): nume(nume) {
}

Facultate::Facultate(const std::string &nume, const std::vector<Student> &studenti,
    const std::vector<Profesor> &profi): nume(nume),
                                         studenti(studenti),
                                         profi(profi) {
}

std::ostream & operator<<(std::ostream &os, const Facultate &facultate) {
    os << "nume: " << facultate.nume << " studenti: ";
    for (const auto &student: facultate.studenti) {
        // student.trece();
        os << student;
    }
    return os;
}
