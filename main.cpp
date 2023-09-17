#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

bool quit(char);
void validate(char, vector<int> &n);
void print_list(const vector<int> &n);
void add_number(vector<int> &n);
void Mean(vector<int> &n);
void find_smallest(vector<int> &n);
void find_largest(vector<int> &n);
void clear_list(vector<int> &n);

enum options {print = 'P', add = 'A', mean = 'M', smallest = 'S', largest = 'L', clean = 'C', qu = 'Q'};

int main()
{
        char inp;
        vector<int> numbers;

    do{

        cout << "\n\n\tList manupulating System\n" << endl;
        cout << "\t\t01. Print the list(P) " << endl;
        cout << "\t\t02. Add a number(A) " << endl;
        cout << "\t\t03. Print the mean of the list(M) " << endl;
        cout << "\t\t04. Print the smallest number in the list(S) " << endl;
        cout << "\t\t05. Print the largest number in the list(L) " << endl;
        cout << "\t\t06. Clear the list(C) " << endl;
        cout << "\t\t07. Quit(Q) " << endl;


        cout << "\t\t\n\nEnter you option to perform : ";
        cin >> inp;
        validate(inp, numbers);

    }while(quit(inp));


    return 0;
}


bool quit(char inp)
{
    char INP = toupper(inp);
    if(INP == 'Q')
        return false;

    return true;
}

void validate(char inp, vector<int> &n)
{
    char INP = toupper(inp);

    switch((int)INP)
    {
    case print:
        print_list(n);
        break;
    case add:
        add_number(n);
        break;
    case mean:
        Mean(n);
        break;
    case smallest:
        find_smallest(n);
        break;
    case largest:
        find_largest(n);
        break;
    case clean:
        clear_list(n);
        break;
    case qu:
        cout << "\n\n\t\tThank you!!\n\n\n" << endl;
    default:
        cout << "\n\nWrong input! Check the options menu. " << endl;
    }
}

void print_list(const vector<int> &n)
{
    if(n.size() == 0){
        cout << "\nThe list is empty" << endl;
    }else{
        cout << "List : [ ";
        for(int val:n){
            cout << val << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
}

void add_number(vector<int> &n)
{
    int val;
    cout << "\n\nEnter the number that you want to add : ";
    cin >> val;
    cout << "\n" << val << " is added to the list. " << endl;

    n.push_back(val);
}

void Mean(vector<int> &n)
{
    double sum {};
    double mean {};

    for(int val: n){
        sum += val;
    }

    mean = (sum/n.size());

    cout << "\nThe mean of the list is : " << mean << endl;
}

void find_smallest(vector<int> &n)
{
    if(n.size() != 0){
        int smallest = numeric_limits<int>::max();
        for(int val: n){
            if(val < smallest) smallest = val;
        }

        cout << "The smallest value of the list is : " << smallest << endl;
    }else{
        cout << "The list is empty : " << endl;
    }

    cout << endl;
}


void find_largest(vector<int> &n)
{
    if(n.size() != 0){
        int largest = numeric_limits<int>::max()*(-1);
        for(int val: n){
            if(val > largest) largest = val;
        }

        cout << "The largest value of the list is : " << largest << endl;
    }else{
        cout << "The list is empty" << endl;
    }

    cout << endl;
}

void clear_list(vector<int> &n)
{
    char inp;
    cout << "Are you sure! You want to clear the list(Y/N) : ";
    cin >> inp;

    if(inp == 'Y' || inp == 'y'){
        n.clear();
        cout << "\nList cleared successfully " << endl;
    }
}
