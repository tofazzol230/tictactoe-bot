<div align="center">

# 🎮 Tic Tac Toe Bot

[![C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Windows%20%7C%20macOS-lightgrey.svg)]()

A terminal-based Tic Tac Toe game with an **unbeatable AI bot** implemented in pure C.

```
   1 | 2 | 3
  -----------
   4 | 5 | 6
  -----------
   7 | 8 | 9
```

</div>

---

## 📋 Table of Contents

- [Features](#-features)
- [How It Works](#-how-it-works)
- [Installation](#-installation)
- [Usage](#-usage)
- [Game Rules](#-game-rules)
- [Bot Strategy](#-bot-strategy)
- [Example Gameplay](#-example-gameplay)
- [Author](#-author)
- [References](#-references)

---

## ✨ Features

| Feature | Description |
|---------|-------------|
| 🤖 Smart AI | Unbeatable bot using optimal strategy |
| 🎯 Choose Turn | Player can go first or let computer start |
| ✅ Input Validation | Handles invalid moves gracefully |
| 🖥️ Clean UI | Simple and clear terminal interface |
| ⚡ Lightweight | Single C file, no dependencies |

---

## 🧠 How It Works

The bot follows a **priority-based decision strategy**:

```
┌─────────────────────────────────────────┐
│           Bot Decision Tree             │
├─────────────────────────────────────────┤
│  1. 🏆 WIN     → Take winning move      │
│  2. 🛡️ BLOCK   → Block opponent's win   │
│  3. 🎯 CENTER  → Take center (5)        │
│  4. 📐 CORNER  → Take any corner        │
│  5. ➖ SIDE    → Take any side          │
└─────────────────────────────────────────┘
```

---

## 🔧 Installation

### Prerequisites

- GCC compiler

### Compile

```bash
gcc TicTacToe_1740.c -o tictactoe
```

---

## 🚀 Usage

### Run the Game

```bash
./tictactoe
```

### Gameplay

1. Choose who plays first (1 = You, 0 = Computer)
2. Enter position (1-9) to place your mark
3. Try to beat the bot! (Spoiler: You can't 😉)

---

## 📖 Game Rules

| Rule | Description |
|------|-------------|
| Board | 3x3 grid numbered 1-9 |
| Player | You are **X** |
| Computer | Bot is **O** |
| Win | Get 3 marks in a row (horizontal, vertical, or diagonal) |
| Draw | All 9 cells filled with no winner |

### Board Positions

```
 1 | 2 | 3
-----------
 4 | 5 | 6
-----------
 7 | 8 | 9
```

---

## 🎯 Bot Strategy

The bot uses an **optimal Tic Tac Toe strategy** that guarantees it will **never lose**:

1. **Win**: If there's a winning move, take it
2. **Block**: If opponent can win next turn, block them
3. **Center**: Take the center if available (strongest position)
4. **Corner**: Take any available corner (second strongest)
5. **Side**: Take any available side (weakest positions)

> 📚 Strategy Reference: [The Unbeatable Tic Tac Toe Strategy](https://www.esportsheaven.com/features/the-unbeatable-tic-tac-toe-strategy-never-lose-again/)

---

## 🎮 Example Gameplay

```
Welcome to Tic Tac Toe!
You are X(1), computer is O(0).
Enter 1 if you want to play first, 0 if computer should start: 1

	Current Board
	 1 | 2 | 3 
	-----------
	 4 | 5 | 6 
	-----------
	 7 | 8 | 9 
	
Enter your move (1-9): 5
Computer moves at position 1

	Current Board
	 O | 2 | 3 
	-----------
	 4 | X | 6 
	-----------
	 7 | 8 | 9 

Enter your move (1-9): 9
Computer moves at position 3

	Current Board
	 O | 2 | O 
	-----------
	 4 | X | 6 
	-----------
	 7 | 8 | X 

Enter your move (1-9): 2
Computer moves at position 8

	Current Board
	 O | X | O 
	-----------
	 4 | X | 6 
	-----------
	 7 | O | X 

Enter your move (1-9): 4
Computer moves at position 6

It's a draw!
```

---

## 📂 Project Structure

```
tictactoe_1740/
├── 📄 TicTacToe_1740.c    # Main game source code
└── 📄 README.md           # This file
```

---

## 🔍 Code Overview

| Function | Purpose |
|----------|---------|
| `printBoard()` | Display current board state |
| `isEmpty()` | Check if a position is available |
| `updateCell()` | Place a mark on the board |
| `checkWin()` | Check if a player has won |
| `findWinningMove()` | Find a winning move for a player |
| `botMove()` | AI decision making |
| `main()` | Game loop and player input |

---

## 👨‍💻 Author

<table>
  <tr>
    <td align="center">
      <strong>Md. Tofazzol Alam Rahat</strong><br>
      🎓 BSSE-1740, Section B<br>
      📚 Structured Programming Lab<br>
      🏫 Institute of Information Technology<br>
      University of Dhaka
    </td>
  </tr>
</table>

---

## 📚 References

1. **Winning Strategy**: [The Unbeatable Tic Tac Toe Strategy](https://www.esportsheaven.com/features/the-unbeatable-tic-tac-toe-strategy-never-lose-again/)
2. **Implementation Help**: ChatGPT (for multi-variable function handling with while loop)

---

## 📄 License

This project is licensed under the MIT License.

---

<div align="center">

**⭐ Star this repository if you enjoyed the game!**

Made with ❤️ for Structured Programming Lab

*Can you beat the bot? (Hint: No one can! 🤖)*

</div>
