from flask import Flask, render_template, request, redirect, url_for, jsonify  # Aggiungi il modulo jsonify
from interface import *
from db import *

app = Flask(__name__)

logged_in = False

valid_username = "utente"
valid_password = "password"

@app.route('/')
def index():
    return render_template('login.html')

@app.route('/checklogin', methods=['POST'])
def check_login():
    global logged_in

    username = request.form['username']
    password = request.form['password']

    if access(username, password):
        logged_in = True
        return redirect(url_for('welcome'))
    else:
        return "Credenziali non valide. <a href='/'>Torna al login</a>"

@app.route('/welcome')
def welcome():
    if logged_in:
        loginPLC()
        return render_template('dashboard.html')
    else:
        message = "Devi effettuare il login prima."
        return render_template('login.html', alert=message)


@app.route('/plc', methods=['POST'])
def plc():
    value = request.form['action']
    if value == "start":
        startPLC()
        startFactory()

        return render_template('dashboard.html')

    if value == "stop":
        stopFactory()
        return render_template('dashboard.html')

    if value == "reset":
        resetFactory()
        stopPLC()
        logoutPLC()
        loginPLC()
        return render_template('dashboard.html')

@app.route('/get_data', methods=['GET'])
def get_data():
    info = getInfo()
    return jsonify(info)

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')
