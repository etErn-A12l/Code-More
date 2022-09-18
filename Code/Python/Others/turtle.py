import turtle

as_turtle= turtle.Turtle()
as_turtle.speed(500)

def square():
	as_turtle.forward(100)
	as_turtle.right(90)
	as_turtle.forward(100)
	as_turtle.right(90)
	as_turtle.forward(100)
	as_turtle.right(90)
	as_turtle.forward(100)

while True :	
     square()
     as_turtle.right(5)
     as_turtle.backward(2)
