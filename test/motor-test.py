import sys
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

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
    GPIO.output(leftFront1, GPIO.HIGH)
    GPIO.output(leftFront2, GPIO.LOW)
    GPIO.output(rightFront1, GPIO.HIGH)
    GPIO.output(rightFront2, GPIO.LOW)

    GPIO.output(leftBack1, GPIO.HIGH)
    GPIO.output(leftBack2, GPIO.LOW)
    GPIO.output(rightBack1, GPIO.HIGH)
    GPIO.output(rightBack2, GPIO.LOW)
    print("First Round")
    #time.sleep(2)
    

if __name__ == '__main__':
    try:
          main()
    except KeyboardInterrupt:
        GPIO.cleanup()