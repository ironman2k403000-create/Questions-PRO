# 🚀 Samsung Pro Coding Questions Collection

> A curated set of **high-quality coding problems** frequently asked in Samsung interviews and competitive programming rounds.
> These problems cover **Graphs, DP, Greedy, Strings, Geometry, and Advanced Algorithms**.

🔗 Reference: https://github.com/kirang193/samsung-pro-coding-questions/

---

## 📌 Problem List

---

### 🧩 1. Segments on 2D Grid (`segments.cpp`)

* Given a path on an infinite 2D grid (horizontal/vertical segments)
* Given **N points**
* Count how many points lie on the path

🧠 Concepts:

* Geometry
* Hashing / Maps
* Line segment intersection

---

### 📦 2. Minimum Days to Reduce Stock (`days.cpp`)

* Initial stock `A[]`
* Daily inflow `B[]`
* Each day:

  * Add stock
  * Remove one item completely
* Find minimum days such that total stock ≤ K

🧠 Concepts:

* Greedy
* Prefix sum
* Simulation

---

### 🔴🔵 3. Red-Blue Necklace (`RB.cpp`)

* String of `R` and `B`
* Remove from **ends only**
* Make count of R and B equal

💡 Trick:

```
Answer = N - longest substring with equal R and B
```

🧠 Concepts:

* Prefix sum
* Hash map
* Sliding window

---

### 🚚 4. Warehouse Delivery Optimization (`Warehouse.cpp`)

Grid contains:

* `0` → Road
* `1` → Tree
* `2` → Garage
* `3` → Warehouse
* `4` → Airport

🚛 Truck rules:

* Starts at garage
* Can carry unlimited goods
* Cost increases with load

💰 Cost Formula:

```
Cost = distance × (1 + goods carried)
```

🎯 Goal:
Max goods delivered within cost ≤ C

🧠 Concepts:

* BFS / Multi-source BFS
* Bitmask DP
* State optimization

---

### 🧱 5. Tile Selection (`tiles.cpp`)

* Select K tiles
* Minimize maximum difference between any pair

📏 Difference defined as:

```
max(|height difference|, |width difference|)
```

🧠 Concepts:

* Sorting
* Sliding window
* Greedy

---

### 🪨 6. Stone Removal Cost (`stones.cpp`)

* Removing stone cost depends on neighbors
* Find minimum cost to remove all stones

🧠 Concepts:

* DP
* Interval DP

---

### 🔗 7. String Merging (`string_merging.cpp`)

* Merge strings if:

```
last char of A == first char of B
```

🎯 Final string must:

```
first char == last char
```

🧠 Concepts:

* Graph (Directed)
* DP on strings
* Longest path

---

### 📊 8. Score Maximization (`scores.cpp`)

* Arrays A and B
* Score:

  * ≤ D → 1
  * > D → 2

🎯 Maximize:

```
Score(A) - Score(B)
```

🧠 Concepts:

* Sorting
* Prefix sums
* Greedy thresholding

---

### 🚗 9. Cars Movement (`cars.cpp`)

* Move all cars to (p, q)
* Moves increase per turn:

```
1 + 2 + 3 + ... + t
```

🎯 Find minimum drives or return -1

🧠 Concepts:

* Math (triangular numbers)
* Manhattan distance
* Greedy

---

### 🤖 10. Robot Garbage Cleaning (`robots.cpp`)

* Robots clean garbage forward only
* Deploy cost = m

🎯 Minimize total cost

🧠 Concepts:

* 2D DP
* Prefix sums

---

### 🔢 11. Digit Sum Certificates (`digit_sum.cpp`)

* Numbers ≤ A
* Digit sum = S

🎯 Count valid numbers

⚠️ A can be up to `10^100`

🧠 Concepts:

* Digit DP
* Big integers

---

### 🪖 12. Soldier Tree Balancing (`soldiers.cpp`)

* Tree of units
* Equal subtree sum for siblings

🎯 Minimize removed soldiers

🧠 Concepts:

* Tree DP
* Greedy pruning

---

### 🌳 13. Tree Distance Maximization (`min_cost.cpp`)

* Choose node `v` maximizing:

```
Σ (distance(i, v) × a[i])
```

🧠 Concepts:

* Tree DP
* Rerooting technique

---

### ⚖️ 14. Minimum Subset Difference (`min_subset_diff.cpp`)

* Partition array into two sets
* Minimize:

```
|sum(A) - sum(B)|
```

🧠 Concepts:

* Knapsack DP
* Bitset optimization

---

### 🌲 15. Logging Trees Optimization (`logging_trees.cpp`)

* Robot cuts trees along a road
* Must follow **non-increasing tree length order**

🎯 Minimize total time

🧠 Concepts:

* Greedy + DP
* Simulation
* Path optimization

---

## 🧠 Topics Covered

* Dynamic Programming (DP)
* Graph Theory (BFS, DFS, Bitmask)
* Greedy Algorithms
* String Processing
* Geometry & Math
* Tree Algorithms
* Digit DP

---

## 💡 Tips

* Most problems are **interview-level HARD**
* Focus on:

  * Optimization
  * Edge cases
  * Time complexity

---

## 🏁 Contribution

Feel free to:

* ⭐ Star this repo
* 📥 Add solutions
* 🛠 Improve explanations

---

## 🔥 Author Note

This collection is extremely useful for:
* Advanced DSA practice
* Competitive programming

---

⭐ **If this helps you, don’t forget to star the repo!**
