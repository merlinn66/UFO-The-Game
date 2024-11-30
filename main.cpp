#include <iostream>
#include <string>
#include <vector>
#include "main_functions.hpp"

int main() {
    std::vector<char> incorrect;
    std::string codeword = "codecademy";
    std::string answer = "__________";  // Initialize with underscores
    int misses = 0;
    bool guess = false;
    char letter;

    // Display the welcome message
    greet();

    // Main game loop
    while (answer != codeword && misses < 7) {
        display_misses(misses);
        display_status(incorrect, answer);

        // Player inputs their guess
        std::cout << "Please enter your guess: ";
        std::cin >> letter;

        guess = false;

        // Check if the guessed letter is in the codeword
        for (int i = 0; i < codeword.length(); i++) {
            if (codeword[i] == letter) {
                answer[i] = letter;
                guess = true;
            }
        }

        // Update game state based on guess
        if (guess) {
            std::cout << "\nCorrect!\n";
        } else {
            std::cout << "\nIncorrect! The tractor beam pulls the person in further.\n";
            incorrect.push_back(letter);
            misses++;
        }
    }

    // End the game and display the outcome
    end_game(answer, codeword);

    return 0;
}
