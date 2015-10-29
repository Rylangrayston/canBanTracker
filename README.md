# canBanTracker
System for logging events that happen in a can ban system.. shit I spelt Kanban wrong.. oh well


first off how you can break it/ things to know:
- modify the buttonMapping.cvs so that Time is not the last field will break everything  
- changing the order of the buttonMapping.cvs, if we need to add a field add it just in front of the time feild
- if you don't here a beep it's not working, if you do here a beep it just logged your work. 
- remember to use the correct batch size 
- remember to change buttonMappings.cvs befor doing a job new Job
- remember to hit save when filling changing buttonMappings.csv ( you can save while python scrip is 
running... at least on a GNU system. )



how it works:

You push a button and the arduino sends a message over the serial port. It sends 
"A" for button A "B" for button B etc

The python script receives the message and pings it back to the arduino after logging
the buttons coroalting data.  If the arduino receives
the message back then it makes a noise on that buttons
speaker, signaling to the user that things are getting logged.

For each button press the python script reads the values from the
buttonMapping.csv file and then logs the data associated with that button in the logFile.csv 

Graphing the data in logFile.csv can help you see what processes are faster 
which people are best at which jobs, what your longest processes are, etc. 


How the user uses it:
1,  pick a job to do

2,  open the buttonMappings.csv with libreoffice
edit the fields to reflect what you are doing with the button you will be
pressing.

3, Go to the Job and make a part, or batch of parts, push the button, if you hear
a beep that means your part has been logged.. keep making parts untill you have made the bin fill #.. If you don't hear a beep call Rylan to let him know that you will be continuing on
without logging... keep working even if you don't get ahold of Rylan.


now for some descriptions of the Fields that your button logs:
button:
which button you will be using to do the job

name:
name of employee doing the work

Job number:
each job should have a number, you can look that up on the wall. if you cant figure out what the job number is dont do the job

item description:
describe the item you are putting in the bin IE “bagged String”

Process / Machine Description
What machine are you using for the job IE are you using the hose spooler or
are you just wrapping hose on your hand... explain what your doing here.

Batch Size:
When you push the button you are logging this many items ...
so if the batch size is 10, pushing the button once logs that you have
just put 10 items in the bin.

Items Per Printer:
obvi

bin fill number:
how many are to be produced to fill a bin.

notes:
write anything you want to add here

Time:
Never write anything in the time field, also this must alwase be the last field
The software will enter in the date and time that you push the button. 
