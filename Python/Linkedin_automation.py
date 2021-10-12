from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import pyautogui as pag


def login():
	username = driver.find_element_by_id("login-email")
	username.send_keys("username")						
	password = driver.find_element_by_id("login-password")
	password.send_keys("password")					
	driver.find_element_by_id("login-submit").click()		

def goto_network():
	driver.find_element_by_id("mynetwork-tab-icon").click()

def send_requests():
	n = input("Number of requests: ")

	for i in range(0, n):
		pag.click(880, 770)
	print("Completed!")
