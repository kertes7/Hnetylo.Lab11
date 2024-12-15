 #include <iostream> 

#include <Windows.h> 

#include <regex> 

#include <string> 

  

class Student { 

private: 

    std::string name; 

    std::string studentID; 

    std::string major; 

  

public: 

    Student(const std::string& n, const std::string& id, const std::string& m) 

        : name(n), studentID(id), major(m) { 

    } 

  

    bool isIDValid(int& year) const { 

        std::regex idPattern(R"(^\d{4}-\d{4}$)"); 

        if (std::regex_match(studentID, idPattern)) { 

            year = std::stoi(studentID.substr(0, 4)); 

            return true; 

        } 

        return false; 

    } 

  

    std::string getName() const { return name; } 

    std::string getStudentID() const { return studentID; } 

    std::string getMajor() const { return major; } 

}; 

  

int main() { 

    SetConsoleCP(1251); 

    SetConsoleOutputCP(1251); 

    Student student("Biden", "2024-6251", "Технології Цифрового Розвитку"); 

  

    int year = 0; 

    if (student.isIDValid(year)) { 

        std::cout << "Студентський ID є дійсним." << std::endl; 

        std::cout << "Рік вступу: " << year << std::endl; 

    } 

    else { 

        std::cout << "Студентський ID є недійсним." << std::endl; 

    } 

  

    return 0; 

} 
