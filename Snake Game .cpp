#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;
struct Node {
    int x, y;
    Node* Link;
};
class Snake {
public:
    Node* head;
    Node* tail;
    int length;
    Snake() {
        head = tail = nullptr;
        length = 0;
    }
    void SNAKE_HEAD(int x, int y) {
        Node* New_NODE = new Node;
        New_NODE->x = x;
        New_NODE->y = y;
        New_NODE->Link = head;
        head = New_NODE;
        if (tail == nullptr) {
            tail = head;
        }
        length++;
    }

    void SNAKE_Movement(char direction, bool grow = false) {
        Node* New_Head = new Node;

        switch (direction) {
            case 'u': New_Head->x = head->x; New_Head->y = head->y - 1; break;
            case 'd': New_Head->x = head->x; New_Head->y = head->y + 1; break;
            case 'l': New_Head->x = head->x - 1; New_Head->y = head->y; break;
            case 'r': New_Head->x = head->x + 1; New_Head->y = head->y; break;
        }

        New_Head->Link = head;
        head = New_Head;

        if (!grow) {
            Node* temp = tail;
            Node* prev = head;

            while (prev->Link != tail) {
                prev = prev->Link;
            }

            tail = prev;
            tail->Link = nullptr;
            delete temp;
        } else {
            length++;
        }
    }

    void Display_Snake(char board[20][40]) {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 40; j++) {
                board[i][j] = ' ';
            }
        }
        Node* Curr = head;
        while (Curr != nullptr) {
            board[Curr->y][Curr->x] = 'O';
            Curr = Curr->Link;
        }
    }
};
void Display_Board(char board[20][40]) {
    for (int j = 0; j < 42; j++) {
        cout << "~";
    }
    cout << endl;
    for (int i = 0; i < 20; i++) {
        cout << "|";
        for (int j = 0; j < 40; j++) {
            cout << board[i][j];
        }
        cout << "|";
        cout << endl;
    }
    for (int j = 0; j < 42; j++) {
        cout << "~";
    }
    cout << endl;
}
int Food_X_Axis, Food_Y_Axis;
void generateFood(int Board_W, int Board_H, Snake& snake) {
    bool Checking_Position;
    do {
        Checking_Position = true;
        Food_X_Axis = rand() % Board_W;
        Food_Y_Axis = rand() % Board_H;

        Node* Curr = snake.head;
        while (Curr != nullptr) {
            if (Curr->x == Food_X_Axis && Curr->y == Food_Y_Axis) {
                Checking_Position = false;
                break;
            }
            Curr = Curr->Link;
        }
    } while (!Checking_Position);
}

void clearScreen() {
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    GetConsoleScreenBufferInfo(console, &screen);
    DWORD written;

    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

void gameOver(int score, const string& playerName) {
    ofstream file("highscore.txt", ios::app);
    if (file.is_open()) {
        file << playerName << " " << score << endl;
        file.close();
    }

    clearScreen();
    cout << "Game Over!" << endl;
    cout << "Your Score: " << score << endl;
    exit(0);
}

void displayHighestScore() {
    ifstream file("highscore.txt");
    string line, highestScorer;
    int highestScore = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            size_t lastSpace = line.find_last_of(" ");
            if (lastSpace == string::npos) {
                continue;
            }

            string name = line.substr(0, lastSpace);
            int score = stoi(line.substr(lastSpace + 1));

            if (score > highestScore) {
                highestScore = score;
                highestScorer = name;
            }
        }
        file.close();
    }

    if (highestScore > 0) {
        cout << "Highest Score: " << highestScore << " Name: " << highestScorer << endl;
    } else {
        cout << "No high scores !" << endl;
    }
}


int main() {
    srand(time(0));
    Snake snake;

    string playerName;
    cout << "Enter your name: ";
    getline(cin, playerName);

    clearScreen();
    displayHighestScore();
    cout << "Enter to start!" << endl;
    cin.get();
    int Start_Pos_x = 10, Start_Pos_y = 10;
    snake.SNAKE_HEAD(Start_Pos_x, Start_Pos_y);
    generateFood(40, 20, snake);
    char board[20][40];
    char direction = 'r';
    int score = 0;

    while (true) {
        clearScreen();

        snake.Display_Snake(board);
        board[Food_Y_Axis][Food_X_Axis] = '*';

        Display_Board(board);

        if (_kbhit()) {
            char Get_Direction = _getch();
            switch (Get_Direction) {
                case 'w': if (direction != 'd') direction = 'u'; break;
                case 's': if (direction != 'u') direction = 'd'; break;
                case 'a': if (direction != 'r') direction = 'l'; break;
                case 'd': if (direction != 'l') direction = 'r'; break;
            }
        }

        bool grow = false;
        if (snake.head->x == Food_X_Axis && snake.head->y == Food_Y_Axis) {
            grow = true;
            score++;
            generateFood(40, 20, snake);
        }

        snake.SNAKE_Movement(direction, grow);

        Node* Curr = snake.head->Link;
        while (Curr != nullptr) {
            if (snake.head->x == Curr->x && snake.head->y == Curr->y) {
                gameOver(score, playerName);
            }
            Curr = Curr->Link;
        }

        if (snake.head->x < 0 || snake.head->x >= 40 || snake.head->y < 0 || snake.head->y >= 20) {
            gameOver(score, playerName);
        }
        Sleep(120);
    }
    return 0;
}