# ICPC-Regionals Solutions
### Currently Solved 12/16
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
O-<br>
P-DONE</p>


## EXPLANATIONS

### Ant Typing [A]
The approach for this problem is brute force. 
There is only 1-9 keys possible therefore the number of permutations of digits 1-9 is 9!=362880. 
This number is very small and we can work with it. 

For every possible keyboard we have some number of seconds. We have two options
A) Iterate through the given string and compute the seconds for each keyboard. At worst case we get O(n*9!) where n can be 10^5. This solution sucks. 
B) We can actually precompute a table that helps a lot. 
table will be as follows 
  1 2 3 4 5 6 7 8 9
1 0 0 0 0 0 0 0 0 0
2 0 0 0 0 1 0 0 0 0 
3 0 1 0 0 0 0 0 0 0 
4 0 0 1 0 0 0 0 0 0
5 0 0 0 0 0 0 1 0 0
6 0 0 0 0 0 0 0 0 0
7 0 0 0 0 0 0 0 1 1 
8 0 0 0 1 0 0 0 0 0
9 0 0 0 0 0 0 0 0 0
This represents A[i,j] = number of times we go from i->j. 
In the example we are given we have string 78432579. 
7->8 
8->4
4->3 
You go from key 7 to 8 once. Then to key 4. 
After we fill this table the answer is easy to see. 
First create this table by iterating through every digit in the string 'S' we are given. Then we just add 1 to S[i]->S[j] in the table. 
So in the example we update A[7,8]
Then we update A[8,4], A[4,3] so on and so on. 

Next we brute force every permutation of keyboards. Then what we can do is calculate the weight for each A[i,j]. 
To do this for a given permuation of 1...n we do as follows. 
Ex. {4,3,1,5,2} Permutation of 1...5
Weight from i to j = (pos of i)-(pos of j) + 1
The weight from 4->3 will be 2
Weight from 3->1 is 2 
Weight from 4->4 is 1
We can make another table of size 9^2. Where W[i,j] is the number of seconds going from key i to key j.
For each permuation of the keyboard sum for all i and j A[i,j]*W[i,j].
However this is not the answer we are missing one part. 
We are told that we start at the leftmost key. So we just have to add the W[starting key, first number of S]
Now we just take the minimum over all permutations
Total time complexity is O(9!9^2)=29393280
So around 29 million computations for 1 second CPU time this is a valid solution. Rule of thumb: 250 million computations per second of time you are given. 
Keep in mind O(n) does not mean that you are doing n computations. 