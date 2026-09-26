#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    // Extract AM or PM indicator from the last 2 characters
    string period = s.substr(8, 2);
    
    // Extract the hour integer from the first 2 characters
    int hour = stoi(s.substr(0, 2));
    
    // Extract minutes and seconds (HH:MM:SS format)
    string timeWithoutPeriod = s.substr(2, 6); // Includes ":MM:SS"

    if (period == "AM") {
        if (hour == 12) {
            hour = 0; // Midnight 12:XX:XXAM -> 00:XX:XX
        }
    } else { // PM
        if (hour != 12) {
            hour += 12; // PM times except 12 PM -> add 12 hours
        }
    }

    // Format the updated hour back into a two-digit string
    stringstream ss;
    ss << setfill('0') << setw(2) << hour << timeWithoutPeriod;

    return ss.str();
}

int main()
{
    // Output to console locally, or to file on HackerRank
    const char* output_path = getenv("OUTPUT_PATH");
    ostream* out = &cout;
    ofstream fout;

    if (output_path) {
        fout.open(output_path);
        out = &fout;
    }

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    *out << result << "\n";

    if (fout.is_open()) {
        fout.close();
    }

    return 0;
}