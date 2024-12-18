class radius:
    def __init__(self):
        
    def area(self,radius):
        self.radius=radius
        self.area=3.14*radius*radius
        print(self.area)
    def  perimeter(self,radius):
        self.radius=radius
        self.perimeter=3.14*2*radius
        perimeter=self.perimeter
        print(perimeter)
r1=radius()
print(r1.area(10))
print(r1.perimeter(10))