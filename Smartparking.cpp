#include <bits/stdc++.h>
using namespace std;

class Parking {
public:
    int id;
    int distance;
    int cost;

    Parking(int i, int d, int c) {
        id = i;
        distance = d;
        cost = c;
    }
};

class Compare {
public:
    bool operator()(const Parking &a, const Parking &b) {
        if (a.distance == b.distance)
            return a.cost > b.cost;  // If distance same, choose lower cost
        return a.distance > b.distance; // Otherwise, choose closer slot
    }
};

int main() {
    priority_queue<Parking, vector<Parking>, Compare> pq;

    // Initial parking slots
    pq.push(Parking(1, 10, 50));
    pq.push(Parking(2, 5, 70));
    pq.push(Parking(3, 7, 60));

    cout << "Allocating parking...\n";
    while (!pq.empty()) {
        Parking p = pq.top();
        pq.pop();
        cout << "Allocated Parking " << p.id 
             << " (Dist: " << p.distance 
             << ", Cost: " << p.cost << ")\n";
    }
}
