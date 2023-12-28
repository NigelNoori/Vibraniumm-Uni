#ifndef MINESWEEPERGAME_H
#define MINESWEEPERGAME_H

#include <iostream>
#include <vector>

class MinesweeperGame {
public:
    MinesweeperGame();
    void run();

private:
    static const int SIZE = 10;
    static const int NUM_MINES = 15;

    enum CellState {
        HIDDEN,
        REVEALED,
        FLAGGED
    };

    struct Cell {
        bool hasMine;
        CellState state;
        int adjacentMines;
    };

    std::vector<std::vector<Cell>> board;
    bool gameOver;
    int remainingCells;

    void initializeBoard();
    void printBoard();
    void revealCell(int row, int col);
    void flagCell(int row, int col);
    void handleInput();
    bool isGameOver();
    void revealAllMines();
};

#endif // MINESWEEPERGAME_H
