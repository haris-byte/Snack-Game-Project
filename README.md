## ✅ Project Description

This project is a console-based Snake game implemented in C++ using a **singly linked list** to manage the snake's body. The snake grows in length when it eats food, and the game ends when the snake collides with the wall or itself. It also maintains a **high score leaderboard** saved in a file (`highscore.txt`).

Key features:

* Snake body implemented using a dynamic data structure (linked list).
* Real-time movement control using `w`, `a`, `s`, `d`.
* Food spawns randomly without overlapping the snake.
* Score tracking and persistent high score management.
* Clear screen animations using Windows API.
* Console-based user interface with board display.

---

## 📝 README.md

````markdown
# 🐍 Snake Game using Singly Linked List in C++

This is a classic Snake game developed in C++ that uses a **singly linked list** to represent the snake's body dynamically. The game runs in the Windows console and keeps track of scores, including persistent high scores stored in a text file.

---

## 🎮 Gameplay

- Move the snake using:
  - `W` - Up
  - `S` - Down
  - `A` - Left
  - `D` - Right
- Eat the food (`*`) to grow the snake.
- Avoid hitting the wall or yourself.
- High scores are saved in `highscore.txt`.

---

## 🧠 Data Structures Used

- **Singly Linked List**:
  - Each node represents one part of the snake's body.
  - New head nodes are added with every movement.
  - Tail node is removed unless the snake eats food.

---

## 💾 Features

- Console-based UI with board rendering.
- Real-time input handling using `_getch()` from `<conio.h>`.
- Random food generation that avoids overlapping with the snake.
- High score tracking with player names saved in a file.
- Clean and efficient screen rendering using Windows API (`windows.h`).

---

## 📁 Files

- `snake_game.cpp`: Main game logic and implementation.
- `highscore.txt`: Stores high scores (generated during gameplay).

---

## ▶️ Getting Started

### Prerequisites

- Windows OS (uses `<conio.h>` and `<windows.h>`)
- C++ Compiler (like g++, MinGW, or MSVC)

### Compile & Run

```bash
g++ snake_game.cpp -o snake_game
./snake_game
````

Or use any C++ IDE (e.g., Code::Blocks, Visual Studio) to build and run.

---

## 🏆 Sample Output

```
Highest Score: 12 Name: Alex
Enter to start!
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
|                            |
|             O             *|
|                            |
|                            |
|                            |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
```

---

## 🙌 Acknowledgements

* This game was developed as a personal/academic project to practice data structures and console-based game logic.

---

## 📜 License

This project is open-source and available under the [MIT License](LICENSE).

```

---

If you'd like, I can also generate:
- A `LICENSE` file (MIT or other)
- GitHub repository structure
- A preview image or GIF for the game (using ASCII board)

Let me know what else you want to enhance for GitHub!
```
