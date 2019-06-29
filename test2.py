import requests
import json

total_point = 20
count = 0
for i in range(3):
    print("Total: ",total_point)
    evenOrOdd = input("Input your bet(odd,even) >> ")
    if evenOrOdd != "odd" and evenOrOdd != "even":
        print("Please input 'odd' or 'even'")
        exit(1)
    try:
        point = int(input("Input your bet points(0 - 20) >> "))
    except ValueError:
        print("No valid number.Please input a natural number.")
        exit(1)
    total_point -= point
    input_data = {
                    "bet":(None,evenOrOdd),
                    "points":(None,point),
    }
    response = requests.post('https://tanaka-server.herokuapp.com/',files=input_data)
    data = response.json()
    print("Dice: ",data["dice"])
    print("Result: ",data["result"])
    print("Points: ",data["points"])
    if(data["result"] == evenOrOdd):
        total_point += int(data["points"])
        count += 1
    print()
print("#### finish ####")
print("Win: ",count)
print("Lose: ",3-count)
print("Total points ",total_point)
