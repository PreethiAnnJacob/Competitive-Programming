#Python Program for PASSWORD 
password="williams"
for i in range(3):
    pwd=input('Enter the password:')
    j=2
    if(pwd==password):
        print('Welcome')
        break
    else:
        print('Wrong password.Chances left:',(j-i))
        if((j-i)>0):
            continue
    print('Try next time')
input('Press Enter to exit')
