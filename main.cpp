#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to display the hangman based on the number of incorrect guesses
void displayHangman(int wrongGuesses) {
    switch (wrongGuesses) {
        case 0:
            cout << "   -----\n";
            cout << "   |   |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "=========\n";
            break;
        case 1:
            cout << "   -----\n";
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "=========\n";
            break;
        case 2:
            cout << "   -----\n";
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "   |   |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "=========\n";
            break;
        case 3:
            cout << "   -----\n";
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "  /|   |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "=========\n";
            break;
        case 4:
            cout << "   -----\n";
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "  /|\\  |\n";
            cout << "       |\n";
            cout << "       |\n";
            cout << "=========\n";
            break;
        case 5:
            cout << "   -----\n";
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "  /|\\  |\n";
            cout << "  /    |\n";
            cout << "       |\n";
            cout << "=========\n";
            break;
        case 6:
            cout << "   -----\n";
            cout << "   |   |\n";
            cout << "   O   |\n";
            cout << "  /|\\  |\n";
            cout << "  / \\  |\n";
            cout << "       |\n";
            cout << "=========\n";
            break;
    }
}

// Function to display the current state of the word
void displayWord(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.length(); i++) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    // List of words for the game
    vector<string> words = {"programming", "hangman", "developer", "computer", "keyboard", "software"};

    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));

    // Pick a random word
    string word = words[rand() % words.size()];
    vector<bool> guessed(word.length(), false);
    int wrongGuesses = 0;
    const int maxWrongGuesses = 6;
    char guess;
    bool correctGuess;

    cout << "Welcome to Hangman!\n";

    while (wrongGuesses < maxWrongGuesses) {
        displayHangman(wrongGuesses);
        displayWord(word, guessed);

        // Prompt the user for a guess
        cout << "\nGuess a letter: ";
        cin >> guess;

        correctGuess = false;

        for (size_t i = 0; i < word.length(); i++) {
            if (word[i] == guess && !guessed[i]) {
                guessed[i] = true;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            wrongGuesses++;
            cout << "Incorrect guess! You have " << (maxWrongGuesses - wrongGuesses) << " guesses left.\n";
        }

        // Check if the user has guessed the entire word
        bool allGuessed = true;
        for (bool letterGuessed : guessed) {
            if (!letterGuessed) {
                allGuessed = false;
                break;
            }
        }

        if (allGuessed) {
            cout << "\nCongratulations!!! You guessed my word: " << word << endl;
            return 0;
        }
    }

    displayHangman(wrongGuesses);
    cout << "\nGame Over! The word was: " << word << endl;

    return 0;
}
