#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem;

int main() {
    std::cout << "Hi! Wait a little before cleaning the files...\n";

    char* localAppDataEnv = std::getenv("LOCALAPPDATA");

    if (localAppDataEnv == nullptr) {
        std::cout << "Could not find system variable LOCALAPPDATA!" << std::endl;
        return 1;
    }

    std::filesystem::path fullPath = localAppDataEnv;

    fullPath /= "Rockstar Games";
    fullPath /= "Launcher";
    fullPath /= "download_cache";

    if (!fs::exists(fullPath)) { 
        std::cout << "A mistake! download_cache folder not found on your PC\n";
    } else {
        std::cout << "Success! Path found: " << fullPath.string() << "\n";
        
        try {
            fs::remove_all(fullPath);
            fs::create_directories(fullPath);
            std::cout << "Success! Cache cleared successfully.\n";
        } 
        catch (const fs::filesystem_error& e) {
            std::cout << "Error! Could not delete files. Please close Rockstar Games Launcher and try again.\n";
        }
    }

    system("pause");

    return 0;
}