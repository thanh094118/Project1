#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    queue<int> q;
    string command;

    while (getline(cin, command))
    {
        if (command == "#")
        {
            break; // End of input
        }

        // Process each command
        stringstream ss(command);
        string op;
        ss >> op;

        if (op == "PUSH")
        {
            int v;
            ss >> v;
            q.push(v); // Push the value into the queue
        }
        else if (op == "POP")
        {
            if (!q.empty())
            {
                cout << q.front() << endl; // Print the front value and pop it
                q.pop();
            }
            else
            {
                cout << "NULL" << endl; // If the queue is empty, print NULL
            }
        }
    }

    return 0;
}
