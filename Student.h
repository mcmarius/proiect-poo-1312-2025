//
// Created by marius on 31.03.2025.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <iosfwd>
#include <unordered_map>


class Student {
    std::string nume;
    std::unordered_map<std::string, int> note;
    int an{1};
    const int id = 1;

public:
    friend std::size_t hash_value(const Student &obj);
    bool operator==(const Student &) const = default;
    bool operator!=(const Student &) const = default;

    Student() = default;
    Student(const std::string &nume,
            const std::unordered_map<std::string,
                int> &note);
    Student(const Student &other);
    Student &operator=(const Student &other);
    ~Student();

    friend std::ostream &operator<<(std::ostream &os, const Student &student);
    bool trece();
    std::ostream &operator<<(std::ostream &os) const;
};

std::size_t hash_value(const Student &obj);


#endif //STUDENT_H
