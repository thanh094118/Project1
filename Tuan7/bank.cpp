#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
struct Transaction {
    string from_account;
    string to_account;
    int money;
    string time_point;
    string atm;
};
vector<Transaction> transactions;
bool has_cycle(const string& start_account, int k, map<string, vector<string>>& graph, set<string>& visited, const string& current, int depth) {
    if (depth == k) {
        return current == start_account;
    }
    visited.insert(current);
    for (size_t i = 0; i < graph[current].size(); i++) {
        string neighbor = graph[current][i];
        if (visited.find(neighbor) == visited.end() || (depth == k - 1 && neighbor == start_account)) {
            if (has_cycle(start_account, k, graph, visited, neighbor, depth + 1)) {
                return true;
            }
        }
    }
    visited.erase(current);
    return false;
}
int main() {
    string line;
    while (true) {
        getline(cin, line);
        if (line == "#") break;
        Transaction t;
        size_t pos = 0;
        // Tách từng phần trong chuỗi giao dịch
        t.from_account = line.substr(0, 11);
        t.to_account = line.substr(12, 11);
        pos = 24;
        t.money = stoi(line.substr(pos, line.find(' ', pos) - pos));
        pos = line.find(' ', pos) + 1;
        t.time_point = line.substr(pos, 8);
        pos += 9;
        t.atm = line.substr(pos);

        transactions.push_back(t);
    }
    while (true) {
        getline(cin, line);
        if (line == "#") break;
        if (line == "?number_transactions") {
            cout << transactions.size() << endl;
        } else if (line == "?total_money_transaction") {
            int total_money = 0;
            for (size_t i = 0; i < transactions.size(); i++) {
                total_money += transactions[i].money;
            }
            cout << total_money << endl;
        } else if (line == "?list_sorted_accounts") {
            set<string> accounts;
            for (size_t i = 0; i < transactions.size(); i++) {
                accounts.insert(transactions[i].from_account);
                accounts.insert(transactions[i].to_account);
            }
            for (auto it = accounts.begin(); it != accounts.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        } else if (line.substr(0, 28) == "?total_money_transaction_from") {
            string account = line.substr(29);
            int total_money = 0;
            for (size_t i = 0; i < transactions.size(); i++) {
                if (transactions[i].from_account == account) {
                    total_money += transactions[i].money;
                }
            }
            cout << total_money << endl;
        } else if (line.substr(0, 15) == "?inspect_cycle") {
            size_t pos = 16;
            string account = line.substr(pos, 11);
            pos += 12;
            int k = stoi(line.substr(pos));
            map<string, vector<string>> graph;
            for (size_t i = 0; i < transactions.size(); i++) {
                graph[transactions[i].from_account].push_back(transactions[i].to_account);
            }
            set<string> visited;
            if (has_cycle(account, k, graph, visited, account, 0)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
