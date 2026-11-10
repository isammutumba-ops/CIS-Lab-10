# AI Reflection

### Tools

I used AI to help draft `lottery.cpp`, explain how `rand() % 10` limits the digit range, and suggest fixed-array tests. I also asked it to refer to Tony Gaddis et al., *Starting Out with C++: Early Objects*, 10th edition, Chapter 3, Section 3.10. Before submitting, I’ll read through the program and test records and make sure I can explain them.

### One decision

I asked for lowercase variable names without camel case, so the code uses names like `player`, `matches`, and `digit_number`. I kept the required `winningDigits` name and used `SIZE` for the named constant. The comparison loop checks only corresponding positions, since a digit elsewhere in the array should not count as a match.

### A specific check

In the repeated-digit test, winning digits `[1, 1, 2, 2, 3]` and player digits `[1, 2, 2, 3, 3]` were expected to give 3 matches. The actual count was 3. The final random run also printed digits from 0 through 9 and a count that matched a manual position-by-position check. The program compiled with `g++ -std=c++17 -Wall -Wextra` without compiler messages.

### Learning

I learned how to coordinate multiple loops and parallel arrays to perform strict, index-by-index positional data validation I struggled and still need to practice positional checking and set membership checks in order to effectively work with arrays and loops and avoid uneccesary debugging procedures while testing my code.
