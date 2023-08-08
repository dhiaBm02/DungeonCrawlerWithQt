//
// Created by Benjamin Meyer on 19.12.2022.
//

#include "Graph.h"
#include <algorithm>
#include <iostream>


vector<Tile*> Graph::Dijkastra_Algorithm(Tile* from,Tile* to){

    int row=from->getRow();
    int col=from->getCol();
    Node* start=findNode(row,col);
    start->distanceFromStart=0;
    cout<<"start fromdijskastra :  "<<start->name->getTexture()<<"  * *  "<<start->name->getRow()<<"  ##  "<<start->name->getCol()<<endl;

    Dijkastra();
    int r=to->getRow();
    int c=to->getCol();
    Node* toNode=findNode(r,c);
    Node* prev=toNode;
    vector<Tile*> tmp;
    tmp.reserve(50);
    while(prev){

        if(prev->name->getTexture()=="O") {
            tmp.push_back(prev->name->onEnter(prev->name,nullptr));
            prev=prev->previous;
            continue;
        }
        tmp.push_back(prev->name);
        prev=prev->previous;
    }
    vector<Tile*> path;
    for(int i=tmp.size()-1;i>-1;i--){
        path.push_back(tmp.at(i));
    }

    return path;
}
void Graph::Dijkastra(){
    vector<Node*> kopie=nodes;
    while(kopie.size()>0){
        Node* smallest = ExtractSmallest(kopie);
        vector<Node*> *adjacentNodes = AdjacentRemainingNodes(smallest,kopie);
        for(auto* node : *adjacentNodes){
            int dist= 1+smallest->distanceFromStart;
            if(dist<node->distanceFromStart){
                node->distanceFromStart=dist;
                node->previous=smallest;
            }
        }
    }
}

Node* Graph::ExtractSmallest(vector<Node*>& nodes){
    int size = nodes.size();
    if (size == 0) return nullptr;
    int smallestPosition = 0;
    Node* smallest = nodes.at(0);
    for (int i = 1; i < size; ++i) {
      Node* current = nodes.at(i);
      if (current->distanceFromStart < smallest->distanceFromStart) {
        smallest = current;
        smallestPosition = i;
      }
    }
    nodes.erase(nodes.begin() + smallestPosition);
    return smallest;
}

vector<Node*>* Graph::AdjacentRemainingNodes(Node* node,vector<Node*> kopie) {
    vector<Node*>* adjacentNodes = new vector<Node*>();
    for(auto* nod:kopie){
        if(Contains(nod,node)) adjacentNodes->push_back(nod);
    }
    return adjacentNodes;
}

bool Graph::Contains( Node* node, Node* start) {
    for (auto* tmp: start->edges ) {
    if (node==tmp)  return true;
  }
  return false;
}

/////////////////////////

void Graph::addNode(Tile *name) {
    nodes.push_back(new Node{name});
    std::cout << "Node added!"<< std::endl;
}


void Graph::makeConnections()
{
    for(Node*node :nodes){

        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
                int r = node->name->getRow();
                int c= node->name->getCol();
                r+=i;
                c+=j;
                if(i==0 && j==0)
                    continue;
                auto* toAdd=findNode(r,c);
                if(toAdd!=nullptr && node->name->onLeave(toAdd->name,nullptr)!=nullptr){
                    if(toAdd->name->getTexture()=="O") {//wenn portal dann mit dessen destiantion edge einbinden
                        int ro=toAdd->name->onEnter(node->name,nullptr)->getRow();
                        int co=toAdd->name->onEnter(node->name,nullptr)->getCol();
                        node->edges.push_back(findNode(ro,co)) ;
                    }else
                        node->edges.push_back(toAdd);
                }
            }
        }
    }
}

void Graph::notify(Aktive* source){
    doorIsClosed = !doorIsClosed;
    cout<<"hey wild il 9a7ba rani na5dem"<<endl;
    if(!doorIsClosed){
        addEdgeDoor();
    }else deleteEdgeDoor();
}
void Graph::addEdgeDoor(){
    Node * door =findDoor();
    if (door==nullptr) return;
        int r =door->name->getRow();
        int c= door->name->getCol();
        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
                r+=i;
                c+=j;
                if(i==0 && j==0)
                    continue;
                auto* toAdd=findNode(r,c);
                if(toAdd!=nullptr ){
                    if(toAdd->name->getTexture()=="O") {//wenn portal dann mit dessen destiantion edge einbinden
                        int ro=toAdd->name->onEnter(door->name,nullptr)->getRow();
                        int co=toAdd->name->onEnter(door->name,nullptr)->getCol();
                        door->edges.push_back(findNode(ro,co)) ;
                        toAdd->edges.push_back(door);
                    }else if(toAdd->name->getTexture()!="_"){
                        toAdd->edges.push_back(door);
                        door->edges.push_back(toAdd);
                    }else door->edges.push_back(toAdd);
                }
            }
        }

}

void Graph::deleteEdgeDoor(){

    Node * door =findDoor();
    if (door==nullptr) return;

    for(auto* node :door->edges){

        auto it  =  std::find_if(node->edges.begin(),node->edges.end(),
                     [door](auto x){return x == door;});

        node->edges.erase(it);
    }
    door->edges.clear();
}

Node* Graph::findDoor(){
    for(auto* n : nodes){
        if (n->name->getTexture()=="X" ||n->name->getTexture()=="/" ){
            return n;
        }
        return nullptr;
    }
       return nullptr;
}


Node *Graph::findNode(int r, int c)
{

    for(auto* n:nodes){
        if(n->name->getRow()==r && n->name->getCol()==c && n->name->getTexture()!="X")
            return n;
    }
    return nullptr;
}


