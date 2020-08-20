from three import made3sVersus
from turn import turnoversVersus
from plus import plusMinusVersus
from datetime import date, datetime, timedelta

# function to get a text output for three categories: plus minus, turnovers, and three pointers made.
# Combines text of the three primary bets based off of decisions with my friends
# twoDays variable important for determining if the player's team played the day before
# Works for any player who was on an NBA roster in the 2019-2020 season
def runBetsUpdate():

    today = date.today()
    days = timedelta(2)
    twoDays = today - days

    plusText = plusMinusVersus("Jordan Clarkson", "J.J. Redick", twoDays)
    toText = turnoversVersus("Russell Westbrook", "Ben Simmons", twoDays)
    threeText = made3sVersus("Damian Lillard", "Donovan Mitchell", twoDays)

    totalText = '\n'.join(["2020 Bubble Basketball Bets", "", plusText, "", "", toText, "", "", threeText])

    return totalText
