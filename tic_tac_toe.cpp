#include <iostream>
#include <vector>
#include <cctype>
#include <utility>
#include <map>

using namespace std;

char humanplayer = 'x';
char AIplayer = 'y';

vector<int> CheckEmpty(int A[9])
{
    vector<int> vec;
    for (int i = 0; i < 9; i++)
    {
        if (A[i] != humanplayer && A[i] != AIplayer)
        {
            vec.push_back(i);
        }
    }
    return vec;
}

bool CheckWinning(int A[9], char player)
{
    if ((A[0] == player && A[1] == player && A[2] == player) ||
        (A[3] == player && A[4] == player && A[5] == player) ||
        (A[6] == player && A[7] == player && A[8] == player) ||
        (A[0] == player && A[3] == player && A[6] == player) ||
        (A[1] == player && A[4] == player && A[7] == player) ||
        (A[2] == player && A[5] == player && A[8] == player) ||
        (A[0] == player && A[4] == player && A[8] == player) ||
        (A[2] == player && A[4] == player && A[6] == player))
    {
        return true;
    }
    return false;
}
pair<int, int> Minimax(int A[9], char player)
{
vector<int> vec = CheckEmpty(A);


if (CheckWinning(A, humanplayer))
{
    return make_pair(-10, -1);
}
else if (CheckWinning(A, AIplayer))
{
    return make_pair(10, -1);
}
else if (vec.size() == 0)
{
    return make_pair(0, -1);
}
int score, index;
vector<pair<int, int>> Myvec;

for (int i = 0; i < vec.size(); i++)
{
    index = A[vec[i]];
    A[vec[i]] = player;

    if (player == AIplayer)
    {
        score = Minimax(A, humanplayer).first;
    }
    else if (player == humanplayer)
    {
        score = Minimax(A, AIplayer).first;
    }
    A[vec[i]] = index;
    Myvec.push_back(make_pair(score,vec[i]));
}
int bestmove = -1;

if (player == AIplayer)
{
    int bestscore = -100000;
    for (int i = 0; i < Myvec.size(); i++)
    {
        if (Myvec[i].first > bestscore)
        {
            bestscore = Myvec[i].first;
            bestmove = i;
        }
    }
}
if (player == humanplayer)
{
    int bestscore = 100000;
    for (int i = 0; i < Myvec.size(); i++)
    {
        if (Myvec[i].first < bestscore)
        {
            bestscore = Myvec[i].first;
            bestmove = i;
        }
    }
}
return make_pair(Myvec[bestmove].first,Myvec[bestmove].second);
}
int main()
{
    int A[9];
    int n;

    for (int i = 0; i < 9; i++)
    {
        A[i] = i;
    }

    for (int i = 0; i < 9; i++)
    {

        cout << "It's human player's turn" << endl;
        cin >> n;
        A[n] = humanplayer;

        if (CheckEmpty(A).size() < 5)
        {
            if (CheckWinning(A, humanplayer))
            {
                cout << "Human won which isn't possible" << endl;
                return 1;
            }
            if (CheckEmpty(A).size() == 0)
            {
                cout << "Tie" << endl;
                break;
            }
        }

        cout << "It's AI player's turn" << endl;
        pair<int, int> result = Minimax(A, AIplayer);
        n = result.second;
        A[n] = AIplayer;
        cout << "AI plays at position " << n << endl;

        if (CheckEmpty(A).size() < 5)
        {
            if (CheckWinning(A, AIplayer))
            {
                cout << "AI won!!!" << endl;
                return 1;
            }
            if (CheckEmpty(A).size() == 0)
            {
                cout << "Tie" << endl;
                break;
            }
        }
    }
    return 0;
}
