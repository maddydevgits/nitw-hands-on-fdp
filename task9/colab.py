import paho.mqtt.client as mqtt
client=mqtt.Client()
client.connect('broker.hivemq.com',1883)

client.subscribe('nitw/fdp')

def notification(client,userdata,msg):
  print(msg.payload)

client.on_message=notification
client.loop_forever()
