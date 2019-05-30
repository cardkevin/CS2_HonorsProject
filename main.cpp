#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const int MAX_DIMENSION = 999;
const int DISPLAY_LENGTH = 50;
const int SPACE_B4_COMMAND = 2;
const int SPACE_B4_DESCRIPTION = 10;

void menu(string questionArray[], int& questionSize, string answerArray[], int& answerSize);
//function to display options to the user and ask the user to choose

void open(ifstream& fin, string fileName);
//function to open an input file
void close(ifstream& fin);
//function to close an input file

void open(ofstream& fout, string fileName);
//function to open an output file
void close(ofstream& fout);
//function to close an input file
string format_QandA(string text, string QorA);
//function to format answer or question that suits the plist file

void findQuestion(ifstream& fin);
//loops through the file from the beginning and looks for "<key>questions</key>"
//since there will always be a "<key>text</key>" at the line before the question, look for that line
//get the next line and extract the text using the function extractText();

string extractText(string& xml);
//takes "<tag>TEXT</tag>" as the argument and returns "TEXT"
//works by ignoring everything from '<' to '>'

int fillArray(string fileName, string textArray[]);
//function to pull answers/questions from the file indicated by fileName
//put the answers/questions into textArray[]

void userView(string textArray[], int arraySize);
//function to format and display the questions and answers files to the user
//This function is different from displayFile because the other one displays everything in a file as it is
//whereas this function formats the content of the file before outputting it
//This function should only be used for "answers.txt" and "questions.txt"

void addQorA(string textArray[], int& arraySize, string whatToAdd);
//function to append another string at the end of an array

void delQorA(string textArray[], int& arraySize, int whereToDelete);
//function to delete something in an array

void stringToLower(string& text);
//function to convert a string into all lowercase

vector<char> parseCommandLine(string choice, unsigned int& start);
//reads the string "choice", find the first word, store it in a char vector and return it

void displayVector(vector<char> dummyVector);

bool compareVector(vector<char> dummyVector, string command);
//compare vector to a command. returns 1 if they are the same. 0 if they are not

int main()
{
    ifstream fin;
    ofstream fout;
    string questionArray[MAX_DIMENSION];
    string answerArray[MAX_DIMENSION];
    int questionSize;
    int answerSize;
    
    string test = "testing";
    
    //initialization
    questionSize = fillArray("questions.txt", questionArray);
    answerSize = fillArray("answers.txt", answerArray);
    
    //menu
    menu(questionArray, questionSize, answerArray, answerSize);
    
    close(fout);
    return 0;
}

void menu(string questionArray[], int& questionSize, string answerArray[], int& answerSize)
{
    cout.setf(ios::left);
    
    string choice;
    while (true)
    {
        cout << "CS2_honors:~ vhtoolkit$ ";
        getline(cin, choice);
        stringToLower(choice);
        //use getline to get the whole line of user input
        //then, store the line into a C string. parse the c string into separate chuncks.
        
        unsigned int start = 0;
        if (compareVector(parseCommandLine(choice, start), "display"))
        {
            if (compareVector(parseCommandLine(choice, start), "answers"))
            {
                userView(answerArray, answerSize);
            }
            else if (compareVector(parseCommandLine(choice, start), "questions"))
            {
                userView(questionArray, questionSize);
            }
            else
            {
                cout << "Display name not found.\n"
                << "Available commands:\n"
                << setw(SPACE_B4_COMMAND) << " " << setw(SPACE_B4_DESCRIPTION) << "questions" << endl
                << setw(SPACE_B4_COMMAND) << " " << setw(SPACE_B4_DESCRIPTION) << "answers" << endl;
            }
        }
        else if (compareVector(parseCommandLine(choice, start), "vhtoolkit"))
        {
            cout << endl
            << "Usage: \n"
            << setw(SPACE_B4_COMMAND) << " " << setw(SPACE_B4_DESCRIPTION) << "<command>" << "[options]"
            << endl << endl;
            
            
            cout << "Available commands:\n"
            << setw(SPACE_B4_COMMAND) << " " << setw(SPACE_B4_DESCRIPTION) << "display" << "Display either the questions or answers in the vhtoolkit" << endl
            << setw(SPACE_B4_COMMAND) << " " << setw(SPACE_B4_DESCRIPTION) << "quit" << "Quit the program" << endl;
        }
        
        else if (compareVector(parseCommandLine(choice, start), "quit"))
        {
            break;
        }
        else if (compareVector(parseCommandLine(choice, start), " "))
        {
            continue;
        }
        else
        {
            cout << "Unknown command: " << choice <<  endl << endl
            << "Use \"vhtoolkit\" to see available  commands\n";
        }
    }
}

