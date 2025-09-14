#include <iostream>
#include <vector>
#include <string>

using namespace std;

void helper(const vector<string> &strings, int row, int col, char current_op, int &total)
{
    while (col < strings[row].size())
    {
        char c = strings[row][col];

        if (isdigit(c))
        {
            int num = c - '0';
            if (current_op == '+')
                total += num;
            else if (current_op == '-')
                total -= num;
            else if (current_op == '*')
                total *= num;
        }
        else if (c == '+' || c == '-' || c == '*')
        {
            current_op = c;
        }
        else if (c == '^')
        {
            helper(strings, row - 1, col, current_op, total);
        }
        else if (c == 'v')
        {
            helper(strings, row + 1, col, current_op, total);
        }

        col++;
    }
}

int calculate_vector(const vector<string> &strings)
{
    int total = 0;
    helper(strings, 0, 0, '+', total);
    return total;
}

int main()
{
    vector<string> vec = {"257*233+6v790-12", "61247833212+*9^3"};
    cout << calculate_vector(vec) << endl;

    return 0;
}
