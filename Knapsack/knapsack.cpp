/**
* @file knapsack.cpp Dynamic programming algorithm for 
* solving 0-1 Knapsack problem
*
* @author Pinak Das
* @date 3/16/16
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Declaration of Knapsack class
class Knapsack{
  private:
    int noItems, capacity, value, weight;
    int *weightArray, *valueArray;
    int **ValueMatrix, **BacktrackMatrix;
    vector<int> itemsChosen;
  public:
    ~Knapsack();
    void getInputs();              // reads in data
    void findItems();         // calculates best value of items
    void backTrack(int row, int col); // backtracks items selected
    void print();                       //prints out data
};

/** @brief Destructor to deallocate the memory
 * allocated for the dynamic arrays
 */
Knapsack::~Knapsack()
{
  delete[] weightArray;
  delete[] valueArray;
  for(int i=1;i<=noItems;i++)
  {
    delete[] ValueMatrix[i];
  }
  delete[] ValueMatrix;
  for(int i=1;i<=noItems;i++)
  {
    delete[] BacktrackMatrix[i];
  }
  delete[] BacktrackMatrix;
}

/** @brief function to read weights and values of items and store
 * them in an array. Create two 2 dimensional array, first one to hold
 * optimal value according to weight. The second is to backtrack the
 * items that are chosen.
 */
void Knapsack::getInputs()
{
  cin>>noItems;
  cin>>capacity;
  weightArray=new int[noItems];
  valueArray=new int[noItems];
  for(int i=1;i<=noItems;i++)
  {
    cin>>value;
    valueArray[i]=value;
  }
  for(int i=1;i<=noItems;i++)
  {
    cin>>weight;
    weightArray[i]=weight;
  }
  ValueMatrix=new int*[noItems];
  for(int i=1;i<=noItems;i++)
  {
    ValueMatrix[i]=new int[capacity+1];
  }
  BacktrackMatrix=new int*[noItems];
  for(int i=1;i<=noItems;i++)
  {
    BacktrackMatrix[i]=new int[capacity+1];
  }
}

/** @brief Implements dynamic programming to fill
 * two 2-dimensional arrays. One for best value
 * other for backtracking. Call the backTrack function
 */
void Knapsack::findItems()
{
  for(int j=0;j<=capacity;j++)
  {
    if(weightArray[1]>j)
    {
      ValueMatrix[1][j]=0;
      BacktrackMatrix[1][j]=j;
    }
    else
    {
      ValueMatrix[1][j]=valueArray[1];
      BacktrackMatrix[1][j]=j-weightArray[1];
    }
  }
  for(int i=2;i<=noItems;i++)
  {
    for(int j=0;j<=capacity;j++)
    {
      if(weightArray[i]>j)
      {
        ValueMatrix[i][j]=ValueMatrix[i-1][j];
        BacktrackMatrix[i][j]=j;
      }
      else if(weightArray[i]<=j)
      {
        if(ValueMatrix[i-1][j]>
													ValueMatrix[i-1][j-weightArray[i]]+valueArray[i])
        {
          ValueMatrix[i][j]=ValueMatrix[i-1][j];
          BacktrackMatrix[i][j]=j;
        }
        else
        {
          ValueMatrix[i][j]=ValueMatrix[i-1][j-weightArray[i]]+valueArray[i];
          BacktrackMatrix[i][j]=j-weightArray[i];
        }
      }
    }
  }
  backTrack(noItems, capacity);
}

/** @brief Implements backtracking to retrieve the selected
 * items and put them in a vector
 * @param int row
 * @param int col
 */
void Knapsack::backTrack(int row, int col)
{
  if(row==0)
  {
    return;
  }
  if(row==1 && BacktrackMatrix[1][col]==1)
  {
    itemsChosen.push_back(1);
    return;
  }
  else
  {
    if(BacktrackMatrix[row][col]==col)
    {
      backTrack(row-1,col);
    }
    else
    {
      backTrack(row-1, col-weightArray[row]);
      itemsChosen.push_back(row);
    }
  }
}

/** @brief function to print the best value
 * and items selected
 */
void Knapsack::print()
{
  cout<<ValueMatrix[noItems][capacity]<<endl;
  for( vector<int>::iterator iter = itemsChosen.begin();
  iter != itemsChosen.end(); iter++){
    cout << *iter << " ";
  }
  cout<<endl;
}

// main function to run the program
int main()
{
  Knapsack knap;
  knap.getInputs();
  knap.findItems();
  knap.print();
  return 0;
}
