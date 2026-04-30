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

* Samsung R&D preparation
* Advanced DSA practice
* Competitive programming

---

⭐ **If this helps you, don’t forget to star the repo!**


you can find the questions here 
(link)->refernece => https://github.com/kirang193/samsung-pro-coding-questions/

ques1-> segments.cpp
Test - 1
You are given a path on an infinite 2d lattice. The path consists of line segments parallel to either the x or y axis. VVA
Example : 1, 1 to 1, 3 to 6, 3 to 6, 6 to bla bla
Also there is a set of points given . You have to find how many of the given points lie on the path. The input was as follow
N M as two variables
There were n numbers that denoted x coordinates of n points
There were n numbers again which denoted y coordinates of those n points

So total, there is the info of n points in space
Now, there are two more arrays of size m , one consisting of x coordinates and other of y coordinates correspondingly
These points are the turning points in a path.
Examples.
Say I went from 1, 1 to 1, 5 to 2, 5 so the given arrays will be
1, 1, 2
1, 5, 5
In the given path , we have to find how many of the given n points lie.


ques2-> days.cpp
You are in charge of maintaining inventory for a warehouse. You have an initial stock of goods given by an array A of size N.

Your day starts off by getting an inflow of goods given by another array B of size N (so the stock becomes A[i] = A[i]+B[i] for all i). 

After that, you can choose any one good, and export it, making its stock 0. Before you leave, you have to report the total stock of all items in the warehouse to the headquarters. 

Your task is to find the minimum number of days required to make the total stock of all items <= K, where K is given.


ques3->RB.cpp
You will be given a necklace having only red and blue stones in it. Your task is to make the number of blue and red stones equal. 
Stones can only be removed from either the left or right end. 
Return the minimum number of stones that are to be removed to complete the given task.

For eg, input: BBRRBRBRBRBBR

            output: 1

//  try this
Length of string - (longest length of subarray with equal no of “A” and ‘B’) 




ques 4->Warehouse.cpp
There is 2d Matrix of size h*w representing the city.
Each cell can be 0,1,2,3,4
0-> road
1->Tree
2-> Garage
3-> warehouse
4-> Airport

There is a truck parked at the garage. The truck's task is to go to the warehouse (one or many at a time) , load the goods and unload the truck at the airport.
There is no limit on the number of goods a truck can carry.

There is a cost associated with a truck.
Cost is (Number of blocks it has moved * (1+Number of good truck carries)) like 
To move one block cost is 1 on an empty truck
Cost is 2 if truck has 1 good
3 if the truck has 2 goods. 
……….
You have to tell how many maximum goods can be unloaded at airport using at max C cost

Constraints
Number of test cases - 50
h,w belongs to (2,40)
c belongs to (5,2000)
There can be at max 13 warehouses
A truck cannot pass a tree, if it is at any warehouse truck can or cannot load the goods, similarly if it's at an airport it's not necessary to unload the goods.
But starting point is fixed ie garage 



ques5->tiles.cpp
Given N tiles of given width an koid height, we have to select K out of it, we need to minimise the maximum of the difference between any two tiles selected, the difference between any two tiles is defined as the maximum of the height difference and width difference.

ques6->stones.cpp
There's a cost of removing stone, the cost is different if it has one neighbour, two neighbours and it's zero if no neighbour.
Within a given sequence of stones, find minimum cost to remove all of them. Each stone had different costs for each neighbour condition 


ques7->string_merging.cpp
You are given an array of strings. You can merge two strings, arr[i] and arr[j], only if,
i < j  and the last letter of arr[i] == first letter of arr[j]
Eg, you have two strings -> “123” and “389” -> after merging it becomes “123389”
You can keep merging strings like this, but the ‘final’ string you form must be such that the first letter of the string should be the same as the last letter.
Eg, after merging several strings, the ‘final’ string becomes -> “123389…………1”
Print the max length of the ‘final’ string that can be formed in this way.
Test case - 1:
Array of strings = [“14”, “123”, “323”, “321”,  “421”, “535”]
Possible ‘final’ strings -> “323”, “535”, “14421”, “123323321”, “123321”
Ans = 9 (which is the length of “123323321”) 
Test case – 2:
Array of strings = [“14”, “15”, “89”, “22”]
Possible ‘final’ strings -> “22”
Ans = 2 (which is the length+ of “22”)


