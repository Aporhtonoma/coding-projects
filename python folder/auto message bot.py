import pyautogui
import time
msg = input("Enter the message: ")   #message string
n = input("How many times ?: ")     #how many times it will repeat
time.sleep(5)     #5 second delay so it dosent immidiately start
for i in range(0,int(n)):
     pyautogui.typewrite(msg + '\n') #message typign