void open(ifstream& fin, string fileName)
{
    fin.open(fileName);
    if (fin.fail())
    {
        cout << "Failed to open " << fileName << endl;
        exit(1);
    }
}

void close(ifstream& fin)
{
    fin.close();
}

void open(ofstream& fout, string fileName)
{
    fout.open(fileName);
    if (fout.fail())
    {
        cout << "Failed to open " << fileName << endl;
        exit(1);
    }
}

void close(ofstream& fout)
{
    fout.close();
}

void findQuestion(ifstream& fin)
{
    string line;
    bool doubleBreak = false;
    while (!fin.eof())
    {
        getline(fin, line);
        if (line == "<key>questions</key>") //after finding the questions tag, loop until answer tag is seen
        {
            while (!fin.eof()) //keep looping through the file
            {
                getline(fin, line);
                if (line == "<key>text</key>")
                {
                    getline(fin, line);
                    cout << extractText(line) << endl;
                }
                else if (line == "<key>answers</key>")
                {
                    doubleBreak = true;
                    break;
                }
            }
        }
        else if (doubleBreak)
            break;
    }
}

string extractText(string& xml)
{
    vector<char> text;
    bool tag = false;
    for (unsigned int i = 0; i < xml.length(); i++)
    {
        if (xml[i] == '<')
        {
            tag = true;
            continue;
        }
        else if (tag)
        {
            if (xml[i] == '>')
                tag = false;
            continue;
        }
        text.push_back(xml[i]);
    }
    string str(text.begin(), text.end());
    return str;
}

int fillArray(string fileName, string textArray[])
{
    ifstream fin;
    
    open(fin, fileName);
    
    string line;
    int index = 0;
    while (!fin.eof())
    {
        getline(fin, line);
        textArray[index] = line;
        index++;
    }
    
    close(fin);
    
    return index;
}

void userView(string textArray[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (textArray[i].length() <= DISPLAY_LENGTH)
        {
            cout << i << " " << textArray[i] << endl << endl;
        }
        else
        {
            cout << i << " ";
            for (unsigned int j = 0; j < DISPLAY_LENGTH; j++)
            {
                cout << textArray[i][j];
            }
            cout << "..." << endl << endl;
        }
    }
}

void addQorA(string textArray[], int& arraySize, string whatToAdd)
{
    textArray[arraySize] = whatToAdd;
    arraySize++;
}

void delQorA(string textArray[], int& arraySize, int whereToDelete)
{
    return;
}

void stringToLower(string& text)
{
    for (unsigned int i = 0; i < text.length(); i++)
    {
        text[i] = tolower(text[i]);
    }
}

vector<char> parseCommandLine(string choice, unsigned int& start)
{
    vector<char> inputVector;
    cout << "0\n";
    for (unsigned int i = start; i < choice.length(); i++)
    {
        if (choice[i] != ' ')
        {
            cout << "1\n";
            inputVector.push_back(choice[i]);
        }
        else
        {
            cout << "2\n";
            start = i + 1;
            inputVector.resize(i);
            break;
        }
    }
    
    if (inputVector.size() == 0)
    {
        inputVector.push_back(' ');
        inputVector.resize(1);
        start += 1;
    }
    cout << "r\n";
    return inputVector;
}

void displayVector(vector<char> dummyVector)
{
    for (unsigned int i = 0; i < dummyVector.size(); i++)
    {
        cout << "'" << dummyVector[i] << "' ";
    }
    cout << endl;
}

bool compareVector(vector<char> dummyVector, string command)
{
    int bigger;
    
    if (dummyVector.size() > command.length())
        bigger = dummyVector.size();
    else
        bigger = command.length();
    
    for (int i = 0; i < bigger; i++)
    {
        if (dummyVector[i] != command[i])
            return 0;
    }
    return 1;
}
