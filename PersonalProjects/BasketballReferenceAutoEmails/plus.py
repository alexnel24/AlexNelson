import urllib.request
from bs4 import BeautifulSoup
import pandas as pd
from datetime import date, datetime, timedelta
import os, ssl
if (not os.environ.get('PYTHONHTTPSVERIFY', '') and
getattr(ssl, '_create_unverified_context', None)):
    ssl._create_default_https_context = ssl._create_unverified_context


# function to get an individuals plus/minus stat between April 30th and the day after the variable dateTime
def runPlusMinusIndividual(playerName, dateTime):
    url = "https://www.basketball-reference.com/players/"
    initial = playerName.split(" ")[1][0].lower()
    letterurl = url + "{}/".format(initial)

    with urllib.request.urlopen(letterurl) as response:
        html = response.read()
        html = html.decode('utf-8')

    # print('plus playerWithInitial cwd:       ', os.getcwd())
    with open('playersWithInitial.html', 'w') as new_file:
        new_file.write(html)
    soup = BeautifulSoup(open('playersWithInitial.html'), 'html5lib')

    playerLocate = soup.find_all('a', href=True)
    for tag in playerLocate:
        if tag.string == playerName:
            indHTML = tag.get('href')

    playerPage = "https://www.basketball-reference.com" + indHTML

    with urllib.request.urlopen(playerPage) as response:
        html = response.read()
        html = html.decode('utf-8')

    # print('plus playerHTML cwd:       ', os.getcwd())
    with open('playerHTML.html', 'w') as new_file:
        new_file.write(html)
    soup = BeautifulSoup(open('playerHTML.html'), 'html5lib')

    yearsPlayed = soup.find_all('a')

    for tag in yearsPlayed:
        if tag.string == '2019-20':
            if 'gamelog' in tag.get('href'):
                finalHTML = "https://www.basketball-reference.com" + tag.get('href')

    with urllib.request.urlopen(finalHTML) as response:
        html = response.read()
        html = html.decode('utf-8')

    # print('plus gamelog cwd:       ', os.getcwd())
    with open('gamelog.html', 'w') as new_file:
        new_file.write(html)
    soup = BeautifulSoup(open('gamelog.html'), 'html5lib')

    gameTags = soup.find_all('td')

    #     regularDF = pd.DataFrame(columns=['Date','PlsMinus'])
    bubbleDF = pd.DataFrame(columns=['Date', 'PlsMinus'])

    comboList = playerName.split(' ')
    combo = comboList[0] + comboList[1]

    bubbleString = combo + 'Bubble.csv'
    #     if os.path.isfile(bubbleString):
    #         oldDf = pd.read_csv(bubbleString)
    #         oldDf['Date'] = pd.to_datetime(oldDf['Date'])
    #         maxDate = oldDf['Date'].max()
    #     else:
    #         maxDate = date(2019, 9,30)

    maxDate = dateTime

    bubbleDate = date(2020, 4, 30)

    booleanPreBubble = False
    booleanBubble = False
    for tag in gameTags:
        for k, v in tag.attrs.items():
            if v == 'date_game':
                dateList = tag.string.split('-')
                dateInput = pd.Timestamp(date(int(dateList[0]), int(dateList[1]), int(dateList[2])))

                #                 if dateInput < bubbleDate and dateInput > maxDate:
                #                     booleanPreBubble = True
                if dateInput > bubbleDate:
                    booleanBubble = True

            if v == 'plus_minus':
                points = str(tag.string)
                plsmns = points.replace("'", "")
                plsmns = int(points)
                #                 if booleanPreBubble:
                #                     regularDF = regularDF.append({'Date' : dateInput, 'PlsMinus' : plsmns},ignore_index=True)
                #                     booleanPreBubble = False
                if booleanBubble:
                    bubbleDF = bubbleDF.append({'Date': dateInput, 'PlsMinus': plsmns}, ignore_index=True)
                    booleanBubble = False

            if v == 'reason':
                #                 if booleanPreBubble:
                #                     regularDF = regularDF.append({'Date' : dateInput, 'PlsMinus' : 'DNP'},ignore_index=True)
                #                     booleanPreBubble = False
                if booleanBubble:
                    bubbleDF = bubbleDF.append({'Date': dateInput, 'PlsMinus': 'DNP'}, ignore_index=True)
                    booleanBubble = False

    #     regString = combo + 'Prebubble.csv'
    #     regularDF.to_csv(regString, index = False)
    bubbleString = combo + 'Bubble.csv'
    bubbleDF.to_csv(bubbleString, index=False)

    playedYesterday = False
    teamGames = 0
    playerGames = 0
    overallTotal = 0
    last = 0
    for index, line in bubbleDF.iterrows():
        teamGames += 1
        if line['PlsMinus'] != 'DNP':
            playerGames += 1
            overallTotal += line['PlsMinus']
        if line['Date'] > maxDate:
            playedYesterday = True
            if line['PlsMinus'] != 'DNP':
                last = line['PlsMinus']
    return playedYesterday, teamGames, playerGames, overallTotal, last


# function to compare two players against each other and output text with intention of getting fed to an e-mail
def plusMinusVersus(player1, player2, dateTime):
    p1bool, p1team, p1games, p1total, p1last = runPlusMinusIndividual(player1, dateTime)
    p2bool, p2team, p2games, p2total, p2last = runPlusMinusIndividual(player2, dateTime)

    if p1total == p2total:
        firstLine = player1 + " and " + player2 + " are TIED!"
    elif p1total > p2total:
        firstLine = player1 + " is WINNING!"
    else:
        firstLine = player2 + " is WINNING!"

    textTitle = "PLUS/MINUS " + player1 + " vs " + player2

    play1Text = "Games " + player1 + " has played in the bubble: " + str(p1games)
    team1Text = "Games " + player1 + "'s team has played in the bubble: " + str(p1team)
    left1Text = "Team games left for " + player1 + ": " + str(8 - p1team)

    if p1bool:
        yest1Text = player1 + " had a plus/minus of: " + str(p1last) + " in yesterday's game"
    else:
        yest1Text = player1 + " did not play yesterday"

    total1text = player1 + "'s OVERALL plus/minus in the bubble: " + str(p1total)

    play2Text = "Games " + player2 + " has played in the bubble: " + str(p2games)
    team2Text = "Games " + player2 + "'s team has played in the bubble: " + str(p2team)
    left2Text = "Team games left for " + player2 + ": " + str(8 - p2team)

    if p2bool:
        yest2Text = player2 + " had a plus/minus of: " + str(p2last) + " in yesterday's game"
    else:
        yest2Text = player2 + " did not play yesterday"

    total2text = player2 + "'s OVERALL plus/minus in the bubble: " + str(p2total)

    return '\n'.join([textTitle, "", firstLine, "", play1Text, team1Text, left1Text, yest1Text, total1text,
                      "", play2Text, team2Text, left2Text, yest2Text, total2text])