ques8->scores.cpp (sa-sb problem)
2 arrays given
a = [1, 2, 3, 4, 5]
b = [6, 7, 8, 9, 10]
Value of an array is the total score of elements, 
and score of element is 1 if it is less than or equal to D and 2 if it is greater than D, 
Find D such that A_score - B_Score is maximum
 
constraints -
0 <= D <= 1e9
1 <= a[i] <= 1e8
1 <= b[i] <= 1e8
1 <= a.size(), b.size() <= 1e5


ques9->cars.cpp
There are N cars parked at random positions on x-y plane.
You'll be given M which means all the Locations of cars lies between the square  (-M,M), (M,M), (M,-M) (-M,-M).
Your task is to move them at a given location (p,q) at the same time i.e. all of them should reach (p,q) at same time in minimum drives. And if not possible then return -1.
1st drive : you should take 1 move 
2nd drive : you should take 2 moves 
Tth drive : you should take t mov⁸es

You can go left, right, up or down in each move.
Also, you can revisit your previous location i.e if you are in say 5th drive, you can do 2 downs, 2 ups and 1 right or any possible combination.
Constraints:

1 <= N <= 100
1 <= M <= 1e7

Example 1:
N=2
P,q is (1,1)

Locations of cars are (2,3) and (-4,1)
 
Ans : 5 drives 
(Total moves 1 + 2 + 3 + 4 + 5 = 15).

Example 2: 
N=2
P,q = (0,0)
Locations : (0,1), (0,2)
Ans : -1

Constraints:

1 <= N <= 100
1 <= M <= 1e17


ques10->robots.cpp
Robot Sum
Given an array of garbage values at index i.
●	A robot can be deployed at any index with cost m.
●	A robot can clean garbage at index and can move only to i+1.
●	At any point the cost is Sum of garbage which remains uncleaned.
Find the minimum cost of cleaning all garbage and any number of robots can be deployed at any index.
●	2D DP at any index you either deploy a new robot at that index or get it cleaned by a robot deployed at a previous index.


ques11->digit_sum.cpp
There is a company that issues gift certificates every day. The company will apply the following rules to the gift certificates
-	A gift certificate is printed on with its own serial number which is made up of only numbers. So, all gift certificates will have different serial numbers.
-	The digit sum of a serial number is S. Gift certificates issued on the same day have the same S.
The maximum value of a serial number is A and its number of digits is N. (For example, if A = 34567, N is 5)

Given A and S for gift certificates to be issued on a day, you are required to write a program that calculates the maximum issuable number of gift certificates

The calculated result may be too big. So, print the answer modulo 10^9 + 7.
You may increase the number from 1 to A by 1 and compare S with the sum of all digits. However, this method cannot be used because the given A can be too large. So you are required to write a more efficient program.
Examples: 
-	A = 101, S = 3, Answer: 4
Explanation: 21, 12, 3, and 30 can be made. As up to 101 can be made, 102 cannot be made
-	A = 172, S = 3, Answer: 7
Explanation: 3, 12, 21, 30, 102, 111, and 120 can be made
-	A = 50, S = 4, Answer 5
Explanation: 4, 40, 13, 31, and 22 can be made.
-	A = 999 , S = 500 , Answer 0
Explanation: The maximum digit sum is 27. No gift certificate that meets the condition of S = 500 can be issued
Constraints: 1 <= A < 10^100, 1 <= S <= 1000  


ques12->soldiers.cpp
 each node of the tree represents a military unit. We are given the no. of soldiers in each     unit.
    we need to balance the tree such that
        all nodes belonging to the same parent node have the same subtree sum
        we can only balance by deleting some soldiers from a node 
        we should remove the minimum no. of soldiers(total)
    return the no. of soldiers total after balancing

    constraints:
        N<=500
        node.val<=100
        depth<=100
    input form:(for each of the n nodes)
        parent index, soldiers in that unit
  


