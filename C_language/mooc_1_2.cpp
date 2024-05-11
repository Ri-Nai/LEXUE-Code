#include <string>
#include <iostream>
int main()
{
    std::string s, t1, t2;
    std::getline(std::cin, s);
    std::getline(std::cin, t1);
    std::getline(std::cin, t2);
    int pos = 0;
    while ((pos = s.find(t1, 0)) != -1)
        s.replace(pos, t1.length(), t2);
    std::cout << s << std::endl;
}
