#include <iostream>

#include <algorithm>

#include <vector>

#include <string>


// ------------------------------ Algorithm 1 Prototypes -----------------------------------------

// First algorithm used to collect anagrams.  This algorithm uses the sorting technique
std::vector<std::vector<std::string>> Algorithm_1(std::vector<std::string> strs);

// Checks each index of each collected anagram to determine if anagram has already been collected
bool checkIndex(int index, std::vector<std::vector<int>> AnagramIndex);

// ------------------------------ Algorithm 2 Prototypes -----------------------------------------

// Second algorithm used to collect anagrams.  This algorithm retreive asccii value of each string
std::vector<std::vector<std::string>> Algorithm_2(std::vector<std::string> strs);


// --------------------------------- Global Prototype --------------------------------------------

// Display results of each algorithm
void Print(std::string header, std::vector<std::vector<std::string>>);

// -----------------------------------------------------------------------------------------------

int main()
{
    // ------------------------------ Algorithm 1 ------------------------------
    
    // Initialize vector
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    
    // Display Results of Algorithm 1
    Print("------------ Algorithm 1 ------------\n\n",Algorithm_1(strs));
    
    // ------------------------------ Algorithm 2 ------------------------------
    
    // Initialize second vector
    strs = {"signer","dog","casters","saw","reigns","god","actress","singer","was","recasts","singer"};
    
    // Display Results of Algorithm 2
    Print("------------ Algorithm 2 ------------\n\n",Algorithm_2(strs));
    
    std::cout << "---------------------------------------------------------------------------------------\n\n";
    
    return 0;
}

// -----------------------------------------------------------------------------------------------
// First algorithm used to collect anagrams.  This algorithm uses the sorting technique
std::vector<std::vector<std::string>> Algorithm_1(std::vector<std::string> strs)
{
    // Create a copy of strs vector
    std::vector<std::string> strsCopy; strsCopy.assign(strs.begin(), strs.end());
    
    // Alphabetically sort each subscript of strs vector
    for(std::vector<std::string> :: size_type i = 0; i < strsCopy.size(); i++)
        sort(strsCopy[i].begin(),strsCopy[i].end());
    
    // ------------------------ Group Anagrams ------------------------
    
    // Contains results of all anagrams
    std::vector<std::vector<std::string>> AnagramVector;
    
    // Used as helper vector to collect subscripts one by one
    std::vector<std::string> singleAnagramVector;
    
    // Contains indices of all anagrams
    std::vector<std::vector<int>> AnagramIndex;
    
    // Used as helper vector to collect indices one by one
    std::vector<int> IndexVector;
    
    // Initiate operation
    for(std::vector<std::string> :: size_type i = 0; i < strsCopy.size(); i++)
    {
        if(checkIndex(i, AnagramIndex))
            continue;
        else
        {
            IndexVector.push_back(i);
            
            singleAnagramVector.push_back(strs[i]);
        }
        
        for(std::vector<std::string> :: size_type x = i + 1; x < strsCopy.size(); x++)
        {
            if(strsCopy[i] == strsCopy[x])
            {
                IndexVector.push_back(x);
                
                singleAnagramVector.push_back(strs[x]);
            }
        }
        
        // Insert index collection into AnagramIndex
        AnagramIndex.push_back(IndexVector);
        
        // Insert anagram collection into AnagramVector
        AnagramVector.push_back(singleAnagramVector);
        
        // Clear indexVector
        IndexVector.clear();
        
        // Clear anagram vector
        singleAnagramVector.clear();
    }
    
    return AnagramVector;
}
// -----------------------------------------------------------------------------------------------
// Second algorithm used to collect anagrams.  This algorithm retreive asccii value of each string
std::vector<std::vector<std::string>> Algorithm_2(std::vector<std::string> strs)
{
    // Create vector which contains all ascii values
    std::vector<int> asciiVector;
    
    // Determine sum of each ascii character
    int sum = 0;
    
    // Determine ascii values of strs vector
    for(std::vector<std::string> :: size_type i = 0; i < strs.size(); i++)
    {
        for(std::vector<std::string> :: size_type x = 0; x < strs[i].size(); x++)
            sum += int(strs[i][x]);
        
        // Collor ascii value
        asciiVector.push_back(sum);
        
        // Clear sum
        sum = 0;
    }
    
    // ------------------------ Group Anagrams ------------------------
    
    // Contains results of all anagrams
    std::vector<std::vector<std::string>> AnagramVector;
    
    // Used as helper vector to collect subscripts one by one
    std::vector<std::string> singleAnagramVector;
    
    // Contains indices of all anagrams
    std::vector<std::vector<int>> AnagramIndex;
    
    // Used as helper vector to collect indices one by one
    std::vector<int> IndexVector;
    
    // Initiate operation
    for(std::vector<int> :: size_type i = 0; i < asciiVector.size(); i++)
    {
        if(checkIndex(i, AnagramIndex))
            continue;
        else
        {
            IndexVector.push_back(i);
            
            singleAnagramVector.push_back(strs[i]);
        }
        
        
        for(std::vector<int> :: size_type x = i+1; x < asciiVector.size(); x++)
        {
            if(asciiVector[i] == asciiVector[x])
            {
                IndexVector.push_back(x);
                
                singleAnagramVector.push_back(strs[x]);
            }
        }
        
        // Insert index collection into AnagramIndex
        AnagramIndex.push_back(IndexVector);
        
        // Insert anagram collection into AnagramVector
        AnagramVector.push_back(singleAnagramVector);
        
        // Clear indexVector
        IndexVector.clear();
        
        // Clear anagram vector
        singleAnagramVector.clear();
    }
    
    return AnagramVector;
    
}
// -----------------------------------------------------------------------------------------------
// Checks each index of each collected anagram to determine if anagram has already been collected
bool checkIndex(int index, std::vector<std::vector<int>> AnagramIndex)
{
    for(std::vector<int> :: size_type i = 0; i < AnagramIndex.size(); i++)
    {
        for(std::vector<int> :: size_type x = 0; x < AnagramIndex[i].size(); x++)
            if(AnagramIndex[i][x] == index)
                return true;
    }
    return false;
}
// -----------------------------------------------------------------------------------------------
// Display results of each algorithm
void Print(std::string header, std::vector<std::vector<std::string>>AnagramVector)
{
    // Display header
    std::cout << header;
    
    // Display results
    for(std::vector<std::string> :: size_type i = 0; i < AnagramVector.size(); i++)
    {
        if(i == 0)
            std::cout << '[';
        for(std::vector<std::string> :: size_type x = 0; x < AnagramVector[i].size(); x++)
        {
            if(x == 0)
                std::cout << '[';
            
            std::cout << AnagramVector[i][x];
            
            if(x != AnagramVector[i].size() - 1)
                std::cout << ',' << ' ';
        }
        
        std::cout << ']';
        
        if(i !=  AnagramVector.size() - 1)
            std::cout << ',' << ' ';

    }
    
    std::cout << ']';
    
    std::cout << '\n' << '\n';
}
// -----------------------------------------------------------------------------------------------
