from flask import Flask
from flask import Response
from mailbox import Mailbox

app = Flask(__name__)


mailbox = Mailbox()


@app.route("/state")
def get_state():
    response = Response(mailbox.mailbox_state)
    response.headers['Access-Control-Allow-Origin'] = '*'
    return response


@app.route("/state/<state>", methods=['POST'])
def state_changed(state):
    mailbox.mailbox_state = state
    return mailbox.mailbox_state

if __name__ == "__main__":
    app.run(debug=True, host='0.0.0.0')
