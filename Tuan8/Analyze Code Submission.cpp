#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Helper function to convert HH:MM:SS into seconds
int timeToSeconds(const string &timeStr)
{
    int h, m, s;
    sscanf(timeStr.c_str(), "%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
}

int main()
{
    unordered_map<string, unordered_map<string, int>> userProblemPoints; // For storing max points for each user & problem
    unordered_map<string, int> userErrors;                               // For counting number of ERR submissions per user
    vector<pair<int, string>> submissions;                               // For counting submissions by time

    string line;

    // Processing submission data
    while (getline(cin, line))
    {
        if (line == "#")
            break;

        string userID, problemID, timePoint, status;
        int points;

        stringstream ss(line);
        ss >> userID >> problemID >> timePoint >> status >> points;

        // Update max points for the problem for the user
        if (userProblemPoints[userID][problemID] < points)
        {
            userProblemPoints[userID][problemID] = points;
        }

        // If the status is "ERR", increment the user's error count
        if (status == "ERR")
        {
            userErrors[userID]++;
        }

        // Add this submission to the list of all submissions by time
        submissions.push_back({timeToSeconds(timePoint), userID});
    }

    // Sort the submissions based on time for efficient range queries
    sort(submissions.begin(), submissions.end());

    // Processing query data
    while (getline(cin, line))
    {
        if (line == "#")
            break;

        stringstream ss(line);
        string query;
        ss >> query;

        if (query == "?total_number_submissions")
        {
            cout << submissions.size() << endl;
        }
        else if (query == "?number_error_submision")
        {
            int errCount = 0;
            for (const auto &pair : userErrors)
            {
                errCount += pair.second;
            }
            cout << errCount << endl;
        }
        else if (query == "?number_error_submision_of_user")
        {
            string userID;
            ss >> userID;
            cout << userErrors[userID] << endl;
        }
        else if (query == "?total_point_of_user")
        {
            string userID;
            ss >> userID;
            int totalPoints = 0;
            for (const auto &problem : userProblemPoints[userID])
            {
                totalPoints += problem.second;
            }
            cout << totalPoints << endl;
        }
        else if (query == "?number_submission_period")
        {
            string fromTime, toTime;
            ss >> fromTime >> toTime;
            int fromSec = timeToSeconds(fromTime);
            int toSec = timeToSeconds(toTime);

            // Count number of submissions within this period using the sorted submissions array
            int count = 0;
            for (const auto &sub : submissions)
            {
                if (sub.first >= fromSec && sub.first <= toSec)
                {
                    count++;
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}
