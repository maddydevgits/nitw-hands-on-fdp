from AWSIoTPythonSDK.MQTTLib import AWSIoTMQTTClient
import time
import random

client=AWSIoTMQTTClient('trichy-client')
client.configureEndpoint('a2ijhhvhvwhuqv-ats.iot.us-east-1.amazonaws.com',8883)
client.configureCredentials("AmazonRootCA1.pem","device-private.pem.key","device-certificate.pem.crt")

client.configureOfflinePublishQueueing(-1) # Infinite Publishing
client.configureDrainingFrequency(2) # frequency of data transfer
client.configureConnectDisconnectTimeout(10)
client.configureMQTTOperationTimeout(5)

client.connect()
print("Connected with AWS")

time.sleep(2)

while True:
    h,t = (random.randint(20,100),random.randint(20,50))
    payload='{"humidity":'+str(h) +',"temperature":' +str(t) +'}'
    client.publish('iot/nit',payload,0)
    time.sleep(2)
    print(payload)
    print('Data Uploaded to AWS')
