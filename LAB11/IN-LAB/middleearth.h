#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H

/** @def defines MiddleEarth header(.h)
*/
#define MIDDLEEARTH_H

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp


/** @brief Middle Earth class definition
 * @details MiddleEarth class that will create a 
 * random 2-D world
 * @class MiddleEarth class.h
 * @headerfile MiddleEarth.h "MiddleEarth.h"
*/
class MiddleEarth {
private:
    /** @var int num_city_names
     * @var xsize
     * @var ysize
     * @brief variables for number of city names, 
     * width of world and height of world
     */
    int num_city_names, xsize, ysize;
    
    /** @var vector<float> xpos
     * @var vector<float> ypos
     * @brief variables for position of x and 
     * position of y
     */
    vector<float> xpos, ypos;
    
    /** @var vector<string> cities
     * @brief vector that holds the name of the 
     * cities
    */
    vector<string> cities;
    
    /** @var float *distances
     * @brief pointer to distances between cities
    */
    float *distances;
    
    /** @var map<string, int> indices
     * @brief map pair of indices
    */
    map<string, int> indices;

public:
    /** @brief MiddleEarth constructor
    * @param xsize, the width of the world
    * @param ysize, the height of the world
    * @param num_cities, number of cities in the world
    * @param seed ; random seem to create worlds
    */
    MiddleEarth (int xsize, int ysize, int numcities, int seed);
    
    /** @brief Destrucor of Middle-Earth
    */
    ~MiddleEarth();
    
    /** @brief Prints out the statistics of the world
    */
    void print();
    
    /** @brief Method to print out a table of the distances between all cities
    */
    void printTable();
    
    /** @brief Method that gets the distance between the two provided cities
    * @param city1, name of first city
    * @param city2, name of second city
    */
    float getDistance (string city1, string city2);
    
    /** @brief return a list of the cities to travel to
     * @param length, int length of cities to visit
     */
    vector<string> getItinerary(unsigned int length);
};

#endif
