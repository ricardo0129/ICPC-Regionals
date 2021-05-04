# ICPC-Regionals Solutions
### Currently Solved 13/16
A-DONE<br>
B-DONE<br>
C-DONE<br>
D-<br>
E-DONE<br>
F-DONE<br>
G-<br>
H-<br>
I-DONE<br>
J-DONE<br>
K-DONE<br>
L-DONE<br>
M-DONE<br>
N-DONE<br>
O-DONE<br>
P-DONE</p>


## EXPLANATIONS

### Ant Typing [A]
The approach for this problem is brute force. <br>
There is only 1-9 keys possible therefore the number of permutations of digits 1-9 is 9!=362880. <br>
This number is very small and we can work with it. <br>

For every possible keyboard we have some number of seconds. We have two options <br>
A) Iterate through the given string and compute the seconds for each keyboard. At worst case we get O(n*9!) where n can be 10^5. This solution sucks. <br>
B) We can actually precompute a table that helps a lot.<br> 
table will be as follows<br> 
  1 2 3 4 5 6 7 8 9<br>
1 0 0 0 0 0 0 0 0 0<br>
2 0 0 0 0 1 0 0 0 0 <br>
3 0 1 0 0 0 0 0 0 0 <br>
4 0 0 1 0 0 0 0 0 0<br>
5 0 0 0 0 0 0 1 0 0<br>
6 0 0 0 0 0 0 0 0 0<br>
7 0 0 0 0 0 0 0 1 1 <br>
8 0 0 0 1 0 0 0 0 0<br>
9 0 0 0 0 0 0 0 0 0<br>
This represents A[i,j] = number of times we go from i->j. <br>
In the example we are given we have string 78432579. <br>
7->8 <br>
8->4<br>
4->3 <br>
You go from key 7 to 8 once. Then to key 4. <br>
After we fill this table the answer is easy to see. <br>
First create this table by iterating through every digit in the string 'S' we are given. Then we just add 1 to S[i]->S[j] in the table. <br>
So in the example we update A[7,8]<br>
Then we update A[8,4], A[4,3] so on and so on. <br>
<br>
Next we brute force every permutation of keyboards. Then what we can do is calculate the weight for each A[i,j]. <br>
To do this for a given permuation of 1...n we do as follows. <br>
Ex. {4,3,1,5,2} Permutation of 1...5<br>
Weight from i to j = (pos of i)-(pos of j) + 1<br>
The weight from 4->3 will be 2<br>
Weight from 3->1 is 2 <br>
Weight from 4->4 is 1<br>
We can make another table of size 9^2. Where W[i,j] is the number of seconds going from key i to key j.<br>
For each permuation of the keyboard sum for all i and j A[i,j]*W[i,j].<br>
However this is not the answer we are missing one part. <br>
We are told that we start at the leftmost key. So we just have to add the W[starting key, first number of S]<br>
Now we just take the minimum over all permutations<br>
Total time complexity is O(9!9^2)=29393280<br>
So around 29 million computations for 1 second CPU time this is a valid solution. Rule of thumb: 250 million computations per second of time you are given. <br>
Keep in mind O(n) does not mean that you are doing n computations. <br>


### Bad Packing [B]

This is a variation of the well known knapsack problem. <br>
We won't immediatly answer the problem but first lets solve the problem. We are given a set of items with weights {w1,w2,...,wk}. <br>
If we pick a subset of items the smallest missing item is what needs to maximized for the weight of that subset. <br>
The dynamic programming recurrance relation is <br>
dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i-1]]) <br>
           or i+1 if sum of weights = j<br>
To find the answer to the problem we just iterate through the last row of our dp table <br>
Since we have the largest minimum weight missing for a total capacity. We just check <br>
if adding that weight to the capacity is over the maximum allowed weight. If it is this is a possible answer. <br>
Now just take the minimum over all possible answers and output that. <br>
Total run time is O(n*c) <br>

### Bitonic Ordering [C]

We begin by looking at a couple of observations. <br>
1. To build every possible bitonic array we notice that the smallest element will be the rightmost or leftmost element. We can prove this by contradiction <br>
if the smallest element is not the leftmost or rightmost then there it will be inbetween two larger elements than itself. This creates a peak in the array <br>
which violates the bitonic ordering. We then see this is true for all elements. So if we sort the array and iterate over all elements the current element will be <br>
the leftmost or rightmost of all the remaining elements. <br>
2. When moving each element to the right or left, the only elements left at the point are the number of inversions to either the left or right. <br>
So to solve this we count the number of inversions to the left and to the right of each element. We can save these answers as prefix and postfix sum array. <br>
Now we sort the elements and starting from the smallest one choose for that element to go to the leftside or right side of the remaining elements. Since picking one <br>
side over the other doesn't change the number of inversions we can greedily pick the smaller of the two values. Or we can just use dp. I'm not too sure if this <br>
is a dp or greedy solution, but that doesn't matter. One part missing is how do we count the number of inversions from 1..i for all i in n. To do this we use a <br>
data structure called a binary index tree, you can treat this like a black box. But it lets us count the number of inversions in O(nlogn).<br>
So our final runtime is O(nlogn)<br>

### Condorcet [D]
TBA

### Dominating Duos
