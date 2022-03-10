
# Fanduel NBA Best Possible Lineup
 > 
 
  Authors: [Jordan Kuschner](https://github.com/marinersjk00),  [Chris Chua](https://github.com/cchua00) , [Andrew Ocegueda](https://github.com/xTh3Unkn0wnx), [Bilal Nasir](https://github.com/noshotbigjuicersbilal151)
 

 



## Project Description


On websites like FanDuel.com and DraftKings.com, one can play "daily fantasy sports" which differ from typical fantasy sports in that your team is only your team for one day. In regular fantasy basketball, when you draft your team at the start of the year, you're stuck with pretty much the same team throughout the year whether they're good, bad, healthy, or unhealthy. In daily fantasy basketball, if one of your players gets a season-ending injury, you will be down for a night but can just simply choose to avoid picking that player the next time you play.

The goal of daily fantasy is to draft the best possible lineup for that day's slate of games. The most surefire way to do this, although there is no surefire way since we cannot predict the future, would be to draft all the top players. However, this is not possible because there is an implemented salary cap. The star players who typically have great games every night are far more expensive than the secondary players who average much lower statistics. But, on any given night, any player can have a great game regardless of how consistently good they've been in the past. Thus, the goal of daily fantasy is to work within the limitations of the salary cap to find the best possible lineup for that day. This will almost always be a mix of a couple big stars and more secondary players that one might personally think will do well that night.

Now, again, we cannot accurately predict the future. That said, we can use past data to help us in our attempts to accurately predict the future. The goal of our program is to be able to return the best possible lineup from a given past day knowing all the stats of all the possible players now exist and are unchangeable. The user should be able to enter a day in the past that basketball games occurred, and from that the program should return at least the best possible lineup, if not the top 2 or 3 best possible lineups. The user can then use this information to try and find more under the radar players that seem to consistently do well when he/she is creating his future lineups. We plan to do as much as possible in C++, although SQL and possibly JDBC may be necessary to organize data.

  ## Phase II

## Class Diagram
![image](https://github.com/cs100/final-project-jkusc002-bnasi004-cchua032-aoce003/blob/a7e4bae0d7e328749fb3792b512f8fae37c6bc58/UML%20Diagram.png)
 The client calls on csvReader(), which in turn calls on webscraper.py which webscrapes [this website](http://rotoguru1.com/cgi-bin/hyday.pl?game=fd&mon=2&day=22&year=2021&scsv=) (date values changeable based on input) and generates a .csv file with a list of players and their information from that day. csvReader() then parses the .csv file into a 2D vector of strings. Then the client instantiates a Team object. The Team class houses vectors to hold Players in their different forms, as well as various methods to manipulate the vectors of players to find the best possible lineup. The client calls these methods in a specific order to get the best lineup. The Player class is separate from Team, and represents each individual player. Each Player has variables to hold their cost, points scored, name, position, value, and a position value (for sorting purposes). The Player class has getters for each variable except value, in which it has a method to calculateValue() instead. The five position classes (PointGuard, ShootingGuard, PowerForward, SmallForward, Center) all inherit from PLayer and simply define their position strings and values appropriately.
 
 ## Phase III
We ultimately used the Singleton design pattern. We decided to do this because all of our work to figure out the best lineup after webscraping the player data was just manipulating groupings of players in different ways. As such, it seemed appropriate to have a Team class that housed all the methods. Likewise, we were able to create only one instance of a Team object and use its methods to produce the best possible lineup. Following the Singleton design pattern made our code much more readable and easier to debug. Rather than having everything written in main and scrolling through large files, we were able to work on each individual method one by one in Team and pinpointing the errors was much easier. 

 
 
 ## Screenshots
 ![image](https://github.com/cs100/final-project-jkusc002-bnasi004-cchua032-aoce003/blob/7817f44d513d62728e6639029c085bd51b58ed6a/output1.png)
 ![image](https://github.com/cs100/final-project-jkusc002-bnasi004-cchua032-aoce003/blob/a7e4bae0d7e328749fb3792b512f8fae37c6bc58/output2.png)
 ![image](https://github.com/cs100/final-project-jkusc002-bnasi004-cchua032-aoce003/blob/a7e4bae0d7e328749fb3792b512f8fae37c6bc58/output3.png)  
 ![image](https://github.com/cs100/final-project-jkusc002-bnasi004-cchua032-aoce003/blob/a7e4bae0d7e328749fb3792b512f8fae37c6bc58/output4.png)
 ## Installation/Usage 
 In order to install the program first make sure you are in the your home directory by using the following command:
   ```
   $ cd ~ 
   ```
   Then clone the repository by using the git clone command followed by the URL repository link:
   ```
   $ git clone https://github.com/cs100/final-project-jkusc002-bnasi004-cchua032-aoce003.git
   ```
   Change the directory from home to the repository with the following: 
   ``` 
   $ cd final-project0jkusc002-bnasi004-cchua032-aoce003/ 
   ```
   After cloning the repository, run the following command in order to install the extensions for the requests, pandas, and beautiful soup extensions for python 3 and higher use: 
   ```
   $ python3 -m pip3 install --user requests
   $ python3 -m pip3 install --user pandas
   $ python3 -m pip3 install --user bs4
   ```
   for python 2.7 and below use:
   ``` 
   $ python3 -m pip install --user requests
   $ python3 -m pip install --user pandas
   $ python3 -m pip install --user bs4
   ```
  After all of these have successfully been installed, the program will be able to run.   
  In order to run the program, first compile main.cpp with following command:   
  ```
   $ g++ -o FanduelProgram main.cpp 
   ```
    
  Then run the executable using the following command: 
   ``` 
   $ ./FanduelProgram
   ```
   The program will ask you for a month, day, and year in order.
  ```  
   Enter month: 02
   Enter day: 28 
   Enter year: 2015 
  ``` 
  **NOTE: Example Date is given above**
  
  Inputting the date will bring up the best line up possible on that day.  
  Inputting the date as 04/13/2016 or 4/13/2016 will find the same best line up.  
  
  **The program will only work if the user inputs numbers for the date.**   
  **Inputting "feb" for the month will not output the correct data.**  
  
  __Due to the website used in the webscrapper, the date of the earliest game that can find the best line up is October 28, 2014 (10,28,2014) and the date of the last game is     June 22, 2021 (06,22,2021).__
  
  After you have received your best line-up for that particular date, the program will ask you if you want to enter another date. It will ask for a character input so the user can reply to this segment of the program with one letter.
  ```
  Do you want to find another lineup from another date?
  Yes (Y) / No (N) : Y
  ```
  If you entered "Y" or "y," the program will execute the program again and the user can now enter another date for that days best line-up. If the user inputs anything else, the program would end, completing its objective. 
  
  **Note: It will not take "Yes" as an input, it can only accept 'Y' or 'y' as an input to execute the program again**
  
  ## Testing
  For testing we adopted the google test framework. We ran unit tests on all of our functions including our webscraper. We created the file CMakeLists.txt to generate an executable for the unit tests under a file called unit_test. This will pull the unit tests from unit_test.cpp. 
  We basically created two test suites, one that uses a fixed csv file that is generated at the beginning of the tests, and one that tests our webscraper. 
  
  ## Fixed CSV Test Suite
  In this test suite we test our algorithm that creates the best line up to ensure functionality. This consists of multiple functions including: 
  ```
   getPositions()
   valueSorter()
   bestByValue()
   sortByPointsScored()
   spendRemainingCapOnPoints()
   sortByPosition()
  ``` 
  This test suite is reliant on asking the tester to give the python webscraper a certain date. We know which values to expect for each function so we simply pass the test if the values match up. We ensure this works because if we enter a different date, all of our tests fail. 
  
  ## Webscraper Test Suite
  Testing the webscraper proved to be quite difficult. Our webscraper is implemented in python and its primary use is to give us a csv file to read. Since googletest framework is used for c++ we had to get creative on how to test it. Our solution was to test that it would indeed create the csv file needed. We simply remove the existing csv file, call our webscraper, and check if a new file is created. We also test if the date that was input is valid. We do this by checking the contets of the csv file, if it's empty itll fail and if its full it'll pass.

 
