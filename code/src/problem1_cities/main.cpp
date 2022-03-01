#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>

//     Main task - to implement the function fillCountries to put countries into a container]
// (vector<Country> or map<std::string, Country>).

//     Intermediate steps:
//     1. Define operator< for both Cities and Countries based on their names.
//     2. Read cities as pairs <City, name of the country>.
//     3. Use the name of the country to find if there is such country in the container.
//     4. Add a country to the container or a city to an existing country.

struct Coordinate
{
    double longitude;
    double latitude;
};

struct City
{
    std::string name;
    Coordinate coordinate;
    
    bool operator <(const City& rhs) const
    {
        return name < rhs.name;
    }
};

struct Country
{
    std::string name;
};



void fillCountries(std::istream& inFile, std::vector<Country>& countries)
{
    std::string line;
    // skip header
    std::getline(inFile, line);
    
    while (std::getline(inFile, line))
    {
        std::stringstream sstr(line);
        std::string buffer;
        
        // city,lat,lng,country,population
        
        City newCity;
        
        // city name
        std::getline(sstr, buffer, ',');
        newCity.name = buffer;
        
        // latitude
        std::getline(sstr, buffer, ',');
        newCity.coordinate.latitude = std::stod(buffer);

        // longitude
        std::getline(sstr, buffer, ',');

        // country name
        std::getline(sstr, buffer, ',');
        std::string countryName = buffer;
        
        // population
        std::getline(sstr, buffer, ',');
        
        
        bool cityFound = false;
        for (const Country& country: countries)
        {
            if (country.name == countryName)
            {
                cityFound = true;
                // add city to country
                break;
            }
        }
                
        if (!cityFound)
        {
            // make a new country
            // add the city to the new country
        }
        
        
    }
}

int main()
{
    const std::string FILENAME = "../../data/problem1_cities/cities.csv";
    std::ifstream inputFile;
    inputFile.open(FILENAME);
    if(inputFile)
    {
        std::cout<<"OK\n";
    }
    
    std::vector<Country> countries;
    fillCountries(inputFile, countries);
    
    for (const Country& country: countries)
    {
        std::cout << country.name << std::endl;
    }
    
    return 0;
}
