#include <iostream>
#include <array>

#include <Helper.h>
#include <unordered_map>
#include <vector>

#include "Profesor.h"
#include "Student.h"

#include <iostream>

#include <iostream>

#include <iostream>
#include <ostream>

class Baza {
private: // (1)
    int x;
    void f() { std::cout << "f\n"; }

    virtual void afis(std::ostream &os) const {
    }

protected:
    int y{};
    void g() { std::cout << "g\n"; }

public:
    explicit Baza(int x_) : x(x_) {
        std::cout << "Constructor Bază: " << x << "\n";
        f();
    }

    friend std::ostream &operator<<(std::ostream &os, const Baza &baza) {
        os
                << "x: " << baza.x
                << " y: " << baza.y;
        baza.afis(os);
        os << "\n";
        return os;
    }
};

class Baza2 {
};

class Baza3 {
};

class Derivata : private Baza {
public:
    Derivata() : Baza(1) {
        //x;
        //f();
        y;
        g();
        // std::cout << "Constructor 1 Derivată: " << x << "\n"; f();
    }

private:
    int x1{};

    void f1() {
    }

protected:
    int x2{};

    void g1() {
    }

public:
    int x3{};

    void h1() {
        f1();
        g1();
    }

private:
    void afis(std::ostream &os) const override {
        const auto &derivata = *this;
        os
                << " x1: " << derivata.x1
                << " x2: " << derivata.x2
                << " x3: " << derivata.x3;
    }

public:
    Derivata(int x_, int x1, int x2)
        : Baza(x_),
          x1(x1),
          x2(x2) {
    }
};

class Der2 : protected Derivata {
    void f2() {
        // x2;
        g1();
        // x3;
        h1();
    }

    [[maybe_unused]] int q{};

public:
    Der2() = default;

    Der2(int x_, int x1, int x2, int q)
        : Derivata(x_, x1, x2),
          q(q) {
        f2();
    }
};

void k() {
    Der2 d2;
    // d2.h1();
}

class Curs {
protected:
    int nota_laborator{};
    int nota_examen{};

public:
    virtual double nota_finala() const { return nota_examen; }

    virtual ~Curs() = 0;
};

Curs::~Curs() = default;

class CursObligatoriu : public Curs {
    int bonus{};

public:
    double nota_finala() const override;
};

// double Curs::nota_finala() const {
//     return (nota_examen * 0.6 + nota_laborator * 0.4) * 0.9 + 0.1;
// }

double CursObligatoriu::nota_finala() const {
    return Curs::nota_finala() + bonus;
}

class CursOptional : public Curs {
};


class Baza1 {
protected:
    ~Baza1() {
        std::cout << "Baza1::~Baza1()\n";
    }
};

class Der1 : public Baza1 {
public:
    ~Der1() {
        std::cout << "Der1::~Der1()\n";
    }
};

int main() {
    // Curs c1;
    // CursOptional opt;
    //const Baza1& b1 = Der1{};
    //Baza1* b1 = new Der1;
    //delete b1;
    Der1 d1;
    // return 0;
    // CursObligatoriu co;
    // std::vector<int> v1{1, 2, 3}, v2{1, 2, 3, 4};
    // if (v1 == v2) {
    //     std::cout << "egali\n";
    // } else {
    //     std::cout << "nu\n";
    // }
    k();
    [[maybe_unused]] auto hsh = [](const Student &st) { return hash_value(st); };
    std::unordered_map<Student, int, decltype(hsh)> studenti;
    Student st1("abc", {{"oop", 10}}), st2{"def", {}};
    std::cout << st1 << st2 << std::endl;
    // st2 << (st1 << (std::cout));
    if (st1.trece())
        studenti[st1] = 1;
    studenti[st2] = 3;
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
