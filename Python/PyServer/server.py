import socket
import os
from flask import Flask, render_template, request
from flask_wtf import FlaskForm
from wtforms import StringField, FileField, SubmitField
from datetime import datetime
import struct
import threading

server_socket = None
tftp_server_thread = None
tftp_threads = []

app = Flask(__name__)
app.config['UPLOAD_FOLDER'] = 'uploads'
app.config['ALLOWED_EXTENSIONS'] = {'txt', 'pdf', 'png', 'jpg', 'jpeg', 'gif'}
app.config['SECRET_KEY'] = '123'
app.config['DEBUG'] = True

class UploadFileForm(FlaskForm):
    file = FileField("File")
    submit = SubmitField("Upload File")

@app.route('/', methods=['GET', 'POST'])
@app.route('/form', methods=['POST'])
@app.route('/home', methods=['GET', 'POST'])
def home():
    form = UploadFileForm()
    if request.method == 'POST':

        print("Request: POST")
        if form.validate_on_submit():
            print("Formulario de archivos válido")
            # Manejar el formulario de archivos
            message = request.form.get('message', '')
            
            if message:
                hora_actual = datetime.now()
                formato = "%Y-%m-%d %H:%M:%S"
                hora_formateada = hora_actual.strftime(formato)

                try:
                    with open('C:/Martin/PyServer/templates/static/Files/mensajes.txt', 'a') as file:
                        file.write(f'Mensaje recibido [{hora_formateada}], mensaje: \"{message}\" \n')
                except Exception as e:
                    print(f"Error al escribir en el archivo: {e}")
            else:
                print("Mensaje vacío")
                error_message = "El mensaje estaba vacío."
                write_error_to_file(error_message, message)
        else:
            print("Error de formulario")    
            print("Formulario de archivos válido")
            # Manejar el formulario de archivos
            message = request.form.get('message', '')
            
            if message:
                hora_actual = datetime.now()
                formato = "%Y-%m-%d %H:%M:%S"
                hora_formateada = hora_actual.strftime(formato)

                try:
                    with open('C:/Martin/PyServer/templates/static/Files/mensajes.txt', 'a') as file:
                        file.write(f'Mensaje recibido [{hora_formateada}], mensaje: \"{message}\" \n')
                except Exception as e:
                    print(f"Error al escribir en el archivo: {e}")
    return render_template('web.html', form=form)


def write_error_to_file(error_message, message_o):
    hora_actual = datetime.now()
    formato = "%Y-%m-%d %H:%M:%S"
    hora_formateada = hora_actual.strftime(formato)

    try:
        with open('C:/Martin/PyServer/templates/static/Files/mensajes.txt', 'a') as file:
            file.write(f'Mensaje de error [{hora_formateada}]: {error_message}, posible mensaje: {message_o}\n')
    except Exception as e:
        print(f"Error al escribir en el archivo: {e}")

def send_data_block(block_number, data, client_address):
    data_packet = struct.pack('!HH', 3, block_number) + data
    server_socket.sendto(data_packet, client_address)

def handle_read_request(filename, mode, client_address):
    print(f"Handling RRQ for file '{filename}' from {client_address}")

    block_number = 1
    data_block = b'Hello, this is a sample file content.'
    send_data_block(block_number, data_block, client_address)

def handle_acknowledgment(block_number, client_address):
    print(f"Received ACK for block {block_number} from {client_address}")

def handle_write_request(filename, mode, client_address):
    print(f"Handling WRQ for file '{filename}' from {client_address}")

    ack_packet = struct.pack('!HH', 4, 0)
    server_socket.sendto(ack_packet, client_address)

def handle_client(data, client_address):
    opcode = struct.unpack('!H', data[:2])[0]

    if opcode == 1:  # RRQ
        filename = data[2:data.find(b'\x00', 2)].decode('utf-8')
        mode = data[data.find(b'\x00', 2) + 1:data.find(b'\x00', data.find(b'\x00', 2) + 1)].decode('utf-8')
        handle_read_request(filename, mode, client_address)

    elif opcode == 4:  # ACK
        block_number = struct.unpack('!H', data[2:4])[0]
        handle_acknowledgment(block_number, client_address)

    elif opcode == 2:  # WRQ
        filename = data[2:data.find(b'\x00', 2)].decode('utf-8')
        mode = data[data.find(b'\x00', 2) + 1:data.find(b'\x00', data.find(b'\x00', 2) + 1)].decode('utf-8')
        handle_write_request(filename, mode, client_address)

def tftp_server():
    global server_socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind(("127.0.0.1", 6970))
    print("Servidor TFTP iniciando....")
    
    while True:
        print("Entro al bucle")
        try:
            data, client_address = server_socket.recvfrom(516)
            print(f"Received packet from {client_address}")

            client_thread = threading.Thread(target=handle_client, args=(data, client_address))
            client_thread.start()
            tftp_threads.append(client_thread)
        except Exception as e:
            print(f"Error en el bucle principal: {e}")
            import traceback
            traceback.print_exc()

#tftp_server()

def main():
    global tftp_server_thread
    tftp_server()
    try:
        print("iniciando servidores....")
        # Inicia el servidor TFTP en un hilo separado
        tftp_server_thread = threading.Thread(target=tftp_server)
        tftp_server_thread.start()
        # Inicia el servidor Flask en el hilo principal
        app.run(debug=True, host='127.0.0.1', port=4900)

    except KeyboardInterrupt:
        # Maneja la interrupción del teclado (Ctrl+C) para detener los servidores
        print("Deteniendo el servidor TFTP y Flask...")
        server_socket.close()
        tftp_server_thread.join()

        for client_thread in tftp_threads:
            client_thread.join()

if __name__ == '__main__':
    app.run(debug=False, host='127.0.0.1', port=4900)
    tftp_server_thread = threading.Thread(target=tftp_server)
    tftp_server_thread.start()
