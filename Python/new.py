import tkinter as tk

class FoodOrderApp:
    def __init__(self, master):
        self.master = master
        self.master.title("Food Ordering System")
        
        # Centering the window on the screen
        window_width = 400
        window_height = 300
        screen_width = self.master.winfo_screenwidth()
        screen_height = self.master.winfo_screenheight()
        x = (screen_width / 2) - (window_width / 2)
        y = (screen_height / 2) - (window_height / 2)
        self.master.geometry(f"{window_width}x{window_height}+{int(x)}+{int(y)}")
        
        # Label for menu heading
        self.menu_heading = tk.Label(self.master, text="Menu", font=("Helvetica", 16, "bold"))
        self.menu_heading.pack(pady=10)
        
        # Frame to hold the menu
        self.menu_frame = tk.Frame(self.master)
        self.menu_frame.pack(pady=10, padx=20)
        
        # Dictionary to store food items and their prices
        self.food_menu = {
            "Naan": 20.00,
            "Paneer": 350.00,
            "Salad": 25.00,
            "Roti": 8.00,
            "Papad": 15.00,
            "Rasmalai": 30.00
        }
        
        self.selected_items = {}
        
        self.create_widgets()
        
    def create_widgets(self):
        # Create Checkbuttons and Entry widgets for each food item
        self.food_vars = {}
        self.quantity_entries = {}
        row = 0
        for food_item, price in self.food_menu.items():
            var = tk.IntVar()
            self.food_vars[food_item] = var
            chkbtn = tk.Checkbutton(self.menu_frame, text=f"{food_item} - Rs{price}", variable=var)
            chkbtn.grid(row=row, column=0, sticky="w")
            
            quantity_label = tk.Label(self.menu_frame, text="Quantity:")
            quantity_label.grid(row=row, column=1, padx=10)
            
            quantity_entry = tk.Entry(self.menu_frame, width=5)
            quantity_entry.grid(row=row, column=2)
            self.quantity_entries[food_item] = quantity_entry
            
            row += 1
        
        # Button to calculate total bill
        self.total_button = tk.Button(self.master, text="Calculate Total", command=self.calculate_total)
        self.total_button.pack(pady=10)
        
        # Label to display total bill
        self.total_label = tk.Label(self.master, text="")
        self.total_label.pack(pady=10)
        
    def calculate_total(self):
        total = 0
        self.selected_items.clear()
        for food_item, var in self.food_vars.items():
            if var.get() == 1:
                try:
                    quantity = int(self.quantity_entries[food_item].get())
                except ValueError:
                    continue
                price = self.food_menu[food_item] * quantity
                total += price
                self.selected_items[food_item] = price
        
        self.total_label.config(text=f"Total Bill: Rs{total:.2f}")

def main():
    root = tk.Tk()
    app = FoodOrderApp(root)
    root.mainloop()

if __name__ == "__main__":
    main()
