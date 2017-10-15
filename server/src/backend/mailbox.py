from flask import Blueprint

mailbox = Blueprint('mailbox', __name__, url_prefix='/mailbox')


@mailbox.route('/', methods=['GET'])
def mailbox_status():
    return 1
