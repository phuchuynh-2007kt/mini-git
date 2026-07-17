#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem; 

int main(int argc, char* argv[]) {

    if(argc < 2) {
        std::cerr << "Using: minigit <command>\n";
        return 1; // error code
    }

    std::string command = argv[1];

    if(command == "init") {
        fs::path directoryPath = ".minigit";

        if(fs::exists(directoryPath)) {
            std::cerr << "Repository already initialized.\n";
        } else {
            fs::path objects = ".minigit/objects";
            fs::path heads = ".minigit/refs/heads";
            create_directories(heads);

            fs::path headFilePath = ".minigit/HEAD";
            std::ofstream headFile(headFilePath);
            
            if(headFile.is_open()) {
                headFile << "ref: refs/head/main\n";
                headFile.close();
                std::cout << "Initialized empty Mini-Git repository in .minigit/\n";
            }
            else {
                std::cerr << "Could not initiliaze HEAD file.\n";
                return 1;
            }
        }

    } else {
        std::cerr << "Unknown command: " << command << "\n";
    }

    return 0;
}