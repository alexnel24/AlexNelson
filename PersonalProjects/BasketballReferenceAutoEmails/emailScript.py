import smtplib

# this is the file where login information was stored, not included in gitHub repo
import emailKeeper


# Function created to send e-mail out
def send_email(subject, msg, outgoingAddress):


    try:
        server = smtplib.SMTP('smtp.gmail.com:587')
        server.ehlo()
        server.starttls()
        server.login(emailKeeper.USERNAME, emailKeeper.PASSWORD)
        # print("successfully logged in")
        message = 'Subject: {}\n\n{}'.format(subject, msg)
        server.sendmail(emailKeeper.USERNAME, outgoingAddress, message)
        server.quit
        # print("Success!")
    except Exception as e:
        print("Email failed to send " + str(e))

