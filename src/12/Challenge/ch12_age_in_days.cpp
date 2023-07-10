// C++ Code Challenges, LinkedIn Learning

// Challenge #12: Age in Days Calculator
// Write an application that asks the user's birth date and responds with the user's age in days. 
// If the user claims to be over 120 years old, output a message calling the bluff.

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

const unsigned char month_length[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool is_leap_year(int year) {
    bool result = true;
    if (year % 4) {
        result = false; // not divisible by 4 then common year
    } else if (year % 100) {
        result = true; // not divisible by 100 then leap year
    } else if (year % 400) {
        result = false; // not divisible by 400 then common year
    }
    return result;
}  

// Age in Days, main()
// Summary: This application asks the user's birth date and prints their age in days.
int main(){
    int birth_y, birth_m, birth_d, today_y, today_m, today_d, age;

    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;
    
    if(birth_m < 1)
        birth_m = 1;
    if(birth_m > 12)
        birth_m = 12;

    // Write your code here
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    struct tm* parts = std::localtime(&now_c);
    today_y = parts->tm_year + 1900;
    today_m = parts->tm_mon + 1;
    today_d = parts->tm_mday;
    age = 0;
    int day = birth_d, month = birth_m, year = birth_y;

    while(day != today_d || month != today_m || year != today_y){
        age++;
        day++;
        if(day > month_length[month-1])
            if(month==2 && day==29 && is_leap_year(year))
                continue;
            else{
                day = 1;
                month++;
                if(month > 12){
                    month = 1;
                    year++;
                }
            }
    }
    std::cout << "\n";
    if(age < 43830)
        std::cout << "You are " << age << " days old.";
    else
        std::cout << "Come on. You can't be " << age << " days old!";
    std::cout << "\n\n" << std::flush;
}
