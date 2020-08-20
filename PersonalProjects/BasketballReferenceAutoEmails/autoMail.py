from NBAbubbleBets import runBetsUpdate
from datetime import date, datetime, timedelta

# to schedule cron job use command export EDITOR=nano; crontab -e

# needed to pull today's date to update the subject
today = date.today()
day = timedelta(1)
yesterday = today - day
subject = "NBA Bubble Bet Updates as of " + str(today)
# print(subject)

# runBetsUpdate contained in NBAbubbleBets.py
msg = runBetsUpdate()

# put import below where typical for pathing to get password and e-mail addresses
from emailScript import send_email
# print(msg)

# actual commands were removed to protect friends e-mails, syntax is still shown below
send_email(subject, msg, "fakeemail1@gmail.com")
send_email(subject, msg, "fakeemail2@aol.com")