#include "sudoku.h"
#include <iostream>

using namespace std;

Sudoku::Sudoku(int puzzle[9][9]) {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      board[i][j] = puzzle[i][j];
    }
  }
}

Sudoku::~Sudoku() {
}

void Sudoku::verify() {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      if(!isValid(i, j)) {
        cout << "INVALID PUZZLE" << endl;
        return;
      }
    }
  }
  cout << "VALID PUZZLE" << endl;
}

void Sudoku::print() {
  for (int row=0; row<9; row++) {
      if (row % 3== 0) {
      std::cout << "-------------------------------" << std::endl;
    }
    
    for (int col=0; col<9; col++) {
      if (col % 3 == 0) {
        std::cout << "|";
      }
    
        if (board[row][col] != 0) {
        std::cout << " " << board[row][col] << " ";
      } else {
        std::cout << " . ";
      }
      
    }
    
    std::cout << "|" << std::endl;
  }
  std::cout << "-------------------------------" << std::endl;
}

bool Sudoku::isValid(int row, int col) {


  int value = board[row][col];

  for (int i=0; i<9; i++) {
    if (i == row) {
    continue;
    }
    
    int temp = board[i][col];
    if (temp == value) {
      return false;
    }
  }
  
  for (int i=0; i<9; i++) {
      if (i == col) {
      continue;
    }
    
    int temp = board[row][i];
    if (temp == value) {
      return false;
    }
  }
  
  int box_row = row / 3; 
  int box_col = col / 3; 
  
  for (int i=box_row * 3; i < box_row * 3 + 3; i++) {
    for (int j=box_col * 3; j < box_col * 3 + 3; j++) {
      if (i == row && j == col) {
        continue;
      }
      
      int temp = board[i][j];
      if (temp == value) {
        return false;
      }
    }
  }
  
  return true;
}

void Sudoku::solve(){
  solveHelper(0, 0); 
}

bool Sudoku::isDone() {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      if(!isValid(i, j)) {
        return false;
      }
    }
  }
  return true;
}

bool Sudoku::solveHelper(int row, int col) {
  // TODO: IMPLEMENT THIS
  // Handle end cases
  if (this->isDone()) {
    for (int i = 1; i<=9; i++) {
      this->board[8][8] = i;
      if(this->isValid(8,8)) {
        return true;
      } 
    }
  } else if(!(this->board[row][col])) {
    //needs to be solved
    for (int i = 1; i<=9; i++) {
      this->board[row][col] = i;
      if(this->isValid(row,col)) {
        if (solveHelper(row,col)) {
          for (int i = 1; i<=9; i++) {
            this->board[8][8] = i;
            if(this->isValid(8,8)) {
              return true;
            } 
          }
          return true;
        }
      } else {
        this->board[row][col] = 0;
      }
    }
  } else {
    // solve the next one
    if ((col==8) && (row ==8)) { return false; }
    else if ((col < 8) && (row==8)) { return solveHelper(0,col+1); }
    else if ((row < 8) && (col==8)) { return solveHelper(row+1,col); }
    else { return solveHelper(row+1,col); }
  }

  return false;
} 