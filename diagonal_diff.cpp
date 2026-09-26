#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'diagonalDifference' function below.
 */

int diagonalDifference(const vector<vector<int>>& arr) {
    int primary_sum = 0;
    int secondary_sum = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        primary_sum += arr[i][i];
        secondary_sum += arr[i][n - 1 - i];
    }

    return abs(primary_sum - secondary_sum);
}

int main()
{
    // Write output to console if running locally, or to file if OUTPUT_PATH exists
    const char* output_path = getenv("OUTPUT_PATH");
    ostream* out = &cout;
    ofstream fout;

    if (output_path) {
        fout.open(output_path);
        out = &fout;
    }

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = diagonalDifference(arr);

    *out << result << "\n";

    if (fout.is_open()) {
        fout.close();
    }

    return 0;
}

// Modern, warning-free ltrim
string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !isspace(ch);
        })
    );

    return s;
}

// Modern, warning-free rtrim
string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !isspace(ch);
        }).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}