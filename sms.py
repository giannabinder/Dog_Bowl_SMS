from twilio.rest import Client
import serial



# make object of serial type to read from the port
serial_info = serial.Serial('COM', 9600) # define correct COM port for testing



# Twillio account credentials
account_sid = 'AC464086b85d49c74231e786775f32a203'
auth_token = '[AuthToken]'
# create a Twillio client
client = Client(account_sid, auth_token)


# define the function to send messages
def send_message(message_content):

    # create a message using Twillio client
    message = client.messages.create(
            from_= 'whatsapp:+14155238886',
            body = message_content,
            to = 'whatsapp:+14165753025'
        )
    
    # output message sent confirmation (testing)
    print("Message sent: {}".format(message.sid))



# enter loop which monitors serial and calls SMS function
# set the loop conditions to "True" so it always runs
while True:

    # enter a new loop to analyze each serial line
    while serial_info.inWaiting():

        # read the serial line of the arduino
        command = serial_info.readline().decode().strip()
            # .readline() = reads line from arduino until /n
            # .decode() = convert data read from line into a string type
            # .strip() = removes whitespace before and after the line


        if command == "FILL WATER BOWL":
            send_message("Creed's water bowl is empty")
