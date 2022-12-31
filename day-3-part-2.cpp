#include <bits/stdc++.h>
using namespace std;

int main() {
  fstream file;
  string input, filename;

  filename = "input.txt";

  file.open(filename, ios::in);

  if (file.is_open()) {

    vector<string> batch;
    int total_score = 0;

    while (getline(file, input)) {

      batch.push_back(input);

      char commonChar = '.';

      if (batch.size() == 3) {
        set<char> first_set, second_set;

        for (auto &ele : batch[0]) {
          first_set.insert(ele);
        }

        for (auto &ele : batch[1]) {
          const bool is_in_first = first_set.find(ele) != first_set.end();
          if (is_in_first) {
            second_set.insert(ele);
          }
        }

        for (auto &ele : batch[2]) {
          const bool is_in_second = second_set.find(ele) != second_set.end();
          if (is_in_second) {
            commonChar = ele;
            break;
          }
        }

        cout << commonChar << endl;
        int score = 0;
        if (isupper(commonChar)) {
          score += 26;
        }

        commonChar = tolower(commonChar);
        score += int(commonChar) - int('a') + 1;
        total_score += score;
        batch.clear();
      }
    }

    cout << total_score << endl;
  }

  file.close();
  return 0;
}
