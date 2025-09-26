#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

// Implementation of getch() for Linux
int getch()
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int main()
{
    char digit;
    unsigned long number = 0;

    cout << "Enter number:";
    for (int i = 0; i < 6; ++i)
    {
        digit = static_cast<char>(getch());
        if (digit == '\r' || digit == '\n')
        {
            break;
        }
        number = number * 10 + (digit - '0');
    }

    cout << "Your entered number: " << number << endl;

    return 0;
}
