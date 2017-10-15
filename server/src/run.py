from flask import Flask
from backend.mailbox import mailbox

app = Flask(__name__)
app.register_blueprint(mailbox)

app.run(host='0.0.0.0', port=5000, debug=True)
