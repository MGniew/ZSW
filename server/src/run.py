from flask import Flask
from mailbox import Mailbox

app = Flask(__name__)


mailbox = Mailbox()


@app.route("/state")
def get_state():
    return mailbox.mailbox_state


@app.route("/state/<state>", methods=['POST'])
def state_changed(state):
    mailbox.mailbox_state = state
    return mailbox.mailbox_state

if __name__ == "__main__":
    app.run(debug=True, host='0.0.0.0')
