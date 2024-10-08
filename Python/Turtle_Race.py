import turtle, random

screen = turtle.Screen()
screen.title("The Turtle Race is Here !!!!")
screen.setup(width = 1000, height = 600)
screen.bgcolor("black")
colors = ["Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"]
racers = {}
user_bet = turtle.textinput("Make a Bet", "Which Rainbow Bow are you Manifesting On !!!").capitalize()
turt = turtle.Turtle()
turt.hideturtle()

def finishing_line():
    turt.penup()
    turt.goto(430,-130)
    turt.pendown()
    turt.left(90)
    turt.color("white")
    turt.forward(280)
    turt.penup()
    turt.home()
    turt.pendown()
    
finishing_line()   

y = -120
for _ in colors:
    racers[_] = turtle.Turtle(shape="turtle")
    racers[_].color(_)
    racers[_].penup()
    racers[_].goto(-450, y)
    y += 40

flag = True
while flag:
    for color in racers:
        if racers[color].xcor() > 430:
            flag = False
            winner = racers[color].pencolor()
            col = color
            if user_bet == winner:
                print(f"Congratulations, you won! The winner is {winner}!")
            else:
                print(f"Sorry, you lost! The winner is {winner}!")
        else:
            random_speed = random.randint(0,10)
            racers[color].forward(random_speed)


screen.title(f"The winner is {winner}!")            
turt.color(col)
turt.write(f"The winner is {winner}!",align='center', font=('Arial', 20, 'normal'))

screen.exitonclick()

