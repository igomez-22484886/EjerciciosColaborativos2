//
// Created by Israel on 07/10/2025.
//
#include <iostream>
#include "../include/Exercise1_StudentManagement.h"

class User {
private:
    int id;
    std::string name, surname, role;
public:
    User() {
    };

    User(int id, std::string name, std::string surname, std::string role) {
        this->id = id;
        this->name = name;
        this->surname = surname;
        this->role = role;
    }

    int getId() {
        return id;
    }

    std::string getName() {
        return name;
    }

    std::string getSurname() {
        return surname;
    }

    std::string getRole() {
        return role;
    }

    void setId(int id) {
        this->id = id;
    }

    void setName(std::string &name) {
        this->name = name;
    }

    void setSurname(std::string &surname) {
        this->surname = surname;
    }

    void setRole(std::string &role) {
        this->role = role;
    }
};

void Exercise1_StudentManagement::run() {
}
