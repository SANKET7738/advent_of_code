#include <bits/stdc++.h>
using namespace std;

vector<vector<char> > parseInput(const string &drawing) {
  vector<vector<char> > crateContainers;
  stringstream ss(drawing);
  string line;
  while(getline(ss,line,'\n')){
   int index = 1;
   vector<char> crateRow;
   while(index < line.length()){
    crateRow.push_back(line[index]);
    index += 4;
   }
   crateContainers.push_back(crateRow);
  }
  crateContainers.pop_back();
  return crateContainers;
}

struct Instruction {
  int payload;
  int from;
  int to;
};

Instruction parseInstruction(const string& instruction_str) {
  string int_str;
  for(auto &c: instruction_str) {
    if(isdigit(c)){
      int_str += c;
    }
  }
  string payload, from, to;
  if(int_str.length()==4){
    payload.push_back(int_str[0]);
    payload.push_back(int_str[1]);
    from = int_str[2];
    to = int_str[3];
  } else {
    payload = int_str[0];
    from = int_str[1];
    to = int_str[2];
  }
  Instruction instruction;
  instruction.payload = atoi(payload.c_str());
  instruction.from = atoi(from.c_str()) - 1;
  instruction.to = atoi(to.c_str()) - 1;
  
  return instruction;
}

vector<stack<char> > convertColsToStack(vector<vector<char> >& crateContainers) {
  vector<stack<char> > stackedRows;
  for(int i=0; i<9; i++){
    stack<char> row;
    char ele;
    for(int j=crateContainers.size()-1; j>=0;j--){
      ele = crateContainers[j][i];
      if(!isspace(ele)) {
        row.push(ele);
      }
    }
    stackedRows.push_back(row);
  }
  return stackedRows;
}


void proccessInstrcution(vector<stack<char> >& stackedRows, const string& instruction_str) { 
  Instruction instruction = parseInstruction(instruction_str);
  int k = instruction.payload;
  char ele;
  while(k>0){
    ele = stackedRows[instruction.from].top();
    stackedRows[instruction.from].pop();
    stackedRows[instruction.to].push(ele);
    k -= 1;
  }
}

int main() {
  fstream file;
  string input, filename;

  filename = "input.txt";

  file.open(filename, ios::in);

  if (file.is_open()) {
    string fileString;
    while (getline(file, input)) {
      fileString += input + "\n";
    }

    string drawing = fileString.substr(0, fileString.find("\n\n"));
    vector<vector<char> > crateContainers = parseInput(drawing);

    vector<stack<char> > stackedRows = convertColsToStack(crateContainers);

    string instructions = fileString.substr(fileString.find("\n\n")+1,fileString.length());
    stringstream ss(instructions);
    string instruction;

    while(getline(ss,instruction,'\n')){
      proccessInstrcution(stackedRows, instruction);
    }

    for(auto &row: stackedRows){
      char temp = row.top();
      cout << temp << " ";

    }

  }

  file.close();
  return 0;
}
