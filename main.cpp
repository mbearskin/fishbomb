//Programmer: Martha Winger-Bearskin
//Class: CS 153 section A
//Date: 09/02/13


#include <iostream>
using namespace std;

int main()
{
    
    //Variables:
    
    int numGrids;
    int rows;
    int colums;
    int power;
    int sum; // holds sum to compare if it's the higest number of fish you can catch
    int bestSum= 0;
    int bestX, bestY; 
    int **grid;
    
    
    
    
    cin>> numGrids;
    
    // Create, fill and evaluate each data grid
    for(int f= 0; f<= numGrids; f++)
    {
        
        cin>> colums;
        cin>> rows;
        cin>> power;
        
        //Create 2D array
        grid = new int*[rows];
        for(int i=0; i<rows; i++)
        {
            grid[i] = new int[colums];
        }
        // grid[rows][cols]
        
        //fill Array
        for(int i=0; i<rows; i++)
        {
            for (int j=0; j<colums; j++)
            {
                cin >> grid[i][j];
            }
        }
        
        
        //Evaluate grid
        int gap = (power/2);
        bestSum = 0;
        
        for(int x=gap; x < rows-gap; x++) // x location
        {
            for(int y=gap; y < colums-gap; y++) //y location
            {
                
                sum = 0;
                for(int j= (x-gap); j <= (x+gap) ; j++)
                {
                    for(int k= (y-gap); k<= (y+gap); k++)
                    {
                        
                        sum += grid[j][k];
                    }
                 }
                
                
                
                if (sum > bestSum)
                {
                    bestSum = sum;
                    bestX = x;
                    bestY = y;
                }
            }
        }
        
        
        cout << "\n#" << f << ": (" << bestY << ", " << bestX << ") " << bestSum << endl;
        
        
        
        //deallocate array
        for(int k=0; k< rows; k++)
        {
            delete [] grid[k];
        }
        delete[] grid;
    }
        
    
    return 0;
    
}




