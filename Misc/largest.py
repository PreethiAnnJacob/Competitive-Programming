#Python Program to find the largest of three numbers
num1=int(input("Enter number1 : "))
num2=int(input("Enter number2 : "))
num3=int(input("Enter number3 : "))
if((num1>num2) & (num1>num3)):
    largest=num1
elif((num2>num1) & (num2>num3)):
    largest=num2
else:
    largest=num3
print("Largest of three = ",largest)
