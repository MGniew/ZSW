from inspect import signature

class CommandProcessor(object):

    def __init__(self):
        self.possibles = globals().copy()
        self.possibles.update(locals())
    
    def read_command(self, text):
        try:
            command = next(x for x in commands if text.startswith(x[0]))
        except StopIteration as err:
            raise StopIteration("EXCEPTION: Method not found")
        
        text = text.replace(command[0], "", 1)
        text = text.strip()
        
        method = self.possibles.get(command[1])
        if not method:
            print(":(")
            raise NotImplementedError("EXCEPTION: Method %s not implemented" % command[1])
           
        sig = signature(method)
        length = len(sig.parameters)
        if (length == 0):
            return method()
        elif (length == 1):
            return method(text)
        else:
            raise ValueError("EXCEPTION: Trying to call a function with more than one parameter") 
        
        
        

commands = [
    ("hello", "print_hello"),
    ("bye", "print_bye"),
    ("print", "print_text")
]
        
        
#custom commands:

def print_hello(text):
    print("hello")
    
    
def print_bye(text):
    print("bye")
    
def print_text(text):
	print(text)
