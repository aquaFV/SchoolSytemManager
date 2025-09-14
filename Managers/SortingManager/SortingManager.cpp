#include "SortingManager.h"
#include "../StudentManager/StudentClass.h"

#include <QString>

#include <algorithm>
#include <iostream>
#include <vector>

void SortingManager::sort_students(std::vector<Student> &students, const std::string &orderBy, const std::string &order) {
    if (order == "ascending") {
        if (orderBy == "name") {
            std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.get_name().localeAwareCompare(b.get_name()) < 0;
            });
        }
        else if (orderBy == "grade") {
            std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.get_grade() < b.get_grade();
            });
        }
        else if (orderBy == "class") {
            sort_students(students, "grade", "ascending");
            std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.get_class_number() < b.get_class_number();
            });
        }
    }
    else if (order == "descending") {
        if (orderBy == "name") {
            std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.get_name().localeAwareCompare(b.get_name()) > 0;
            });
        }
        else if (orderBy == "grade") {
            std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.get_grade() > b.get_grade();
            });
        }
        else if (orderBy == "class") {
            sort_students(students, "grade", "descending");
            std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.get_class_number() > b.get_class_number();
            });
        }
    }
    else {
        std::cerr << "Invalid sort order!" << std::endl;
    }
}
