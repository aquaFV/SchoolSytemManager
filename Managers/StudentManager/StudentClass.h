#pragma once

#include <QString>

#include <cstdint>

class Student final {
    private:
    QString name;
    int32_t ID;
    int16_t grade;
    int16_t classNumber;
    int16_t sickLeaves;
    int16_t totalAbsences;

    public:
    Student() = default;
    template<typename T>
    Student(T&& name, const int32_t ID, const int16_t grade, const int16_t classNumber)
        : name(std::forward<T>(name)), ID(ID), grade(grade), classNumber(classNumber) {
        sickLeaves = 0;
        totalAbsences = 0;
    }

    [[nodiscard]] QString get_name() const {return name;}
    [[nodiscard]] int32_t get_ID() const {return ID;}
    [[nodiscard]] int16_t get_grade() const {return grade;}
    [[nodiscard]] int16_t get_class_number() const {return classNumber;}
    [[nodiscard]] int16_t get_sick_leaves() const {return sickLeaves;}
    [[nodiscard]] int16_t get_total_absences() const {return totalAbsences;}
};
