#Python Program to find FACTORIAL

'''#using for loop
fact=1
number=int(input("Enter an integer : "))
for i in range(1,number+1):
    fact=fact*i
print("Factorial of",number,"=",fact)
input("Press Enter to exit")'''

#using while loop
fact=1
number=int(input("Enter an integer : "))
i=1
while(i<=number):
    fact=fact*i
    i=i+1
print("Factorial of",number,"=",fact)
input("Press Enter to exit")


