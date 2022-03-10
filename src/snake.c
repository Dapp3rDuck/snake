#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winuser.h>

#define ROWS 25
#define COLS 100

char checkKb() {
  
  if (GetKeyState(0x57) < 0) return 'w';
  if (GetKeyState(0x41) < 0) return 'a';
  if (GetKeyState(0x53) < 0) return 's';
  if (GetKeyState(0x44) < 0) return 'd';
  
  return '\0';

}

void drawFrame(char frame[ROWS][COLS]) {
  
  system("clear");

  // Print top border
  for (int i = 0; i < COLS+4; i++)
    printf("%c", 219);

  printf("\n");

  // Print Board
  for (int i = 0; i < ROWS; i++) {
    
    printf("%c%c", 219, 219);
    printf("\033[1;32m");

    for (int j = 0; j < COLS; j++)
      printf("%c", frame[i][j]);

    printf("\033[0m");
    printf("%c%c\n", 219, 219);
  
  }

  // Print bottom border
  for (int i = 0; i < COLS+4; i++)
    printf("%c", 219);

  printf("\n");

}
int main() {

    // Initialize variables
    char grid[ROWS][COLS];
    int snake[ROWS*COLS][2];
    char keyPress;
    char key = 'd';

    // Initialize board
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++){
        grid[i][j] = ' ';
      }
    }

    // Initialize snake
    for (int i = 0; i < ROWS*COLS; i++) {
      snake[i][0] = -1;
      snake[i][1] = -1;
    }

    ///// Test /////
    snake[0][0] = 5;
    snake[0][1] = 5;

    snake[1][0] = 5;
    snake[1][1] = 4;

    snake[2][0] = 5;
    snake[2][1] = 3;
    ////////////////

    // Game loop
    //while (1) {

      keyPress = checkKb();

      if (keyPress != '\0') 
        key = keyPress;

      for (int i = 0; i < ROWS*COLS; i++)
        if (snake[i][0] > 0 && snake[i][1] > 0)
          grid[snake[i][0]][snake[i][1]] = 178;

      drawFrame(grid);

    //}

    return 0;

}

