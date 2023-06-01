#include <iostream>
#include <string>

using namespace std;

bool redo();
void multiplication();

int main()
{
  do
  {
  cout << "1. Multiplication" << endl;
  } while (redo() == true);
}

void multiplication()
{
  int row, col, value, row2, col2, value2;
  cout << "What are the dimensions of the matrix 1? Enter as m n" << endl;
  cin >> row >> col;
  
  for (int i = 0; i < row; i ++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << "What is the value in " << i << "row and " << j << "column?" << endl;
      cin >> value;
    }
  }
    
      cout << "What are the dimensions of the matrix 2? Enter as m n" << endl;
  cin >> row >> col;
  
  for (int i = 0; i < row; i ++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << "What is the value in " << i << "row and " << j << "column?" << endl;
      cin >> value;
    }
  }
  
  
}

bool redo()
{
  string redo;
  
  cout << "Continue?" << endl;
  cin >> redo;
  
  if (redo == "yes"
      {
        return true;
      }
      else if (redo == "no"
               {
               return false;
               }
                 
  
}
