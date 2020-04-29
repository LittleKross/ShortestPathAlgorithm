#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class MazeNode
{
public:
    MazeNode(int ID, vector<int> neighbors) {
        known = false;
        pathCost = 1;
        id = ID;
        parent = -1;
        neighbors = neighbors;
    };
    friend ostream& operator<<(ostream& os, const MazeNode& value);
    bool known;
    int id;
    int parent;
    vector<int> neighbors;
    int pathCost;
};

ostream& operator<<(ostream& os, const MazeNode& value) {
    os << "(Node:" << value.id + 1 << ", Cost:" << value.pathCost << ", Parent:" << value.parent << ", Known:" << value.known << ", Neighbors:" << value.neighbors.size() << ")";
    return os;
}

vector<MazeNode> inputData() {
    ifstream inFile("maze.txt");
    string line;
    int value;
    vector<MazeNode> nodelist;
    while (getline(inFile, line)) {
        istringstream word(line);
        //cout << line << endl;
        word >> value;
            vector<int> neighbors;
            MazeNode node = MazeNode(value - 1, neighbors);
            while (word >> value) {
                if (value == -1) {
                    break;
                }
                node.neighbors.push_back(value - 1);
            }
            //cout << node << endl;//cout << "(" << node.id << ", " << node.known << ", " << node.parent << ", " << node.pathCost << ", " << node.neighbors.size() << ")" << endl;
            nodelist.push_back(node);
    }
    return nodelist;
}//inputData

void printVector(vector<MazeNode> data) {
    cout << "Vector:" << endl;
    for (int i = 0; i < data.size(); i++) {
        cout << data.at(i) << endl;
    }
}

void printShortestPath(vector<MazeNode> data, MazeNode current) {
    if (current.parent != -1) {
        printShortestPath(data, data.at(current.parent));
    }
    if (current.id == data.size()-1)
        cout << current;
    else
    {
        cout << current << " -> ";
    }
}

void printShortestPath(vector<MazeNode> data) {
    MazeNode current = data.at(data.size()-1);
    printShortestPath(data, current);
}

vector<MazeNode> shortestPath(vector<MazeNode> data) {
    queue<MazeNode> path;
    //cout << data.front();
    path.push(data.front());
    //cout << path.front();
    //cout << !path.empty();
    while (!path.empty()) {
        MazeNode current = path.front();
        //cout << current;
        path.pop();
        //cout << "testing";
        //cout << current.neighbors.size();
        for (int i = 0; i < current.neighbors.size(); i++) {
            //cout << current.neighbors[i];
            //cout << neighbor;
            if (!data.at(current.neighbors[i]).known) {
                //cout << neighbor;
                data.at(current.neighbors[i]).pathCost = current.pathCost + 1;
                data.at(current.neighbors[i]).known = true;
                data.at(current.neighbors[i]).parent = current.id;
                //cout << data.at(current.neighbors[i]) << endl;
                path.push(data.at(current.neighbors[i]));
            }
        }

    }
    return data;
}



int main()
{
    vector<MazeNode> data = inputData();
    data = shortestPath(data);
    cout << "Shortest Path Cost: " << data.at(99).pathCost << endl << endl;
    printShortestPath(data);
    
    //printVector(data);
    //printShortestPath(data);
    
    //printShortestPath(data,data.at(data.size()-1));
    
    
    /*
    q.enqueue(v_start)

    while (!q.isEmpty()) {

        v = q.dequeue();

        for each w adjacent to v {

            if (w is unknown){

                w.cost = v.cost + 1

                w.known = true

                w.parent = v

                q.enqueue(w);

            }

        }

    }
    */

}

/*outputs:
Shortest Path Cost: 47

(Node:1, Cost:1, Parent:-1, Known:0, Neighbors:1) -> (Node:2, Cost:2, Parent:0, Known:1, Neighbors:1) -> (Node:3, Cost:3, Parent:1, Known:1, Neighbors:2) -> (Node:8, Cost:4, Parent:2, Known:1, Neighbors:1) -> (Node:9, Cost:5, Parent:7, Known:1, Neighbors:1) -> (Node:10, Cost:6, Parent:8, Known:1, Neighbors:1) -> (Node:11, Cost:7, Parent:9, Known:1, Neighbors:1) -> (Node:12, Cost:8, Parent:10, Known:1, Neighbors:2) -> (Node:16, Cost:9, Parent:11, Known:1, Neighbors:1) -> (Node:17, Cost:10, Parent:15, Known:1, Neighbors:1) -> (Node:18, Cost:11, Parent:16, Known:1, Neighbors:2) -> (Node:30, Cost:12, Parent:17, Known:1, Neighbors:1) -> (Node:31, Cost:13, Parent:29, Known:1, Neighbors:1) -> (Node:32, Cost:14, Parent:30, Known:1, Neighbors:1) -> (Node:33, Cost:15, Parent:31, Known:1, Neighbors:1) -> (Node:34, Cost:16, Parent:32, Known:1, Neighbors:2) -> (Node:35, Cost:17, Parent:33, Known:1, Neighbors:1) -> (Node:36, Cost:18, Parent:34, Known:1, Neighbors:1) -> (Node:37, Cost:19, Parent:35, Known:1, Neighbors:2) -> (Node:39, Cost:20, Parent:36, Known:1, Neighbors:1) -> (Node:40, Cost:21, Parent:38, Known:1, Neighbors:1) -> (Node:41, Cost:22, Parent:39, Known:1, Neighbors:1) -> (Node:42, Cost:23, Parent:40, Known:1, Neighbors:2) -> (Node:45, Cost:24, Parent:41, Known:1, Neighbors:1) -> (Node:46, Cost:25, Parent:44, Known:1, Neighbors:1) -> (Node:47, Cost:26, Parent:45, Known:1, Neighbors:1) -> (Node:48, Cost:27, Parent:46, Known:1, Neighbors:1) -> (Node:49, Cost:28, Parent:47, Known:1, Neighbors:1) -> (Node:50, Cost:29, Parent:48, Known:1, Neighbors:1) -> (Node:51, Cost:30, Parent:49, Known:1, Neighbors:1) -> (Node:52, Cost:31, Parent:50, Known:1, Neighbors:1) -> (Node:53, Cost:32, Parent:51, Known:1, Neighbors:2) -> (Node:55, Cost:33, Parent:52, Known:1, Neighbors:2) -> (Node:57, Cost:34, Parent:54, Known:1, Neighbors:1) -> (Node:58, Cost:35, Parent:56, Known:1, Neighbors:1) -> (Node:59, Cost:36, Parent:57, Known:1, Neighbors:1) -> (Node:60, Cost:37, Parent:58, Known:1, Neighbors:1) -> (Node:61, Cost:38, Parent:59, Known:1, Neighbors:1) -> (Node:62, Cost:39, Parent:60, Known:1, Neighbors:1) -> (Node:91, Cost:40, Parent:61, Known:1, Neighbors:1) -> (Node:92, Cost:41, Parent:90, Known:1, Neighbors:2) -> (Node:95, Cost:42, Parent:91, Known:1, Neighbors:1) -> (Node:96, Cost:43, Parent:94, Known:1, Neighbors:1) -> (Node:97, Cost:44, Parent:95, Known:1, Neighbors:1) -> (Node:98, Cost:45, Parent:96, Known:1, Neighbors:1) -> (Node:99, Cost:46, Parent:97, Known:1, Neighbors:1) -> (Node:100, Cost:47, Parent:98, Known:1, Neighbors:0)
*/