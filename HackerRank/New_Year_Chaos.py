'''
New Year Chaos

It is New Year's Day and people are in line for the Wonderland rollercoaster ride. Each person wears a sticker indicating their initial Position in the queue from 1 to n. Any person can bribe the prson directly in front of them to swap positions, byt they still wear their original sticker. One person can bribe at most two others. 
Determine the minimum number of bribes that took place to get to a given queue order. Print the number of bribes, or, if anyone has bribed more than two people, print "Too Chaotic".

Example
q=[1,2,3,5,4,6,7,8]
If person 5 bribes person 4, the queue will look like this: 1,2,3,5,4,6,7,8. Only 1 bribe is required. Print 1.

q=[4,1,2,3]
Person 4 had to bribe 3 people to get to the current position. Print Too Chaotic

Function Description
Complete the function minimumBribes in the editor below.
minimumBribes has the following parameters:
int q[n]: the positions of the people after all bribes

Returns
No value is returned. Print the minimum number of bribes necessary or Too Chaotic if someone has bribed more than 2 people.

Input Format
The first line contains an inter t, the number of testcases.
Each of the next t pairs of lines areas fo.lows:
- The first line contains an integer t, the number of people in the queue.
- The second line has n space-separated integers describing the final state of the queue.

Constraints
1<=t<=10
1<=n<=10^5

Subtasks
For 60%score 1<=n<=10^3
For 100% score 1<=n<=10^5

Sample Input
STDIN        Function
-----        --------
2            t=2
5            n=5
2 1 5 3 4    q=[2,1,5,3,4]
5            n=5
2 5 1 3 4    q=[2,5,1,3,4]

Sample Output
3
Too chaotic

Explanation
Testcase 1
The initial state:1 2 3 4 5
After 5 moves one position ahead by bribing person 4: 1 2 3 5 4
Now person 5 moves another position ahead by bribing person 3: 1 2 5 3 4
And person 2 mobes one position ahead by bribing person 1: 2 1 5 3 4
So the final state is 2,1,5,3,4 after three bribing operations.

Testcase 2
No person can bribe more than two people, yet it appears person 5 has done so. It is not possile to achieve the input state.

'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumBribes' function below.
#
# The function accepts INTEGER_ARRAY q as parameter.
#

# # Method 1: 10/12 testcases wrong. score=0
# # Tried to calculate difference in positions between sorted and current.
# # eg. Doesn't work in similar cases: q= 1 2 5 3 7 8 6 4
# # No of bribes=7 but my output=6
# def minimumBribes(q): 
#     # Write your code here
#     bribe=0
#     chaos=0
#     qsorted=q.copy()
#     qsorted.sort()
#     for i in range(len(q)):
#         for j in range(i,len(q)):
#             if q[i]==qsorted[j]:
#                 if(j-i<=2):
#                     bribe+=(j-i)
#                 else:
#                     chaos=1
#                 break
#         if chaos==1:
#             break
#     if chaos==1:
#         print ("Too chaotic")
#     else:
#         print (bribe)

# # Method 2: Time limit exceeded error for 4/12 cases. score=55.0
# def minimumBribes(q): 
#     # Write your code here
#     bribe=0
#     # toomuch=False
#     for i in reversed(range(len(q))):
#         currbribe=0
#         for j in reversed(range(i+1,len(q))):
#             if (q[i]>q[j]):
#                 currbribe+=1
#                 if currbribe>2:
#                     print("Too chaotic") 
#                     return
#         bribe+=currbribe
#     print(bribe)
    
# Method 3: Score=100
# Trying out O(n) method:
# - Optimize Method 2 for bribes by Keeping track of the two smallest numbers + 
# - Use Method 1 for chaos: chaos if position difference>2. (Note: Sorted array is actually list with index+1)
def minimumBribes(q): 
    # Write your code here  
    small1=math.inf
    small2=math.inf
    bribe=0
    for i in range(len(q)-1,-1,-1):
        if (q[i]-1-i>2):
            print ("Too chaotic")
            return
        bribe+=int(q[i]>small1)+int(q[i]>small2)
        if (q[i]<small1):
            small2=small1
            small1=q[i]
        elif (q[i]<small2):
            small2=q[i]
    print(bribe)

if __name__ == '__main__':
    t = int(input().strip())
    for t_itr in range(t):
        n = int(input().strip())
        q = list(map(int, input().rstrip().split()))
        minimumBribes(q)
