from flask import Flask, render_template_string, request, jsonify
import re

app = Flask(__name__)

blacklist = ["os", "popen", "subprocess", "_", "mro", ".", "globals", "locals", "config","builtins", "import"]

def sanitize_input(name):
    for word in blacklist:
        if word in name:
            return False
    return name

@app.route('/', methods=['GET', 'POST'])
def index():
    username = ''
    
    if request.method == 'POST':
      username = request.form['username'] or ''
      username = sanitize_input(username)
      if not username:
        return jsonify({'error': 'Forbidden Words'})
	
    template = '''<!DOCTYPE html>
    <html>
    <body>
    <form action="" method="POST">
      Username: <input name="username"> <br>
      <input type="submit" value="Preview!">
    </form>
    <p>{}</p>
    </body>
    </html>'''.format(username)
    return render_template_string(template)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5555)