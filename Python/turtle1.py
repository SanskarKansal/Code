# import turtle 
# loadWindow = turtle.Screen() 
# turtle.speed(12) 
# for i in range(30): 
# 	turtle.circle(5*i) 
# 	turtle.color("blue")
# 	turtle.circle(-5*i) 
# 	turtle.left(i) 
# turtle.exitonclick() 
# import turtle
# a=turtle.Turtle()
# a.right(22.5)
# a.screen.bgcolor("black")
# a.color("green")
# a.width(5)
# for i in range(8):
#     a.circle(100 ,steps=8)
#     a.right(45)
# turtle.done()
# import tkinter as tk
# from tkinter import ttk

# class RestaurantApp:
#     def _init_(self, master):
#         self.master = master
#         self.master.title("Restaurant Application")
#         self.master.geometry("600x400")
#         self.master.configure(bg="#f0f0f0")  # Set background color for the main window

#         # Menu items and prices
#         self.menu = {
#             "Burger": 5.99,
#             "Pizza": 8.99,
#             "Pasta": 6.99,
#             "Salad": 4.99,
#             "Soda": 1.99,
#             "Water": 0.99
#         }

#         # Reservation status for 20 tables
#         self.reservation_status = [False] * 20

#         # Variables to store order information
#         self.selected_items = {}
#         self.total_price = tk.DoubleVar()

#         # Variable to store selected table number
#         self.selected_table = tk.StringVar()

#         # Create widgets
#         self.create_menu()
#         self.create_table_status()
#         self.create_order_section()

#     def create_menu(self):
#         menu_frame = tk.Frame(self.master, bg="#d9d9d9")  # Set background color for the menu frame
#         menu_frame.grid(row=0, column=0, padx=10, pady=10)

#         tk.Label(menu_frame, text="Menu Card", font=("Helvetica", 16, "bold"), bg="#d9d9d9").grid(row=0, column=0, columnspan=2)

#         row = 1
#         for item, price in self.menu.items():
#             tk.Label(menu_frame, text=item, font=("Helvetica", 12), bg="#d9d9d9").grid(row=row, column=0, sticky="w", padx=5, pady=2)
#             tk.Label(menu_frame, text="${:.2f}".format(price), font=("Helvetica", 12), bg="#d9d9d9").grid(row=row, column=1, sticky="e", padx=5, pady=2)
#             row += 1

#     def create_table_status(self):
#         table_frame = tk.Frame(self.master, bg="#d9d9d9")  # Set background color for the table frame
#         table_frame.grid(row=0, column=1, padx=10, pady=10)

#         tk.Label(table_frame, text="Table Status", font=("Helvetica", 16, "bold"), bg="#d9d9d9").grid(row=0, column=0)

#         self.table_status_labels = []

#         row = 1
#         for i, status in enumerate(self.reservation_status, start=1):
#             status_str = "Reserved" if status else "Unreserved"
#             label = tk.Label(table_frame, text="Table {}: {}".format(i, status_str), font=("Helvetica", 12), bg="#d9d9d9")
#             label.grid(row=row, column=0, sticky="w")
#             self.table_status_labels.append(label)
#             row += 1

#         tk.Label(table_frame, text="Choose Table:", font=("Helvetica", 12), bg="#d9d9d9").grid(row=row, column=0, sticky="w", pady=5)
#         self.table_dropdown = ttk.Combobox(table_frame, textvariable=self.selected_table, values=["Table {}".format(i) for i in range(1, 21)], state="readonly")
#         self.table_dropdown.grid(row=row, column=1, sticky="e", pady=5)
#         self.table_dropdown.bind("<<ComboboxSelected>>", self.update_table_status)

#     def update_table_status(self, event):
#         table_num = int(self.selected_table.get().split()[1])
#         self.reservation_status[table_num - 1] = True
#         self.table_status_labels[table_num - 1].config(text="Table {}: Reserved".format(table_num), bg="#ffcccc")  # Change background color to indicate reservation

#     def create_order_section(self):
#         order_frame = tk.Frame(self.master, bg="#d9d9d9")  # Set background color for the order frame
#         order_frame.grid(row=1, column=0, columnspan=2, padx=10, pady=10)

#         tk.Label(order_frame, text="Order Section", font=("Helvetica", 16, "bold"), bg="#d9d9d9").grid(row=0, column=0, columnspan=2)

#         self.order_listbox = tk.Listbox(order_frame, selectmode=tk.MULTIPLE, height=6, width=40, font=("Helvetica", 12))
#         self.order_listbox.grid(row=1, column=0, padx=5, pady=5)

