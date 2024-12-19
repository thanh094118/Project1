#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Recursive function to generate all valid binary sequences
void generateSequences(int n, string current, vector<string> &result)
{
    if (current.length() == n)
    {
        result.push_back(current);
        return;
    }

    // Add '0' to the sequence
    generateSequences(n, current + "0", result);

    // Add '1' to the sequence only if it doesn't create "11"
    if (current.empty() || current.back() != '1')
    {
        generateSequences(n, current + "1", result);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<string> result;
    generateSequences(n, "", result);

    // Output results in lexicographic order
    for (const string &seq : result)
    {
        cout << seq << endl;
    }

    return 0;
}
