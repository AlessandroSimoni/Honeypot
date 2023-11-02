from pymodbus.client import ModbusTcpClient
import time
import  requests

# Specifica l'indirizzo IP e la porta del tuo PLC
IP_RASP = '169.254.130.151'
PORT_PLC = 8080
PORT_MODBUS = 502
# Definisci le credenziali di accesso
USERNAME = "openplc"
PASSWORD = "openplc"

status = True

# Creo la sessione
session = requests.Session()

# Connetti il client al server
c = ModbusTcpClient(IP_RASP, PORT_MODBUS)

def loginPLC():
    global session
    # Costruisci l'URL utilizzando le variabili
    url = "http://{}:{}/login".format(IP_RASP, PORT_PLC)

    # Effettua la richiesta POST con le credenziali di accesso in sessione
    r = session.post(url, data={'username': USERNAME, 'password': PASSWORD})

    # Controllo se la richiesta è andata a buon fine
    if r.status_code == 200:
        print("Login avvenuto con successo")
    else:
        print("Errore durante il login")

def startPLC():
    global session
    # Costruisci l'URL utilizzando le variabili
    url = "http://{}:{}/start_plc".format(IP_RASP, PORT_PLC)

    # Effettua la richiesta GET
    r = session.get(url)

    # Controllo se la richiesta è andata a buon fine
    if r.status_code == 200:
        print("PLC avviato con successo")
    else:
        print("Errore durante l'avvio del PLC")

def logoutPLC():
    global session
    # Costruisci l'URL utilizzando le variabili
    url = "http://{}:{}/logout".format(IP_RASP, PORT_PLC)

    # Effettua la richiesta GET
    r = session.get(url)

    # Controllo se la richiesta è andata a buon fine
    if r.status_code == 200:
        print("PLC disconnesso con successo")
    else:
        print("Errore durante la disconnessione del PLC")

def stopPLC():
    global session
    # Costruisci l'URL utilizzando le variabili
    url = "http://{}:{}/stop_plc".format(IP_RASP, PORT_PLC)

    # Effettua la richiesta GET
    r = session.get(url)

    # Controllo se la richiesta è andata a buon fine
    if r.status_code == 200:
        print("PLC fermato con successo")
    else:
        print("Errore durante l'arresto del PLC")

def startFactory():
    global status, c
    status = True
    try:
        if c.connect():
            print("Connessione avvenuta con successo")

            # Imposta InputSegnale a True (%QX0.0) per avviare la fabbrica virtuale
            c.write_coil(0, True)

            print("Fabbrica avviata")

            numBottiglie = 0
    except Exception as e:
        print(e)

def stopFactory():
    global status, c
    status = False
    try:
    # Connetti il client al server
        if c.connect():
            print("Connessione avvenuta con successo")
            
            # Imposta InputSegnale a True (%QX0.0) per avviare la fabbrica virtuale
            c.write_coil(0, False)
    except Exception as e:
        print(e)

def resetFactory():
    global status, c
    status = False
    try:
    # Connetti il client al server
        if c.connect():
            print("Connessione avvenuta con successo")
            
            # Imposta InputSegnale a True (%QX0.0) per avviare la fabbrica virtuale
            c.write_coil(0, False)
            c.write_register(0, 0)
            c.write_register(1, 0)
            c.write_register(2, 0)
            c.write_register(3, 0)
    except Exception as e:
        print(e)

def getInfo():
    info = []
    
    for i in range(0, 5):
        # Array data keeps the data read from the PLC
        info.append(c.read_coils(i, 1).bits[0])

    for i in range(0, 4):
        # Array data keeps the data read from the PLC
        info.append(c.read_holding_registers(i, 1).registers[0])


    return info
