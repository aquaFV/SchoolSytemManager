#include "Managers/StudentManager/StudentClass.h"
#include "Managers/SortingManager/SortingManager.h"

#include <QString>

#include <iostream>
#include <vector>

int main() {
    std::vector<Student> students;
    students.emplace_back("محمد", 1122334455, 12, 5);
    students.emplace_back("ثامر", 2233445566, 11, 2);
    students.emplace_back("عبدالعزيز", 3344556677, 10, 3);
    students.emplace_back("يوسف", 4455667788, 11, 4);

    std::cout << "Students before sorting:" << std::endl;
    for (const auto& student : students) {
        std::cout << student.get_name().toUtf8().constData() << "," << student.get_grade() << std::endl;
    }

    SortingManager::sort_students(students, "class", "ascending");

    std::cout << "Students after sorting:" << std::endl;
    for (const auto& student : students) {
        std::cout << student.get_name().toUtf8().constData() << "," << student.get_grade() << std::endl;
    }
}