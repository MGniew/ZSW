from flask import Flask
from mailbox import Mailbox

app = Flask(__name__)


mailbox = Mailbox()


@app.route("/state")
def get_state():
    return mailbox.mailbox_state


@app.route("/state/change")
def state_changed():
    mailbox.mailbox_state = "0" if mailbox.mailbox_state == "1" else "1"
    return mailbox.mailbox_state

if __name__ == "__main__":
    app.run(debug=True, host='0.0.0.0')
