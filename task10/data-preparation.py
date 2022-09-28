import paho.mqtt.client as mqtt
import pandas as pd

client=mqtt.Client()
client.connect('broker.hivemq.com',1883)

client.subscribe('nitw/fdp')
dataStream=[]
count=0

def notification(client,userdata,msg):
  global count
  data=msg.payload.decode('utf-8')
  data=data.split(':')
  h=data[1][1:]
  h=h.split(' ')[0][:-1]
  t=data[-1][1:-1]
  t=t.split(' ')[-1]
  h=float(h)
  t=float(t)
  print(h,t)
  count+=1
  dummy=[]
  dummy.append(h)
  dummy.append(t)
  dataStream.append(dummy)
  print(dataStream)

  if(count==10):
    df=pd.DataFrame(dataStream)
    df.to_csv('iot.csv')
    count=0



client.on_message=notification
client.loop_forever()
