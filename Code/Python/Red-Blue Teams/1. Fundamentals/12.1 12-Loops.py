for i in range(4) :
    for j in range(2) :
        print(f"{i} , {j}")

cmd = ""
while cmd.lower() != "exit":
    cmd= input(">>>")
    print("you typed : ", cmd)
    if cmd.lower() == "exit" :
        break
