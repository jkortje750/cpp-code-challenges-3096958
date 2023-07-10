// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main(){
    std::fstream file ("names.csv", std::ios::in);
    std::vector<std::string> fullnames;
    // Read the CSV file.
    if(file.is_open()){
        std::string name;
        // Write your code here
        while (std::getline(file, name, ',')) {
            fullnames.push_back(name);
        }
    
        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    // Write your code here
    if (!fullnames.empty()) {
        std::unordered_map<std::string, std::vector<std::string>> relatives;
        for (auto name : fullnames) {
            if (name.size() == 2) {
                std::istringstream ss(name);
                std::string firstname;
                std::string lastname;
                ss >> firstname >> lastname;
                relatives[lastname].push_back(firstname);
            }
        }
        for (auto it = relatives.begin(); it != relatives.end(); ++it) {
            if (it->second.size() > 1) {
                std::cout << it->second[0] << " " << it->first << " may be related to ";
                std::cout << it->second[1] << " " << it->first << std::endl;
            }
        }
    } else {
        std::cout << "No relatives found.\n\n" << std::flush;
    }    
    return 0;
}
 