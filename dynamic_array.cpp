#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'dynamicArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

vector<int> dynamicArray(int n, const vector<vector<int>>& queries) {
    // Create a 2D vector array 'arr' of size n (n empty 1D vectors)
    vector<vector<int>> arr(n);
    int lastAnswer = 0;
    vector<int> results;

    for (const auto& query : queries) {
        int type = query[0];
        int x = query[1];
        int y = query[2];

        // Determine array index using bitwise XOR as specified in the problem
        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            // Query Type 1: Append y to arr[idx]
            arr[idx].push_back(y);
        } else if (type == 2) {
            // Query Type 2: Assign value at arr[idx][y % size(arr[idx])] to lastAnswer
            int element_idx = y % arr[idx].size();
            lastAnswer = arr[idx][element_idx];
            results.push_back(lastAnswer);
        }
    }

    return results;
}

int main()
{
    // Output to console locally, or to output file on HackerRank
    const char* output_path = getenv("OUTPUT_PATH");
    ostream* out = &cout;
    ofstream fout;

    if (output_path) {
        fout.open(output_path);
        out = &fout;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);
    int q = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> result = dynamicArray(n, queries);

    for (size_t i = 0; i < result.size(); i++) {
        *out << result[i];

        if (i != result.size() - 1) {
            *out << "\n";
        }
    }

    *out << "\n";

    if (fout.is_open()) {
        fout.close();
    }

    return 0;
}

// Modern C++17/20 string trimming helpers
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