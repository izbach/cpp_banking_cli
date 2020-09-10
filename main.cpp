#include <iostream>
#include <string>
#include <climits>
#include <sstream> //string stream
#include <fstream> //file stream
#include <vector>

using namespace std;

// SETUP FUNCTIONS FOR ADDING AND UPDATING RECORDS
int get_account_number()
{
    while(true)
    {
        cout << "\nEnter Account Number: ";
        int AccountNumber;
        cin >> AccountNumber;
        
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\nInvalid number please try again\n";
        }
        else
        {
            cin.ignore(INT_MAX, '\n');
            return AccountNumber;
        }
    }
}
string get_first_name()
{
    string FirstName;
    cout << "\nEnter First Name: ";
    cin >> FirstName;
    cin.ignore(INT_MAX, '\n');
    return FirstName;
}
string get_last_name()
{
    string LastName;
    cout << "\nEnter Last Name: ";
    cin >> LastName;
    cin.ignore(INT_MAX, '\n');
    return LastName;
}
double get_balance()
{
    while(true)
    {
        cout << "\nEnter Balance: ";
        double Balance;
        cin >> Balance;
        
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\nInvalid number please try again\n";
        }
        else
        {
            cin.ignore(INT_MAX, '\n');
            return Balance;
        }
    }
}
// SETUP FUNCTIONS FOR SEARCHING AND SHOWING RECORDS


void add_record()
{
    string FirstName, LastName;
    int AccountNumber;
    double Balance;
    
    AccountNumber = get_account_number();
    FirstName = get_first_name();
    LastName = get_last_name();
    Balance = get_balance();
    
    ofstream myFile("db.csv", fstream::app);
    myFile << AccountNumber << "," << FirstName << "," << LastName << "," << Balance;
    myFile.close();
    
    return;
}

void show_record()
{
    bool validRecord = false;
    string AccountNumber;
    string FirstName, LastName;
    string Balance;
    string SearchAccount = to_string(get_account_number());
    ifstream myFile;
    myFile.open("db.csv");

        for( std::string line; getline( myFile, line ); )
        {
                vector<string> result;
                stringstream s_stream(line); //create string stream from the string
                while(s_stream.good()) 
                {
                    string substr;
                    getline(s_stream, substr, ','); //get first string delimited by comma
                    result.push_back(substr);
                }
                if(SearchAccount == result.at(0))
                {
                    validRecord = true;
                    AccountNumber = result.at(0);
                    FirstName = result.at(1);
                    LastName = result.at(2);
                    Balance = result.at(3);
                }

        if(validRecord){break;}
        }
    
    myFile.close();
    if(validRecord)
    {
        cout << "\nHere is the file for account #" << AccountNumber;
        cout << "\nTheir name is " << FirstName << " " << LastName;
        cout << "\nTheir current balance is $" << Balance << endl << endl;
    } else {
        cout << "You have entered an invalid account number\n\n";
    }

    return;
}
void search_record()
{
    
    return;
}
void update_record()
{
    return;
}
void delete_record()
{
    return;
}
int main()
{
    bool quit = false;
    while(!quit){
        bool cond;
        int choice;
        cout << "***Account Information System***\n";
        cout << "Select one of the options below\n";
        cout << "       1-->Add record to the file\n";
        cout << "       2-->Show record from the file\n";
        cout << "       3-->Search record from the file\n";
        cout << "       4-->Update record\n";
        cout << "       5-->Delete record\n";
        cout << "       6-->Quit\n";
        do  
            {  
                cout << "Enter your choice: ";
                cin >> choice;
                
                cond = cin.fail();
  
                cin.clear();  
                cin.ignore(INT_MAX, '\n');  
  
            }while(cond); 
        switch(choice)
        {
            case 1:
                add_record();
                break;
            case 2:
                show_record();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                quit = true;
                break;
            default:
                cout << "\n***Invalid number please try again***\n\n";
        }
        }

    
    return 0;
}
