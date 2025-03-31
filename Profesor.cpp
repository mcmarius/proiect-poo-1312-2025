//
// Created by marius on 31.03.2025.
//

#include <iostream>
#include "Profesor.h"

Profesor::Profesor(const std::string &nume, const std::vector<std::string> &materii): nume(nume),
    materii(materii) {
}

std::ostream & operator<<(std::ostream &os, const Profesor &prof) {
    os << "nume: " << prof.nume << " materii:\n";
    for (const auto &materie: prof.materii) {
        os << materie << "\n";
    }
    return os;
}
