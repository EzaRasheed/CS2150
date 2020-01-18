// Eza Rasheed
// er6qt
// 04-23-19
// traveling.cpp


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"


/** @brief Program to implement that will find a brute force solution to the    
 * traveling salesperson problem
 * @details The TSP takes in five command line parameters:
 * the x-size, width, of the world (20)
 * the y-size, height, of the world (20)
 * the number of cities in the world (20)
 * the random seed, specific number generates same world each time (14)
 * and then number of cities to visit(8)
 */


/** @var float computeDistance (MiddleEarth &me, string start, vector<string> dests)
 * @brief initialize function that computes distance
 * @details computes the full cycle distance to get from the first city and back
 * @see computeDistance implementation below
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests);

/** @var void printRoute (string start, vector<string> dests)
 * @brief initialize function that prints route 
 * @details prints out the route of the full cycle path taken to get to the cities and back to where you began
 * * @see printRoute implementation below
 */
void printRoute (string start, vector<string> dests);


/** @brief main function to implement the TSP
 * @details Print all the permutations of the list of destinations
 * for n cities, there are n! possible permutations
 * the start city should not be permuted
 * @param argc is the number of parameters plus one
 * @param argv is an array of C-style strings
 * @todo check the number of parameters, create the world and select your itinerary, sort the vector from beginning to end, cycle through each and every permutation of the passed vector, and print out the shortest path found
 * @return 0 and succesfully exit the program
 */
int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);

    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    // YOUR CODE HERE

    // vecor to store the cities to visit
    vector <string> city_itin = me.getItinerary(cities_to_visit);
    // start at 0th position in vector of cities to travel to
    string start = dests.at(0); 
    // call computeDistance and set it to a float variable that will find the shortest distance length
    float shortest_dist = computeDistance(me, start, dests);
    
    // sort the cities in the vector before using next_permutation()
    std::vector<string>::iterator b = (++dests.begin());
    std::vector<string>::iterator e = dests.end();
    sort(b, e);
    
    // cycle through each permutation of the passed vector from beginnning to end and move through each possible list ordering
    while(std::next_permutation(b, e)) {
        float find_dist = computeDistance(me, start, dests);
        if (find_dist < shortest_dist) { // if the current distance of a path is less than the distance of the path being compared to
            shortest_dist = find_dist; // the shortest distance is set to be the one found while iterating
            city_itin = dests; //the vector of cities to visit is set to the new/updates itinerary of cities to visit
        }
    }

    start = city_itin.at(0);
    printRoute(start, city_itin); // call print route
    cout << "and will have length " << shortest_dist << endl; //print out length(distance) of shortest path 
    return 0;

}
 
/** @brief computeDistance method
 * @details method to compute the full distance of the cycle that 
 * starts at the 'start' parameter, goes to each of the cities in the dests
 * vector IN ORDER, and end back at the 'start' parameter (cycle)
 * @param me is a Middle Earth object
 * @param start is used to indicate where to begin the path to the cities
 * @param dest is a vector that holds all the cities to visit
 * @return get_dist, which is a float that returns the distance length it takes to travel the different paths
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
    // YOUR CODE HERE
    float get_dist = 0; 
    //int size = dests.size()-1;
    int size = dests.size();
    start = dests.at(0);
    for (int i = 0; i < size; i++) { //iterate through the size of the vector that holds the list of the path of cities to travel to
        get_dist = get_dist + me.getDistance(start, dests.at(i)); //get the distance of the path taken
        start = dests.at(i); //starting city is set back to start at end
}
    string s = dests[size-1];
    get_dist = get_dist + me.getDistance(dests.at(0), s);
    return get_dist; //return the length of the path taken starting from the start city...and then ending back at the start city (full cycle)
}


/** @brief printRoute method
 * @details This method will print the entire route, starting and ending at
 * the 'start' parameter.  The output should IN ORDER, in the form:
 * Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
 * @param start is a string that indicates what city to begin with in the       
 * route
 * @param dests is a vector that hold the list of cites to travel to
 * @todo iterate through the dests vector that holds the list of city destinations, and print each city in a path/route in order, with the starting city also being the ending city
 */
void printRoute (string start, vector<string> dests) {
    // YOUR CODE HERE
    //cout << start;
    cout << "Your journey will take you along the path ";
    for (int i = 0; i < dests.size(); i++) {
        cout <<  dests.at(i) << " -> ";
}
cout << start << endl;
}
