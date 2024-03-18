#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

class Point2D {
private:
    int x;
    int y;

public:
    Point2D(int x, int y) : x(x), y(y) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void setX(int newX) {
        x = newX;
    }

    void setY(int newY) {
        y = newY;
    }

    void move(int deltaX, int deltaY) {
        x += deltaX;
        y += deltaY;
    }
};

class Character {
protected:
    Point2D position;

public:
    Character(int x, int y) : position(x, y) {}

    Point2D getPosition() const {
        return position;
    }

    virtual void move(int deltaX, int deltaY) = 0;
};

class Prey : public Character {
public:
    Prey(int x, int y) : Character(x, y) {}

    void move(int deltaX, int deltaY) override {
        position.move(deltaX, deltaY);
    }
};

class Predator : public Character {
public:
    Predator(int x, int y) : Character(x, y) {}

    void move(int deltaX, int deltaY) override {
        position.move(deltaX, deltaY);
    }
};

class Arena {
private:
    static const int SIZE = 30;
    static const int CELL_WIDTH = 2; // Ширина одной клетки
    char grid[SIZE][SIZE * CELL_WIDTH]; // Увеличиваем размерность массива

public:
    Arena() {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE * CELL_WIDTH; ++j) { // Увеличиваем размерность
                grid[i][j] = ' ';
            }
        }
    }

    void placeCharacter(const Character& character, const std::string& symbol) {
        Point2D pos = character.getPosition();
        // Учитываем ширину клетки при размещении символа
        grid[pos.getX()][pos.getY() * CELL_WIDTH] = symbol[0];
        grid[pos.getX()][pos.getY() * CELL_WIDTH + 1] = symbol[1];
    }


    void display() const {
        for (int i = 0; i < SIZE + 3; ++i) {
            if (i != 0 && i < SIZE + 1) {
                if (31 - i < 10) {
                    std::cout << " ";
                }
                std::cout << 31 - i;
            }
            else {
                std::cout << "  ";
            }

            for (int j = 0; j < SIZE * CELL_WIDTH + 2; ++j) {
                if (i != SIZE + 2) {
                    if (i == 0 || i == SIZE + 1) {
                        std::cout << "~";
                    }
                    else if (j == 0 || j == SIZE * CELL_WIDTH + 1) {
                        std::cout << "|";
                    }
                    else {
                        std::cout << grid[i - 1][j - 1];
                    }
                }
                else {
                    if (j == 0) {
                        std::cout << 0;
                    }
                    if (j > 0 && j < SIZE * CELL_WIDTH) {
                        int col_num = j / 2 + 1;
                        if (col_num < 10) {
                            std::cout << " ";
                        }
                        std::cout << col_num;
                        ++j;
                    }
                }
            }
            std::cout << std::endl;
        }
    }


    bool isInsideArena(int x, int y) const {
        // Проверяем, что обе координаты x и y входят в допустимый диапазон,
        // и что y * CELL_WIDTH + 1 также входит в диапазон по горизонтали
        return x >= 0 && x < SIZE && y >= 0 && y < SIZE && y * CELL_WIDTH + 1 < SIZE * CELL_WIDTH;
    }

    void clearPosition(int x, int y) {
        if (isInsideArena(x, y)) {
            // Очищаем обе ячейки, соответствующие данной клетке арены
            grid[x][y * CELL_WIDTH] = ' ';
            grid[x][y * CELL_WIDTH + 1] = ' ';
        }
    }

    char getCharacterAt(int x, int y) const {
        if (isInsideArena(x, y)) {
            // Возвращаем символ из первой ячейки, так как вторая ячейка содержит тот же символ
            return grid[x][y * CELL_WIDTH];
        }
        return ' ';
    }
};