ques13->min_cost.cpp
// https://codeforces.com/blog/entry/63962
/*
Given a tree with n vertices, where each vertex has a number ai written on it. 
Distance between two vertices is defined as the number of edges on the path between them. 
You have to choose a vertex v such that d1 × a1 + d2 × a2 + d3 × a3 + ... ... + dn × an is maximized, 
where di denotes the distance between vertex i and vertex v. You have to print this maximum value.

ques14->min_subset_diff.cpp
There are a total of N cargoes. The weight of the ith cargo is given as L[i]. (0<=i<N).
There is a compartment A and B on the left and right side of the airplane, respectively.
The two compartments are large enough to carry all the cargoes. 
N cargoes should be loaded and distributed among compartment A and B.
When the cargoes are loaded in a way that makes the difference between (The toal weight of cargoes in compartment A) and  (The toal weight of cargoes in compartment B).
You are required to print the diff between  (The toal weight of cargoes in compartment A) and  (The toal weight of cargoes in compartment B). testcases: N=5, l[]=[3,3,7,3,1]. ans: 1 explaination: divide into 3,3,3 and 7,1

Simplified Qn:[
Given a list L[0..N-1], divide it into two groups A and B such that:
Every item is in either A or B (no item left behind)
You minimize: abs(sum(A) - sum(B))

ques15->logging_trees.cpp
The Korea Expressway Corporation is planning to expand the road where the volume of traffic is high.
In order to expand the road, all of the roadside trees planted nearby the road have to be chopped down.
To do the course of action, they should rent a logging robot which is developed by Samsung Electronics.
However, the rental fee of the logging robot is obviously high due to its high production cost.
Thus, the development of an operation software which allows logging trees within the shortest time is needed.

The logging robot has following features:

1.The logging robot can move forward and backward. And to get moved by 1, it takes 1 minute.

2.The roadside trees to the left or right can be cut and loaded which requires 1 minute.

3.Trees can be loaded in the order of their cut. Also only a tree which length is shorter or equal in length to the previous one can be loaded. (refer to Fig.1)

4.If there are trees on both sides such as to the left and right, without moving each can be cut and loaded by following the third requirement (above).

5.The logging robot can load infinite number of trees.

The information of the road to expand is as follows:

The road is given as a straight line with a length of N. The first point of the road is the starting point (point 0) and the last point (where N is located) is the ending point.

1.On each side of the road there will be one tree at most after every 1 unit length with varying lengths (it is possible that there is no tree)

2.On both sides to the starting and ending point there are no trees planted.

3.The logging robot starts moving from the starting point, chops down all trees along the way, transport them and it reaches the ending point.

Suppose a road with N=5 as demonstrated in [Fig.2] is given.

The beginning part of the road 0 is the starting point of the robot and 5 the ending point.
The logging robot moves forward, backward, chops down all trees on the left, right side of the road, transports them and must reach point 5.

The logging robot can move as follows:

=>
Point0 -> Point3 (chops down tree with a length of 3)
-> Point4 (chops down tree with a length of 2)
-> Point2 (chops down tree with a length of 2)
-> Point4 (chops down tree with a length of 1)
-> Point5 (moves to the ending point)
The total time is 13 minutes. (time needed to chop down: 4 minutes, time needed to move: 9 minutes)
However, if the robot follows the moves as given below, the total time becomes 11 minutes and the rental fee can be reduced.

=>
Point0 -> Point3 (chops tree with a length of 3)
-> Point2 (chops down tree with a length of 2)
-> (Standing still) (chops down tree with a length of 1)
-> Point4 (chops down tree with a length of 2)
-> Point5 (moves to the ending point)
(time needed to chop down: 4 minutes, time needed to move: 7 minutes)

Given the information of the road, write a program that finds the minimum time (in minute unit) that is needed in order to chop down all trees along the way from the starting to the end point.

The correct answer in [Fig.2] is 11.

Constraints:

The length of the road N is given as an integer that is greater than or equal to 5 and less than or equal to 1,000. (5 ≤ N ≤ 1,000)

On each side of the road there is one tree at most after every 1 unit length (it is possible that there is no tree)

The length of a tree L is given as an integer that is greater than or equal to 1 and less than or equal to 1,000. (1 ≤ L ≤ 1,000)

The starting point of the logging robot is given as point 0 on the map and the ending point as N.

There are no trees on both sides of the starting and ending point.

There is no situation where there are no trees at all on the road.

