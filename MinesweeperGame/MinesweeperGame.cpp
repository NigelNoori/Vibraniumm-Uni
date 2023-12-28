#include "MinesweeperGame.h"
#include <cstdlib>
#include <ctime>

MinesweeperGame::MinesweeperGame() : gameOver(false), remainingCells(SIZE * SIZE - NUM_MINES) {
    initializeBoard();
}

void MinesweeperGame::initializeBoard() {
    // Initialize the board with empty cells
    board.resize(SIZE, std::vector<Cell>(SIZE, {false, HIDDEN, 0}));

    // Place mines randomly on the board
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < NUM_MINES; ++i) {
        int row, col;
        do {
            row = rand() % SIZE;
            col = rand() % SIZE;
        } while (board[row][col].hasMine);

        board[row][col].hasMine = true;
    }

    // Calculate and set the number of adjacent mines for each cell
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (!board[row][col].hasMine) {
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        int newRow = row + i;
                        int newCol = col + j;
                        if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE &&
                            board[newRow][newCol].hasMine) {
                            board[row][col].adjacentMines++;
                        }
                    }
                }
            }
        }
    }
}

void MinesweeperGame::run() {
    while (!gameOver) {
        printBoard();
        handleInput();
        gameOver = isGameOver();
    }

    if (remainingCells == 0) {
        std::cout << "Congratulations! You won!\n";
    } else {
        std::cout << "Game over! You hit a mine.\n";
        revealAllMines();
        printBoard();
    }
}

void MinesweeperGame::printBoard() {
    system("clear");
    std::cout << "   ";
    for (int col = 0; col < SIZE; ++col) {
        std::cout << col << " ";
    }
    std::cout << "\n";

    for (int row = 0; row < SIZE; ++row) {
        std::cout << row << " |";
        for (int col = 0; col < SIZE; ++col) {
            char cellChar = ' ';
            if (board[row][col].state == HIDDEN) {
                cellChar = '*';
            } else if (board[row][col].state == REVEALED) {
                if (board[row][col].hasMine) {
                    cellChar = 'X';
                } else if (board[row][col].adjacentMines > 0) {
                    cellChar = '0' + board[row][col].adjacentMines;
                }
            } else if (board[row][col].state == FLAGGED) {
                cellChar = 'F';
            }
            std::cout << cellChar << " ";
        }
        std::cout << "\n";
    }
}

void MinesweeperGame::revealCell(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col].state == REVEALED) {
        return;
    }

    board[row][col].state = REVEALED;
    remainingCells--;

    if (board[row][col].adjacentMines == 0) {
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                revealCell(row + i, col + j);
            }
        }
    }
}

void MinesweeperGame::flagCell(int row, int col) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE &&
        board[row][col].state == HIDDEN) {
        board[row][col].state = FLAGGED;
    }
}

void MinesweeperGame::handleInput() {
    int row, col;
    std::cout << "Enter row and column (separated by a space): ";
    std::cin >> row >> col;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        std::string action;
        std::cout << "Enter 'R' to reveal, 'F' to flag: ";
        std::cin >> action;

        if (action == "R") {
            revealCell(row, col);
        } else if (action == "F") {
            flagCell(row, col);
        }
    }
}

bool MinesweeperGame::isGameOver() {
    if (remainingCells == 0) {
        return true;
    }

    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (board[row][col].hasMine && board[row][col].state == REVEALED) {
                return true;
            }
        }
    }

    return false;
}

void MinesweeperGame::revealAllMines() {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (board[row][col].hasMine) {
                board[row][col].state = REVEALED;
            }
        }
    }
}
