#include <iostream>

#include <vector>

// ---------------------------- Class -----------------------------------
class Square {
    
private:
    
    // Represents final result
    int output;
    
    std::vector<std::vector<int>> grid;
    
public:
    
    // Paramaterized Constructor
    Square(std::vector<std::vector<int>> grid);
    
    // Function used to generate equal pairs
    int EqualPairs();
    
    // Output object
    friend std::ostream & operator << (std::ostream &, Square &s);
    
};
// ----------------------------------------------------------------------
// Paramaterized Constructor
Square :: Square(std::vector<std::vector<int>> grid)
{
    this -> grid = grid;
}

// ----------------------------------------------------------------------
// Find equal row and column pair
int Square :: EqualPairs()
{
    int count = 0;
    
    bool flag = true;
    
    std::vector<int>temp;
    
    for(std::vector<std::vector<int>>::size_type i = 0; i < grid.size(); i++)
    {
        for(std::vector<std::vector<int>>::size_type j = 0; j < grid[i].size(); j++)
        {
            temp.push_back(grid[i][j]);
        }
        
        for(std::vector<std::vector<int>>::size_type x = 0; x < grid.size(); x++)
        {
            for(std::vector<std::vector<int>>::size_type y = 0; y < grid[i].size(); y++)
            {
                if(grid[y][x] != temp[y])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                count++;
            flag = true;
        }
        
        temp.clear();
    }
    
    return count;
}
// ----------------------------------------------------------------------
// Output object
std::ostream & operator << (std::ostream &o, Square &square)
{
    o << square.EqualPairs();
    
    return o;
}
// ----------------------------------------------------------------------

int main(int argc, const char * argv[]) {

    // Initialize object
    Square square({{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}});
    
    // Output object
    std::cout << "There are " << square << " equal row and column pairs.\n\n";
    
    return 0;
}
// ----------------------------------------------------------------------
