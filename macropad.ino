//Created by Jonathan Clifford
//adapted & modified from https://github.com/Johnmadlabs/10Key-MechKeeb
//This installation tutorial can be used if you've never used Arduinos/The Pro Micro before in order to get this set up: 
//https://www.youtube.com/watch?v=UeGEP8vxzZQ


//______________________________________________________________________________________________________________________________________________________________________________________________
// We will be using the HID Library instead of the normal keyboard and mouse library packaged with Arduino.
#include <HID.h> // this is used for media controls. Essentially, Windows recognizes the Pro Micro as a HID rather than a keyboard, and as a result, it can't make use of media inputs.
// in addition, the FN + Function row is located locally on the keyboard in order to process what to send to the USB port, so trying to hard code an "FN" key just won't work. 
#include <HID-Project.h> // same as above logic, this also needs to be used 

// Defining each pin, with a unique name
// Physical Key => Physical Pin 
#define KEY0 2
#define KEY1 3
#define KEY2 4
#define KEY3 5
#define KEY4 6
#define KEY5 7
#define KEY6 8
#define KEY7 9
#define KEY8 10
#define KEY9 16
int RXLED = 17; // for backlight, this will essentially go on once the macropad detects an input from a key.    

//______________________________________________________________________________________________________________________________________________________________________________________________
void setup() {


  pinMode (KEY0, INPUT_PULLUP);
  pinMode (KEY1, INPUT_PULLUP);
  pinMode (KEY2, INPUT_PULLUP);
  pinMode (KEY3, INPUT_PULLUP);
  pinMode (KEY4, INPUT_PULLUP);
  pinMode (KEY5, INPUT_PULLUP);
  pinMode (KEY6, INPUT_PULLUP);
  pinMode (KEY7, INPUT_PULLUP);
  pinMode (KEY8, INPUT_PULLUP);
  pinMode (KEY9, INPUT_PULLUP);
  pinMode(RXLED, OUTPUT);  // Set RX LED as an output, used for backlight  
  
  //init mouse and keyboard. 
  Keyboard.begin();
  Mouse.begin();
  //boolean layer2 = false; //used to set the second layer of the keyboard, testing for now. 

}


//______________________________________________________________________________________________________________________________________________________________________________________________
void loop() {
  // make light go on for extra backlight: 
  digitalWrite(RXLED, LOW);   // set the LED on
  TXLED0; //TX LED is not tied to a normally controlled p

//TODO - KEY 0 - Used for Opening Task Manager
  if (digitalRead(KEY0) == LOW)//If the circuit can be complete, run these commands
  {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_RIGHT_SHIFT);
    Keyboard.press(KEY_ESC);
    delay(85); //delay for 85 ms 
    
  }//Then, once it's released,
   if (digitalRead(KEY0) == HIGH)
    {
      Keyboard.releaseAll(); //send messages 
    }

//KEY 1 - intro 
  if (digitalRead(KEY1) == LOW)
  {
    Keyboard.press(KEY_RIGHT_SHIFT);
    Keyboard.press(KEY_HOME);
    delay(85);
  }
   if (digitalRead(KEY1) == HIGH)
    {
      Keyboard.releaseAll();
    }


//KEY 2 - end intro 
  if (digitalRead(KEY2) == LOW)
  {
    Keyboard.press(KEY_RIGHT_SHIFT);
    Keyboard.press(KEY_END);
    delay(85);
  }
   if (digitalRead(KEY2) == HIGH)
    {
      Keyboard.releaseAll();
    }

//KEY 3 - Used for muting computer - prefered to mute microphone but theres really no easy way to do that - will research an easier way to do this via HID 
  if (digitalRead(KEY3) == LOW)
  {
    Consumer.write(HID_CONSUMER_MUTE);
    delay(115); // for whatever reason this key double taps sometimes for me so increasing the delay here 
  }
   if (digitalRead(KEY3) == HIGH)
    {
      Keyboard.releaseAll();
    }

//KEY 4 - End recording 
  if (digitalRead(KEY4) == LOW)
  {
    Keyboard.press(KEY_RIGHT_SHIFT);
    Keyboard.press(KEY_PAGE_DOWN);
        delay(85);
  }
   if (digitalRead(KEY4) == HIGH)
    {
      Keyboard.releaseAll();
    }


//KEY 5 - ZOOM OUT 
  if (digitalRead(KEY5) == LOW)
  {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.print("-");
        delay(125);
  }
   if (digitalRead(KEY5) == HIGH)
    {
      Keyboard.releaseAll();
    }

//KEY 6 - Vol -
  if (digitalRead(KEY6) == LOW)
  {
    Consumer.write(MEDIA_VOLUME_DOWN);//using HID library for this 
        delay(90);
  }
   if (digitalRead(KEY6) == HIGH)
    {
      Keyboard.releaseAll();
    }
 //KEY 7 - Start recording 
  if (digitalRead(KEY7) == LOW)
  {
    Keyboard.press(KEY_RIGHT_SHIFT);
    Keyboard.press(KEY_PAGE_UP);
        delay(85);
  }

   if (digitalRead(KEY7) == HIGH)
    {
      Keyboard.releaseAll();
    }
//KEY 8 - Zoom in 
  if (digitalRead(KEY8) == LOW)
  {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.print("+");
        delay(125);
  }
   if (digitalRead(KEY8) == HIGH)
    {
      Keyboard.releaseAll();
    }
//KEY 9 - Vol + 
  if (digitalRead(KEY9) == LOW)
  {
    Consumer.write(MEDIA_VOLUME_UP); // HID library 
        delay(90);
  }
   if (digitalRead(KEY9) == HIGH)
    {
      Keyboard.releaseAll();
    }

// This is how you can access the second layer of the keyboard, in the event that you would like more than 1 set of macros. 
// However: Note that since we don't have individual diodes for this keypad, we do not have N-Key Rollover, meaning that 
// We will need to basically have a manual delay in order to then detect if the second key is actually registered or not. 
// Accessing the second layer of the keyboard\
// Note that this is primarily just test code as I don't need to use this - effectively you can use this to add a sort of 
// 0 + some other key to do something else rather than what we coded above. You can use the boolean layer2 at the top and bottom 
// of the loop in order to declare another function in order to get this working. 
// Practically I don't see myself needing this many keys so it's going to be commented out so that I can use my 0 key as Task Manager. 
//  if (digitalRead(KEY0) == LOW)
//    {
//      delay(1000); 
//      if (digitalRead(KEY1) == LOW)
//      {
//        boolean layer2 = true; // Set this to true 
//        Consumer.write(MEDIA_VOLUME_UP); 
//        delay(90); 
//        if (digitalRead(KEY1) == HIGH)
//        {
//          Keyboard.releaseAll();
//        }
//        
//      }
//    }

} //end 
