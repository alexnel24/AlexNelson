import requests
import json
from datetime import datetime

#THIS FILE IS ME LEARNING ABOUT REQUESTS AND LEARNING ABOUT THE SPACESTATION API
print("running")
print("first test")
response = requests.get("http://api.open-notify.org/this-api-doesnt-exist")
print("this-api-doesnt-exist: " + str(response.status_code))
print("first test done\n")

print("second test")
spaceResponse = requests.get("http://api.open-notify.org/astros.json")
print("astros.json: " + str(spaceResponse))
print("json: " + str(spaceResponse.json()))
print("second test done\n")

print(type(spaceResponse))
print(type(spaceResponse.json()))

dict = spaceResponse.json()


# with open(spaceResponse.json()) as json_file:
#     dict = json.load(json_file)
numOfPeople = dict['number']
print(numOfPeople)

# function for creating a formatted string of the Python JSON object (used in third test)
def jprint(obj):
    text = json.dumps(obj, sort_keys=True, indent=4)
    print(text)


print("third test")
jprint(spaceResponse.json())
spaceResponse.close()
print("third test done\n")

print("fourth test")
# latitude is required, longitude is required, altitude is optional, number of passes is optional
parameters = {
    "lat": 40.281890,
    "lon": -111.712380
}
requiredSpace = requests.get("http://api.open-notify.org/iss-pass.json", params=parameters)
print(requiredSpace)
passTimes = requiredSpace.json()['response']
jprint(passTimes)
riseTimes = []

for d in passTimes:
    riseTime = d['risetime']
    riseTimes.append(riseTime)

print(riseTimes)

readableTimes = []
for rt in riseTimes:
    time = datetime.fromtimestamp(rt)
    readableTimes.append(time)
    print(time)
print("fourth test done\n")


# original work with json before learning about dictinoaries and lists
# def peopleCurrentlyInSpace(APIrequest):
#     noOfPeople = APIrequest.content.split("\"number\": ")
#     noOfPeople = noOfPeople[1].split(",")
#     print("number of people in space: " + noOfPeople[0])












