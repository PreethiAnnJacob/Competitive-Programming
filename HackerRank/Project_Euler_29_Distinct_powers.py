'''
Project Euler #29: Distinct powers

Consider all integer combinations of a^b for 2<=a<=5 and 2<=b<=5:
2^2=4,2^3=8,2^4=16,2^5=32
3^2=9,3^3=27,3^4=81,3^5=243
4^2=16,4^3=64,4^4=256,4^5=1024
5^2=25,5^3=125,5^4=625,5^5=3125
If they are then placed in numerical order, with any repeats removed, we get the following sequence of 15 distinct terms:
4,8,9,16,25,27,32,64,81,125,243,256,625,1024,3125
How many distinct terms are in the sequence generated by a^b for 2<=a<=N and 2<=b<=N?

Input Format
Input contains an integer N

Constraints
2<=N<=10^5

Output Format
Print the answer corresponding to the test case.

Sample Input
5

Sample Output
15
'''


# Try 1: TC:3/21, Rest:TLE
n =  int(input())
list =[]
for a in range(2,n+1):
    for b in range(2,n+1):
        if ((a**b) not in list):
            list.append(a**b)
print(len(list))
