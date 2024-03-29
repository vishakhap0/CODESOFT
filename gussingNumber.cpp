#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Welcome to the Guessing Game!" << endl;
    cout << "I have chosen a number between 1 and 100. Can you guess what it is?" << endl;

    // Loop until the user guesses the correct number
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number (" << randomNumber << ") in " << attempts << " attempts!" << endl;
        }
    } while (guess != randomNumber);

    return 0;
}
