#pragma once
#include <vector>
#include "../StudentManager/StudentClass.h"

namespace SortingManager {
    void sort_students(std::vector<Student>& students, const std::string& orderBy,
                       const std::string& order);
}