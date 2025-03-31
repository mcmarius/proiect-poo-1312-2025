//
// Created by marius on 31.03.2025.
//

#include <iostream>
#include "Student.h"

Student::Student(const std::string &nume, const std::unordered_map<std::string, int> &note): nume(nume),
    note(note) {
    std::cout << "constr init student " << nume << std::endl;
}

Student::Student(const Student &other): nume(other.nume),
                                        note(other.note),
                                        an(other.an), id(other.id) {
    std::cout << "cc student " << nume << std::endl;
}

Student & Student::operator=(const Student &other) {
    if (this == &other)
        return *this;
    nume = other.nume;
    note = other.note;
    an = other.an;
    std::cout << "op= student " << nume << std::endl;
    return *this;
}

Student::~Student() {
    std::cout << "destr student " << nume << std::endl;
}

bool Student::trece() {
    for (const auto &[nume_materie, nota]: note) {
        if (nota < 5)
            return false;
    }
    an++;
    return true;
}

std::ostream & Student::operator<<(std::ostream &os) const {
    os << "student " << nume << std::endl;
    return os;
}

std::size_t hash_value(const Student &obj) {
    std::size_t seed = 0x36E05842;
    seed ^= (seed << 6) + (seed >> 2) + 0x1E6FF02C + std::hash<std::string>{}(obj.nume);
    // seed ^= (seed << 6) + (seed >> 2) + 0x35E8E29B + std::hash{}(obj.note);
    seed ^= (seed << 6) + (seed >> 2) + 0x1B9FFE06 + static_cast<std::size_t>(obj.an);
    seed ^= (seed << 6) + (seed >> 2) + 0x751C4A44 + static_cast<std::size_t>(obj.id);
    return seed;
}

std::ostream &operator<<(std::ostream &os, const Student &student) {
    os << student.nume << ":\n";
    for (const auto &[materie, nota]: student.note) {
        os << materie << ": " << nota << "\n";
    }
    os << std::endl;
    return os;
}
