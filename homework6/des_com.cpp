#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

const std::string pattern_one = "//";
const std::string pattern_two = "/*";
const std::string pattern_three = "*/";

bool find_pattern_one(const std::string& s)
{
    return s.find(pattern_one) != -1;
}
std::string correct_with_pattern_one(std::string& s)
{
    std::reverse(s.begin(), s.end());
    size_t i = s.size() - s.find(pattern_one) - 2;
    std::reverse(s.begin(), s.end());
    return s.substr(0, i);
}

bool find_pattern_two(const std::string& s)
{
    return s.find(pattern_two) != -1;
}

bool find_pattern_three(const std::string& s)
{
    return s.find(pattern_three) != -1;
}
std::string wrong_pattern(std::string& s)
{
    while (find_pattern_two(s) and find_pattern_three(s)) {
        s = s.substr(0, s.find(pattern_two)) +
            s.substr(s.find(pattern_three) + 2, s.size());
    }
    return s;
}

int main()
{
    std::ifstream input("comments.txt");
    std::ofstream output("comments_.txt");
    std::string text;
    std::string temp;
    if (!input.is_open() or !output.is_open()) {
        std::cout << "InputError" << std::endl;
        return -1;
    }
    bool find = false;
    while (!input.eof()) {
        std::getline(input, temp);
        if (find_pattern_one(temp)) {
            temp = correct_with_pattern_one(temp);
            if (find_pattern_two(temp) and find_pattern_three(temp)) {
                temp = wrong_pattern(temp);
                output << temp << std::endl;
                continue;
            }
            output << temp << std::endl;
            continue;
        } else if (find_pattern_two(temp) and find_pattern_three(temp)) {
            output << wrong_pattern(temp) << std::endl;
        } else if (find_pattern_two(temp) or find_pattern_three(temp)) {
            if (find_pattern_two(temp)) {
                find = true;
                output << temp.substr(0, temp.find(pattern_two)) << std::endl;
            } else {
                find = false;
                output << temp.substr(temp.find(pattern_three) + 2, temp.size())
                       << std::endl;
            }
        } else if (!find) {
            output << temp;
        }
    }
    input.close();
    output.close();
    return 0;
}