#         for item in self.menu.keys():
#             self.order_listbox.insert(tk.END, item)

#         self.quantity_entry = tk.Entry(order_frame, width=5, font=("Helvetica", 12))
#         self.quantity_entry.grid(row=1, column=1, padx=5, pady=5)
#         tk.Label(order_frame, text="Quantity:", font=("Helvetica", 12), bg="#d9d9d9").grid(row=1, column=2, padx=5, pady=5)

#         add_button = tk.Button(order_frame, text="Add to Order", command=self.add_to_order, font=("Helvetica", 12))
#         add_button.grid(row=1, column=3, padx=5, pady=5)

#         tk.Label(order_frame, text="Total Price:", font=("Helvetica", 12), bg="#d9d9d9").grid(row=2, column=0, sticky="e")
#         tk.Label(order_frame, textvariable=self.total_price, font=("Helvetica", 12), bg="#d9d9d9").grid(row=2, column=1, sticky="w")

#         calculate_button = tk.Button(order_frame, text="Calculate Total", command=self.calculate_total, font=("Helvetica", 12))
#         calculate_button.grid(row=3, column=0, columnspan=2, pady=10)

#     def add_to_order(self):
#         selected_indices = self.order_listbox.curselection()
#         quantity = int(self.quantity_entry.get())
#         for i in selected_indices:
#             item = self.order_listbox.get(i)
#             if item in self.selected_items:
#                 self.selected_items[item] += quantity
#             else:
#                 self.selected_items[item] = quantity

#     def calculate_total(self):
#         total = sum(self.menu[item] * quantity for item, quantity in self.selected_items.items())
#         self.total_price.set("${:.2f}".format(total))

# if _name_ == "__main__":
#     root = tk.Tk()
#     app = RestaurantApp(root)
#     root.mainloop()

# import PIL
# from PIL import Image
# a=Image.open("image.png")
# print(a.mode)
# b=a.transpose(method=Image.FLIP_TOP_BOTTOM)
# b.save("copy.png")
# b.show()

# from PIL import Image
# image = Image.open("image.png")
# image.load()
# im=image.convert('RGB')
# r, g, b= im.split()
# print(g)
# im1 = Image.merge('RGB', (g, b, r))
# im1.show()

# import turtle
# a=turtle.Turtle()
# a.speed(30)
# l=["orange","blue","green"]
# for i in range(3):
#     a.circle(100,steps=3)
#     a.right(240)
#     a.forward(173)
#     a.right(180)
#     a.circle(100,steps=3)
#     a.forward(173)
#     a.fillcolor(l[i])
#     a.begin_fill()
#     a.circle(100,steps=3)
#     a.right(240)
#     a.forward(173)
#     a.right(180)
#     a.circle(100,steps=3)
#     a.forward(173)
#     a.end_fill()
# a.up()
# a.goto(0,-203)
# a.down()
# a.circle(203,steps=6)
# turtle.done()
# import turtle
# t=turtle.Turtle()
# t.pensize(2)
# t.speed(0)
# t.circle(120,360,18)
# t.left(90)
# t.forward(120)
# t.right(180)
# t.forward(120)
# for i in range(1,18):
#     t.left(180)
#     t.forward(120)
#     t.right(180)
#     t.left(20)
#     t.forward(120)    
# for j in range(0,12):
#   t.left(60)
#   t.forward(63)
#   t.left(100)
#   t.forward(63)
#   t.right(120)
# turtle.done()

# import turtle
# a=turtle.Turtle()
# a.shapesize(25)
# a.forward(50)
# a.shape("classic")
# turtle.done()

# import turtle
# a=turtle.Turtle()
# a.screen.bgcolor("black")
# a.speed(100)
# a.width(2)
# for i in range(90):
#     a.color("red")
#     a.forward(180-2*i)
#     if(i%6==0):
#         a.left(61)
#     else:
#         a.left(60)
#     a.color("blue")
#     a.forward(180-2*i)
#     if((i+1)%6==0):
#         a.left(61)
#     else:
#         a.left(60)
#     a.color("green")
#     a.forward(180-2*i)
#     if((i+2)%6==0):
#         a.left(61)
#     else:
#         a.left(60)
#     a.color("orange")
#     a.forward(180-2*i)
#     if((i+3)%6==0):
#         a.left(61)
#     else:
#         a.left(60)
#     a.color("purple")
#     a.forward(180-2*i)
#     if((i+4)%6==0):
#         a.left(61)
#     else:
#         a.left(60)
#     a.color("pink")
#     a.forward(180-2*i)
#     if((i+5)%6==0):
#         a.left(61)
#     else:
#         a.left(60)
# turtle.done()
# class complex:
#     def __init__(self,real,img):
#         self.real=real
#         self.img=img
#     def shownum(self):
#         print(self.real,"i +",self.img,"j")
#     def __add__(self,other):
#         numr=self.real+other.real
#         nume=self.img+other.img
#         return complex(numr,nume)
# num1= complex(1,3)
# num2=complex(4,6)
# num3=num1+num2
# num3.shownum()
# print(num3.real,"i+",num3.img,"j")

