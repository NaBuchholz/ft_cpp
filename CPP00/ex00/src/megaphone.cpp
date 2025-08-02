#include <iostream>

int main(int argc, char **argv)
{
    int i = 1;
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    while (i < argc)
    {
        std::string word = argv[i];
        size_t j = -1;
        while (++j < word.length())
            word[j] = std::toupper(word[j]);
        std::cout << word;
        i++;
    };
    std::cout << std::endl;
    return (0);
};