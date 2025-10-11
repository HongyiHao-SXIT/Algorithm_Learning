#include <conio.h>
#include <windows.h>

#include <iostream>
#include <vector>
using namespace std;

const int width = 20;
const int height = 20;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

vector<pair<int, int>> snake;
pair<int, int> food;
bool gameOver;

void InitSnake() {
  snake.clear();
  snake.push_back({10, 10});
  snake.push_back({9, 10});
  snake.push_back({8, 10});
  dir = RIGHT;
  food = {rand() % (width - 2) + 1, rand() % (height - 2) + 1};
  gameOver = false;
}

void Draw() {
  system("cls");

  for (int y = 0; y <= height; y++) {
    for (int x = 0; x <= width; x++) {
      if (x == 0 || x == width || y == 0 || y == height) {
        cout << "#";
      } else if (x == food.first && y == food.second) {
        cout << "*";
      } else {
        bool isSnake = false;
        for (int i = 0; i < snake.size(); i++) {
          if (snake[i].first == x && snake[i].second == y) {
            if (i == 0)
              cout << "O";
            else
              cout << "o";
            isSnake = true;
            break;
          }
        }
        if (!isSnake)
          cout << " ";
      }
    }
    cout << endl;
  }
}

void Input() {
  if (_kbhit()) {
    switch (_getch()) {
    case 'a':
      if (dir != RIGHT)
        dir = LEFT;
      break;
    case 'd':
      if (dir != LEFT)
        dir = RIGHT;
      break;
    case 'w':
      if (dir != DOWN)
        dir = UP;
      break;
    case 's':
      if (dir != UP)
        dir = DOWN;
      break;
    case 'x':
      gameOver = true;
      break;
    }
  }
}

void Logic() {
  pair<int, int> head = snake[0];
  switch (dir) {
  case LEFT:
    head.first--;
    break;
  case RIGHT:
    head.first++;
    break;
  case UP:
    head.second--;
    break;
  case DOWN:
    head.second++;
    break;
  default:
    break;
  }

  if (head.first <= 0 || head.first >= width || head.second <= 0 ||
      head.second >= height) {
    gameOver = true;
    return;
  }

  for (int i = 1; i < snake.size(); i++) {
    if (snake[i] == head) {
      gameOver = true;
      return;
    }
  }

  snake.insert(snake.begin(), head);

  if (head == food) {
    food = {rand() % (width - 2) + 1, rand() % (height - 2) + 1};
  } else {
    snake.pop_back();
  }
}

int main() {
  InitSnake();
  while (!gameOver) {
    Draw();
    Input();
    Logic();
    Sleep(100);
  }
  cout << "Game Over!" << endl;
  return 0;
}
