import paho.mqtt.client as mqtt

# MQTT broker details
broker_address = "192.168.1.100"
broker_port = 1883

# Callback function when a connection is established
def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to MQTT broker")
        client.publish("testTopic", "From my PC to MQTTX")
        client.subscribe("testTopic")
    else:
        print(f"Failed to connect to MQTT broker. Return code: {rc}")

def on_message(client, userdata, msg):
    print(f"Received message: {msg.payload.decode()}")
# Create an MQTT client instance
client = mqtt.Client()

# Set the callback function
client.on_connect = on_connect
client.on_message = on_message
# Connect to the MQTT broker
client.connect(broker_address, broker_port)

# Start the MQTT loop
client.loop_start()

# Keep the script running
while True:
    
    pass
