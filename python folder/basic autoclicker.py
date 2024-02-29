import pyautogui
import time
 
def click(): 
    time.sleep(0.5)     #time between clicks
    pyautogui.click()
def main():
    for i in range(100000): #total repetitions to avoid infinite loop (move mouse to screen corner for failsafe)
        click()
 
main()
