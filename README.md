Created by Jonathan Clifford, initial design by https://github.com/Johnmadlabs/10Key-MechKeeb

I made some fairly significant changes to the actual design & code, aside from just using the same 3D Model.

Design philosophy: 
This project is great for any hobbyist who wants to learn how to wire up a circuit without a PCB, someone who wants to learn soldering and wire wrapping, or an Electrical/Computer engineer who wants more experience using microcontrollers and wiring circuits while also having it do something useful that they can use in their daily lives. 

At the end of this project, you should have an entire macropad that you can use to program hotkeys that can be used at any time while you are using your computer. 

___________________________________________________________________________________________________________________________________________________________________________________
Design & Fabrication: 
The first step to this project is getting a case that will fit the switches properly. This case worked well for me, and is 3D Printable. I specifically printed it with PLA and the switches work extremely well: https://www.thingiverse.com/thing:2076220

You'll now need to choose your specific switch type. I personally went with Kailh Box Pink switches due to the tactile response and the IP56 waterproof and dust resistant qualities that this switch provides. I'd reccommend either a tactile or clicky switch with this macropad, as you will be hitting the keys at a non-standard angle and will need some sort of a response so that you know that the switch has actuated. You can pick up the Box Pink switches from Novelkeys (West Virginia) or KBDFans (China). 

You'll also need some keycaps for these switches, you can either 3D Print them or get them from somewhere like Amazon, they are quite cheap. 

Finally, you'll also need an Arduino Pro Micro, either the 5V version or the 3.3V one, I personally went with the 5V version a 10K resistor (Note that this might vary depending on the contact resistance for the switches you are using) and wire. 

Once you have everything layed out and the switches are fitted into the case, you can begin wiring. Here, you can see a wiring diagram that you can follow. In order to actually get the wire on the contacts of the switch, I'd reccommend wire wrapping and then soldering the wire in place once connections have been made. 

https://imgur.com/a/YFiu76P

Once you have finished wiring, before gluing the case together, make sure to load the code and test that every key is working, and then you can glue the case shut. Everything should work, and you can program each of the keys to your liking. 

In total, this took me about 4-6 hours to complete, as I had never wire wrapped before, but once I figured it out, it ended up speeding up quite a bit.

Total cost: ~$20 USD, sans 3D Printing costs. 

Note as well that with a little modification, you can essentially add layers to the keyboard, so instead of just the standard 10 keys that this design has, the code has a basis for having a few layers (So 0 + another key could have an entirely new hotkey, and so on). 
