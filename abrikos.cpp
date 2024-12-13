#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    std::string id;
    std::string major;

public:
    Student(const std::string& n, const std::string& i, const std::string& m)
        : name(n), id(i), major(m) {
    }

    bool isIDValid() const {
        return id.size() == 9 && isdigit(id[0]) && isdigit(id[1]) && isdigit(id[2]) && isdigit(id[3]) &&
            id[4] == '-' && isdigit(id[5]) && isdigit(id[6]) && isdigit(id[7]) && isdigit(id[8]);
    }

    int getYear() const {
        if (isIDValid()) {
            return std::stoi(id.substr(0, 4));
        }
        else {
            throw std::invalid_argument("Invalid ID format");
        }
    }

    std::string getName() const { return name; }
    std::string getID() const { return id; }
    std::string getMajor() const { return major; }
};

int main() {
    Student s("Ivan", "2024-7745", "CS");

    std::cout << "Name: " << s.getName() << std::endl;
    std::cout << "ID: " << s.getID() << std::endl;
    std::cout << "Major: " << s.getMajor() << std::endl;

    if (s.isIDValid()) {
        std::cout << "ID is valid." << std::endl;
        std::cout << "Year: " << s.getYear() << std::endl;
    }
    else {
        std::cout << "ID is invalid." << std::endl;
    }

    return 0;
}
