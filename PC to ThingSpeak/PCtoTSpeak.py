import requests

# ThingSpeak channel details
channel_id = 1742416
write_api_key = 'FEZK7OO590RYWDV6'

# Data to send to the channel
field1_data = '10'
field2_data = '20'

# ThingSpeak API endpoint
api_endpoint = f'https://api.thingspeak.com/update?api_key={write_api_key}'

# Prepare the payload with field values
payload = {
    'field1': field1_data,
    'field2': field2_data
}

# Send the POST request to ThingSpeak
response = requests.post(api_endpoint, json=payload)

# Check the response status
if response.status_code == 200:
    print('Data sent successfully to ThingSpeak!')
else:
    print('Failed to send data to ThingSpeak.')
    print('Response:', response.text)
