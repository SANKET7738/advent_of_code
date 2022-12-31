#include<bits/stdc++.h>
using namespace std;

string get_losing_move(const string& player_move) {
  if (player_move == "A") {
    return "C";
  } else if (player_move == "B") {
    return "A";
  } else {
    return "B";
  }
}

string get_wining_move(const string& player_move) {
  if (player_move == "A") {
    return "B";
  } else if (player_move == "B") {
    return "C";
  } else {
    return "A";
  }
}

string get_move(const string& player_one_move, const string& match_outcome) {
  if (match_outcome == "Y") {
    return player_one_move;
  } else if (match_outcome == "X" ) {
    return get_losing_move(player_one_move);
  } else {
    return get_wining_move(player_one_move);
  }
}

int get_score(const string& player_move, const string& match_outcome ) {
  int score = 0;

  if(player_move == "A") {
    score += 1;
  } else if (player_move == "B") {
    score += 2;
  } else {
    score += 3;
  }

  if (match_outcome == "Y") {
    score += 3;
  } else if (match_outcome == "Z") {
    score += 6;
  }

  return score;
}

int main() {
  fstream file;
  string input, filename;

  filename = "input.txt";

  file.open(filename, ios::in);

  if(file.is_open()) {
    int total_score;

    while(getline(file,input)) {
      string player_one_move = input.substr(0,input.find(" "));
      string match_outcome = input.substr(input.find(" ")+1, input.length());
    
      string player_two_move = get_move(player_one_move,match_outcome);
      
      int score = get_score(player_two_move, match_outcome);
      total_score += score;
    }

    cout << total_score << endl;
  }

  file.close();
  return 0;
}
