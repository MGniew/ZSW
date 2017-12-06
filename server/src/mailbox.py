class Mailbox:
    filename="state.txt"

    def __init__(self):
        pass
        
    def get_state(self):
        f = open(self.filename, "r+")
        mailbox_state = f.read()
        f.close()
        return mailbox_state
		
    def set_state(self, state):
        f = open(self.filename, "w")
        f.write(state)
        f.close()
        return state
		
