import turtle
l=["yellow","green","blue","red","pink"]
a=turtle.Turtle()
a.hideturtle()
a.speed(2)
for i in range(5):
    a.begin_fill()
    a.fillcolor(l[i])
    a.forward(85)
    a.left(126)
    a.forward(100)
    a.left(126)
    a.forward(85)
    a.end_fill()
    a.right(180)