# Script python to insert data in database (users.db)

import sqlite3
import os

DB_FILE = 'users.db'

def check_db():
    if os.path.exists(DB_FILE):
        print("Database già esistente")
    else:
        print("Database non esistente, creazione in corso...")
        # Connect to database
        conn = sqlite3.connect(DB_FILE)

        # Create a cursor
        c = conn.cursor()

        # If table users doesn't exist, create it
        c.execute("""CREATE TABLE IF NOT EXISTS users (ID, username, password, role)""")

        # Insert data in table users
        c.execute("INSERT INTO users VALUES ('1', 'admin', 'admin', 'admin')")
        c.execute("INSERT INTO users VALUES ('2', 'user', 'user', 'user')")
        c.execute("INSERT INTO users VALUES ('3', 'user2', 'user2', 'user')")
        c.execute("INSERT INTO users VALUES ('4', 'user3', 'user3', 'user')")
        c.execute("INSERT INTO users VALUES ('5', 'guest', 'guest', 'guest')")

        # Commit our command
        conn.commit()

        # Close our connection
        conn.close()

def access(username, password):
    check_db()
    # Check username and password are valid
    if username == "" or password == "":
        print("Username or password are empty")
        return False
    
    # Connect to database
    conn = sqlite3.connect(DB_FILE)

    # Create a cursor
    c = conn.cursor()

    # Query the database
    c.execute("SELECT * FROM users WHERE username = ? AND password = ?", (username, password))

    # Fetch all data
    items = c.fetchall()

    # Check if username and password are correct
    if len(items) > 0:
        print("Login successfully")
        result = True

    else:
        print("Username or password are incorrect")
        result = False

    # Commit our command
    conn.commit()

    # Close our connection
    conn.close()

    return result


