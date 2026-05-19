#include "NavigationGraph.hpp"

#include <iostream>

NavigationGraph::NavigationGraph()
{
    cityNames =
        {
            "Frankfurt",
            "Koeln",
            "Hamburg",
            "Berlin",
            "Stuttgart",
            "Muenchen"};

    adjacencyList.resize(cityNames.size());
}

void NavigationGraph::addConnection(
    int from,
    int to,
    int distance)
{
    adjacencyList[from].push_back({to, distance});
    adjacencyList[to].push_back({from, distance});
}

Route NavigationGraph::findShortestRoute(
    int start,
    int destination) const
{
    std::vector<bool> visited(cityNames.size(), false);

    std::vector<int> previous(cityNames.size(), -1);

    std::vector<int> distances(
        cityNames.size(),
        999999);

    distances[start] = 0;

    for (std::size_t i = 0; i < cityNames.size(); ++i)
    {
        int currentCity = -1;
        int shortestDistance = 999999;

        for (std::size_t j = 0; j < distances.size(); ++j)
        {
            if (!visited[j] &&
                distances[j] < shortestDistance)
            {
                shortestDistance = distances[j];
                currentCity = j;
            }
        }

        if (currentCity == -1)
        {
            break;
        }

        visited[currentCity] = true;

        for (const Edge &edge :
             adjacencyList[currentCity])
        {
            int newDistance =
                distances[currentCity] + edge.distance;

            if (newDistance <
                distances[edge.destination])
            {
                distances[edge.destination] =
                    newDistance;

                previous[edge.destination] =
                    currentCity;
            }
        }
    }

    Route route;

    route.totalDistance = distances[destination];

    int currentCity = destination;

    while (currentCity != -1)
    {
        route.vertices.insert(
            route.vertices.begin(),
            currentCity);

        currentCity = previous[currentCity];
    }

    return route;
}

void NavigationGraph::printRoute(
    const Route &route) const
{
    std::cout << "Shortest route: ";

    for (std::size_t i = 0;
         i < route.vertices.size();
         ++i)
    {
        std::cout
            << cityNames[route.vertices[i]];

        if (i < route.vertices.size() - 1)
        {
            std::cout << " -> ";
        }
    }

    std::cout
        << "\nDistance: "
        << route.totalDistance
        << " km\n";
}

int main()
{
    const int FRANKFURT = 0;
    const int KOELN = 1;
    const int HAMBURG = 2;
    const int BERLIN = 3;
    const int STUTTGART = 4;
    const int MUENCHEN = 5;

    NavigationGraph graph;

    graph.addConnection(FRANKFURT, KOELN, 190);
    graph.addConnection(KOELN, HAMBURG, 430);
    graph.addConnection(HAMBURG, BERLIN, 290);
    graph.addConnection(STUTTGART, FRANKFURT, 205);
    graph.addConnection(STUTTGART, MUENCHEN, 220);
    graph.addConnection(MUENCHEN, FRANKFURT, 395);
    graph.addConnection(MUENCHEN, BERLIN, 585);
    graph.addConnection(STUTTGART, KOELN, 360);
    graph.addConnection(BERLIN, FRANKFURT, 555);

    Route shortestRoute =
        graph.findShortestRoute(
            STUTTGART,
            BERLIN);

    graph.printRoute(shortestRoute);

    return 0;
}