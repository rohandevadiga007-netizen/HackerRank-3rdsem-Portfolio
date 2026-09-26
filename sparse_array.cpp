#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'matchingStrings' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY stringList
 *  2. STRING_ARRAY queries
 */

vector<int> matchingStrings(const vector<string>& stringList, const vector<string>& queries) {
    // Hash map to store frequency of each string in stringList
    unordered_map<string, int> counts;
    for (const string& s : stringList) {
        counts[s]++;
    }

    // Process queries and retrieve counts in O(1) average time
    vector<int> result;
    result.reserve(queries.size());
    
    for (const string& q : queries) {
        auto it = counts.find(q);
        if (it != counts.end()) {
            result.push_back(it->second);
        } else {
            result.push_back(0);
        }
    }

    return result;
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

    string stringList_count_temp;
    getline(cin, stringList_count_temp);

    int stringList_count = stoi(ltrim(rtrim(stringList_count_temp)));

    vector<string> stringList(stringList_count);

    for (int i = 0; i < stringList_count; i++) {
        string stringList_item;
        getline(cin, stringList_item);

        stringList[i] = stringList_item;
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(stringList, queries);

    for (size_t i = 0; i < res.size(); i++) {
        *out << res[i];

        if (i != res.size() - 1) {
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