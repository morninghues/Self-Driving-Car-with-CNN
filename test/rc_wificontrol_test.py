import os
import paho.mqtt.client as mqtt
from time import sleep
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

SleepTimeL = 0.2

pinList = [2,3,4,17,27,22,10,9] #[2,3,4,17,27,22,10,9]

leftFront1 = 2      #L298n Motor Driver pins
leftFront2 = 3
rightFront1 = 4
rightFront2 = 17
leftBack1 = 27
leftBack2 = 22
rightBack1 = 10
rightBack2 = 9

for i in pinList:
    GPIO.setup(i, GPIO.OUT)
    GPIO.output(i, GPIO.LOW)

def main():
  def on_connect(client, userdata, flags, rc):
    client.subscribe("pod/#")
    client.publish("pod/rpi_status", "Raspberry is Online")
    print("Passed Callback")
  
  def on_message(client, userdata, msg):
    msg_received=str(msg.payload.decode("utf-8","ignore"))
    if msg.topic == "pod/car_control" :
        print(msg_received)
        if str(msg_received) == "F" :
            forward() 
            time.sleep(SleepTimeL);
            client.publish("pod/car_status", "Forward")       
            
        if str(msg_received) == "B" :
            reverse() 
            time.sleep(SleepTimeL);
            client.publish("pod/car_status", "Backward")

        if str(msg_received) == "L" :
            left() 
            time.sleep(SleepTimeL);
            client.publish("pod/car_status", "Left")
        
        if str(msg_received) == "R" :
            right() 
            time.sleep(SleepTimeL);
            client.publish("pod/car_status", "right")
        
        if str(msg_received) == "S" :
            resett() 
            time.sleep(SleepTimeL);
            client.publish("pod/car_status", "STOP")
            
    
    def on_disconnect(client, userdata, rc):
        if rc != 0:
         print("Unexpected disconnection.")

  def forward():
    print ("Forward")
    GPIO.output(leftFront1, GPIO.HIGH)
    GPIO.output(leftFront2, GPIO.LOW)
    GPIO.output(rightFront1, GPIO.HIGH)
    GPIO.output(rightFront2, GPIO.LOW)

    GPIO.output(leftBack1, GPIO.HIGH)
    GPIO.output(leftBack2, GPIO.LOW)
    GPIO.output(rightBack1, GPIO.HIGH)
    GPIO.output(rightBack2, GPIO.LOW)
    #time.sleep(0.2)
    #client.publish("pod/car_control", "S")    

  def reverse():
    print ("Reverse")
    GPIO.output(leftFront1, GPIO.LOW)
    GPIO.output(leftFront2, GPIO.HIGH)
    GPIO.output(rightFront1, GPIO.LOW)
    GPIO.output(rightFront2, GPIO.HIGH)

    GPIO.output(leftBack1, GPIO.LOW)
    GPIO.output(leftBack2, GPIO.HIGH)
    GPIO.output(rightBack1, GPIO.LOW)
    GPIO.output(rightBack2, GPIO.HIGH)
    #time.sleep(0.2)
    #client.publish("pod/car_control", "S")    

  def left():
    print ("Left")
    GPIO.output(leftFront1, GPIO.HIGH)
    GPIO.output(leftFront2, GPIO.LOW)
    GPIO.output(rightFront1, GPIO.HIGH)
    GPIO.output(rightFront2, GPIO.HIGH)

    GPIO.output(leftBack1, GPIO.HIGH)
    GPIO.output(leftBack2, GPIO.HIGH)
    GPIO.output(rightBack1, GPIO.HIGH)
    GPIO.output(rightBack2, GPIO.LOW)
    #time.sleep(0.2)
    #client.publish("pod/car_control", "S")    


  def right():
    print ("Right")
    GPIO.output(leftFront1, GPIO.HIGH)
    GPIO.output(leftFront2, GPIO.HIGH)
    GPIO.output(rightFront1, GPIO.HIGH)
    GPIO.output(rightFront2, GPIO.LOW)

    GPIO.output(leftBack1, GPIO.HIGH)
    GPIO.output(leftBack2, GPIO.LOW)
    GPIO.output(rightBack1, GPIO.HIGH)
    GPIO.output(rightBack2, GPIO.HIGH)
    #time.sleep(0.2)
    #client.publish("pod/car_control", "S")    


  def resett():
    print ("Reset")
    GPIO.output(leftFront1, GPIO.HIGH)
    GPIO.output(leftFront2, GPIO.HIGH)
    GPIO.output(rightFront1, GPIO.HIGH)
    GPIO.output(rightFront2, GPIO.HIGH)

    GPIO.output(leftBack1, GPIO.HIGH)
    GPIO.output(leftBack2, GPIO.HIGH)
    GPIO.output(rightBack1, GPIO.HIGH)
    GPIO.output(rightBack2, GPIO.HIGH)
    

  

  client = mqtt.Client()
  client.username_pw_set(username="homehub", password="Future_home")
  client.on_connect = on_connect
  client.on_message = on_message

  client.connect("192.168.0.100", 1883, 60)
  print("Passed Connection Setup")

  client.loop_forever()

if __name__ == '__main__':
    try:
          main()
    except KeyboardInterrupt:
        GPIO.cleanup()

