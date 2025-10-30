📘 Slot Machine 3x3 (C++)
🎯 Description

A simple console-based slot machine game written in C++, simulating a 3×3 slot reel system.
Each spin generates random values between 1 and 7.
If any row or either of the two diagonals contain three identical numbers, the player wins an amount calculated as:

Winning = Symbol × Bet × 2

<img width="516" height="177" alt="image" src="https://github.com/user-attachments/assets/0c38328a-f9c0-411a-a98b-f85479fd8623" /> <img width="361" height="203" alt="image" src="https://github.com/user-attachments/assets/a00046e2-52c4-447a-93b0-6b63615b6162" />

The player starts with a balance of 1000 credits, can place any bet, and continues spinning until their balance reaches zero or they exit.

⚙️ Features

🎲 Randomized 3×3 grid using rand() and srand(time(NULL))

💰 Win detection on rows and diagonals

🧮 Automatic win calculation based on symbol value and bet

🧼 Console clear for each new spin (system("cls"))

🔁 Continuous play until exit or balance depletion

🧠 Technologies & Concepts Learned

✅ C++ fundamentals – variables, loops, functions, conditionals

✅ Multidimensional arrays – passing and modifying matrices in functions

✅ Random number generation with rand() and srand(time)

✅ Procedural design – breaking code into helper and core functions

✅ Console UI basics – clearing output and formatting display

✅ Code debugging & structure improvement

🎮 How to Play
1️⃣ Start the Game

Compile and run:

g++ main.cpp -o slot
./slot        # Linux / macOS
slot.exe      # Windows


You start with a balance of 1000 credits.

2️⃣ Place Your Bet

When prompted:

Current balance: 1000
Place your bet (0 to exit):


Enter a number:

0 → exit the game

≥ 1 and ≤ your balance → the amount you want to bet

Example:

50 → places a 50-credit bet
0  → quits the game


If you enter an invalid amount, the game will ask again.

3️⃣ Spin the Reels

After placing your bet, the console clears and shows a 3×3 grid with random numbers between 1 and 7:
Each spin is completely random and independent.

4️⃣ How You Win

You win when three identical numbers appear on:

any of the three rows, or

either of the two diagonals

Payout rule (your custom logic):

Winning per line = Symbol × Bet × 2
Total win = Sum of all winning lines


Example:

Bet: 50
Winning row: 6 6 6
→ Win = 6 × 50 × 2 = 600


If multiple rows or diagonals match, the winnings add up.

5️⃣ Balance Update

Before each spin: balance -= bet
After results: balance += win

Then the game displays:

You won: <amount>
New balance: <value>


or

You lost: <bet>
New balance: <value>


You can keep playing as long as your balance > 0.
Enter 0 at any time to exit.

6️⃣ Example Sessions

🟢 Example A — Win on 2nd row:

Bet: 50

+---+---+---+
| 4 | 1 | 4 |
+---+---+---+
| 6 | 6 | 6 |   ← Winning row
+---+---+---+
| 2 | 5 | 7 |
+---+---+---+

You won: 600
New balance: 1550


🔴 Example B — No win:

Bet: 30

+---+---+---+
| 2 | 3 | 5 |
+---+---+---+
| 1 | 4 | 2 |
+---+---+---+
| 6 | 7 | 1 |
+---+---+---+

No winning lines.
You lost: 30
New balance: 970


🟢 Example C — Two winning rows:

Bet: 20

+---+---+---+
| 3 | 3 | 3 |   ← Row 1 win
+---+---+---+
| 3 | 3 | 3 |   ← Row 2 win
+---+---+---+
| 1 | 2 | 3 |
+---+---+---+

You won: 480
New balance: 1460

7️⃣ Tips & Notes

On Windows, use system("cls") to clear the console.

On Linux/macOS, use system("clear").

The code seeds randomness with the current time using srand(time(nullptr));
(Do this only once at startup.)

The display and logic are fully console-based — no external libraries required.


