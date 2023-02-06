#include <iostream>
using namespace std;
bool Check(char A[3][3], char x)
{   
    int m = 0, n = 0, j = 0, foo = 1,goo=0;
    // Checks if winning is possible diagonally
    if (A[m][n] == A[m + 1][n + 1] && A[m][n] == A[m + 2][m + 2] || A[m][n + 2] == A[m + 1][n + 1] && A[m][n + 2] == A[m + 2][n])
    {
        if (A[m][n] == x)
        {
            // cout<< "block 1 is being executed 1 ...";
            foo = 0;
            
        }
    }
    // Checks if winning is possible linearly
    else if (foo == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            int j = 0;
            if (A[i][j] == A[i][j + 1] && A[i][j] == A[i][j + 2] || A[j][i] == A[j + 1][i] && A[j][i] == A[j + 2][i])
            {
                if (A[i][j] == x)
                {   goo=1;
                cout<<"...";
                    break;
                    // cout<< "block 2 is being executed 1 ...";
                }
            }
        }
    }
    
    
        if(foo==0 || goo==1){
            return true;
        }
        return false;
    
}


int main()
{
    char A[3][3] = {0};
    int row, column;
    char x, y;
    int iterator;
    int fount = 1, mount = 1;
    for (iterator = 0; iterator < 5; iterator++)
    {
        cout << "Player 1 may give the input: ";
        cin >> row;
        
        cin >> column;
        
        cin >> x;

        A[row][column] = x;

        if (iterator >= 2 && Check(A, x) == 1)
        {
            cout << "Player 1 has won...";
            fount = 0;
            break;
        }
        if (fount == 1 && iterator < 4)
        {
            cout << "Player 2 may give the input: ";
            cin >> row;
            
            cin >> column;
            
            cin >> y;

            A[row][column] = y;
            if (iterator >=2 && Check(A, y)==1 )
            {
                cout << "Player 2 has won...";
                mount = 0;
                break;
            }
        }
    }
    if (mount == 1 && fount == 1 )
    {
        cout << "It's a tie... ";
    }

    return 0;
}