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
