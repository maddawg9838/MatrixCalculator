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

    cout << "Your final sum: " << endl;

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
    int row1, col1, row2, col2;

    cout << "Enter rows and columns for first matrix: ";
    cin >> row1 >> col1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> row2 >> col2;

    if (col1 != row2)
    {
        cout << "Error! The column of first matrix is not equal to row of second matrix, thus they cannot be multiplied together" << endl;
    }

    int matrix1[row1][col1], matrix2[row2][col2], product[row1][col2];

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            matrix1[i][j] = 0;
        }
    }

        for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            matrix2[i][j] = 0;
        }
    }

    cout << endl
         << "Enter elements of matrix 1: " << endl;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cout << "Enter the value in row " << (i + 1) << " and column " << (j + 1) << " : ";
            cin >> matrix1[i][j];
        }
        cout << endl;
    }

    cout << endl
         << "Enter elements of matrix 2:" << endl;
    for (int a = 0; a < row2; a++)
    {
        for (int b = 0; b < col2; b++)
        {
            cout << "Enter the value in row " << (a + 1) << " and column " << (b + 1) << " : ";
            cin >> matrix2[a][b];
        }
        cout << endl;
    }

    for (int c = 0; c < row1; c++)
    {
        for (int d = 0; d < col2; d++)
        {
            product[c][d] = 0;
        }
        cout << endl;
    }

    for (int e = 0; e < row1; e++)
    {
        for (int f = 0; f < col2; f++)
        {
            for (int g = 0; g < col1; g++)
            {
                product[e][f] += matrix1[e][g] * matrix2[g][f];
            }
        }
    }

    cout << endl
         << "Output Matrix from multiplying matrix 1: " << endl;
    for (int h = 0; h < row1; h++)
    {
        for (int i = 0; i < col1; i++)
        {
            cout << " " << matrix1[h][i];
        }
        cout << endl;
    }

    cout << endl
         << "to matrix 2: " << endl;
    for (int j = 0; j < row2; j++)
    {
        for (int k = 0; k < col2; k++)
        {
            cout << " " << matrix2[j][k];
        }
        cout << endl;
    }

    cout << endl
         << "results in this: " << endl;
    for (int l = 0; l < row1; l++)
    {
        for (int m = 0; m < col2; m++)
        {
            cout << " " << product[l][m];
        }
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

    cout << endl
         << "is : " << endl;

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
