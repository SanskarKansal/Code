import turtle
a=turtle.Turtle()
a.hideturtle()
a.speed(5)
a.up()
a.goto(50,20)
a.down()
for i in range(5): 
	a.circle(50*(i+1))
	a.up()
	a.goto(50,20-50*(i+1))
	a.down()
turtle.done()