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

    int matrix[row][col];
    int sum[row][col];

    for (int d = 0; d < row; d++)
    {
        for (int e = 0; e < col; e++)
        {
            sum[d][e] = 0;
            matrix[d][e] = 0;
        }
    }

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < row; j++)
        {
            for (int a = 0; a < col; a++)
            {
                cout << "Enter the value in row " << (j + 1) << " and column " << (a + 1) << " : ";
                cin >> matrix[j][a];
                sum[j][a] += matrix[j][a];
            }
        }

        cout << endl
             << "Please enter the values for the next matrix" << endl
             << endl;
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
    int row, col;

    cout << "Please enter the dimensions for matrices " << endl;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of cols: ";
    cin >> col;

    int matrix[row][col];
    int transpose[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            transpose[j][i] = 0;
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter the value in row " << (i + 1) << " and column " << (j + 1) << " : ";
            cin >> matrix[i][j];
            transpose[j][i] = matrix[i][j];
        }
        cout << endl;
    }

cout << "The transpose of: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    cout << endl << "is : " << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << transpose[i][j];
        }
        cout << endl;
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
