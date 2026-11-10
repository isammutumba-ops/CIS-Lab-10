#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    const int SIZE = 5;
    int winningDigits[SIZE];
    int player[SIZE];
    int matches = 0;

    // Seed once so each run can use a different sequence.
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // rand() % 10 gives a digit from 0 through 9.
    for (int index = 0; index < SIZE; index++)
    {
        winningDigits[index] = std::rand() % 10;
    }

    std::cout << "Enter your five digits from 0 to 9:\n";
    for (int index = 0; index < SIZE; index++)
    {
        int digit_number = index + 1;
        std::cout << "Digit " << digit_number << ": ";
        std::cin >> player[index];
    }

    // Only digits in the same position count as matches.
    for (int index = 0; index < SIZE; index++)
    {
        if (winningDigits[index] == player[index])
        {
            matches++;
        }
    }

    std::cout << "Winning digits: ";
    for (int index = 0; index < SIZE; index++)
    {
        std::cout << winningDigits[index] << ' ';
    }
    std::cout << '\n';

    std::cout << "Player digits:  ";
    for (int index = 0; index < SIZE; index++)
    {
        std::cout << player[index] << ' ';
    }
    std::cout << '\n';

    std::cout << "Matches: " << matches << '\n';

    return 0;
}
