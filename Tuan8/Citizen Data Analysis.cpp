#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <ctime>

using namespace std;

struct Person
{
    string code;
    string dob; // Date of birth (YYYY-MM-DD)
    string father_code;
    string mother_code;
    char is_alive; // 'Y' or 'N'
    string region_code;
};

unordered_map<string, Person> citizens;
unordered_map<string, int> birth_count;         // Counts the number of people born at each date
unordered_map<string, vector<string>> children; // Maps parent -> list of children

// To handle the MAX_UNRELATED_PEOPLE, we can use a disjoint set / union-find
unordered_map<string, string> parent; // Union-find parent pointer for each citizen

// Function to find the root in the union-find structure
string find_parent(const string &code)
{
    if (parent[code] != code)
    {
        parent[code] = find_parent(parent[code]);
    }
    return parent[code];
}

// Function to perform union of two disjoint sets in union-find
void union_sets(const string &code1, const string &code2)
{
    string root1 = find_parent(code1);
    string root2 = find_parent(code2);
    if (root1 != root2)
    {
        parent[root2] = root1;
    }
}

int main()
{
    string line;

    // Read and parse the citizen database block
    while (getline(cin, line))
    {
        if (line == "*")
            break;

        stringstream ss(line);
        Person person;
        ss >> person.code >> person.dob >> person.father_code >> person.mother_code >> person.is_alive >> person.region_code;

        // Add to citizens database
        citizens[person.code] = person;

        // Increment the birth count for the date of birth
        birth_count[person.dob]++;

        // Union the person with their parents if alive
        if (person.father_code != "0000000")
        {
            union_sets(person.code, person.father_code);
        }
        if (person.mother_code != "0000000")
        {
            union_sets(person.code, person.mother_code);
        }

        // Make each person their own root initially
        parent[person.code] = person.code;

        // Store the children for family tree processing
        if (person.father_code != "0000000")
        {
            children[person.father_code].push_back(person.code);
        }
        if (person.mother_code != "0000000")
        {
            children[person.mother_code].push_back(person.code);
        }
    }

    // Read the query block
    while (getline(cin, line))
    {
        if (line == "***")
            break;

        stringstream ss(line);
        string query;
        ss >> query;

        if (query == "NUMBER_PEOPLE")
        {
            // Output the total number of people
            cout << citizens.size() << endl;
        }
        else if (query == "NUMBER_PEOPLE_BORN_AT")
        {
            string date;
            ss >> date;
            cout << birth_count[date] << endl;
        }
        else if (query == "MOST_ALIVE_ANCESTOR")
        {
            string code;
            ss >> code;

            // Find the most alive ancestor of the given person
            int generation = 0;
            string current = code;
            while (current != "0000000" && citizens[current].is_alive == 'Y')
            {
                if (citizens[current].father_code != "0000000" && citizens[citizens[current].father_code].is_alive == 'Y')
                {
                    current = citizens[current].father_code;
                }
                else if (citizens[current].mother_code != "0000000" && citizens[citizens[current].mother_code].is_alive == 'Y')
                {
                    current = citizens[current].mother_code;
                }
                else
                {
                    break;
                }
                generation++;
            }
            cout << generation << endl;
        }
        else if (query == "NUMBER_PEOPLE_BORN_BETWEEN")
        {
            string from_date, to_date;
            ss >> from_date >> to_date;

            int count = 0;
            // Count people born between two dates
            for (const auto &person : citizens)
            {
                if (person.second.dob >= from_date && person.second.dob <= to_date)
                {
                    count++;
                }
            }
            cout << count << endl;
        }
        else if (query == "MAX_UNRELATED_PEOPLE")
        {
            // Find the largest unrelated group (using union-find)
            unordered_map<string, set<string>> group;
            for (const auto &citizen : citizens)
            {
                string root = find_parent(citizen.first);
                group[root].insert(citizen.first);
            }
            int max_size = 0;
            for (const auto &g : group)
            {
                max_size = max(max_size, (int)g.second.size());
            }
            cout << max_size << endl;
        }
    }

    return 0;
}
