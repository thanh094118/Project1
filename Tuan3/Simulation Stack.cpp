#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<int> s;
    string command;

    while (getline(cin, command))
    {
        if (command == "#")
        {
            break;
        }

        if (command.substr(0, 4) == "PUSH")
        {
            int value = stoi(command.substr(5)); // Lấy giá trị sau lệnh PUSH
            s.push(value);
        }
        else if (command == "POP")
        {
            if (!s.empty())
            {
                cout << s.top() << endl;
                s.pop();
            }
            else
            {
                cout << "NULL" << endl;
            }
        }
    }

    return 0;
}
