#File : CS112_A1_T2_3_20231175.py
#Purpose : Subtract asquare is a strategic two-player game where players take turns removing coins from a pile, 
# with each removal being a non-zero square number of coins [1,4,9,16,25,36,...],
# The objective is to be the player to remove the last coins from the pile,thus winning the game.
#Author : Manar sameh abd el samad
#ID : 20231175
#--------------------------------********************************---------------------------------
#                                     welcome to square game
#--------------------------------********************************---------------------------------
import random
import math
# دالة للتاكد من ان الرقم الذي يدخله المستخدم رقم موجب وليس صفر ولا رقم مربع 
def is_valid_input(number):
    return number > 0 and not math.isqrt(number) ** 2 == number

def get_valid_input() :
    while True:
        try: 
            n_coins = int(input("Enter the number of coins: "))
            if is_valid_input(n_coins):
                return n_coins
            else:
                print("Please enter a correct number. ")
        except ValueError:
            print("Please enter a correct number. ")

# الترحيب بالمستخدم , اخيره مابين انه هو هيدخل عدد العملات او يجعل الكمبيوتر يختار له رقم عشوائ 
print("Welcome to the game and get ready for a unique advanture :> ")
choose = int(input("If you want to enter the number of coins choose 1 , If you want me to enter the number of coins choose 0 : "))
if choose == 1:
    # اذا اختار المستخدم ادخال عدد العملات 
    n_coins = get_valid_input()
elif choose == 0:
    # المستخدم ترك البرنامج يختار عدد العملات عشوائيا 
    n_coins = random.randint(10,1000)

print("The number of coins that i choose for you  : ", n_coins)

# بدء اللعبة 
while n_coins > 1:
    # دور اللاعب الاول 
    move = int(input("player 1: Please take square coins for example [1,4,9,16,25,36,...]"))
    while (move**0.5) % 1 != 0:
        move = int(input("player 1: Please take square coins for example [1,4,9,16,25,36,...]"))
    n_coins -= move
    print(f"Now we have {n_coins}")
    if n_coins <= 0:
        print("Player 1 is the winner!")
        break

    # دور اللاعب الثاني 
    move = int(input("player 2: Please take square coins for example [1,4,9,16,25,36,...]"))
    while (move**0.5) % 1 != 0:
        move = int(input("player 2: Please take square coins for example [1,4,9,16,25,36,...]"))
    n_coins -= move
    print(f"now we have {n_coins}")
    if n_coins <= 0:
        print("Player 2 is the winner")
        break 