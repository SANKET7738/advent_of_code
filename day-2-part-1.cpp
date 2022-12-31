#include<bits/stdc++.h>
using namespace std;

string getMatchOutcome(const string& first_player_move, const string& second_player_move) {
  // first player uses rock
  if (first_player_move == "A") {
    if (second_player_move == "X") // rock
    {
      return "draw";
    } else if (second_player_move == "Y") // paper 
    {
      return "win";
    } else { // scissor
      return "lose";
    }
  } else if (first_player_move == "B") {
    // first paper uses paper 
    if (second_player_move == "X") // rock
    {
      return "lose";
    } else if ( second_player_move == "Y") { // paper 
      return "draw";
    } else {
      return "win";
    }
  } else {
    if (second_player_move == "X") 
    {
      return "win";
    } else if (second_player_move == "Y") {
      return "lose";
    } else {
      return "draw";
    }
  } 
}

int get_score(const string& match_outcome, const string& player_move) {
  int score = 0;

  if (player_move == "X") {
    score += 1;
  } else if (player_move == "Y") {
    score += 2;
  } else {
    score += 3;
  }

  if (match_outcome == "draw") {
    score += 3;
  } else if (match_outcome == "win") {
    score += 6;
  }

  return score;
}

int main()
{
  fstream file;
  string input, filename;

  filename = "input.txt";

  file.open(filename, ios::in);

  if (file.is_open())
  {
    int total_score;

    while (getline(file,input))
    {
      string first_player_move = input.substr(0, input.find(" "));
      string second_player_move = input.substr(input.find(" ")+1, input.length());
      
      cout << first_player_move + "<>" + second_player_move << endl;
      string match_outcome = getMatchOutcome(first_player_move, second_player_move);
      cout << match_outcome << endl;

      int score = get_score(match_outcome,second_player_move);
      cout << score << endl;

      total_score += score;
    }

    cout << total_score << endl;
  }

  file.close();
  return 0;
}