int main() {
    setlocale(LC_ALL, "rus"); // Установка русской локали

    srand(time(0)); // Инициализация генератора случайных чисел

    int choice;
    std::cout << "Выберите персонажа:\n1 - Хищник\n2 - Жертва\n";
    std::cin >> choice;
    if (choice != 1 && choice != 2) {
        std::cout << "Некорректный выбор персонажа.\n";
        return 1;
    }

    Arena arena;
    Prey prey(15, 15);
    Predator predator(10, 10);

    if (choice == 1) {
        std::cout << "Вы выбрали Хищника\n";
    }
    else {
        std::cout << "Вы выбрали Жертву\n";
    }

    arena.placeCharacter(prey, "()");
    arena.placeCharacter(predator, "**");

    if (choice == 1) {
        while (true) {
            arena.display();

            int moveDirection;
            std::cout << "Выберите направление хода:\n1 - Влево\n2 - Вниз\n3 - Вправо\n4 - Вверх\n";
            std::cin >> moveDirection;

            int moveSteps;
            std::cout << "Выберите количество шагов от 1 до 3\n";
            std::cin >> moveSteps;

            int deltaX = 0, deltaY = 0;
            if (moveSteps <= 3) {
                if (moveDirection == 1) {
                    deltaY = -moveSteps;
                }
                else if (moveDirection == 2) {
                    deltaX = moveSteps;
                }
                else if (moveDirection == 3) {
                    deltaY = moveSteps;
                }
                else if (moveDirection == 4) {
                    deltaX = -moveSteps;
                }
                else {
                    std::cout << "Некорректное направление хода.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
            }
            else {
                std::cout << "Некорректное количество шагов.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            // Перемещение хищника
            int newPredatorX = predator.getPosition().getX() + deltaX;
            int newPredatorY = predator.getPosition().getY() + deltaY;
            if (arena.isInsideArena(newPredatorX, newPredatorY)) {
                arena.clearPosition(predator.getPosition().getX(), predator.getPosition().getY());
                predator.move(deltaX, deltaY);
                arena.placeCharacter(predator, "**");
            }

            // Проверка на столкновение
            if (prey.getPosition().getX() == predator.getPosition().getX() && prey.getPosition().getY() == predator.getPosition().getY()) {
                std::cout << "Хищник поймал жертву! Конец игры.\n";
                break;
            }

            // Перемещение жертвы
            deltaX = 0, deltaY = 0;
            int randomDirection = rand() % 4 + 1; // Генерация числа от 1 до 4
            if (randomDirection == 1) {
                deltaY = -1; // Влево
            }
            else if (randomDirection == 2) {
                deltaX = 1; // Вниз
            }
            else if (randomDirection == 3) {
                deltaY = 1; // Вправо
            }
            else {
                deltaX = -1; // Вверх
            }

            int newPreyX = prey.getPosition().getX() + deltaX;
            int newPreyY = prey.getPosition().getY() + deltaY;
            if (arena.isInsideArena(newPreyX, newPreyY)) {
                arena.clearPosition(prey.getPosition().getX(), prey.getPosition().getY());
                prey.move(deltaX, deltaY);
                arena.placeCharacter(prey, "()");
            }

            // Проверка на столкновение
            if (prey.getPosition().getX() == predator.getPosition().getX() && prey.getPosition().getY() == predator.getPosition().getY()) {
                std::cout << "Жертва пришла к охотнику! Конец игры.\n";
                break;
            }


        }
    }

    if (choice == 2) {
        while (true) {
            arena.display();

            int moveDirection;
            std::cout << "Выберите направление хода:\n1 - Влево\n2 - Вниз\n3 - Вправо\n4 - Вверх\n5 - Влево-вниз\n6 - Влево-вверх\n7 - Вправо-вниз\n8 - Вправо-вверх\n";
            std::cin >> moveDirection;

            int deltaX = 0, deltaY = 0;
            if (moveDirection == 1) {
                deltaY = -1;
            }
            else if (moveDirection == 2) {
                deltaX = 1;
            }
            else if (moveDirection == 3) {
                deltaY = 1;
            }
            else if (moveDirection == 4) {
                deltaX = -1;
            }
            else if (moveDirection == 5) {
                deltaY = -1;
                deltaX = 1;
            }
            else if (moveDirection == 6) {
                deltaY = -1;
                deltaX = -1;
            }
            else if (moveDirection == 7) {
                deltaY = 1;
                deltaX = 1;
            }
            else if (moveDirection == 8) {
                deltaY = 1;
                deltaX = -1;
            }
            else {
                std::cout << "Некорректное направление хода.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            // Перемещение жертвы
            int newPreyX = prey.getPosition().getX() + deltaX;
            int newPreyY = prey.getPosition().getY() + deltaY;
            if (arena.isInsideArena(newPreyX, newPreyY)) {
                arena.clearPosition(prey.getPosition().getX(), prey.getPosition().getY());
                prey.move(deltaX, deltaY);
                arena.placeCharacter(prey, "()");
            }

            // Перемещение хищника

            // Получение координат текущего положения хищника и жертвы
            int predatorX = predator.getPosition().getX();
            int predatorY = predator.getPosition().getY();
            int preyX = prey.getPosition().getX();
            int preyY = prey.getPosition().getY();

            // Определение направления движения для хищника
            deltaX = 0, deltaY = 0;
            if (preyX < predatorX) {
                if (predatorX - preyX >= 3) {
                    deltaX = -3; // Жертва находится слева от хищника
                }
                else if (predatorX - preyX < 3) {
                    deltaX = -(predatorX - preyX); // Жертва находится слева от хищника
                }

            }
            else if (preyX > predatorX) {
                if (preyX - predatorX >= 3) {
                    deltaX = 3; // Жертва находится справа от хищника
                }
                else if (preyX - predatorX < 3) {
                    deltaX = preyX - predatorX; // Жертва находится справа от хищника
                }
            }

            else if (preyY < predatorY) {
                if (predatorY - preyY >= 3) {
                    deltaY = -3; // Жертва находится выше хищника
                }
                else if (predatorY - preyY < 3) {
                    deltaY = -(predatorY - preyY); // Жертва находится выше хищника
                }

            }
            else if (preyY > predatorY) {
                if (preyY - predatorY >= 3) {
                    deltaY = 3; // Жертва находится ниже хищника
                }
                else if (preyY - predatorY < 3) {
                    deltaY = preyY - predatorY; // Жертва находится ниже хищника
                }
            }

            // Перемещение хищника в направлении жертвы
            int newPredatorX = predatorX + deltaX;
            int newPredatorY = predatorY + deltaY;

            if (arena.isInsideArena(newPredatorX, newPredatorY)) {
                arena.clearPosition(predatorX, predatorY);
                predator.move(deltaX, deltaY);
                arena.placeCharacter(predator, "**");
            }

            // Проверка на столкновение
            if (prey.getPosition().getX() == predator.getPosition().getX() && prey.getPosition().getY() == predator.getPosition().getY()) {
                std::cout << "Хищник поймал жертву! Конец игры.\n";
                break;
            }
        }
    }
    return 0;
}