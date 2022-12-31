#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int main() {
  fstream file;
  string input, filename;

  filename = "input.txt";

  file.open(filename, ios::in);

  if (file.is_open()) {
    int total_score;
    while (getline(file, input)) {
      int mid = input.length() / 2;
      int start = 0;
      int end = input.length() - 1;
      set<char> firstHalf, secondHalf;
      char commonChar = '.';
      while (start < mid && end >= mid) {
        char front = input[start];
        char back = input[end];
        if (front == back) {
          commonChar = front;
          break;
        } else {
          const bool is_in_secondHalf =
              secondHalf.find(front) != secondHalf.end();
          if (is_in_secondHalf) {
            commonChar = front;
            break;
          }
          const bool is_in_firstHalf = firstHalf.find(back) != firstHalf.end();
          if (is_in_firstHalf) {
            commonChar = back;
            break;
          }
        }
        firstHalf.insert(front);
        secondHalf.insert(back);
        start++;
        end--;
      }
      cout << commonChar << endl;

      int score = 0;
      if (isupper(commonChar)) {
        score += 26;
      }
      commonChar = tolower(commonChar);
      score += int(commonChar) - int('a') + 1;
      total_score += score;
      cout << score << endl;
    }

    cout << total_score << endl;
  }

  file.close();
  return 0;
}
