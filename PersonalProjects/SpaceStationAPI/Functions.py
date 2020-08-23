import pandas as pd
import requests
from datetime import datetime

# connect to the SpaceStation API to get the current information in a request object
# returns an int
def SpaceStationAPIResponse():
    resquestToReturn = requests.get("http://api.open-notify.org/astros.json")
    if resquestToReturn.status_code != 200:
        raise Exception("Could not connect to astros.json API")
    return resquestToReturn

# pull the number of people from the request object created above used as a dictionary
def peopleCurrentlyInSpace(APIrequest):
    return APIrequest.json()['number']

# pull the names of the people from the request object created above used as a dictionary
# returns a list of names (strings)
def namesOfThoseInSpace(APIrequest):
    listOfTheo = APIrequest.json()['people']
    toReturn = []
    for dict in listOfTheo:
        toReturn.append(dict['name'])
    return toReturn

# takes in two floats (intended to be a latitude and longitude value to get pass times
# acts as a void function (no return)
def printOverheadList(latitudeFloat, longitudeFloat):
    parameters = {
        "lat": latitudeFloat,
        "lon": longitudeFloat
    }
    requiredSpace = requests.get("http://api.open-notify.org/iss-pass.json", params=parameters)
    passTimes = requiredSpace.json()['response']
    riseTimes = []

    for d in passTimes:
        riseTime = d['risetime']
        riseTimes.append(riseTime)

    print("These are the next times the ISS will be over the coordinates you have given:")
    for rt in riseTimes:
        time = datetime.fromtimestamp(rt)
        print(time)
