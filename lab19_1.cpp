#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename ,vector<string> &name , vector<int> &score , vector<char> &grade){
    ifstream read;
    read.open(filename);
    string text;
    char format[] = "%[^:]:%d %d %d";
    string a[100];
    int b,c,d;
    while(getline(read,text))
    {
        sscanf(text.c_str,format,a,b,c,d);
        name.push_back(a);
        score.push_back(b+c+d);
        grade.push_back(score2grade(b+c+d));
    }
}

void getCommand(string command , string key){
    cout << "Please input your command: ";
    cin >> command >> key;
}

void searchName(vector<string> &names , vector<int> &scores , vector<char> &grades , string key){
    for(int i=0 ; i < names.size() ; i++)
    {
        if(key==names[i])
        {
            cout << names[i] << "'s score = " << scores[i] << endl;
            cout << names[i] << "'s grade = " << grades[i] << endl;
        }
        else
        {
            cout << "Cannot found.";
        }
    }
}

void searchGrade(vector<string> &name , vector<int> &score , vector<char> &grade , string key){
    for(int i=0 ; i < name.size() ; i++)
    {
        if(key==toUpperStr(grade[i]))
        {
            cout << name[i] << " (" << score[i] << ")" << endl; 
        }
        else
        {
            cout << "Cannot found.";
        }
    }
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
