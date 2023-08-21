#include <iostream>
#include <cctype>
using namespace std;

bool Setvalues(char A[3][3], int n, char x)
{
    if (n == 1 && A[0][0] == ' ')
    {
        A[0][0] = x;
        return true;
    }
    if (n == 2 && A[0][1] == ' ')
    {
        A[0][1] = x;
        return true;
    }
    if (n == 3 && A[0][2] == ' ')
    {
        A[0][2] = x;
        return true;
    }
    if (n == 4 && A[1][0] == ' ')
    {
        A[1][0] = x;
        return true;
    }
    if (n == 5 && A[1][1] == ' ')
    {
        A[1][1] = x;
        return true;
    }
    if (n == 6 && A[1][2] == ' ')
    {
        A[1][2] = x;
        return true;
    }
    if (n == 7 && A[2][0] == ' ')
    {
        A[2][0] = x;
        return true;
    }
    if (n == 8 && A[2][1] == ' ')
    {
        A[2][1] = x;
        return true;
    }
    if (n == 9 && A[2][2] == ' ')
    {
        A[2][2] = x;
        return true;
    }
    return false;
}
bool Checkwin(char A[3][3], char x)
{
    for (int i = 0; i < 3; i++)
    {
        int j = 0;
        if (A[i][j] == A[i][j + 1] && A[i][j] == A[i][j + 2] && A[i][j] != ' ')
        {
            return true;
        }
    }
    for (int j = 0; j < 3; j++)
    {
        int i = 0;
        if (A[i][j] == A[i + 1][j] && A[i][j] == A[i + 2][j] && A[i][j] != ' ')
        {
            return true;
        }
    }
    if (A[0][0] == A[1][1] && A[0][0] == A[2][2] && A[0][0] != ' ')
    {
        return true;
    }
    if (A[0][2] == A[1][1] && A[1][1] == A[2][0] && A[1][1] != ' ')
    {
        return true;
    }
    return false;
}
bool Legalmove(int n,char x)
{
    if (n > 9 || n < 1 || !isalpha(x))
    {
        return false;
    }
    return true;
}
int main()
{
    char A[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            A[i][j] = ' ';
        }
    }
    int n, count = 9;
    char x, y;
    while (count>0)//isEmpty(A)
    {
        cout << "Player 1 should play ";
        cin >> n;
        cin >> x;
        if (!(Legalmove(n,x)) || !(Setvalues(A, n, x)))
        {
            break;
        }

        count--;

        if (count < 5)
        {
            if (Checkwin(A, x))
            {
                cout << "player 1 has won!!!";
                return 1;
            }
            if(count==0){
            cout << "It's a tie";
            return 1;
        }
            
        }
        cout << "Player 2 should play ";
        cin >> n;
        cin >> y;
        if (!(Legalmove(n,y)) || !(Setvalues(A, n, y)))
        {
            break;
        }
        count--;

        if (count < 5)
        {
            if (Checkwin(A, y))
            {
                cout << "player 2 has won!!!";
                return 1;
            }
            if(count==0){
            cout << "It's a tie";
            return 1;
        }
            
        }
        
    }
    

    return 0;
}
