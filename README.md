


# Chicken Egg Incubator
I have made this chicken egg incubator using the Arduino Uno microcontroller and a paint bucket. A chicken egg has a 21 day incubation period. Both temperature, as well as humidity, need to be maintained during this period for a successful hatch.
>[Click to play video](https://www.youtube.com/watch?v=g4gpmBDat7g&t=1s)<br/>
>[![Incubator Video](https://i.ytimg.com/vi/g4gpmBDat7g/hqdefault.jpg?sqp=-oaymwEZCPYBEIoBSFXyq4qpAwsIARUAAIhCGAFwAQ==&rs=AOn4CLCzsZ1GBde_9asK2zsRaL4HBt6P7Q)](https://www.youtube.com/watch?v=g4gpmBDat7g&t=1s)

## Things required
- Paint bucket x 1
- Cable ties ( as required ) - not more than 25
- Chicken wire mesh ( having width and height of the paint bucket ) x 1
- Surface mount cable raceway - 1 inch x 1, 1/2 inch x 1
- Arduino Uno x 1
- [HTU21D Humidity sensor](https://robu.in/product/htu21d-temperature-and-humidity-sensor-module/) x 1
- [Piezoelectric atomizer module with frequency generator circuit](https://robu.in/product/dc-5v-ultrasonic-humidifiers-power-circuit-board-with-atomizing-chip/) x 1
- 4 channel relay module x 1
- PC cooling fan x 1 ( I took it from my old computer's SMBS )
- 100 watt incandescent lamp x 1
- Holder, wire, and plug for lamp
- Jumper cables
- Bread board x 1
- LCD display x 1
- Small plastic can with lid x 1 ( I used an old m&m chocolate can )
- Cotton roll ( used for dressing wound ) x 1
- Iron nail x 1
- Candle x 1
- Glue for plastic
- 1 meter hose ( I used an old water level checking hose )

## Steps for making
**Step 1: Building the heater**
I used an incandescent lamp as the heating element in this incubator. Initially, I took out the SMBS from my old computer. Then, I opened it and removed the circuit board. Unplug the fan but do not unscrew it. Install the holder with an incandescent lamp inside the SMBS such that the hot air around the lamp is sucked out by the fan.

**Step 2: Building the humidifier**
For building a humidifier, you need a piezoelectric atomizer. It is a piezoelectric vibrating drum that vibrates at a frequency of 1.7 MHz. When water comes in contact with this drum, it instantly turns into vapor.

If we place the drum directly in a container with water, then it may be damaged after prolonged exposure. Also, it may lose contact with water once the water level drops. To solve this issue, I used the [capillary action](https://en.wikipedia.org/wiki/Capillary_action) of water.

>Step 1: Take a small piece of cotton ( the type of cotton used for dressing wounds ) and make it into a roll.
>
>Step 2: Take a small plastic can and make a hole at the center of its lid so that the cotton roll can be attached to it.
>
>Step 3: Attach the cotton roll to the plastic can's lid such that a small portion of the roll ( about 0.3 cm ) comes out of the lid and the rest is inside the can.
>![Humidifier](/Images/Humidifier-2.jpg)
>
>Step 4: Fill the can with water and close the lid so that the cotton roll is dipped in the water. The capillary effect will cause water to rise through the cotton roll.
>
>Step 5: Position the piezoelectric vibrating drum on top of the exposed end of the cotton roll which is outside the container. Make sure that the drum touches the tip of the cotton roll gently. This will cause the water on the tip to get atomized due to the vibration of the drum.
>![Humidifier](/Images/Humidifier-3.jpg)
>
>Step 6: Secure the drum in position using hot glue. Also fix the frequency generator circuit to the side of the container using hot glue.
>
>Step 7: Put another small hole near the bottom of the container and insert a level checking hose through it. Make the joint watertight by applying hot glue. This can be used to check the water level inside the container and refill it without opening the incubator.
>
>Step 8: Put some extra holes on the lid for ventilation. These are important for proper capillary action.
>![Humidifier](/Images/Humidifier-1.jpg)

**Step 3: Building the egg holder base**
Now, we need to build a base on which the eggs are placed. For this, take the chicken wire mesh and cut it to the length and breadth of the bucket. Place it inside the bucket and secure it in position using cable ties. You can put holes on the bucket using a heated iron nail and insert cable ties through those holes to secure the mesh.

**Step 4: Building the egg turner**
A chicken egg needs to be turned every 8 hours during the first 18 days of incubation. This is because the embryo will drift towards the bottom due to gravity and so, we need to recenter it for a successful hatch. I built the egg turner using a surface mount cable raceway. Our egg turner will have a frame inside which eggs are placed. The frame will move on top of a static base, which in turn causes the eggs to roll. I tried to implement the movement using servo motor but I have not fully implemented it. I am working on a better turner design using a [rack and pinion mechanism](https://en.wikipedia.org/wiki/Rack_and_pinion). But I have already made the egg holder frame and a frictionless track through which the frame can move.

>Step 1: Take the 1/2 inch cable raceway and cut two pieces having (3/4)th of the length of your bucket. These pieces will form the left and right sides of your frame.
>
>Step 2: Now, we need pieces from left to right, joining the two pieces. The frame will have a table row structure. The number of eggs that can be placed in each row depends on the width of the frame. In my case, it was 3 per row.
>
>Step 3: Connect the frame to a servo motor, which will be controlled by the Arduino board. This servo motor will move the frame which in turn will rotate the eggs placed in the frame.

**Step 5: Programming the Arduino board**
Upload the program to the Arduino board. The board will continuously monitor temperature and humidity readings from the HTU21D humidity sensor. There are two modes of operation for this incubator - from 1 to 17 days and from 18 to 21 days. Different sets of temperature and humidity have to be maintained for these two periods.
|Modes|Temperature ( °C )|Humidity ( % )|Egg turning|
|---|---|---|---|
|**Days 1 to 17**|37.5 to 40|50 to 55|At least every 8 hours|
|**Days 18 to 21**|37.5 to 37.6|above 65|Should not be turned|

The Arduino will automatically regulate the temperature and humidity inside the bucket. The LCD screen will display the current temperature, humidity, and mode of operation of the board.

**Step 6: Building the power supply**
The power supply is very important for this incubator circuit. Failure of the power supply can alter the incubation atmosphere and kill the chicks. Powering all circuits using Arduino can also damage the circuit.
|Component|Voltage|Power supply|
|---|---|---|
|Arduino board|5V|Mobile charger|
|LCD Screen|5V|Directly powered from the Arduino|
|HTU21D Sensor|3.3V|Directly powered from the Arduino|
|Relay module|5V|Mobile charger|
|Humidifier|5V|Mobile charger|
|Heater Fan|12V|12V Adapter|
|Heater Bulb|230 V|Directly from mains|

As there are many different components, powering them all from the Arduino board can damage the board. It is recommended to power the relay module and the humidifier separately. I used 2 mobile chargers for this purpose. One for the Arduino board and the other for the relay and humidifier. I created a power distribution device to draw out the power form the mobile charger as follows:
>A USB port has 4 pins, two of which are data pins and the other two are power pins. We need these power pins 1 & 4. Pin 1 is + 5V and Pin 4 is ground. I desoldered a USB connector from an old faulty card reader and soldered it to a common board. Then I soldered two sets of single row female pin header connectors to the common board. The power supply pins from the USB connector were soldered to the header pins. Thus the header pins were able to deliver power when the USB connector was plugged into a mobile charger. You can also buy a 5V adapter for this purpose. I created this circuit as all electronics stores in my area were closed down due to the COVID-19 lockdown.

Finally, amperage is a very important fact to consider while designing a power supply. It should be always greater than the total summed up amperage of all components used in the circuit. I used a 1 ampere power mobile charger for the Arduino and a 2 ampere charger for the relay and humidifier circuit. If you are using multiple power supplies for modules directly connected to the Arduino, then make sure that you connect their ground pins to the Arduino's ground.

**Step 7: Final assembly**
The last step is to assemble the components. Set up housing for the Arduino board. I used an old plastic fruit container as the housing. I screwed it to the side of the bucket and placed the Arduino and the LCD screen inside it. Then I fixed the relay module to the side of the bucket using screws. I made a small hole on top of the bucket and took out the sensor wires through that hole and connected them to the Arduino. I made a small hole on the side of the bucket and took out the water supply hose of the humidifier through that hole. The hose needs to be transparent ( I used a level checking hose ) so that we can easily check the water level inside the humidifier without opening the incubator. Secure the hose to the side of the bucket using cable ties. Insert the Heater near to the lid of the bucket. Make sure the light is facing towards the lid. Finally, put some holes for ventilation on the lid using a heated iron nail.

**Step 8: Connections**
##### Interfacing Arduino with LCD Screen
|Arduino|LCD Screen|
|---|---|
|GND|Vss|
|5V|Vdd|
|D6|Vo|
|D12|Rs|
|GND|Rw|
|D11|E|
|D5|D4|
|D4|D5|
|D3|D6|
|D2|D7|
|5v|A|
|GND|K|

##### Interfacing Arduino with HTU21D
|Arduino|HTU21D|
|---|---|
|3.3V|VCC|
|GND|GND|
|A4|SDA|
|A5|SCL|

##### Interfacing Arduino with Relay module
|Arduino|Relay Module|
|---|---|
|D7|Relay 1 Control|
|D8|Relay 2 Control|
|D9|Relay 3 Control|
|D10|Relay 4 Control|

##### Interfacing Relay with components
|Relay Module|Component|Purpose|
|---|---|---|
|Relay 1|12V Fan power supply|Distribute heat|
|Relay 2|230V Incandescent bulb|Heat source|
|Relay 3|Humidifier power supply|Humidification|
|Relay 4|Humidifier toggle switch|Turn humidifier on/off|

##### Mode selection
|Arduino|Mode|
|---|---|
|D13 to GND|Mode 1 - Days 1 to 17|
|D13 to 5V|Mode 2 - Days 18 to 21|

## Things to remember
1) Temperature and humidity need to be maintained throughout this project. So, frequently check the readings shown on the LCD screen.
2) Egg turning is very important. If it is not done automatically, then you should turn them manually at least every 8 hours from days 1 to 17.
3) Use fertile eggs that are not older than 7 days. The eggs should not be exposed to harsh environments.
4) For tracking the egg turning, you can mark 'O' and 'X' on opposite sides of the egg. Make sure to use a pencil as marker ink can be poisonous and can harm the embryo inside the egg.
5) Do not disturb the eggs during the last 3 days of incubation. During these days, the chick will be positioning itself to prepare for hatching.

## After hatching
The chicks need to be transferred to a chick brooder after hatching. Chick brooder is just to provide heat to the chicks. I made a chick brooder myself using a small cardboard box. Setup an incandescent bulb inside the cardboard box, which is separated from the chick by a grid. The grid is important so that the chick does not go too close to the bulb and hurt itself. The chicks will automatically crawl near and away from the bulb when they need heat. This setup needs to be provided for the first 6 weeks.
