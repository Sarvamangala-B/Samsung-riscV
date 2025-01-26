 
                                 TASK -5 
Traffic Signal System Using VSD Squadron Mini

Overview:

This project demonstrates a traffic signal control system implemented using the VSD Squadron Mini development board (based on the CH32V003 microcontroller). The system includes Red, Yellow, and Green LEDs to simulate traffic lights and uses a push button to simulate a pedestrian crossing request. Additional feature used is a push button which gives extra time for the pedestrians for crossing.                            
What Happens When the Button is Pressed
When the push button is pressed, the following actions take place:
1.	Button Detection:
  o	The microcontroller continuously monitors the state of the push button (connected to PD3).
  o	If the button is pressed (logic LOW, because of the pull-up resistor configuration), the system recognizes a pedestrian crossing request.
2.	Red Signal Remains Active:
  o	During the Red LED (Stop) phase, the system ensures vehicles remain stopped for an additional 3 seconds, providing enough time for pedestrians to cross the road.
3.	Buzzer Activation (Optional):
  o	The buzzer (connected to PC1) is activated for 3 seconds to alert pedestrians that it is safe to cross.
  o	The buzzer can also act as an additional warning for vehicles to remain stopped.
4.	Cycle Continues:
  o	After the pedestrian crossing phase ends, the traffic light cycle resumes as usual (Red → Green → Yellow → Red).


Components required:

1. VSD Squadron Mini Board
2. Red, Yellow, Green LEDs (x3)
3. 330Ω Resistors (x3)
4.  Push Button (x1)
5. Buzzer (for pedestrian alert)
6. Breadboard and Jumper Wires
7. 5V Power Supply or USB cable

Pin connection:

![image](https://github.com/user-attachments/assets/9c8da961-e7fc-4f18-ad91-8fc5c0808aa3)


Circuit Diagram:

![Circuit diagram traffic signal](https://github.com/user-attachments/assets/370df6f2-865b-4bbc-89d9-5db2db6aee99)
                                                                                              
•	Connect the Red, Yellow, and Green LEDs to PD0, PD1, and PD2, respectively, with 330Ω resistors in series.
•	Connect the push button to PD3, with one side connected to the pin and the other side to GND. Use an internal pull-up resistor in the microcontroller.
•	Connect the buzzer to PC1 with a series resistor for pedestrian alerts.
•	Ensure all components share a common ground with the microcontroller.

Working:

1.	Initial State:
   o	The Green LED turns ON for 5 seconds, indicating vehicles can pass.
2.	Transition:
  o	The Yellow LED turns ON for 2 seconds, signaling vehicles to prepare to stop.
3.	Stop State:
  o	The Red LED turns ON for 5 seconds, stopping vehicles.
4.	Pedestrian Button:
  o	If the button is pressed during the Red signal, the buzzer activates for 3 seconds to alert pedestrians to cross safely.
5.	Cycle Repeats:
  o	The signals loop continuously in the given sequence.

Conclusion:

The Traffic Signal System Project using the VSD Squadron Mini provides a practical example of real-time traffic control systems. By incorporating pedestrian safety features, it demonstrates the importance of modular and efficient design in microcontroller-based applications.











SARVAMANGALA B
RV INSTITUTE OF TECHNOLOGY AND MANAGEMENT

