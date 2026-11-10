# CIS-165 Lab 10: Lottery Simulation

## Plan

I’ll use two five-element arrays: `winningDigits` for the generated numbers and `player` for the numbers the user enters. A loop will fill the winning array with digits from `rand() % 10`, and another loop will read the player’s five digits. I’ll compare matching positions in a third loop, add one to `matches` for each equal pair, and then print both arrays and the total.

## Compile and run

From this folder, compile the program with:

```sh
g++ -std=c++17 -Wall -Wextra lottery.cpp -o lottery
```

Run it with:

```sh
./lottery
```

Enter five digits from 0 through 9, one at a time.

## Test records

The expected match counts were worked out before the tests. The final random source compiled with the command above and produced no warnings or errors. The fixed-data checks used temporary copies of the program with only the winning-digit assignment replaced by the stated fixed array; the comparison loop stayed unchanged. Those test copies were removed afterward. The actual-output entries below show the two printed arrays and the match count.

| Test data | Expected result | Actual output | Match |
| --- | --- | --- | --- |
| Fixed winning `[7, 4, 9, 1, 3]`; player `[4, 2, 9, 7, 3]` | 2 matches | `Winning digits: 7 4 9 1 3`; `Player digits: 4 2 9 7 3`; `Matches: 2` | Yes |
| Same fixed winning array; player `[7, 4, 9, 1, 3]` | 5 matches | `Winning digits: 7 4 9 1 3`; `Player digits: 7 4 9 1 3`; `Matches: 5` | Yes |
| Same fixed winning array; player `[0, 0, 0, 0, 0]` | 0 matches | `Winning digits: 7 4 9 1 3`; `Player digits: 0 0 0 0 0`; `Matches: 0` | Yes |
| Fixed winning `[1, 1, 2, 2, 3]`; player `[1, 2, 2, 3, 3]` | 3 matches | `Winning digits: 1 1 2 2 3`; `Player digits: 1 2 2 3 3`; `Matches: 3` | Yes |
| Additional: winning `[0, 3, 3, 8, 1]`; player `[0, 8, 3, 3, 9]` | 2 matches, at positions 0 and 2 | `Winning digits: 0 3 3 8 1`; `Player digits: 0 8 3 3 9`; `Matches: 2` | Yes |
| Final random run: player `[0, 1, 2, 3, 4]` | Winning digits must be 0–9; manually predicted 2 matches | `Winning digits: 0 4 6 1 4`; `Player digits: 0 1 2 3 4`; `Matches: 2` | Yes |

For the final random run, every winning digit was between 0 and 9. Comparing the arrays position by position gives matches at positions 0 (`0`) and 4 (`4`), for a total of 2. The fixed test copies were removed, and the submitted source uses `rand() % 10` again. No other temporary source changes were made.

## Explanation

`rand()` returns a non-negative integer. Dividing that value by 10 with `%` leaves a remainder from 0 through 9, so `rand() % 10` produces one digit in the required range.

The comparison loop checks `winningDigits[index]` against `player[index]`. A matching digit in a different position does not count because the two values at that index are different.

For winning digits `[7, 4, 9, 1, 3]` and player digits `[4, 2, 9, 7, 3]`, positions 0 and 1 do not match, position 2 matches, position 3 does not match, and position 4 matches. The count goes from 0 to 1 to 2.

The loops stop when `index` reaches `SIZE`, which is 5. Valid array indices are 0 through 4, so stopping before 5 avoids reading past the end. The fixed tests checked no matches, all matches, partial matches, and repeated digits at different positions.

## Course reference

The random-number approach follows Tony Gaddis et al., *Starting Out with C++: Early Objects*, 10th edition, Chapter 3, Section 3.10, “Random Numbers.”