# class A(object):
#     def method(self):
#         print("In A")
#         super().method()
# class B(object):
#     def method(self):
#         print("In B")
#         super().method()
#     def mo(self):
#         print("59")
# class C(A,B):
#     def method(self):
#         print("In C")
#         super().method()
# c1=C()     
# print(C.mo())
# Create bytearray 
# (sequence of values in 
# the range 0-255 in binary form)

# ASCII for A,B,C,D
# byte_arr = [65,66,67,68,69,70,99,100] 
# some_bytes = bytearray(byte_arr)

# # Bytearray allows modification
# # ASCII for exclamation mark
# some_bytes.append(33)

# # Bytearray can be cast to bytes
# immutable_bytes = bytes(some_bytes)

# # Write bytes to file
# with open("my_file.txt", "rb") as binary_file:
#     for i in binary_file:
#         # print(i, "*")
#         for j in i:
#             print(j,"*")


                

# from tkinter import * 
# root = Tk() 
# root.geometry("300x150") 

# w = Label(root, text ='GeeksForGeeks', font = "50") 
# w.pack() 

# frame = Frame(root) 
# frame.pack() 

# bottomframe = Frame(root) 
# bottomframe.pack( side = BOTTOM ) 

# b1_button = Button(frame, text ="Geeks1", fg ="red") 
# b1_button.pack( side = LEFT) 

# b2_button = Button(frame, text ="Geeks2", fg ="brown") 
# b2_button.pack( side = LEFT ) 

# b3_button = Button(frame, text ="Geeks3", fg ="blue") 
# b3_button.pack( side = LEFT ) 

# b4_button = Button(bottomframe, text ="Geeks4", fg ="green") 
# b4_button.pack( side = BOTTOM) 

# b5_button = Button(bottomframe, text ="Geeks5", fg ="green") 
# b5_button.pack( side = BOTTOM) 

# b6_button = Button(bottomframe, text ="Geeks6", fg ="green") 
# b6_button.pack( side = BOTTOM) 

# root.mainloop() 

# import tkinter as tk

# class FoodOrderApp:
#     def __init__(self, master):
#         self.master = master
#         self.master.title("Food Ordering System")
        
#         # Dictionary to store food items and their prices
#         self.food_menu = {
#             "Burger": 5.00,
#             "Pizza": 8.00,
#             "Salad": 6.00,
#             "Fries": 3.00
#         }
        
#         self.selected_items = {}
        
#         self.create_widgets()
        
#     def create_widgets(self):
#         self.food_label = tk.Label(self.master, text="Select Food:")
#         self.food_label.grid(row=0, column=0, padx=10, pady=10)
        
#         # Create Checkbuttons for each food item
#         self.food_vars = {}
#         row = 1
#         for food_item, price in self.food_menu.items():
#             var = tk.IntVar()
#             self.food_vars[food_item] = var
#             chkbtn = tk.Checkbutton(self.master, text=f"{food_item} - ${price}", variable=var)
#             chkbtn.grid(row=row, column=0, sticky="w")
#             row += 1
        
#         # Button to calculate total bill
#         self.total_button = tk.Button(self.master, text="Calculate Total", command=self.calculate_total)
#         self.total_button.grid(row=row, column=0, pady=10)
        
#         # Label to display total bill
#         self.total_label = tk.Label(self.master, text="")
#         self.total_label.grid(row=row+1, column=0, pady=10)
        
#     def calculate_total(self):
#         total = 0
#         for food_item, var in self.food_vars.items():
#             if var.get() == 1:
#                 total += self.food_menu[food_item]
#                 self.selected_items[food_item] = self.food_menu[food_item]
        
#         self.total_label.config(text=f"Total Bill: ${total:.2f}")

# def main():
#     root = tk.Tk()
#     app = FoodOrderApp(root)
#     root.mainloop()

# if __name__ == "__main__":
#     main()

