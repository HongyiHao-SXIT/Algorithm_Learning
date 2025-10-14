#include <conio.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

const int width = 20;
const int height = 20;

enum class Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

std::vector<std::pair<int, int>> snake;
std::pair<int, int> food;
bool gameOver;

void InitSnake() {
  snake.clear();
  snake.push_back({10, 10});
  snake.push_back({9, 10});
  snake.push_back({8, 10});
  dir = Direction::RIGHT;
  food = {std::rand() % (width - 2) + 1, std::rand() % (height - 2) + 1};
  gameOver = false;
}

void Draw() {
  system("cls");

  for (int y = 0; y <= height; y++) {
    for (int x = 0; x <= width; x++) {
      if (x == 0 || x == width || y == 0 || y == height) {
        std::cout << "#";
      } else if (x == food.first && y == food.second) {
        std::cout << "*";
      } else {
        bool isSnake = false;
        for (size_t i = 0; i < snake.size(); i++) {
          if (snake[i].first == x && snake[i].second == y) {
            std::cout << (i == 0 ? "O" : "o");
            isSnake = true;
            break;
          }
        }
        if (!isSnake)
          std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
}

void Input() {
  if (_kbhit()) {
    switch (_getch()) {
    case 'a':
      if (dir != Direction::RIGHT)
        dir = Direction::LEFT;
      break;
    case 'd':
      if (dir != Direction::LEFT)
        dir = Direction::RIGHT;
      break;
    case 'w':
      if (dir != Direction::DOWN)
        dir = Direction::UP;
      break;
    case 's':
      if (dir != Direction::UP)
        dir = Direction::DOWN;
      break;
    case 'x':
      gameOver = true;
      break;
    default:
      break;
    }
  }
}

void Logic() {
  std::pair<int, int> head = snake[0];

  switch (dir) {
  case Direction::LEFT:
    head.first--;
    break;
  case Direction::RIGHT:
    head.first++;
    break;
  case Direction::UP:
    head.second--;
    break;
  case Direction::DOWN:
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

  for (size_t i = 1; i < snake.size(); i++) {
    if (snake[i] == head) {
      gameOver = true;
      return;
    }
  }

  snake.insert(snake.begin(), head);

  if (head == food) {
    food = {std::rand() % (width - 2) + 1, std::rand() % (height - 2) + 1};
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
  std::cout << "Game Over!" << std::endl;
  return 0;
}
