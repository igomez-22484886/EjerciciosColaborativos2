//
// Created by Israel on 07/10/2025.
//
#include <iostream>
#include "../include/Exercise1_StudentManagement.h"
#include "../include/StaticList.h"

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

class Student : public User {
private:
    StaticList<float> grades;

public:
    Student() {
    }

    Student(int id, std::string name, std::string surname, std::string role) {
        this->setId(id);
        this->setName(name);
        this->setSurname(surname);
        this->setRole(role);
    }

    float getAverageGrade() {
        float averageGrade = 0;
        for (const float grade: grades) {
            averageGrade += grade;
        }
        return grades.isEmpty() ? 0 : averageGrade / grades.size();
    }

    void showData() {
        cout << " - " << getName() << " " << getSurname() << " | Grade: ";
        for (float grade: grades) cout << grade << " ";
        cout << "| Average Grade: " << fixed << getAverageGrade() << endl;
    }

    void addGrade(float grade) {
        grades.insertAtEnd(grade);
    }
};

class Teacher : public User {
private:
    StaticList<Student> studentClass;
public:
    Teacher() {}

    Teacher(int id, std::string name, std::string surname, std::string role) {
        this->setId(id);
        this->setName(name);
        this->setSurname(surname);
        this->setRole(role);
    }

    void addStudent(Student &student) {
        studentClass.insertAtBeginning(student);
    }

    void showClass() {
        cout << "\nTeacher: " << getName() << " " << getSurname() << endl;
        cout << "Students number: " << studentClass.size() << endl;
        cout << "Student list:\n";
        for (Student student : studentClass) {
            student.showData();
        }
    }
};

void Exercise1_StudentManagement::run() {
    Teacher teacher(1, "Jorge", "Gonzalez", "Profesor");

    Student s1(101, "Ana", "Lopez", "Estudiante");
    s1.addGrade(8.5);
    s1.addGrade(9.0);

    Student s2(102, "Luis", "Martin", "Estudiante");
    s2.addGrade(7.5);
    s2.addGrade(6.8);

    teacher.addStudent(s1);
    teacher.addStudent(s2);

    teacher.showClass();
}

