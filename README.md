 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Daily Fantasy Best Possible Lineup
 > 
 
  Authors: [Jordan Kuschner](https://github.com/marinersjk00),  [Chris Chua](https://github.com/cchua00) , [Andrew Ocegueda](https://github.com/xTh3Unkn0wnx), [Bilal Nasir](https://github.com/noshotbigjuicersbilal151)
 

 



## Project Description


On websites like FanDuel.com and DraftKings.com, one can play "daily fantasy sports" which differ from typical fantasy sports in that your team is only your team for one day. In regular fantasy basketball, when you draft your team at the start of the year, you're stuck with pretty much the same team throughout the year whether they're good, bad, healthy, or unhealthy. In daily fantasy basketball, if one of your players gets a season-ending injury, you will be down for a night but can just simply choose to avoid picking that player the next time you play.

The goal of daily fantasy is to draft the best possible lineup for that day's slate of games. The most surefire way to do this, although there is no surefire way since we cannot predict the future, would be to draft all the top players. However, this is not possible because there is an implemented salary cap. The star players who typically have great games every night are far more expensive than the secondary players who average much lower statistics. But, on any given night, any player can have a great game regardless of how consistently good they've been in the past. Thus, the goal of daily fantasy is to work within the limitations of the salary cap to find the best possible lineup for that day. This will almost always be a mix of a couple big stars and more secondary players that one might personally think will do well that night.

Now, again, we cannot accurately predict the future. That said, we can use past data to help us in our attempts to accurately predict the future. The goal of our program is to be able to return the best possible lineup from a given past day knowing all the stats of all the possible players now exist and are unchangeable. The user should be able to enter a day in the past that basketball games occurred, and from that the program should return at least the best possible lineup, if not the top 2 or 3 best possible lineups. The user can then use this information to try and find more under the radar players that seem to consistently do well when he/she is creating his future lineups. We plan to do as much as possible in C++, although SQL and possibly JDBC may be necessary to organize data.

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to:
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller actionable development tasks as issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
 > * Schedule two check-ins using Calendly. You need to pick both time slots during your lab on week 8. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members

## Class Diagram
 The overarching class is the Team class which will hold the total team salary, the total team points, and the date to retrieve a team from. Player will inherit from team, with each player having it's individual statistics and cost to the team salary. Each player has a specific position. The position doesn't matter much except that certain players can only fill out certain positions and there has to be 2 players of each position, except Center which only needs 1.
 
 > ## Phase III

We are using a composite pattern for implementing out Team, Player, and position classes. This is because our inheritance is relatively simple. All of our subclasses are really just smaller instances of their parents. For example, Team is a collection of Players, and every position player is still a player on a team. We don't have many complicated strategies or decisions involved in this portion so we are ok with using a composite design pattern. For our comparison between players, however, we may need to use a strategy pattern instead. As we get into comparing players to see who goes on our best teams, we could run into a multitue of iffy situations such as comparing maximum points vs points per dollar, or considering a tie in points or if a more valueable position is filled. We will also need to consider additonal factors like if our team isfull at a certain position or if a more valueable player exists that we cannot afford. Overall, there are many complications that could occur as a result of comparing between players, so a strategy pattern would be best. The comparisons haven't been implemented yet, but following the composite design pattern has allowed us to stay focued on the specific tasks we are working on. It is easy to think of new ideas while writing the code, but following the design pattern has forced us to keep things simple for this portion and save the more advanced stuff for the strategy side.

 
 > ## Final deliverable
 > All group members will give a demo to the TA/reader during lab time. The TA/reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
