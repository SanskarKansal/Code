import turtle 
t = turtle.Turtle() 
t.speed(0)
t.hideturtle()
colors = ["blue", "yellow", "black", "green", "red"] 
radius = 50
for i in range(3): 
     t.penup() 
     t.goto(-radius * (2 - i), 0)
     t.pendown() 
     t.color(colors[i]) 
     t.circle(radius) 
     t.penup() 
     t.goto(-radius, -radius * 1.5) 
     t.pendown() 
     t.color(colors[3]) 
     t.circle(radius) 
     t.penup() 
     t.goto(radius, -radius * 1.5) 
     t.pendown() 
     t.color(colors[4]) 
     t.circle(radius) 
turtle.done() 
