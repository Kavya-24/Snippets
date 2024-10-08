import turtle
import random 
import time
from random import randrange

delay=0.1
score=0
highestscore=0

#bodies
bodies=[]

#screen
s=turtle.Screen()
s.title("Snake game")
s.bgcolor("white")
s.setup(width=600, height=600)
s.addshape('./head.gif')
s.addshape('./body.gif')
s.addshape('./food.gif')

#snack head
head=turtle.Turtle()
head.speed(0)

head.shape("./head.gif")    
head.color("grey")
head.fillcolor("blue")
head.penup()
head.goto(0,0)
head.direction="stop"

#food
food=turtle.Turtle()
food.speed(0)
food.shape("./food.gif")
food.color("yellow")
food.fillcolor("green")
food.penup()
food.ht()
food.goto(0,200)
food.st()

#score board
sb=turtle.Turtle()
sb.shape("square")
sb.penup()
sb.ht()
sb.goto(140,280)
sb.write("Score:0  |  Heighest Score: 0")

def moveup():
    if head.direction!="down":
        head.direction="up"

def movedown():
    if head.direction!="up":
        head.direction="down"

def moveleft():
    if head.direction!="right":
        head.direction="left"

def moveright():
    if head.direction!="left":
        head.direction="right"

def movestop():
    head.direction="stop"

def move():
    if head.direction=="up":
        y=head.ycor()
        head.sety(y+20)
    if head.direction=="down":
        y=head.ycor()
        head.sety(y-20)
    if head.direction=="left":
        x=head.xcor()
        head.setx(x-20)
    if head.direction=="right":
        x=head.xcor()
        head.setx(x+20)

s.listen()
s.onkey(moveup, "Up")
s.onkey(movedown, "Down")
s.onkey(moveleft, "Left")
s.onkey(moveright, "Right")
s.onkey(movestop, "space")

while True:
    s.update()
    #check collision with border
    if head.xcor()>300:
        head.setx(-300)
    if head.xcor()<-300:
        head.setx(300)
    if head.ycor()>300:
        head.sety(-300)
    if head.ycor()<-300:
        head.sety(300)

    #check collision with food
    if head.distance(food)<20:
        #move food to random location
        x=random.randint(-14,14)*20
        y=random.randint(-14,14)*20
        #x=randrange(-14,14)*20
        #y=randrange(-14,14)*20
        food.goto(x,y)
        
        #increase snack length
        body=turtle.Turtle()
        body.speed(0)
        body.penup()
        body.shape("./body.gif")
        body.color("red")
        bodies.append(body)

        #update score 
        score+=10

        #increasing speed
        if delay>0:
            delay-=0.01

        if score>highestscore:
            highestscore=score
        sb.clear()
        sb.write("Score: {} | Highest Score: {}".format(score, highestscore))
    #move snake body
    for index in range(len(bodies)-1,0,-1):
        x=bodies[index-1].xcor()
        y=bodies[index-1].ycor()
        bodies[index].goto(x,y)

    if len(bodies)>0:
        x=head.xcor()
        y=head.ycor()
        bodies[0].goto(x,y)
    move()

    #check collision with self 
    for body in bodies:
        if body.distance(head)<20:
            time.sleep(1)
            head.goto(0,0)
            head.direction="stop"

            for body in bodies:
                body.ht()
            bodies.clear()

            score=0
            delay=0.1

            sb.clear()
            sb.write("Score: {} Highest Score: {}".format(score, highestscore))
    if delay>0:
        time.sleep(delay)
    else:
        time.sleep(0.1)
s.mainloop()

