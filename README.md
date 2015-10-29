# canBanTracker
System for loging events that happen in a can ban system


first off how you can break it:
1 modifi the buttonMapping.cvs so that Time is not the last field will break this
2 changeing the order of the buttonMapping.cvs, if we need to add a field add it just infron of the time feild
3 if you dont here a beep its not working
4 forget to use the correct bin size
5 forget to change buttonMappings.cvs befor doing a job new Job
6 forget to hit save when filling changing buttonMappings.csv



how it works


you push a button on and the arduino sends a mesage over the serial port 
"A" for button A "B" for button B etc

the python scrip recives the mesage and pings it back to the arduino
If the arduino recives the mesage back then it makes a nois on that buttons 
speaker. signalin to the user that things are getting loged. 

for each button press the python scrip reads the values from the
buttonMapping.csv file
and then logs the data asosiated with that button in the log. 

How the user uses it. 

open the buttonMappings.csv with open ofice 
edit the fields to reflect what you are doing with the button you will be
pressing

Go to the Job and make a part, or batch of parts, push the button, if you hear 
a beep that means your part has been logged.. keep making parts 
if you dont here a beep call rylan to let him know that you will be continuing on
with out logging... keep working evan if you dont get ahold of rylan. 

button
which button you will be using to do the job
name 
Job number
each job should have a number, you can look that up on the wall. if you cant figure out what the job number is 
dont do the job
name of the person doing the job
item description
describe the item you are putting in the bin IE bagged String
Process / Machine Description
What machine are you using for the job IE are you using the hose spooler or
are you just wrapping hose on your hand... explain what your doing here

Batch Size 
When you push the button you are logging this many items ... 
so if the batch size is 10, pushing the button once logs that you have
just put 10 items in the bin. 

Items  Per Printer
obvi

bin fill number
how many are to be produced to fill a bin

notes
write anything you want to add here 

Time 
never write anything in the time field, also this must alwase be the last field




