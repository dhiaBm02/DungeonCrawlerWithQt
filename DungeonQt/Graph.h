//
// Created by Benjamin Meyer on 19.12.2022.
//

#ifndef MYGRAPH_GRAPH_H
#define MYGRAPH_GRAPH_H

#include <string>
#include <list>
#include <map>
#include "Tile.h"
#include <vector>
#include "Passive.h"
#include "Aktive.h"
#include <bits/stdc++.h>

using namespace std;

struct Node{
    Tile* name =nullptr;
    //std::list<std::pair<Node*, int>> nodes;
    vector<Node*> edges ;
    Node* previous;
    int distanceFromStart =10000;
};

class Graph : public Passive{
    vector<Node*> nodes;
    bool doorIsClosed =true;
public:
    void addNode(Tile* name);
    void removeEdge();
    void removeNode();
    void makeConnections();
    Node* findNode(int,int);
    void addEdgeDoor();
    void deleteEdgeDoor();
    void notify(Aktive*) override;
    Node* findDoor();
    vector<Tile*> Dijkastra_Algorithm(Tile*,Tile*);
    Node* ExtractSmallest(vector<Node*>& nodes);
    void Dijkastra();
    vector<Node*>* AdjacentRemainingNodes(Node* node,vector<Node*> kopie) ;
    bool Contains( Node* node,Node*);

};

#endif //MYGRAPH_GRAPH_H
