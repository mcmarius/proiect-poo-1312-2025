#include <iostream>
#include <array>

#include <Helper.h>
#include <ostream>
#include <unordered_map>
#include <vector>

class Student {
    std::string nume;
    std::unordered_map<std::string, int> note;

public:
    Student(const std::string &nume, const std::unordered_map<std::string, int> &note)
        : nume(nume),
          note(note) {
        std::cout << "constr init student " << nume << std::endl;
    }

    Student(const Student &other)
        : nume(other.nume),
          note(other.note) {
        std::cout << "cc student " << nume << std::endl;
    }

    Student & operator=(const Student &other) {
        if (this == &other)
            return *this;
        nume = other.nume;
        note = other.note;
        std::cout << "op= student " << nume << std::endl;
        return *this;
    }

    ~Student() {
        std::cout << "destr student " << nume << std::endl;
    }

    [[nodiscard]] const std::string & get_nume() const {
        return nume;
    }

    [[nodiscard]] const std::unordered_map<std::string, int> & get_note() const {
        return note;
    }
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

class Profesor {
    std::string nume;
    std::vector<std::string> materii;

public:
    Profesor(const std::string &nume, const std::vector<std::string> &materii)
        : nume(nume),
          materii(materii) {
    }

    friend std::ostream & operator<<(std::ostream &os, const Profesor &prof) {
        os << "nume: " << prof.nume << " materii:\n";
        for (const auto& materie : prof.materii) {
            os << materie << "\n";
        }
        return os;
    }
};

class Facultate {
    std::string nume;
    std::vector<Student> studenti;
    std::vector<Profesor> profi;

public:
    Facultate() = default;

    explicit Facultate(const std::string &nume)
        : nume(nume) {
    }

    Facultate(const std::string &nume, const std::vector<Student> &studenti,
        const std::vector<Profesor> &profi)
        : nume(nume),
          studenti(studenti),
          profi(profi) {
    }

};

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << student.nume << ":\n";
    for (const auto& [materie, nota] : student.note) {
        os << materie << ": " << nota << "\n";
    }
    os << std::endl;
    return os;
}

int main() {
    Student st1("abc", {{"oop", 10}}), st2{"def", {}};
    std::cout << st1 << st2 << std::endl;

    std::cout << "Nu mai e mult până la pauză\n";
    // operator<<(std::cout, "Nu mai e mult până la pauză\n");
    std::array<int, 100> v{};
    int nr;
    std::cout << "Introduceți nr: ";
    /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /////////////////////////////////////////////////////////////////////////
    std::cin >> nr;
    /////////////////////////////////////////////////////////////////////////
    for(int i = 0; i < nr; ++i) {
        std::cout << "v[" << i << "] = ";
        std::cin >> v[i];
    }
    std::cout << "\n\n";
    std::cout << "Am citit de la tastatură " << nr << " elemente:\n";
    for(int i = 0; i < nr; ++i) {
        std::cout << "- " << v[i] << "\n";
    }
    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];
    ///
    ///////////////////////////////////////////////////////////////////////////
    ///                Exemplu de utilizare cod generat                     ///
    ///////////////////////////////////////////////////////////////////////////
    Helper helper;
    helper.help();
    ///////////////////////////////////////////////////////////////////////////
    return 0;
}
