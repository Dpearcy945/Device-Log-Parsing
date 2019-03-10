/**********************************************************************
 *  readme.txt template                                                   
 *  Kronos PS7a startup
 **********************************************************************/

Name:
Donovan Pearcy

Hours to complete assignment (optional):
26 Hrs

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Kinda, I dont calculate the difference between start and finish time, I kinda just
post the two times, otherwise its ok and cpplint would also agree


/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
"(.log.c.166)(.+)" - This finds the boot up start line 
"(oejs.AbstractConnector:Started)(.+)" - this finds the line for end/completion of the Boot
"^([0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2}:)" - Start up time
"([0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2}.[0-9]{3}:)" - End time

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
So I spent a lot of time trying to compare the smatch iterators to strings. 
So after wasting a few hours I realized... maybe I shouldn't. So I worked
around that issue by only using the << operator to just write things to the
files directly. I made my program just regulate when things were written to
the files so that the output was ordered a certain way. One thing that was
different was having the total starts and completions at the bottom instead
of the top as the samples do.

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I spent a lot of time trying to compare the smatch iterators to strings. 
So after wasting a few hours I realized... maybe I shouldn't.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

This program was up there, right next the solar system.