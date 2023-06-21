import requests

# ThingSpeak channel details
channel_id = ''
write_api_key = ''  # Find in channel sharing settings

# Data to send to the channel - using dummy data
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
    print('Successfully sent to ThingSpeak!')
else:
    print('Failed to send data to ThingSpeak.')
    print('Response:', response.text)
