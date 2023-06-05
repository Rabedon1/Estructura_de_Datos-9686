#pragma once

#include <string>
#include <iostream>

class Modelo {
public:
    Modelo(int id) : _id(id) {}

    int getId() const {
        return _id;
    }

    void setId(int id) {
        _id = id;
    }

    virtual std::string csv() = 0;
    virtual void imprimir(std::ostream&) = 0;
    friend std::ostream& operator<<(std::ostream& out, Modelo& m) {
        m.imprimir(out);
        return out;
    }

private:
    int _id = 0;
};
