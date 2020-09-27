#Python Program for MULTI MULTIPLICATION TABLE
number=int(input("Enter any number : "))
for num in range(1,number+1):
    for i in range(1,11):
        print(i,"*",num,'=',(num*i))
    print("\n")
input("Press Enter to exit")
