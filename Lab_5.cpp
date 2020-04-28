#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class MapVertex
{
public:
    MapVertex(int ID, vector<int> neighbors) {
        known = false;
        pathCost = 1;
        id = ID;
        parent = -1;
        neighbors = neighbors;
    };
    friend ostream& operator<<(ostream& os, const MapVertex& value);
    bool known;
    int id;
    int parent;
    vector<int> neighbors;
    int pathCost;
};

ostream& operator<<(ostream& os, const MapVertex& value) {
    os << "< Node:" << value.id << ", Cost:" << value.pathCost << ", Parent:" << value.parent << ", Known:" << value.known << ", Neighbors:" << value.neighbors.size() << ">" << endl;
    return os;
}

vector<MapVertex> inputData() {
    ifstream inFile("test-maze.txt");
    string line;
    int value;
    vector<MapVertex> nodelist;
    while (getline(inFile, line)) {
        istringstream word(line);
        cout << line << endl;
        while (word >> value) {
            vector<int> neighbors;
            MapVertex node = MapVertex(value - 1, neighbors);
            while (word >> value) {
                if (value == -1) {
                    break;
                }
                node.neighbors.push_back(value);
            }
            cout << node << endl;//cout << "(" << node.id << ", " << node.known << ", " << node.parent << ", " << node.pathCost << ", " << node.neighbors.size() << ")" << endl;
            nodelist.push_back(node);
        }
    }
    return nodelist;
}//inputData

int main()
{
    vector<MapVertex> data = inputData();

    /*queue q;
    q.enqueue(v_start)
        while (!q.isEmpty()) {
            v = q.dequeue();
            for each w adjacent to v{
                if (w is unknown) {
                    w.cost = v.cost + 1

                    w.known = true

                    w.parent = v

                    q.enqueue(w);

                }

            }

        }*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

/*
1. 2 -1
2. 3 -1
3. 4 5 -1
4. -1
5. 6 -1
6. -1
*/