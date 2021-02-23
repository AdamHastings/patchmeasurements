// install.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <filesystem>


// Install to "C:\\Program Files\\" + RegistryUtils::AppName + "\\"
void install() {
    std::string AppName = "HastingsExperiment";
    std::cout << "\nInstalling program...\n";
    std::filesystem::copy(AppName, "c:/Program Files/" + AppName, std::filesystem::copy_options::recursive);

    std::cout << "\n\nDone!\n\n";
}

int main()
{
    std::string s;
    // std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
    std::cout << "Thank you for participating in this experiment. To get started, you must install a computer program to your computer.\n";

    while (s != "Yes" && s != "yes" && s != "Y" && s != "y") {
        std::cout << "\nType Yes and hit Enter to install the program:\n";
        std::getline(std::cin, s);
    }

    install();

    
    system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
