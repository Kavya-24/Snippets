from tkinter import *
from playsound import playsound
import math

# ---------------------------- CONSTANTS ------------------------------- #
PINK = "#e2979c"
RED = "#e7305b"
GREEN = "#9bdeac"
YELLOW = "#f7f5dd"
FONT_NAME = "Courier"
WORK_MIN = 25
SHORT_BREAK_MIN = 5
LONG_BREAK_MIN = 20
rep = 0
activity = None

# ---------------------------- SCREEN SETUP ------------------------------- # 
screen = Tk()
screen.minsize(width = 500, height = 500)
screen.config(padx = 120, pady = 120, bg = YELLOW)
screen.title("Pomodoro")

# ---------------------------- WINDOW FOCUS ------------------------------- # 
def attention():
    screen.deiconify()
    screen.attributes('-topmost', True)  
    screen.focus_force()
    

# ---------------------------- TIMER RESET ------------------------------- # 
timer = Label(text = "TIMER",width = 11,bg = YELLOW, fg = GREEN, font = (FONT_NAME, 30, "bold"))
timer.grid(row = 0, column = 1)

def reset():
    screen.after_cancel(activity)
    global rep
    rep = 0
    timer.config(text = "TIMER", fg = GREEN)
    canvas.itemconfig(timer_record, text = "00:00")
    tick.config(text = "")
    start["state"] = "normal"

# ---------------------------- TIMER MECHANISM ------------------------------- # 
def start_time():
    global rep 
    rep += 1
    work_time = WORK_MIN * 60
    short_break = SHORT_BREAK_MIN * 60
    long_break = LONG_BREAK_MIN * 60
    
    if rep%8 == 0:
        count_down(long_break)
        timer.config(text = "Long Break", fg = RED)
        rep = 0
    elif rep%2 == 0:
        count_down(short_break)
        timer.config(text = "Short Break", fg = PINK)
    else:
        count_down(work_time)
        timer.config(text = "Work", fg = GREEN)

        
# ---------------------------- COUNTDOWN MECHANISM ------------------------------- # 
def count_down(count):
    start["state"] = "disabled"
    start["disabledforeground"] = start["foreground"]
    min_count_down = math.floor(count/60)
    sec_count_down = count%60
    if sec_count_down == 0:
        sec_count_down = "00"
    elif int(sec_count_down) < 10:
        sec_count_down = f"0{sec_count_down}"
    if min_count_down < 10:
        min_count_down = f"0{min_count_down}"

    
    canvas.itemconfig(timer_record, text = f"{min_count_down}:{sec_count_down}" )
    if count > 0:
        global activity
        activity = screen.after(1000, count_down, count - 1)
    else:
        start_time()
        tick_marks  = ""
        for _ in range(math.floor(rep/2)):
            tick_marks += "✔"
        tick.config(text = tick_marks)
        attention()
        playsound("Snippets/Python/Pomodoro-Timer/NOTIFIKASI WA KEREN 2.mp3")
        
# ---------------------------- UI SETUP ------------------------------- #
canvas = Canvas(width = 200, height = 224, bg = YELLOW, highlightthickness = 0)
tomato = PhotoImage(file = "Snippets/Python/Pomodoro-Timer/tomato.gif")
canvas.create_image(100, 112, image = tomato)
timer_record = canvas.create_text(100, 130, text = "00:00", font =(FONT_NAME, 35, "bold"),fill = "#FFFFFF")
canvas.grid(row = 1, column = 1)
 
start = Button(text = "Start", highlightthickness = 0,fg = PINK, bg = YELLOW, font = (FONT_NAME, 12, "bold"),bd = 0, command = start_time)
reset = Button(text = "Reset", highlightthickness = 0,fg = RED, bg = YELLOW, font = (FONT_NAME, 12, "bold"),bd = 0, command = reset)
start.grid(row = 2, column = 0)
reset.grid(row = 2, column = 2)

tick = Label(bg = YELLOW, fg = GREEN, font = (20))
tick.grid(row = 3, column = 1)

screen.mainloop()