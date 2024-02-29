import pyautogui
import time
 
def click(): 
    time.sleep(0.005)     
    pyautogui.click()
def main():
    for i in range(100000): 
        click()
 
main()
