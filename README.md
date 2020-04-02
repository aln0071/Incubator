# Chicken Egg Incubator
I have made this chicken egg incubator using the Arduino Uno microcontroller and a paint bucket. Chicken egg has 21 day incubation period. Both temperature as well as humidity need to be maintained during this period for successful hatch.

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
- Holder, wire and plug for lamp
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
I used an incandescent lamp as the heating element in this incubator. Initially, I took out the SMBS from my old computer. Then, I opened it and removed the circuit board. Unplug the fan but do not unscrew it. Install the holder with incandescent lamp inside the SMBS such that the hot air around the lamp is sucked out by the fan.

**Step 2: Building the humidifier**
For building a humidifier, you need a piezoelectric atomizer. It is a piezoelectric vibrating drum that vibrates at a frequency of 1.7 MHz. When water comes in contact with this drum, it instantly turns into vapor.

If we place the drum directly in a container with water, then it may be damaged after prolonged exposure. Also, it may loose contact with water once the water level drops. To solve this issue, I used the [capillary action](https://en.wikipedia.org/wiki/Capillary_action) of water.

>Step 1: Take a small piece of cotton ( the type of cotton used for dressing wounds ) and make it into a roll.
>
>Step 2: Take a small plastic can and make a hole at the center of it's lid so that the cotton roll can be attached to it.
>
>Step 3: Attach the cotton roll to the plastic can's lid such that a small portion of the roll ( about 0.3 cm ) comes out of lid and the rest is inside the can.
>
>Step 4: Fill the can with water and close the lid so that the cotton roll is dipped in the water. The capillary effect will cause water to rise up through the cotton roll.
>
>Step 5: Position the piezoelectric vibrating drum on top of the exposed end of the cotton roll which is outside the container. Make sure that the drum touches the tip of the cotton roll gently. This will cause the water on the tip getting atomized due to the vibration of the drum.
>
>Step 6: Secure the drum in position using hot glue. Also fix the frequency generator circuit to the side of the container using hot glue.
>
>Step 7: Put another small hole on the lid of the container and insert a hose through it. This can be used to refill the container without opening the incubator.
>
>Step 8: Put some extra holes on the lid for ventilation. These are important for proper capillary action.

**Step 3: Building the egg holder base**
Now, we need to build a base on which the eggs are placed. For this, take the chicken wire mesh and cut it to the length and breadth of the bucket. Place it inside the bucket and secure it in position using cable ties. You can put holes on the bucket using a heated iron nail and insert cable ties through those holes to secure the mesh.

**Step 4: Building the egg turner**
Chicken egg need to be turned every 8 hours during the first 18 days of incubation. This is because the embryo will drift towards the bottom due to gravity and so, we need to recenter it for successful hatch. I built the egg turner using surface mount cable raceway. Our egg turner will have a frame inside which eggs are placed. When the 

>Step 1: Take the 1/2 inch cable raceway and cut two piece having (3/4)th of the length of your bucket. These pieces will form the left and right sides of your frame.
>
>Step 2: Now, we need pieces from left to right, joining the two pieces. The frame will have a table row structure.

![Humidifier](/Images/Humidifier-1.jpg)
