import random

user = input("Insert Your Username: ")
list_of_users = list()

keys = dict.fromkeys("12345678", user)

fast_func = lambda x : True

def my_function():
        i=0
        for num in keys.items():
            random_num = random.randint(1,100)
            list_of_users.append(f"{num[1]} {random_num}" )
            print(f"Key: {num[0]}, Default Value: {list_of_users[i]}") 
            i = i+1
            

my_function()



