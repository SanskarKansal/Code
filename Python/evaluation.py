class BracValid:
    def __init__(self):
        self.opening_brac = {'(', '[', '{'}
        self.closing_brac = {')', ']', '}'}
        self.matching_brac = {'(': ')', '[': ']', '{': '}'}
    def is_valid(self, input):
        stack = []
        for char in input:
            if char in self.opening_brac:
                stack.append(char)
            elif char in self.closing_brac:
                if not stack:
                    return False 
                last_opening_brac = stack.pop()
                if self.matching_brac[last_opening_brac] != char:
                    return False 
        return not stack 
v = BracValid()
print(v.is_valid("((()))")) 
print(v.is_valid("()[{}]"))  
print(v.is_valid("([)]"))    