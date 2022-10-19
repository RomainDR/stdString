#include <iostream>
#include "String.h"

int main()
{
    String name = "Romain";
    String text = "Hello World !";
    String _split = "Je,suis,quelqu'un";
    std::vector<String> _splited = _split.Split(',');

    std::cout << "Contains: "<< (text.Contains("World") ? "Oui" : "Non") << std::endl;
    std::cout << "Contains: " << (text.Contains("stst") ? "Oui" : "Non") << std::endl;
    for (String _part : _splited)
        std::cout << _part << std::endl;
    std::cout << text.ToLower() << std::endl;
    std::cout << name.ToUpper() << std::endl;
    std::cout << text.SubString(5) << std::endl;
    std::cout << text.SubString(2, 4) << std::endl;
    std::cout << text.Replace('!', '?') << std::endl;
    std::cout << text.Trim() << std::endl;
    std::cout << "Last Index of 'o' " << text.LastIndexOf('o') << std::endl;
    std::cout << "First Index of 'o' " << text.FirstIndexOf('o') << std::endl;
    std::cout << "Empty or null: " << (name.IsNullOrEmpty() ? "Oui" : "Non") << std::endl;
    std::cout << text.Join({ "I'm here." }) << std::endl;
   
}