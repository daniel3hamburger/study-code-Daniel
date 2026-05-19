#ifndef NAVIGATION_GRAPH_HPP
#define NAVIGATION_GRAPH_HPP

#include <string>
#include <vector>

struct Edge
{
    int destination;
    int distance;
};

struct Route
{
    std::vector<int> vertices;
    int totalDistance;
};

class NavigationGraph
{
private:
    std::vector<std::vector<Edge>> adjacencyList;
    std::vector<std::string> cityNames;

public:
    NavigationGraph();

    void addConnection(int from, int to, int distance);

    Route findShortestRoute(int start, int destination) const;

    void printRoute(const Route &route) const;
};

#endif