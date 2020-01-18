// Eza Rasheed
// er6qt
// 04-22-19
// topological.cpp

// included so we can use cout
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>

using namespace std;

/** @brief Program performs a topological sort 
 * Outputs the order that CS courses should be taken using adjacency list
 * representation for a DAG
*/

class graphCourses {
public:
    /** @var variable int edges
     * @brief variable for the number of indegrees
     * @details this variable is used to count the number of indegrees coming 
     * into(directed) to a node
     */
    int edges;
    
    /** @var variable string vertex;
     * @brief variable to hold the names of the vertices
     */
    string vertex; 
    
    /** @var variable vector<graphCourses*> adjList;
     * @brief vector of adjancency list
     * @details vector that stores the adjacent nodes(pointing to) within the 
     * adjacency list
     */
    vector<graphCourses*> adjList;
    
    /** @brief class constructor
     * @details constructor that initilizes the values of the variables edges 
     * and vertex
     */
    graphCourses() {
        edges = 0; // initialize number of indegrees to 0;
        vertex = ""; // initialize veritces to empty string
    }
    
    /** @brief class destructor
     */
    ~graphCourses(){
    }
    
    /** @brief class constructor
     * @details constructor that initializes the values of edges(indegrees) to 
     * 0 and vertex to the string parameter v(which holds the name of a 
     * vertex)
     * @param string v holds the name of a vertex
     */
    graphCourses(string v) {
        edges = 0;
        vertex = v;
    }
};


/** @fn main(int argc, char **argv) //mot finding main?
 * @brief begin main method
 * @param argc
 * @param argv
 * @details main method that reads in an input file with 2 strings and 
 * performs a topological sort
 */
int main(int argc, char **argv) {

    /** @var vector<graphCourses*> graph
     * @brief vector of nodes
     * @details initialize vector to hold the list of nodes in topological 
     * sort in graph
     */
    vector<graphCourses*> graph; 
    
    /** @var void topsort()
     * @brief constructor for topological sort
     * @details function that performs a topological sort on the nodes, 
     * described in more detail when implemented
     */
    void topsort();
    
    /** @var queue<graphCourses*> courses
     * @brief queue of nodes
     * @details initialize queue to push and pop courses in a topological sort
     */
    queue<graphCourses*> courses; 
    
    /** @brief read in input file
     * @if the number of parameter does not equal 2 (verifying the correct 
     * number of parameters)
     * print to screen that the input file can be the only paramter, and then 
     * exit
     * @endif
     * @if the supplied file cannot be opened
     * print to screen that the input file could not be opened and 
     * successfully exit
     * @endif
     */
    if ( argc != 2 ) { 
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    ifstream file(argv[1], ifstream::binary);

    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    
    /** @brief read in two strings
     * @details read in s1 and s2 from the input file and....
     * @cond while loop that goes through the input file and as long as the 
     * end of the file has not been reached(true), continue to get vertices 
     * (lines 142-183)
     * @todo need to read in the 2 input strings to get the vertices of nodes 
     * that have an indegree of 0, and print it out in directed order 
     * @var string variables s1, s2
     * @brief strings that are being read in from the file
     * @var bool variables f, no
     * @brief initalize boolean variables to false use later
     * @var int variables e, z
     * @brief initialize int variables used as temporary resetter variables to 
     * 0
     * @if string1 or string2 equal "0"
     * you have reached the end of the input file, break out of program
     * @endif
     * @var int len = graph.size();
     * @brief get the size of the vector graph, which holds the list of nodes 
     * in graph
     * @todo use for loop to check to see if a vertex pair is already in the 
     * vector list of nodes for both strings 1 and 2, iteratively
     * @if an element in the vector has the same name as the s1 input
     * change bool to equal true and set e to have the position of the found 
     * vertex for s1
     * @endif
     * @if an element in the vector has the same name as the s2 input
     * change bool to equal true and set z to have the position of the found 
     * vertex for s2
     * @endif
     * @if f = true(node s1 does not exist)
     * create new node for string s1
     * push the new node onto graph queue,
     * change size of the vector list of nodes as  one node has been added, so 
     * subtract 1 from size
     * @endif
     * @if same as above if statement^^, except condition is for s2
     * @endif
     * @details in the end, increment number of edges(indegree) for s2 input 
     * by 1 and add nodes in s2 to the vector list of adjacent nodes of s1 
     * (note: vectors use push_back)
     * @endcond
     */ 
    
    while (true) {
        string s1, s2;
        file >> s1;
        file >> s2;
        
        bool f(false);
        bool no(false);
        int e = 0;
        int z = 0;

        if ((s1 == "0") && (s2 == "0")) {
            break;
        }
        
        int len = graph.size();
        for(int i = 0; i < len; i++) {
            if (graph[i] -> vertex == s1) {
                f = true;
                e = i;
            }
            if (graph[i] -> vertex == s2) {
                no = true;
                z = i;
            }
        }
        
        // TA Help
        if (!f) {
            graphCourses *newNode1 = new graphCourses(s1);
            graph.push_back(newNode1); 
            e = graph.size()-1;
        }

        if (!no) {
            graphCourses *newNode2 = new graphCourses(s2);
            graph.push_back(newNode2);
            z = graph.size()-1;
        }
        
        graph[z]->edges++; 
        graph[e]->adjList.push_back(graph[z]); 
    }
    
    /** @brief code to do a topological sort of a directed acyclic graph(DAG) 
     * (lines 208-232)
     * @var variable pointers v and w
     * @details for all pairs of vertices v,w, v is listed before w in topsort
     * @var int length = graph.size()
     * @brief get the size of the vector graph, which holds the list of nodes 
     * in graph
     * @todo need to iterate through a list of nodes and do various steps to 
     * put every vertex with an indegree of 0 onto the queue
     * for loop that iterate through vector list of nodes
     * set v(first node vertex) to the elements in the vector list of nodes
     * @if v's indegree is 0
     * push v(first vertex) onto queue
     * @endif
     * @cond while the queue is not empty
     * set vertex/node v, that has indegree of 0, to the top(front) of queue
     * pop off the vertex that has indegree 0 and print out the node(name of 
     * course(string vertex))
     * for each w adjacent to v/loop through the node's adjacency list
     * set w(second node) to first node's(v's) elements in the adjacency list
     * decrement w(second node)'s number of indegree by 1
     * @if w(second node vertex) now has indegree of 0
     * push w onto queue 
     * @endcond
     * close file
    */ 

    // referenced Bloomfield slides
    graphCourses *w, *v;
    int length = graph.size();
    //int counter = 0;
    
    for (int i = 0; i < length; i++) { 
        v = graph[i]; 
        if (v->edges == 0) { 
            courses.push(v);
        }
    }
    
    while (!courses.empty()) { 
        v = courses.front(); 
        /* v = */ courses.pop();
        cout << v -> vertex << " "; 
        int length2 = v->adjList.size();
        for (int j = 0; j < length2; j++) { 
            w = v -> adjList[j]; 
           
            //cout << w->edges;
            if (--(w -> edges) == 0) {  
                courses.push(w); 
        }
    }
    }
    cout << endl;
        //topsort();
        // output those strings
        //cout << s1 << endl;
        //cout << s2 << endl;
        // string comparison done with ==, but not shown here
        // close the file before exiting
        file.close();
}
    /*
    if (counter != graph) {
        throw CycleFound();
    }
    */
