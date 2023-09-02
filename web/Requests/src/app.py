import requests
from urllib.parse import urlparse
from flask import Flask, request, render_template, Response

app = Flask(__name__)

def is_valid_url(url):
    if url.startswith(("http://", "https://")):
        parsed_url = urlparse(url)
        if parsed_url.hostname not in ("localhost", "127.0.0.1"):
            return True
    return False

@app.route("/")
def home():
    return render_template("index.html")

@app.route("/urls", methods=["POST"])
def process_url():
    data = request.form.get("target")
    if data:
        if is_valid_url(data):
            try:
                resp = requests.get(data)
                return resp.content
            except requests.exceptions.ConnectionError:
                return "Failed to establish a connection.", 400
        else:
            return "Invalid URL format or restricted URL."
    else:
        return "No URL provided."

@app.route("/flag")
def flag():
    if request.remote_addr == "127.0.0.1":
        return "HCS{EsEsErEf_1s_4w3s0m3}"
    else:
        return "Access denied. This endpoint can only be accessed from localhost."

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5555)
