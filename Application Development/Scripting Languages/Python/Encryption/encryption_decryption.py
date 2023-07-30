i = 0
x = []
writefile = ""
index = 0
li = []
lst1 = [
    "",
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--..",
    ".----",
    "..---",
    "...--",
    "....-",
    ".....",
    "-....",
    "--...",
    "---..",
    "----.",
    "------",
    ".-.-.-",
    "--..--",
    "..--..",
    ".----.",
    "-..-.",
    "---...",
    "-.-.-.",
    ".-.-.",
    "-....-",
    "-...-",
    "._.",
]
lst2 = [
    "",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "0",
    ".",
    ",",
    "?",
    "'",
    "#",
    ":",
    ";",
    "+",
    "-",
    "=",
    " ",
]


def encryption():
    f = open("enc.txt", "a")
    f.write("\n")
    for i in read:
        if i in lst2:
            index = lst2.index(i)
            writefile = lst1[index] + " "
            f.write(writefile)
    index = 0
    writefile = ""
    f.close()


def decryption():
    f = open("txt.txt", "a")
    x = opn.split(" ")
    f.write("\n")
    for i in x:
        index = lst1.index(i)
        writefile = lst2[index] + ""
        f.write(writefile)
        index = 0
        writefile = ""
    f.close()


choice = input("Enter 0 for ENCRYPTION and 1 FOR DECRYPTION \n")
print("ENTER \n")

if choice == "0":
    while True:
        read = input()
        read = read.upper()
        encryption()
        if read == "###":
            break
elif choice == "1":
    with open("enc.txt") as w:
        content = w.readlines()

        li = [x.strip() for x in content]  # extracting the data from the encrypt file
        print(li)
        for i in li:
            opn = i
            decryption()
elif choice == "###":
    exit(1)
