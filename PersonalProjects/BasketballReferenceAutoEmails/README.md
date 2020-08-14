Explanation of Contents:
1. ExampleDonovanMitchell3s.csv - example of csv files saved during project running
2. ExampleEmail.png - screenshot of one of the emails sent
3. NBABubbleBets.py - Where the three stat categories are combined
4. autoMail.py - equivalent of main, this is the script that was run by cron to run the program every morning
5. emailScript.py - SMTP work for gmail to login and send emails
6. plus.py - webscraping basketballreference.com for plus/minus stat
7. three.py - webscraping basketballreference.com for Three Pointers Made stat
8. turn.py - webscraping basketballreference.com for turnovers stat

Project Summary: Scrape the website basketballreference.com for specific players to obtain specific game statistics and automatically send e-mails.
Successfully sent to a small list of friends every morning to update after the previous days games. 
Works for any player who has played in the 2019-2020 season on the website.

Scraping: Used beautifulSoup to access basketballreference and go through multiple webpages to get to the correct player 
and correct season to pull the information. Stored data in a pandas dataframe, saved backups as a csv. 

Preparing email: used SMTP library to login to gmail account and send specific e-mails.

Automatic: used cron within MacBook to setup automatic running of python script. 
Setup personal MacBook to wake up one minute before script was scheduled to run so it ran every morning.

Program successfully ran during the NBA 2020 Bubble Restart season July and August 2020. 
