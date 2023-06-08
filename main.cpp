#include <iostream>
#include <string>

using namespace std;

bool redo();
void addition();
void multiplication();
void transpose();

int main()
{
    int option;

    do
    {
        cout << "1. Addition" << endl
             << "2. Multiplication" << endl
             << "3. Transpose" << endl;

        cin >> option;

        if (option == 1)
        {
            addition();
        }
        else if (option == 2)
        {
            multiplication();
        }
        else if (option == 3)
        {
            transpose();
        }
    } while (redo() == true);
}

void addition()
{
    int number, row, col;

    cout << "How many matrices are being added together? ";
    cin >> number;

    cout << "Please enter the dimensions for matrices " << endl;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of cols: ";
    cin >> col;

    int value[row][col];
    int sum[row][col];

    for (int d = 0; d < row; d++)
    {
        for (int e = 0; e < col; e++)
        {
            sum[d][e] = 0;
        }
    }

    for (int f = 0; f < row; f++)
    {
        for (int g = 0; g < row; g++)
        {
            value[f][g] = 0;
        }
    }

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < row; j++)
        {
            for (int a = 0; a < col; a++)
            {
                cout << "Enter the value in row " << (j + 1) << " and column " << (a + 1) << " : ";
                cin >> value[j][a];
                sum[j][a] += value[j][a];
            }
        }

        cout << endl << "Please enter the values for the next matrix" << endl << endl;
    }

     cout << "Your product would be: " << endl;
            for (int b = 0; b < row; b++)
            {
                for (int c = 0; c < col; c++)
                {
                    cout << sum[b][c] << " ";
                }
                cout << endl;
            }
}

void multiplication()
{
    int a[10][10], b[10][10], mult[10][10], r1, c1, r2, c2, i, j, k;

    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    // If column of first matrix in not equal to row of second matrix,
    // ask the user to enter the size of matrix again.
    while (c1 != r2)
    {
        cout << "Error! column of first matrix not equal to row of second.";

        cout << "Enter rows and columns for first matrix: ";
        cin >> r1 >> c1;

        cout << "Enter rows and columns for second matrix: ";
        cin >> r2 >> c2;
    }

    // Storing elements of first matrix.
    cout << endl
         << "Enter elements of matrix 1:" << endl;
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c1; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }

    // Storing elements of second matrix.
    cout << endl
         << "Enter elements of matrix 2:" << endl;
    for (i = 0; i < r2; ++i)
        for (j = 0; j < c2; ++j)
        {
            cout << "Enter element b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }

    // Initializing elements of matrix mult to 0.
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
        {
            mult[i][j] = 0;
        }

    // Multiplying matrix a and b and storing in array mult.
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
            for (k = 0; k < c1; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }

    // Displaying the multiplication of two matrix.
    cout << endl
         << "Output Matrix: " << endl;
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
        {
            cout << " " << mult[i][j];
            if (j == c2 - 1)
                cout << endl;
        }

    return;
}

void transpose()
{
    int a[10][10], transpose[10][10], row, column, i, j;

    cout << "Enter rows and columns of matrix: ";
    cin >> row >> column;

    cout << "\nEnter elements of matrix: " << endl;

    // Storing matrix elements
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << ": ";
            cin >> a[i][j];
        }
    }

    // Printing the a matrix
    cout << "\nEntered Matrix: " << endl;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            cout << " " << a[i][j];
            if (j == column - 1)
                cout << endl
                     << endl;
        }
    }

    // Computing transpose of the matrix
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
        {
            transpose[j][i] = a[i][j];
        }

    // Printing the transpose
    cout << "\nTranspose of Matrix: " << endl;
    for (int i = 0; i < column; ++i)
        for (int j = 0; j < row; ++j)
        {
            cout << " " << transpose[i][j];
            if (j == row - 1)
                cout << endl
                     << endl;
        }

    return;
}

bool redo()
{
    string redo;

    cout << "Continue?" << endl;
    cin >> redo;

    if (redo == "yes")
    {
        return true;
    }
    return false;
}
