#include<iostream>
#include<string>
#include<regex>

// This function uses regex to replace vowels 
// the nubmers 1, 2, and 3 by the letter Z

std::string remVowelwizZ(const std::string& str) {
    std::string myString = str;
    std::regex vowels ("[aeiouAEIOU123]");

    return std::regex_replace(myString, vowels, "Z"); 
}

// The following function checks if a given email is valid
// NOTE: \w --> represents all alpha-numeric characters 
// NOTE: even if not used here \W represent all non-alphanumeric characters 
bool isEmailValid(std::string incoming) {
    //std::regex pattern (R"([a-zA-Z0-9]+@[a-zA-Z0-9]+\.[a-zA-Z]+)");
    std::regex pattern(R"([\w]+@[\w]+\.[\w]+)");    // The Rule 
    return std::regex_match (incoming, pattern);    // Regex function of apply rule 
}

// has lowercase, uppercase, digit, and a Specialcharacter min length 10
bool isPasswordStrong(std::string password) {
    if (password.length() < 10)
        return false; 

    bool hasLower = false; 
    bool hasUpper = false; 
    bool hasDigit = false;
    bool hasSpeci = false;

    for (const auto i : password) {
        if (islower(i))
            hasLower = true; 

        if (isupper(i))
            hasUpper = true; 

        if (!isalnum(i))
            hasSpeci = true;

        if (isdigit(i))
            hasDigit = true; 
            
        if (hasLower && hasUpper && hasDigit && hasSpeci)
            return true; 
    }

    return (hasLower && hasUpper && hasDigit && hasSpeci); 
}

bool isPwStrongRegex(std::string password) {
    std::regex rules(password, std::regex_constants::icase); 

     bool match = regex_match(password, rules); 
     return match; 
}

int main() {
    std::string email = "belaashu23@gmail.com";
    std::string myPassWord = "abcDE12@xcyui"; 

    std::cout << isEmailValid(email) << std::endl;
    std::cout << remVowelwizZ(email) << std::endl;
    std::cout << isPasswordStrong(myPassWord) << std::endl;

    return 0; 
}