This is bit of boilerplate code for physics with time travel.

To use it you need to make a class that inherits the WorldState class.
>The WorldState class has two functions, equivalence and update.
>If you do not define the equivalence function, then the simulation will call the update function on WorldStates that do not need to be updated.
>The update function is where you define how a WorldState should progress from time "t" to time "t+1".

Once you have implemented the WorldSpace class you need to instantiate an object of TimeTime
>The constructor for TimeTime requires the deltaTime that will be used by the simulation and the maximum amount of time that the simulation can run for starting from time 0.
>This will create the correct number of time steps in the timeline ledger so that you can have a simulation that runs for maxTime at deltaTime interval between time steps.
>
>The initialize function will set the WorldState of the simulation at all points in time to the WorldState provided. Or it will set the entire timeline based on the provided TimeState.
>
>The update function will progress the TimeState by one iteration. It it will only update the individual WorldStates in the TimeState if they need to be updated.

If you want to make a player
>Store the state of the player inside the WorldState.
>And keep track of their place on the timeline externally to the simulation code.
>
>Use TimeTime.at to set the player's state for user control purposes. Do this before calling update. This will ensure that the desired player actions actually happen in that update.
>
>As your player will probably be time travelling, you will need the WorldState to support the player being in multiple places at the same time.
>I recommend a list of lists. First dimension being the player number, second number being an instance of that player.
>
>For example, the player moves a cube across the room and then goes back in time. As the player just moved the cube, they should see themself moving the cube. So the WorldState needs to keep track of all previous instances of the player along with having the current instance be controlled. That is why I believe a list of lists is usefull.
>
>Alternatively, you could decide that the player can only be at one place at any given time. In which case, you just need a list of players, and don't need a list of the things they did. But do note that the simulation will not have objects that were previously used move along the old paths if you do this. The cube only moved because the player moved it, so if that instance of the player is not there to move it, then the physics of the WorldState iteration will not move the cube.
