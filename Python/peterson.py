#!/usr/bin/env python
# -*- coding: utf-8 -*-

import threading
import time

cs = 0
flag_0 = False
flag_1 = False
turn = 0

def thread_0():
    global cs, flag_0, flag_1, turn

    flag_0 = True
    turn = 1
    while (flag_1 and turn == 1):
            continue

    for i in range(10):
        cs += 1
        print("Thread 0: cs =", cs)
        time.sleep(0.1)

    flag_0 = False

def thread_1():
    global cs, flag_0, flag_1, turn

    flag_1 = True
    turn = 0
    while (flag_0 and turn == 0):
        continue

    for i in range(10):
        cs += 1000
        print("Thread 1: cs =", cs)
        time.sleep(0.1)

    flag_1 = False

if __name__ == "__main__":
		t0 = threading.Thread(target=thread_0)
		t1 = threading.Thread(target=thread_1)
		t0.start()
		t1.start()
