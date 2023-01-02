#include <bits/stdc++.h>
using namespace std;

int main() {
  fstream file;
  string input, filename;

  filename = "input.txt";

  file.open(filename, ios::in);

  if (file.is_open()) {
    int count = 0;
    while (getline(file, input)) {
      string firstPair = input.substr(0, input.find(","));
      string secondPair = input.substr(input.find(",") + 1, input.length());

      int firstDigitFirstPair = stoi(firstPair.substr(0, firstPair.find("-")));
      int firstDigitSecondPair =
          stoi(secondPair.substr(0, secondPair.find("-")));

      if (firstDigitSecondPair <= firstDigitFirstPair) {
        swap(firstPair, secondPair);
      }

      int firstPairFirstDigit = stoi(firstPair.substr(0, firstPair.find("-")));
      int firstPairSecondDigit =
          stoi(firstPair.substr(firstPair.find("-") + 1, firstPair.length()));
      int secondPairfirstDigit =
          stoi(secondPair.substr(0, secondPair.find("-")));
      int secondPairSecondDigit = stoi(
          secondPair.substr(secondPair.find("-") + 1, secondPair.length()));

      if (firstPairFirstDigit == secondPairfirstDigit) {
        if (firstPairSecondDigit >= secondPairSecondDigit ||
            secondPairSecondDigit >= firstPairFirstDigit) {
          count++;
        }
      } else if (firstPairSecondDigit >= secondPairSecondDigit) {
        count++;
      }
    }
    cout << count << endl;
  }

  file.close();
  return 0;
}
