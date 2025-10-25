# 🚗 Smart Parking Allocation System (C++)

This project demonstrates a simple **parking slot allocation system** using a **priority queue (min-heap)** in C++.  

Each parking slot has three attributes:
- **ID** → Unique slot number  
- **Distance** → Distance from the entry gate  
- **Cost** → Parking fee  

The system automatically allocates the **best parking slot** based on:
1. **Shortest distance** (highest priority)  
2. **Lowest cost** (used when distances are equal)  

---

## 🧠 How It Works

- A **custom comparator class** defines the rules for slot selection.  
- The **STL `priority_queue`** ensures the most suitable slot is always on top.  
- When a parking slot is allocated, it is removed from the queue.  
- The program displays the sequence in which slots are assigned.

---

## 💻 Example Output

```
Allocating parking...
Allocated Parking 2 (Dist: 5, Cost: 70)
Allocated Parking 3 (Dist: 7, Cost: 60)
Allocated Parking 1 (Dist: 10, Cost: 50)
```

---

## 🧩 Key Concepts Used

- **Object-Oriented Programming (OOP)**
- **STL Containers** (`priority_queue`)
- **Custom Comparator Functions**
- **Greedy Allocation Logic**

---

## ⚙️ How to Run

1. Save the code in a file, for example `parking_system.cpp`
2. Open a terminal and compile:
   ```bash
   g++ parking_system.cpp -o parking
   ```
3. Run the executable:
   ```bash
   ./parking
   ```

---

## 🧾 Code Overview

```cpp
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

    cout << "Allocating parking...
";
    while (!pq.empty()) {
        Parking p = pq.top();
        pq.pop();
        cout << "Allocated Parking " << p.id 
             << " (Dist: " << p.distance 
             << ", Cost: " << p.cost << ")
";
    }
}
```

---

## 🏁 Future Enhancements

- Add user input for dynamic slot data  
- Implement parking **deallocation** and **availability tracking**  
- Integrate with a simple GUI or web dashboard  

---

## 👨‍💻 Author

**Harman Preet**  
📚 Student Project | C++ STL Practice | Data Structures and Algorithms
