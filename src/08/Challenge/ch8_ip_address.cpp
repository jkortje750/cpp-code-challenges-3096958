// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){
    // Write your code here
    bool result = false;
    int count = 0;
    std::string octet;
    std::stringstream ss(ip);
    char * end = nullptr;
    while (std::getline(ss, octet, '.')) {
        if ((!octet.empty()) && (octet.size() <= 3)) {
            int value = strtoul(octet.c_str(), &end, 10);
            if (*end == '\0') { // test first uncoverted character
                if (value <= 255) {
                    count++;
                }
            } 
        }
    }
    if (count == 4) {
        result = true;
    }

    return result;
}

// Main function
int main(){
    std::string s;
    
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;
}
