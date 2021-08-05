// uninstall.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <filesystem>

void uninstall() {
    std::string AppName = "HastingsExperiment";
    std::cout << "\nUninstalling program...\n";
    //std::filesystem::copy(AppName, "c:/Program Files/" + AppName, std::filesystem::copy_options::recursive);
    std::filesystem::remove_all("C:/Program Files/HastingsExperiment");


    std::cout << "\n\nDone!\n\n";
}

int main()
{
    std::string s;
    // std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
    std::cout << "Thank you for your participation in this experiment. This program will uninstall the experiment from your computer. It is important that you only run this program *after* your participation in the experiment is complete, or else you may forfeit any of your earnings.\n";

    while (s != "Yes" && s != "yes" && s != "Y" && s != "y") {
        std::cout << "\nHave you already participated in this experiment? If so, type Yes and hit Enter below. If not you may close this window.\n";
        std::getline(std::cin, s);
    }

    s = "";

    while (s != "Yes" && s != "yes" && s != "Y" && s != "y") {
        std::cout << "\nDo you wish to uninstall the experiment program from your computer? If so, type Yes and hit Enter below. If not you may close this window.\n";
        std::getline(std::cin, s);
    }

    uninstall();

    std::cout << "The experiment program has been uninstalled from your computer. You may now delete this folder from your computer.\n\n";


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
