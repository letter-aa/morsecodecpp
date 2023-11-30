#include <iostream>
#include <Windows.h>
#include <string>
#include <map>
#define ANY_ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
using namespace std;
string mainm = "";
map<char, string> morse_code = {
      {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
      {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
      {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
      {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
      {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
      {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {' ', "/"}
};
void morse(string str) {
    for (int a = 0; a < str.size(); a++) {
        for (auto i : morse_code) {
            char up = (char)toupper(str[a]);
            if (str[a] == i.first) {
                mainm = mainm + i.second + " ";
                break;
            }
            else if (up == i.first) {
                mainm = mainm + i.second + " ";
                break;
            }
        }
    }
}
int main()
{
    string input;
    std::getline(std::cin, input);
    morse(input);
    for (int i = 0; i < mainm.size(); i++) {
        if (mainm[i] == '.') {
            Beep(500, 1000);
        }
        if (mainm[i] == '-') {
            Beep(500, 3000);
        }
        if (mainm[i] == '/') {
            Beep(0, 1000);
        }
    }
}
