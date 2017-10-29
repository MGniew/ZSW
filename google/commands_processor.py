from inspect import signature
import RPi.GPIO as gpio
import time
import subprocess
from subprocess import CalledProcessError, check_output
import _thread
import os

#additional functions
def is_process_alive(process_name):
    try:
        check_output(["pgrep", process_name])
        output = 0
    except subprocess.CalledProcessError as er:
        output = er.returncode
        
    if output == 0:
        return True
    else:
        return False
        
        
def play_sound(filename):
    os.system("aplay sounds/"+filename)

##########



#custom commands:

def print_hello(text):
    print("hello")
    
    
def print_bye(text):
    print("bye")
    
def print_text(text):
	print(text)
	
def play_yt(text):
    
    if is_process_alive("vlc"):
        return
        
    play_sound("im_on_it.wav")
    
    playshell = subprocess.Popen(["/usr/local/bin/mpsyt", ""], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    
    playshell.stdin.write(bytes('/' + text + '\n1\n', 'utf-8'))
    playshell.stdin.flush()
    
    gpio.setmode(gpio.BCM)
    gpio.setup(23, gpio.IN, pull_up_down=gpio.PUD_UP)
    
    print("STARTING VLC...")
    while(not is_process_alive("vlc")):
        time.sleep(1)
        
    print("MUSIC IS PLAYING")    
    while(gpio.input(23) and is_process_alive("vlc")):
        time.sleep(1)
        
    subprocess.Popen(["/usr/bin/pkill", "vlc"], stdin=subprocess.PIPE)
    playshell.kill()
	
##################
	

class CommandProcessor(object):
	
    commands = [
    ("hello", print_hello),
    ("bye", print_bye),
    ("print", print_text),
    ("play", play_yt)
    ]
    
	
    def read_command(self, text):
        try:
            command = next(x for x in self.commands if text.startswith(x[0]))
        except StopIteration as err:
            return False
        
        text = text.replace(command[0], "", 1)
        text = text.strip()
        method = command[1]
           
        sig = signature(method)
        length = len(sig.parameters)
        if (length == 0):
            return _thread.start_new_thread(method, ())
        elif (length == 1):
            _thread.start_new_thread(method, (text,))
        else:
            raise ValueError("EXCEPTION: Trying to call a function with more than one parameter") 
        
        
        return True
        
