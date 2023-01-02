#include <bits/stdc++.h>
using namespace std;

int main() {
  fstream file;
  string input, filename;

  filename = "input.txt";

  file.open(filename, ios::in);

  if (file.is_open()) {
    int count;
    while (getline(file, input)) {
      string firstPair = input.substr(0, input.find(","));
      string secondPair = input.substr(input.find(",") + 1, input.length());

      int firstPairFirstDigit = stoi(firstPair.substr(0, firstPair.find("-")));
      int secondPairFirstDigit =
          stoi(secondPair.substr(0, secondPair.find("-")));

      if (firstPairFirstDigit > secondPairFirstDigit) {
        swap(firstPair, secondPair);
      }

      int firstPairSecondDigit =
          stoi(firstPair.substr(firstPair.find("-") + 1, firstPair.length()));
      secondPairFirstDigit = stoi(secondPair.substr(0, secondPair.find("-")));

      if (firstPairSecondDigit >= secondPairFirstDigit) {
        count++;
      }
    }
    cout << count << endl;
  }

  file.close();
  return 0;
}
