'''
Project Euler #27: Quadratic primes - Easy

Euler published the remarkable quadratic formula:n^2+n+41
It turns out that the formula will produce 40 primes for the consecutive values n=0 to 39. However, when n=40, 40^2+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41, 41^2+41+41 is clearly divisible by 41.

Using computers, the incredible formula n^2-79n+1601 was discovered, which produces 80 primes for the consecutive values n=0 to 79. The product of the coefficients, -79 and 1601, is -126479.

Considering quadratics of the form:
n^2 + an + b, where |a|<=N and |b|<=N 
where |n| is the modulus/absolute value of n
e.g. |11|=11 and |-4|=4 

Find the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.

Note: For this challenge you can assume solution to be unique.

Input Format
The first line contains an integer N.

Output Format
Print the value of a and b separated by space.

Constraints
42<=N<=2000

Sample Input
42

Sample Output
-1 41

Explanation
for a=-1 and b=41, you get 42 primes.
'''

# Try 1 : 5/5
def isPrime(num):
    if (num<=1):
        return False
    if num%2==0:    return False
    for i in range(3,int(num**0.5)+1,2):
        if (num%i==0):
            return False
    return True
num=int(input())
max_count, max_a, max_b = 0,-1,-1
breakaFlag = False
for a in range(-1*(num-1),num):
    for b in range (-1*(num-1),num):
        count=0
        for n in range (0,num):
            if (not(isPrime(n**2+a*n+b))):
                break   # Since n is supposed to be consecutively produce primes
            count+=1
        if count>max_count:
            max_count, max_a, max_b = count,a,b
        if count==num:
            breakaFlag=True
            break
    if breakaFlag:
        break
print (max_a, max_b)
        
