# write a program in python .given a file the task is to change the content in reverse order using stack as well as store thr line of that file in reverse order

class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        else:
            return None

    def is_empty(self):
        return len(self.items) == 0

def reverse_content(file_name):
    reversed_lines = []
    with open(file_name, 'r') as file:
        for line in file:
            stack = Stack()
            for char in line.strip():
                stack.push(char)
            reversed_line = ''
            while not stack.is_empty():
                reversed_line += stack.pop()
            reversed_lines.append(reversed_line)
    
    reversed_lines.reverse()
    a=[]
    with open(file_name, 'w') as file:
        for line in reversed_lines:
            a.append(line)
            file.write(line + '\n')
    print(a)
file_name = 'a.txt'
reverse_content(file_name)
print("Content reversed")
