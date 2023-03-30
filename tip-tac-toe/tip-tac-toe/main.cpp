#include <iostream>
using namespace std;

// Convert number in normal index
void get_index(int x, int& i, int& j)
{
    if (x == 1) { i = 1; j = 1; }
    if (x == 2) { i = 1; j = 2; }
    if (x == 3) { i = 1; j = 3; }
    if (x == 4) { i = 2; j = 1; }
    if (x == 5) { i = 2; j = 2; }
    if (x == 6) { i = 2; j = 3; }
    if (x == 7) { i = 3; j = 1; }
    if (x == 8) { i = 3; j = 2; }
    if (x == 9) { i = 3; j = 3; }
}

int main()
{
    int N;
    int X;
    int k, l, i;
    int S1, S2;
    bool check;
    // -1 (not X, not O), 1 (its X), 0 (its O)
    int A[4][4] = { -1 }; //For convenience, let's start with [1][1]

    cin >> N;

    for (i = 0; i < N; i++)
    {
        check = false;

        // Clean playing field
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                A[i][j] = -9;

        for (int j = 1; j <= 9; j++)
        {
            if (check == true)
            {
                cin >> X;
                continue;
            }
            cin >> X;
            get_index(X, k, l);
            if (j % 2 == 0) A[k][l] = 0;
            else A[k][l] = 1;

            // End Check (begin)
            // Rows and columns
            for (k = 1; k <= 3; k++)
            {
                S1 = 0;
                S2 = 0;
                for (l = 1; l <= 3; l++)
                {
                    S1 = S1 + A[k][l];
                    S2 = S2 + A[l][k];
                }
                if ((S1 == 3) || (S1 == 0))
                {
                    cout << j << ' ';
                    check = true;
                    break;
                }
                if ((S2 == 3) || (S2 == 0))
                {
                    cout << j << ' ';
                    check = true;
                    break;
                }
            }
            if (check == true) continue;
            // Diagonals
            S1 = A[1][1] + A[2][2] + A[3][3];
            S2 = A[1][3] + A[2][2] + A[3][1];
            if ((S1 == 3) || (S1 == 0))
            {
                cout << j << ' ';
                check = true;
                continue;
            }
            if ((S2 == 3) || (S2 == 0))
            {
                cout << j << ' ';
                check = true;
                continue;
            }
            // End Check (end)
        }
        if (check == false) cout << 0 << ' ';
    }

    return 0;
}